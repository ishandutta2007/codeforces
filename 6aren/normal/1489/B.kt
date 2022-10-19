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
        var (n, a, b) = readLongs()
        var res = 0L
        if (2 * a < b) {
            res = a * n
        } else {
            var foo = n / 2;
            res = (n - foo * 2) * a + foo * b
        }
        println(res)
    }
}