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
        
        aa = readInts()
        var f = aa[0]
        var l = aa[1]
        
        var qf = IntArray(n + 5)
        var ql = IntArray(n + 5)
        var q = IntArray((n + 5) * (n + 5))
        qf[f]++
        ql[l]++
        q[f * n + l]++
        for (i in 0 until m - 1)
        {
            aa = readInts()
            var f = aa[0]
            var l = aa[1]
            
            qf[f]++
            ql[l]++
            q[f * n + l]++
        }
        
        var ans = 1
        for (f0 in 1 until n + 1)
        {
            for (l0 in 1 until n + 1)
            {
                if (f0 == l0)
                    continue
                if (f0 == f && l0 == l)
                    ans = maxOf(ans, 1)
                else if (f0 == f || l0 == l)
                    ans = maxOf(ans, q[f0 * n + l0] + 1)
                else
                    ans = maxOf(ans, qf[f0] + ql[l0] - q[f0 * n + l0] + 1)
            }
        }
        
        println(ans)
    }
}