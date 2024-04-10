import java.io.PrintWriter
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
        var n = readInt()
        var aa = readInts()
        var a = IntArray(n + 5)
        for (i in 1 until n + 1)
            a[i] = aa[i - 1]
        
        var t = LongArray(n * 4 + 5)
        var laz = IntArray(n * 4 + 5)
        for (i in 0 until n * 4 + 5)
        {
            t[i] = 0
            laz[i] = 0
        }
        fun shi(tl: Int, tr: Int, pos: Int)
        {
            if (laz[pos] == 0)
                return
            var m = (tl + tr) / 2
            t[pos * 2] = (m - tl + 1) * 1L * laz[pos]
            laz[pos * 2] = laz[pos]
            t[pos * 2 + 1] = (tr - m) * 1L * laz[pos]
            laz[pos * 2 + 1] = laz[pos]
            laz[pos] = 0
        }
        fun ubd(tl: Int, tr: Int, l: Int, r: Int, y: Int, pos: Int)
        {
            if (l > r)
                return
            if (tl == l && tr == r)
            {
                t[pos] = (r - l + 1) * 1L * y
                laz[pos] = y
                return
            }
            shi(tl, tr, pos)
            var m = (tl + tr) / 2
            ubd(tl, m, l, minOf(m, r), y, pos * 2)
            ubd(m + 1, tr, maxOf(m + 1, l), r, y, pos * 2 + 1)
            t[pos] = t[pos * 2] + t[pos * 2 + 1]
        }
        fun qry(tl: Int, tr: Int, l: Int, r: Int, pos: Int): Long
        {
            if (l > r)
                return 0
            if (laz[pos] != 0)
                return (laz[pos] * 1L * (r - l + 1))
            if (tl == l && tr == r)
                return t[pos]
            shi(tl, tr, pos)
            var m = (tl + tr) / 2
            return (qry(tl, m, l, minOf(m, r), pos * 2) +
                    qry(m + 1, tr, maxOf(m + 1, l), r, pos * 2 + 1))
        }
        
        var q = readInt()
        var v = Array<MutableList<Int>>(n + 5, { i -> mutableListOf() })
        var vi = Array<MutableList<Int>>(n + 5, { i -> mutableListOf() })
        for (i in 0 until q)
        {
            var aa = readInts()
            var l = aa[0]
            var r = aa[1]
            v[r].add(l)
            vi[r].add(i)
        }
        
        var ans = LongArray(q)
        
        var ss = 0
        var s = IntArray(n + 5)
        for (i in 1 until n + 1)
        {
            while (ss != 0 && a[s[ss - 1]] <= a[i])
                --ss
            if (ss == 0)
                ubd(1, n, 1, i, a[i], 1)
            else
                ubd(1, n, s[ss - 1] + 1, i, a[i], 1)
            s[ss] = i
            ss++
            for (j in 0 until v[i].size)
            {
                ans[vi[i][j]] = qry(1, n, v[i][j], i, 1)
            }
        }
        
        println(ans.joinToString(" "))
    }
}