import java.util.Vector
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
        var (n, s) = readLongs()
        var l = 0L
        var r = s + 1
        while (r - l > 1) {
            var m = (l + r) / 2
            var sum = m
            var tmp = m
            var cnt = 1
            while (tmp > 1 && cnt < n) {
                cnt++
                var a = (tmp + 1) / 2
                sum += a
                tmp = a
            }
            if (sum + n - cnt > s) r = m
            else l = m
        }
        println(l)
    }
}