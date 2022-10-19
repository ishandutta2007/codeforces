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
        var xx = intArrayOf(0, 0, -1, 1)
        var yy = intArrayOf(-1, 1, 0, 0)
        
        var aa = readInts()
        var n = aa[0]
        var m = aa[1]
        val a = Array(n) { IntArray(m) }
        for (i in 0 until n)
        {
            var aa = readInts()
            for (j in 0 until m)
            {
                a[i][j] = aa[j]
            }
        }
        
        val c = Array(n) { BooleanArray(m) }
        var v = mutableListOf<Int>()
        fun dfs(x: Int, y: Int)
        {
            c[x][y] = true
            v.add(a[x][y])
            for (i in 0 until 4)
            {
                var hx = x + xx[i]
                var hy = y + yy[i]
                if (0 <= hx && hx < n && 0 <= hy && hy < m)
                {
                    if (c[hx][hy] == false && a[hx][hy] != 0)
                    {
                        dfs(hx, hy)
                        v.add(a[x][y])
                    }
                }
            }
        }
        
        for (i in 0 until n)
        {
            var f = false
            for (j in 0 until m)
            {
                if (a[i][j] != 0)
                {
                    f = true
                    dfs(i, j)
                    
                    var z = true
                    for (x in 0 until n)
                    {
                        for (y in 0 until m)
                        {
                            if (a[x][y] != 0 && c[x][y] == false)
                            {
                                z = false
                                break
                            }
                        }
                        if (z == false)
                            break
                    }
                    
                    if (z == false)
                    {
                        println("-1")
                        break
                    }
                    
                    /*if (v.size % 2 == 1)
                    {
                        for (k in 0 until 4)
                        {
                            var hx = i + xx[k]
                            var hy = j + yy[k]
                            if (a[hx][hy] != 0)
                            {
                                v.add(a[hx][hy])
                                break
                            }
                        }
                    }*/
                    
                    val k = v.size / 2 + 1
                    val ans = Array(k) { IntArray(k) }
                    
                    var q = 0
                    for (i in 0 until k)
                    {
                        if (i == 0)
                        {
                            for (j in 0 until k - 1)
                            {
                                ans[i][j] = v[q++]
                            }
                        }
                        else
                        {
                            for (j in 0 until k - 1)
                            {
                                ans[i][j] = 0
                            }
                        }
                        ans[i][k - 1] = v[q++]
                    }
                    
                    for (i in 1 until k)
                    {
                        for (j in 1 until k)
                        {
                            ans[i][k - j - 1] = ans[i - 1][k - j];
                        }
                    }
                        
                    print(k)
                    print(" ")
                    println(k)
                    for (i in 0 until k)
                    {
                        for (j in 0 until k)
                        {
                            print(ans[i][j])
                            print(" ")
                        }
                        println()
                    }
                    
                    break
                }
            }
            if (f)
                break
        }
    }
}