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
    var t = readLine()!!.toInt();
    for (q in 1..t)
    {
        val spl = readLine()!!.split(' ').map(String::toLong)
        var n = spl[0]
        var s = spl[1]
        var l = 1L
        var r = 1000000000000000001
        while (r>l+1)
        {
            var m = (r+l)/2
            var M = m
            var sum = m
            for (i in 1..60)
            {
                if (i>=n) break
                m = m/2 + m%2
                sum += m
            }
            if (n>60) sum += n-61
            if (sum<=s) l = M
            else r = M
        }
        println(l)
    }
}