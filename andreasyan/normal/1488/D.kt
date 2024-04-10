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
        var aa = readLongs()
        var n = aa[0]
        var s = aa[1]
        
        fun stg(sx: Long): Boolean
        {
            var ss = s
            var x = sx
            for (i in 0 until n)
            {
                if (x == 1L)
                {
                    ss -= (n - i)
                    break
                }
                ss -= x
                x = (x / 2) + (x % 2)
                if (ss < 0)
                    return false
            }
            if (ss < 0)
                return false
            return true
        }
        
        var l = 1L
        var r = s
        var ans = 1L
        while (l <= r)
        {
            var m = (l + r) / 2
            if (stg(m))
            {
                ans = m
                l = m + 1
            }
            else
                r = m - 1
        }
        println(ans)
    }
}