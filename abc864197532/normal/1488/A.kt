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
        var (x, y) = readLongs()
        var ans : Long = 0
        while (x <= y) {
            var tmp : Long = x
            while (tmp * 10 <= y) tmp *= 10
            y -= tmp
            ans++
        }
        println(ans + y)
    }
}