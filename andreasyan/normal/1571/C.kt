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
        
        var l = 0
        var r = 1000000009
        for (jj in 0 until n)
        {
            var a = readStrings()
            
            var q = 0
            var i = a[0].length - 1
            var j = a[1].length - 1
            while (true)
            {
                if (i == -1 || j == -1)
                    break
                if (a[0][i] != a[1][j])
                    break
                --i
                --j
                ++q
            }
            
            if (a[2] == "1")
                r = minOf(r, q)
            else
                l = maxOf(l, q + 1)
        }
        if (l <= r)
        {
            println(r - l + 1)
            for (i in l until r + 1)
            {
                print(i)
                print(" ")
            }
            println()
        }
        else
        {
            println(0)
        }
    }
}