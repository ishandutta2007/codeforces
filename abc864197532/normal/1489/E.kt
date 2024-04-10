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
    var q = readInt()
    var p = Array <Int>(200001, {it -> 0})
    var l = 0
    var r = 0
    while (q --> 0) {
        var (c, n) = readStrings()
        var id = n.toInt()
        if (c == "L") {
            p[id] = --l
        } else if (c == "R") {
            p[id] = r++
        } else {
            println(min(r - p[id] - 1, p[id] - l))
        }
    }
}