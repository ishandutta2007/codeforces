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
        
        var z = true
        for (i in 0 until n)
        {
            if (a[i] != '=')
            {
                z = false
            }
        }
        if (z)
        {
            println('=');
            continue
        }
        
        z = true
        for (i in 0 until n)
        {
            if (a[i] == '>')
            {
                z = false
            }
        }
        if (z)
        {
            println('<')
            continue
        }
        
        z = true
        for (i in 0 until n)
        {
            if (a[i] == '<')
            {
                z = false
            }
        }
        if (z)
        {
            println('>')
            continue
        }
        
        println('?')
    }
}