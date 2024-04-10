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
        var (n, k) = readInts()
        var s = readLn()
        var cur = 0
        var cnt = 0
        for (i in 0..n-1) {
            if (s[i] == '(') {
                cur++
            } else cur--
            if (cur == 0) cnt++;
        }
        var canDo = (n - 2 * cnt) / 2
        var res = minOf(canDo, k) + cnt
        println(res)
    }
}