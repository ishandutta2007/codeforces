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
        var a = Array<String>(n){""}
        for (i in 0 until n)
            a[i] = readLn()
        a.sortWith(Comparator { s1: String, s2: String -> s1.length - s2.length })
        
        /*for (i in 0 until n)
            println(a[i])
        continue*/
        
        var zzz = true
        for (i in 0 until n - 1)
        {
            var zz = false
            for (l in 0 until a[i + 1].length - a[i].length + 1)
            {
                var r = l + a[i].length - 1
                var z = true
                for (j in l until r + 1)
                {
                    if (a[i + 1][j] != a[i][j - l])
                    {
                        z = false
                        break
                    }
                }
                if (z)
                {
                    zz = true
                    break
                }
            }
            if (!zz)
            {
                zzz = false
                break
            }
        }
        if (!zzz)
        {
            println("NO")
        }
        else
        {
            println("YES")
            for (i in 0 until n)
                println(a[i])
        }
    }
}