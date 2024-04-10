import java.util.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) 
{
    var tt = 1
    //tt = readInt()
    for (ii in 0 until tt) 
    {
        var a = readLn()
        var n = a.length
        
        var p = IntArray(n)
        if (a[0] == '1')
            p[0] = 1
        else
            p[0] = 0
        for (i in 1 until n)
        {
            p[i] = p[i - 1]
            if (a[i] == '1')
                p[i]++
        }
        
        var anss = mutableListOf<Int>()
        for (k in 1 until n + 1)
        {
            var u = 0;
            var ans = 0;
            for (jj in 0 until n + 5)
            {
                if (u == n)
                    break
                ++ans
                var l = u
                var r = n - 1
                var t = -1
                while (l <= r)
                {
                    var m = (l + r) / 2
                    var q = p[m]
                    if (u - 1 >= 0)
                        q -= p[u - 1]
                    if (q <= k || (m - u + 1) - q <= k)
                    {
                        t = m
                        l = m + 1
                    }
                    else
                        r = m - 1
                }
                u = t + 1
            }
            anss.add(ans)
        }
        println(anss.joinToString(" "))
    }
}