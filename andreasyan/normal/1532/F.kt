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
        var a = mutableListOf<String>()
        for (i in 0 until n * 2 - 2)
        {
            var s = readLn()
            a.add(s)
        }
        
        var ans = CharArray(n * 2 - 2)
        fun stg(x: Int, y: Int): Boolean
        {
            for (i in 1 until n)
            {
                var xx = -1
                var yy = -1
                for (j in 0 until n * 2 - 2)
                {
                    if (a[j].length == i)
                    {
                        if (xx == -1)
                        {
                            xx = j
                        }
                        else
                        {
                            yy = j
                        }
                    }
                }
                
                var f = true
                for (j in 0 until i)
                {
                    if (a[x][j] != a[xx][j])
                    {
                        f = false
                        break
                    }
                    if (a[y][n - 1 - j - 1] != a[yy][i - j - 1])
                    {
                        f = false
                        break
                    }
                }
                if (f)
                {
                    ans[xx] = 'P'
                    ans[yy] = 'S'
                    continue
                }
                
                var zz = xx
                xx = yy
                yy = zz
                                         
                f = true
                for (j in 0 until i)
                {
                    if (a[x][j] != a[xx][j])
                    {
                        f = false
                        break
                    }
                    if (a[y][n - 1 - j - 1] != a[yy][i - j - 1])
                    {
                        f = false
                        break
                    }
                }
                if (f)
                {
                    ans[xx] = 'P'
                    ans[yy] = 'S'
                    continue
                }
                return false
            }
            return true
        }
        
        var x = -1
        var y = -1
        for (i in 0 until n * 2 - 2)
        {
            if (a[i].length == n - 1)
            {
                if (x == -1)
                    x = i
                else
                    y = i
            }
        }
        
        if (stg(x, y))
        {
            println(ans.joinToString(""))
            continue
        }
        if (stg(y, x))
        {
            println(ans.joinToString(""))
            continue
        }
    }
}