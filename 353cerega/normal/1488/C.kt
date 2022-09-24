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
        val spl = readLine()!!.split(' ').map(String::toInt)
        var n = spl[0]
        var x = spl[1]
        var y = spl[2]
        if (x>y)
        {
            var z = x
            x = y
            y = z
        }
        var ans = n*2
        for (i in 1..n-1)
        {
            var cur1 = i-1
            if (i<x) cur1 = x
            else {
                if (i - x < x - 1) cur1 += i - x
                else cur1 += x - 1
            }
            var cur2 = n-i-1
            if (y<i+1) cur2 = n-y
            else {
                if (y - i - 1 < n - y) cur2 += y - i - 1
                else cur2 += n - y
            }
            if (cur1<cur2) cur1 = cur2
            if (ans>cur1) ans = cur1
        }
        println(ans)
    }
}