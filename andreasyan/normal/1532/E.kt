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
        
        var t = IntArray(n)
        for (i in 0 until n)
            t[i] = a[i]
        t.sort()
        
        var s = 0L
        for (i in 0 until n)
            s += a[i]
        
        var max1 = 0
        var max2 = 0
        for (i in 0 until n)
        {
            if (a[i] >= max1)
            {
                max2 = max1
                max1 = a[i]
            }
            else if (a[i] >= max2)
                max2 = a[i]
        }
        
        var v = mutableListOf<Int>()
        for (i in 0 until n)
        {
            if ((s - a[i]) % 2 == 0L)
            {
                if (a[i] != max1)
                {
                    if ((s - a[i]) / 2 == max1 * 1L)
                        v.add(i + 1)
                }
                else
                {
                    if ((s - a[i]) / 2 == max2 * 1L)
                        v.add(i + 1)
                }
            }
        }
        
        println(v.size)
        println(v.joinToString(" "))
    }
}