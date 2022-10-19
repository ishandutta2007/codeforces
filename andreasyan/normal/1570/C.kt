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
        var p = IntArray(n) { it }.sortedByDescending { a[it] }
        
        var ans = 0
        for (i in 0 until n)
        {
            ans += (a[p[i]] * i + 1)
        }
        
        println(ans)
        
        var anss = mutableListOf<Int>()
        for (i in 0 until n)
            anss.add(p[i] + 1)
        println(anss.joinToString(" "))
    }
}