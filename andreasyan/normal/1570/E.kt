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
        var a = readLn()
        var n = a.length
        var l = -1
        var r = -2
        for (i in 0 until n)
        {
            if (a[i] == '1')
            {
                if (l == -1)
                    l = i
                r = i
            }
        }
        
        var ans = 0
        for (i in l until r + 1)
        {
            if (a[i] == '0')
                ++ans
        }
        
        println(ans)
    }
}