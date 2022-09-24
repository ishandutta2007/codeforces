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
        var k = spl[1]
        var s = readLine()!!
        var b = 0
        var ans = 0
        for (i in 0..n-1)
        {
            if (s[i]=='(') b++
            else b--
            if (b==0) ans++
        }
        ans += k
        if (ans>n/2) ans = n/2
        println(ans)
    }
}