import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var tt = readInt()
    while (tt > 0) {
        tt -= 1

        var (n, k) = readInts()
        var res = 0
        
        while (n > 0) {
            n -= 1
            var (x, y) = readInts()
            if (x <= k) {
                if (y - k + 1 > res) {
                    res = y - k + 1
                }
            }
        }
        println(res)
    }
}