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
    var S = 0
    var n = spl[0]
    var m = spl[1]
    var a = Array(n)
    {
        0
    }
    var b = Array(n)
    {
        0
    }
    var ans = Array(n)
    {
        -1
    }
    for (i in 0..n-1)
    {
        spl = readLine()!!.split(' ').map(String::toInt)
        a[i] = spl[0]
        b[i] = spl[1]
        if (b[i]==1)
        {
            ans[i] = m-a[i]
            m -= a[i]
        } else S += a[i]
    }
    if (S>m)
    {
        println(-1)
        return
    }
    var dp = Array(S+1)
    {
        0
    }
    dp[0] = 1
    var prv = Array(S+1)
    {
        -1
    }
    for (i in 0..n-1)
    {
        if (b[i]==1) continue
        var j = S-a[i]
        while (j>=0)
        {
            if (dp[j]==1 && dp[j+a[i]]==0)
            {
                dp[j+a[i]] = 1
                prv[j+a[i]] = i
            }
            j--
        }
    }
    var d = 0
    for (i in 0..m)
    {
        if (i*2<S) continue
        if (dp[i]==0) continue
        d = i
        break
    }
    if (d*2-1>m)
    {
        println(-1)
        return
    }
    while (d>0)
    {
        var i = prv[d]
        d -= a[i]
        ans[i] = d*2
    }
    var pos = 1
    for (i in 0..n-1)
    {
        if (ans[i]==-1)
        {
            ans[i] = pos
            pos += a[i]*2
        }
        print(ans[i]+1)
        print(" ")
    }
}