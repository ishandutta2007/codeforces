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
        var k = aa[1]
        var a = readLn()
        
        var f = false
        for (i in 0 until n)
        {
            if (a[i] == '1')
            {
                f = true
                break
            }
        }
        if (f == false)
        {
            println("0")
            continue
        }
        
        var ans = 1
        var c = BooleanArray(n)
        for (i in 0 until n)
            c[i] = false
        var u = 0
        c[u] = true
        for (jj in 0 until 2 * n)
        {
            var f = false
            for (i in 0 until n)
            {
                if (a[i] == '1' && c[i] == false)
                {
                    f = true
                    break
                }
            }
            if (f == false)
                break
            
            ans = ans + 1
            var v = mutableListOf<Int>()
            for (i in 0 until n)
            {
                if (c[(u + i) % n] == false)
                {
                    v.add((u + i) % n)
                }
            }
            
            u = v[((k - 1) % v.size)]
            c[u] = true
        }
        
        println(ans)
    }
}