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
    tt = readInt()
    for (ii in 0 until tt) 
    {
        var n = readInt()
        var s = readLn()
        var a = readLn()
        
        var dp = IntArray((1 shl 4))
        for (x in 0 until (1 shl 4))
        {
            var q = 0
            for (i in 0 until 4)
            {
                if (s[i] == '(' && (x and (1 shl i)) != 0)
                    ++q
                else if (s[i] == ')' && (x and (1 shl i)) == 0)
                    ++q
            }
            if (a[0] == '0')
                dp[x] = q
            else
            {
                if (x == 4 + 8 || x == 2 + 8)
                    dp[x] = q
                else
                    dp[x] = n + 5
            }
        }
        
        for (i in 1 until n - 3)
        {
            var ndp = IntArray((1 shl 4))
            for (x in 0 until (1 shl 4))
                ndp[x] = n + 5
            for (x in 0 until (1 shl 4))
            {
                var y = (x shr 1) + 0
                var q = dp[x]
                if (s[i + 4 - 1] == ')')
                    ++q
                if (a[i] == '0')
                    ndp[y] = minOf(ndp[y], q)
                else if (y == 4 + 8 || y == 2 + 8)
                    ndp[y] = minOf(ndp[y], q)
                
                y = (x shr 1) + 8
                q = dp[x]
                if (s[i + 4 - 1] == '(')
                    ++q
                if (a[i] == '0')
                    ndp[y] = minOf(ndp[y], q)
                else if (y == 4 + 8 || y == 2 + 8)
                    ndp[y] = minOf(ndp[y], q)
            }
            for (x in 0 until (1 shl 4))
                dp[x] = ndp[x]
        }
        
        var ans = n + 5
        for (x in 0 until (1 shl 4))
            ans = minOf(ans, dp[x])
        
        if (ans == n + 5)
            println("-1")
        else
            println(ans)
    }
}