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

val mod = 998244353

fun pew(a: Long, b: Int): Long
{
    var res = 1L
    var B = b
    var A = a
    while (B>0)
    {
        if (B%2==1) res = res*A%mod
        B /= 2
        A = A*A%mod
    }
    return res
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
    var a = spl[1]
    var b = spl[2]
    var x = Array(n)
    {
        0
    }
    var y = Array(n)
    {
        0
    }
    var p10 = pew(1000000L,mod-2)
    var p = Array<Long>(n)
    {
        0
    }
    var ans = 1L
    var was = Array(a)
    {
        0
    }
    var was2 = Array(b)
    {
        0
    }
    var pr1 = Array<Long>(a+b)
    {
        1
    }
    var pr2 = Array<Long>(a+b)
    {
        1
    }
    for (i in 0..n-1)
    {
        spl = readLine()!!.split(' ').map(String::toInt)
        x[i] = spl[0]
        y[i] = spl[1]
        was[x[i]] = 1
        was2[y[i]] = 1
        p[i] = spl[2]*p10%mod
        pr1[x[i]+y[i]] = pr1[x[i]+y[i]]*(mod+1-p[i])%mod
        pr2[x[i]-y[i]+b] = pr2[x[i]-y[i]+b]*(mod+1-p[i])%mod
    }
    for (i in 0..a-1) ans += was[i]
    for (j in 0..b-1) ans += was2[j]
    for (k in 0..a+b-1)
    {
        ans += mod+1+mod+1-pr1[k]-pr2[k]
        ans %= mod

    }
    ans %= mod
    for (i in 0..a-1)
    {
        for (j in 0..b-1)
        {
            if (was[i]==1 && was2[j]==1) ans++
        }
    }
    for (S in 0..a+b-1)
    {
        for (x2 in 1..2*a-1)
        {
            var y2 = 2*S-x2
            if (y2<=0 || y2>=2*b) continue
            if (y2%2==0)
            {
                if (was[x2/2]==1 || was2[y2/2]==1)
                {
                    ans += mod+1-pr1[S]
                    continue
                }
            }
            var Z = (x2-y2)/2+b
            ans += (mod+1-pr1[S])*(mod+1-pr2[Z])%mod
        }
    }
    for (S2 in 0..a+b-1)
    {
        for (x2 in 1..a-1)
        {
            var y2 = x2-S2+b
            if (y2<=0 || y2>=b) continue
            if (was[x2]==1 || was2[y2]==1)
            {
                ans += mod+1-pr2[S2]
                continue
            }
        }
    }
    ans %= mod
    print(ans)
}