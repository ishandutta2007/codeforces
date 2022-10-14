import java.util.Vector
import kotlin.math.min
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, k) = readInts()
        var s = readString()
        var cnt = 0
        var pre = 0
        for (i in 0..n-1) {
            if (s[i] == '(') pre++
            else pre--
            if (pre == 0) cnt++
        }
        println(k + min(cnt, n / 2 - k))
    }
}