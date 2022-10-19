import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, w) = readInts();
    var a = readInts();
    var l = 0;
    var r = w;
    var cur = 0;
    for (e in a) {
        cur += e;
        l = max(l, -cur);
        r = min(r, w - cur);
    }
    print(max(0, r - l + 1));
}