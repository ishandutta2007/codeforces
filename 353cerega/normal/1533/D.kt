import java.util.*


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
    val spl = readLine()!!.split(' ').map(String::toInt)
    var n = spl[0]
    var m = spl[1]
    var num: MutableSet<Long> = sortedSetOf()
    for (i in 0..n-1)
    {
        var s = readLine()!!
        var x = 0L
        for (j in 0..m-1)
        {
            x = x*27+(s[j]-'a')
        }
        num.add(x)
    }
    var q = readLine()!!.toInt()
    for (i in 0..q-1)
    {
        var s = readLine()!!
        var ans = 0
        for (p in 0..m)
        {
            if (p<m && s[p]==s[p+1]) continue
            var x = 0L
            for (j in 0..m)
            {
                if (j==p) continue
                x = 27*x+(s[j]-'a')
            }
            if (num.contains(x))
            {
                ans += 1
            }
        }
        println(ans)
    }
}