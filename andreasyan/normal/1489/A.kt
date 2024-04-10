import java.lang.AssertionError

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
        var aa = readInts()
        var a = IntArray(n + 5)
        for (i in 0 until n)
            a[i + 1] = aa[i]
        
        var c = BooleanArray(1003)
        for (i in 1 until 1000)
            c[i] = false
        
        var m = 0
        var b = IntArray(n + 5)
        for (ri in 1 until n + 1)
        {
            var i = n - ri + 1
            if (c[a[i]])
                continue
            c[a[i]] = true
            b[++m] = a[i]
        }
        
        println(m)
        for (ri in 1 until m + 1)
        {
            var i = m - ri + 1
            print(b[i])
            print(" ")
        }
        print('\n')
    }
}