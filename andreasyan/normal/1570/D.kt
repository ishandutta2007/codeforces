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
        fun f(x_: Int): Int
        {
            var x = x_
            ++x
            while (x % 10 == 0)
            {
                x /= 10
            }
            return x
        }
        var n = readInt()
        
        val s = TreeSet<Int>()
        while (!s.contains(n))
        {
            s.add(n)
            n = f(n)
        }
        
        println(s.size)
    }
}