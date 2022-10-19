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
        var aa = readInts()
        var n = aa[0]
        var m = aa[1]
        
        var t = IntArray(n)
        var k = IntArray(n)
        
        for (i in 0 until n)
        {
            aa = readInts()
            k[i] = aa[0]
            t[i] = aa[1]
        }
        
        var ans = IntArray(n)
        for (i in 0 until n)
        {
            if (t[i] == 2)
                continue
            ans[i] = m - k[i] + 1
            m -= k[i]
        }
        
        if (m < 0)
        {
            println("-1")
            continue
        }
        
        var dp = Array(n) {BooleanArray(m / 2 + 1)}
        
        for (i in 0 until n)
        {
            if (i == 0)
            {
                for (j in 0 until m / 2 + 1)
                    dp[i][j] = false
                dp[i][0] = true
            }
            else
            {
                for (j in 0 until m / 2 + 1)
                    dp[i][j] = dp[i - 1][j]
            }
            if (t[i] == 1)
            {
                continue
            }
            for (rj in 0 until m / 2 + 1)
            {
                var j = m / 2 - rj
                if (dp[i][j] && j + k[i] <= m / 2)
                    dp[i][j + k[i]] = true
            }
        }
        
        var s = 0
        for (i in 0 until n)
        {
            if (t[i] == 1)
                continue
            s += k[i]
        }
        
        var z = false
        for (q in 0 until m / 2 + 1)
        {
            if (!dp[n - 1][q])
                continue
            if (s - q <= m - m / 2)
            {
                z = true
                var o = 1
                var e = 2
                var j = q
                
                for (ri in 0 until n)
                {
                    var i = n - 1 - ri
                    if (t[i] == 1)
                        continue
                    if ((i == 0 && j == 0) || (i > 0 && dp[i - 1][j]))
                    {
                        ans[i] = o
                        o += 2 * k[i]
                    }
                    else
                    {
                        ans[i] = e
                        e += 2 * k[i]
                        j -= k[i]
                    }
                }
                
                println(ans.joinToString(" "))
                break
            }
        }
        
        if (!z)
            println("-1")
    }
}