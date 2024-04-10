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
    //val s = TreeSet<Long>()
    //var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })
    for (ii in 0 until tt) 
    {
        val N = 200005
        val aa = readInts()
        val n = aa[0]
        val m = aa[1]
        
        val bb = readLongs()
        var a = LongArray(n + 5)
        for (i in 0 until n)
            a[i + 1] = bb[i]
        
        var g = Array<MutableList<Int>>(n + 5, { i -> mutableListOf() })
        var gd = Array<MutableList<Long>>(n + 5, { i -> mutableListOf() })
        for (i in 0 until m)
        {
            val aa = readStrings()
            val x = aa[0].toInt()
            val y = aa[1].toInt()
            var z = aa[2].toLong()
            g[x].add(y)
            g[y].add(x)
            gd[x].add(z)
            gd[y].add(z)
        }
        
        val s1 = TreeSet<Long>()
        val s2 = TreeSet<Long>()
        
        s1.add(0L * N + 1)
        for (i in 1 until n + 1)
        {
            s2.add(a[i] * N + i);
        }
        
        var c = BooleanArray(n + 5)
        for (i in 1 until n + 1)
            c[i] = false
        var minu = 1000000009003003L
        var ans = 0L
                   
        while (true)
        {
            if (s2.size == 0)
                break
            var t = 0L
            var tx = 0
            do
            {
                if (s1.size == 0)
                {
                    t = -1L
                    break
                }
                t = s1.first()
                var txx = t % N
                tx = txx.toInt()
                s1.remove(t)
            } while (c[tx] == true)
            if (t == -1L || t / N > s2.first() / N + minu)
            {
                if (t != -1L)
                    s1.add(t)
                ans += (s2.first() / N + minu)
                var xx = s2.first() % N
                var x = xx.toInt()
                s2.remove(s2.first())
                minu = minOf(minu, a[x])
                for (i in 0 until g[x].size)
                    s1.add(gd[x][i] * N + g[x][i])
                c[x] = true
            }
            else
            {
                ans += (t / N)
                var xx = t % N
                var x = xx.toInt()
                s2.remove(a[x] * N + x)
                minu = minOf(minu, a[x])
                for (i in 0 until g[x].size)
                    s1.add(gd[x][i] * N + g[x][i])
                c[x] = true
            }
        }
                   
         println(ans)
    }
}