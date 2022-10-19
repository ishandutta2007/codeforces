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
        tt--
        var (n, x, y) = readInts()
        if (x > y) {
            var z = x
            x = y
            y = z
        }
        var res = 1000000000
        for (i in x..y-1) {
            var u = i - 1 + minOf(i - x, x - 1)
            var v = n - (i + 1) + minOf(y - i - 1, n - y)
            res = minOf(res, maxOf(u, v))
        }
        println(res)

    }
}