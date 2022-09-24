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
    var n = readLine()!!.toInt()
    var a = Array(n+1,{0})
    var b = Array(n,{0})
        for (i in 1..n)
        {
            b[i-1] = n/i - 1
            var j = 1
            while (j*j<=i)
            {
                if (i%j==0)
                {
                    a[i] += 2
                    if (i==j*j) a[i] -= 1
                }
                j += 1
            }
            a[i] -= 1
            b[i-1] -= a[i]
        }
        b.sortWith(compareBy({-it}))
        var ans = 0
        for (j in 0..n-1)
        {
            var i = n-1-j
            ans -= b[i]
            print(ans)
            print(" ")
        }
}