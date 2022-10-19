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
        var k = aa[2]
        var a = readInts()
        
        fun stg(x: Int): Boolean
        {
            var mm = m - 1
            var kk = k
            for (i in x until n)
            {
                if (kk >= a[i])
                {
                    kk -= a[i]
                }
                else
                {
                    --mm;
                    kk = k - a[i]
                }
            }
            return mm >= 0
        }
        
        var l = 0
        var r = n
        var ans = n
        while (l <= r)
        {
            var m = (l + r) / 2
            if (stg(m))
            {
                ans = m
                r = m - 1
            }
            else
                l = m + 1
        }
        println(n - ans)
    }
}