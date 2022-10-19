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
        var n = readInt()
        var a = readInts()
        var b = readInts()
        var m = readInt()
        var c = readInts()
        
        var aa = IntArray(n)
        for (i in 0 until n)
            aa[i] = a[i]
        aa.sort()
        var bb = IntArray(n + 1)
        for (i in 0 until n + 1)
            bb[i] = b[i]
        bb.sort()
        
        var p = IntArray(n)
        p[0] = bb[0] - aa[0]
        for (i in 1 until n)
            p[i] = maxOf(p[i - 1], bb[i] - aa[i])
        
        var s = IntArray(n)
        s[n - 1] = bb[n] - aa[n - 1]
        for (i in 1 until n)
            s[n - i - 1] = maxOf(s[n - i], bb[n - i] - aa[n - i - 1])
        
        var anss = mutableListOf<Int>()
        for (i in 0 until m)
        {
            var l = 0
            var r = n - 1
            var u = 0
            while (l <= r)
            {
                var m = (l + r) / 2
                if (c[i] >= aa[m])
                {
                    l = m + 1
                    u = m + 1
                }
                else
                    r = m - 1
            }
            
            //println(u)
            
            var ans = bb[u] - c[i]
            if (u - 1 >= 0)
                ans = maxOf(ans, p[u - 1])
            if (u < n)
                ans = maxOf(ans, s[u])
            
            anss.add(ans)
        }
        println(anss.joinToString(" "))
    }
}