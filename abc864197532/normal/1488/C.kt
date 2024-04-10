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
        var (n, x, y) = readInts()
        if (x > y) {
            var tmp = y
            y = x
            x= tmp;
        }
        --x
        --y
        var ans = n + 87
        for (i in 0..n - 2) {
            var l = 0
            var r = 0
            var j = i + 1
            if (i <= x) l = x
            else l = i + min(x, i - x)
            if (y <= j) r = n - y - 1
            else r = n - j - 1 + min(y - j, n - 1 - y)
            ans = min(ans, max(l, r))
        }
        // 0 i x
        // 0 x i
        // y i n
        // i y n
        // x + i
        println(ans)
    }
}