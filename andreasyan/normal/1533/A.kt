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
        var aa = readInts()
        var n = aa[0]
        var k = aa[1]
        var ans = 0
        for (i in 0 until n)
        {
            var aa = readInts()
            var l = aa[0]
            var r = aa[1]
            if (l <= k && k <= r)
            {
                if (r - k + 1 > ans)
                {
                    ans = r - k + 1
                }
            }
        }
        println(ans)
    }
}