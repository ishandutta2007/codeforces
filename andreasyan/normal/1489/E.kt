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
        var q = readInt()
        var u = IntArray(200005)
        var c = CharArray(200005)
        var pl = IntArray(q + 5)
        var pr = IntArray(q + 5)
        var p = IntArray(q + 5)
        pl[0] = 0
        pr[0] = 0
        p[0] = 0
        for (i in 1 until q + 1)
        {
            var aa = readStrings()
            var ty = aa[0]
            var x = aa[1].toInt()
            
            pl[i] = pl[i - 1]
            pr[i] = pr[i - 1]
            p[i] = p[i - 1]
            if (ty[0] == 'L')
                pl[i]++
            else if (ty[0] == 'R')
                pr[i]++
            if (ty[0] != '?')
                p[i]++
            
            if (ty[0] == '?')
            {
                if (c[x] == 'L')
                    println(minOf(pl[i] - pl[u[x]], p[u[x] - 1] + pr[i] - pr[u[x]]))
                else
                    println(minOf(p[u[x] - 1] + pl[i] - pl[u[x]], pr[i] - pr[u[x]]))
            }
            else
            {    
                u[x] = i
                c[x] = ty[0]
            }
        }
    }
}