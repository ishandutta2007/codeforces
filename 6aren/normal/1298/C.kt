import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var n = readInt();
    var s = readLn();
    var cur = 0;
    var ans = 0;
    for (ch in s) {
        if (ch == 'x') cur++;
        else {
            ans += max(0, cur - 2);
            cur = 0;
        }
    }
    ans += max(0, cur - 2);
    print(ans);
}