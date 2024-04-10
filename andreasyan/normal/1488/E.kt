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
        var n = readInt()
        var aa = readInts()
        var a = IntArray(n + 5)
        for (i in 1 until n + 1)
            a[i] = aa[i - 1]
        
        var t = IntArray(n * 4 + 5)
        for (i in 0 until n * 4 + 5)
            t[i] = 0
        fun ubd(tl: Int, tr: Int, x: Int, y: Int, pos: Int)
        {
            if (tl == tr)
            {
                t[pos] = maxOf(t[pos], y)
                return
            }
            var m = (tl + tr) / 2
            if (x <= m)
                ubd(tl, m, x, y, pos * 2)
            else
                ubd(m + 1, tr, x, y, pos * 2 + 1)
            t[pos] = maxOf(t[pos * 2], t[pos * 2 + 1])
        }
        fun qry(tl: Int, tr: Int, l: Int, r: Int, pos: Int): Int
        {
            if (l > r)
                return 0
            if (tl == l && tr == r)
                return t[pos]
            var m = (tl + tr) / 2
            return maxOf(qry(tl, m, l, minOf(m, r), pos * 2),
                    qry(m + 1, tr, maxOf(m + 1, l), r, pos * 2 + 1))
        }
        
        var l = IntArray(n + 5)
        var r = IntArray(n + 5)
        for (i in 1 until n + 1)
        {
            l[i] = 0
            r[i] = 0
        }
        for (i in 1 until n + 1)
        {
            if (l[a[i]] == 0)
                l[a[i]] = i
            r[a[i]] = i
        }
        var u = IntArray(n + 5)
        for (i in 1 until n + 1)
        {
            u[i] = 0
        }
        for (i in 1 until n + 1)
        {
            if (l[i] != 0)
                u[r[i]] = l[i]
        }
        
        for (i in 1 until n + 1)
        {
            if (u[i] == 0)
            {
                ubd(1, n, i, 1, 1)
                continue
            }
            if (i != u[i])
                ubd(1, n, u[i], qry(1, n, u[i] + 1, i, 1) + 2, 1)
            ubd(1, n, i, 1, 1)
        }
        
        println(t[1])
    }
}