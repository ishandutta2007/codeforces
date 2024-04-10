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
        var a = aa[0]
        var b = aa[1]
        var k = aa[2]
        
        var ans = 0L;
        if (k % 2 == 0)
            ans = (a - b) * 1L * (k / 2)
        else
            ans = (a - b) * 1L * (k / 2) + a
        
        println(ans)
    }
}