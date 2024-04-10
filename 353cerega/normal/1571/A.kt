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
    var t = readLine()!!.toInt()
    while (t>0)
    {
        t--
        var s = readLine()!!
        var n = s.length
        var x = 0
        for (i in 0..n-1)
        {
            if (s[i]=='<')
            {
                if (x%2==0) x += 1
            }
            if (s[i]=='>')
            {
                if (x/2==0) x += 2
            }
        }
        if (x==0) println("=")
        if (x==1) println("<")
        if (x==2) println(">")
        if (x==3) println("?")
    }
}