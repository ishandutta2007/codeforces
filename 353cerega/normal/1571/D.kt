import java.util.*
import kotlin.math.max


/*fun cont(len: Int, cnt: Array<Int>): Long
{
    var L = len
    var ans: Long = 1
    cnt.sort()
    for (i in 0..8)
    {
        if (cnt[i]>60) return 2000000000
        for (j in 0..(cnt[i]-1))
        {
            ans *= L
            L--
            ans /= (j+1)
            if (ans>1000000000) return 1000000001
        }
    }
    return ans
}*/
var t = Array<Long>(1200000)
{
   0
}

fun upd(v: Int, tl: Int, tr: Int, p: Int, del: Long)
{
    t[v] += del
    if (tl==tr) return;
    var tm = (tl+tr)/2
    if (tm>=p) upd(v*2,tl,tm,p,del)
    else upd(v*2+1,tm+1,tr,p,del)
}

fun get(v: Int, tl: Int, tr: Int, l: Int, r: Int): Long
{
    if (tl==l && tr==r) return t[v]
    var tm = (tl+tr)/2
    if (tm>=r) return get(v*2,tl,tm,l,r)
    if (l>tm) return get(v*2+1,tm+1,tr,l,r)
    return get(v*2,tl,tm,l,tm)+get(v*2+1,tm+1,tr,tm+1,r)
}


fun main(args: Array<String>) = with(java.util.Scanner(System.`in`))
{
    //var n = nextInt()
    //var map: MutableMap<Int, Int>
    //var numbers: Array<Array<Int>> = Array(3, { Array(5, {0}) })
    //var numbers3: MutableSet<Int> = sortedSetOf(15, 16, 17)
    //var t = nextInt()
    //var n = nextInt()
    //var a = Array(n)
    //{
    //    100-it
    //}
    //var n = readLine()!!.toInt()
    //val spl = readLine()!!.split(' ').map(String::toInt)

    //var ord = Array(n)  { Pair(spl[it],it) }
    //ord.sortWith(compareBy({-it.first}, {it.second}))
    //for (i in 0..n-1)
    //{
    //     L[i+1] = max(b[i]-a[i],L[i])
    //}
    var spl = readLine()!!.split(' ').map(String::toInt)
    var n = spl[0]
    var m = spl[1]
    var a = Array(n*n)
    {
       0
    }
    var A1 = Array(n)
    {
        0
    }
    var A2 = Array(n)
    {
        0
    }
    spl = readLine()!!.split(' ').map(String::toInt)
    var x = spl[0]
    var y = spl[1]
    x--
    y--
    a[x*n+y]++
    A1[x]++
    A2[y]++
    for (i in 1..m-1)
    {
        spl = readLine()!!.split(' ').map(String::toInt)
        var A = spl[0]
        var B = spl[1]
        A--
        B--
        a[A*n+B]++
        A1[A]++
        A2[B]++
    }
    var P = 1
    for (i in 0..n-1)
    {
        for (j in 0..n-1)
        {
            if (i==j) continue
            var cnt2 = 1
            var cnt1 = 1+a[i*n+j]
            var cnt0 = A1[i]+A2[j]-cnt1+1+1
            var q = 0
            if (i==x) q++
            if (j==y) q++
            if (q==2)
            {
                if (cnt2>P) P = cnt2
            }
            if (q==1)
            {
                if (cnt1>P) P = cnt1
            }
            if (q==0)
            {
                if (cnt0>P) P = cnt0
            }
        }
    }
    print(P)
}