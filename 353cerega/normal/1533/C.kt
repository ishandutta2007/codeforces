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
    var t = readLine()!!.toInt()
    while (t>0)
    {
        t -= 1
        val spl = readLine()!!.split(' ').map(String::toInt)
        var n = spl[0]
        var k = spl[1]
        var s = readLine()!!
        //println(s)
        var a = Array(n)
        {
            0
        }
        var cnt = 0
        var L = n
        for (i in 0..n-1)
        {
            if (s[i]=='1')
            {
                cnt += 1
            }
        }
        var p = n-k
        while (cnt>0)
        {
            var x = (k-1)%L+1
            while (true)
            {
                p += 1
                if (p==n) p = 0
                if (a[p]==0)
                {
                    x -= 1
                    if (x==0)
                    {
                        L -= 1
                        if (s[p]=='1') cnt -= 1
                        a[p] = 1
                        break
                    }
                }
            }

        }
        println(n-L)
    }
}