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
        var n = aa[0]
        var x = aa[1]
        var y = aa[2]
        
        if (y < x)
        {
            var z = x
            x = y
            y = z
        }
        
        var ans = n * 2
        for (i in x until y)
        {
            ans = minOf(ans, maxOf(i - 1 + minOf(i - x, x - 1), n - i - 1 + minOf(y - i - 1, n - y)))
        }
        println(ans)
        
        /*var c = BooleanArray(n + 5)
        for (i in 1 until n + 1)
            c[i] = false
        var q = n
        c[x] = true
        c[y] = true
        q -= 2
        
        var ans = 0
        var xx = false
        var yy = false
        while (q > 0)
        {
            
            ++ans
            
            if (xx == false && x == 1)
                xx = true
            if (yy == false && y == n)
                yy = true
            
            if (xx == false)
                --x
            else
                ++x
            if (yy == false)
                ++y
            else
                --y
            
            if (c[x] == false)
            {
                c[x] = true
                --q
            }
            if (c[y] == false)
            {
                c[y] = true
                --q
            }
        }
        println(ans)*/
    }
}