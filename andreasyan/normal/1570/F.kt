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
        var a = Array(n) {IntArray(m)}
        for (i in 0 until n)
        {
            var aa = readInts()
            for (j in 0 until m)
            {
                a[i][j] = aa[j]
            }
        }
        
        var ansx = mutableListOf<Int>()
        var ansy = mutableListOf<Int>()
        
        var b = Array(n) {IntArray(m)}
        for (i in 0 until n)
            for (j in 0 until m)
                b[i][j] = 0
        for (i in 0 until n - 1)
        {
            for (j in 0 until m - 1)
            {
                if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1)
                {
                    ansx.add(i)
                    ansy.add(j)
                    b[i][j] = 1
                    b[i + 1][j] = 1
                    b[i][j + 1] = 1
                    b[i + 1][j + 1] = 1
                }
            }
        }
        
        var z = true
        for (i in 0 until n)
        {
            for (j in 0 until m)
            {
                if (a[i][j] != b[i][j])
                    z = false
            }
        }
        
        if (!z)
            println("-1")
        else
        {
            println(ansx.size)
            for (i in 0 until ansx.size)
            {
                print(ansx[i] + 1)
                print(" ")
                println(ansy[i] + 1)
            }
        }
    }
}