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
        var aa = readInts()
        var x = aa[0]
        var y = aa[1]
        
        var ans = 0
        var k = 0
        while (true)
        {
            if (k + x > y)
            {
                ans += (y - k)
                break
            }
            ++ans
            var xx = x
            while (k + xx * 10L <= y)
                xx *= 10
            k += xx
        }
        println(ans)
    }
}