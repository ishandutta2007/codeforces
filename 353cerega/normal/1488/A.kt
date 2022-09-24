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
    var t = nextInt();
    for (q in 1..t)
    {
        var x = nextInt()
        var y = nextInt()
        var ans = 0
        for (i in 0..9)
        {
            var j = 9-i
            var p = 1
            while (j>0)
            {
                j -= 1
                p *= 10
            }
            while (y/p/x>0)
            {
                y -= p*x
                ans += 1
            }
        }
        ans += y
        println(ans)
    }
}