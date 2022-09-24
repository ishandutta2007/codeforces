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

var INF = 10000000000000000L
var t = Array<Long>(2200000)
{
   -INF
}

fun upd(v: Int, tl: Int, tr: Int, p: Int, del: Long)
{
    t[v] = max(del,t[v])
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
    return max(get(v*2,tl,tm,l,tm),get(v*2+1,tm+1,tr,tm+1,r))
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
    var mx = 400000
    var kek = Array(mx)
    {
        Pair(mx*2,Pair(-1,-1))
    }
    var I = 0
    var w = 0
    while (n>0)
    {
        n--
        var k = readLine()!!.toInt()
        var y = Array(k){I}
        I++
        spl = readLine()!!.split(' ').map(String::toInt)
        var b = Array(k){spl[it]}
        spl = readLine()!!.split(' ').map(String::toInt)
        var x = Array(k){spl[it]}
        for (i in 0..k-1)
        {
            if (x[i]+y[i]<m) continue
            kek[w] = Pair(x[i]+y[i],Pair(x[i],b[i]))
            w++
        }
    }
    kek.sortWith(compareBy({it.first}, {it.second.first}))
    upd(1,0,mx,m,0)
    for (i in 0..w-1)
    {
        var p = kek[i].second.first
        var del = kek[i].second.second
        var Z = get(1,0,mx,p,mx)
        upd(1,0,mx,p,Z+del)
    }
    var ans = get(1,0,mx,0,mx)
    print(ans)
}