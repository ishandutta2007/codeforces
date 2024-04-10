import java.util.*
import kotlin.math.min
import kotlin.math.max
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
        var ans = 0
        while (n --> 0) {
            var (l, r) = readInts()
            if (l <= k) ans = max(ans, r - k + 1)
        }
        println(ans)
    }
}