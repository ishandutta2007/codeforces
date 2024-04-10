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
        
        var q = IntArray(105)
        for (i in 1 until 101)
            q[i] = 0
        
        for (i in 0 until n)
        {
            q[a[i]]++
        }
        
        var z = -1
        var ans = 0
        for (i in 1 until 101)
        {
            if (q[i] % 2 == 1)
            {
                if (z == -1)
                    z = i
                else
                {
                    ans += (i - z)
                    z = -1
                }
            }
        }
        
        println(ans)
    }
}