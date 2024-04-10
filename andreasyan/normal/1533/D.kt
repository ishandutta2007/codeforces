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
        
        var alp = "abcdefghijklmnopqrstuvwxyz"
        var u = IntArray(300)
        for (i in 0 until 26)
            u[alp[i].toInt()] = i
        
        var z = 0
        var t = IntArray(n * m * 26 + 100)
        var q = IntArray(n * m + 100)
        for (i in 0 until n)
        {
            var s = readLn()
            var pos = 0
            for (j in 0 until m)
            {
                if (t[pos * 26 + u[s[j].toInt()]] == 0)
                    t[pos * 26 + u[s[j].toInt()]] = ++z
                pos = t[pos * 26 + u[s[j].toInt()]]
            }
            q[pos]++
        }
        
        var qq = readInt()
        for (jj in 0 until qq)
        {
            var s = readLn()
            var v = mutableListOf<Int>()
            for (i in 0 until m + 1)
            {
                var pos = 0
                for (j in 0 until m + 1)
                {
                    if (j == i)
                        continue
                    if (t[pos * 26 + u[s[j].toInt()]] == 0)
                        break
                    pos = t[pos * 26 + u[s[j].toInt()]]
                }
                if (q[pos] == 0)
                    continue
                var f = false
                for (j in 0 until v.size)
                {
                    if (v[j] == pos)
                    {
                        f = true
                        break
                    }
                }
                if (f)
                    continue
                v.add(pos)
            }
            println(v.size)
        }
    }
}