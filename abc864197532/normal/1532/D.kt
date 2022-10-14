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
    var n = readInt()
    var a = readInts()
    a = a.sorted()
    var ans = 0
    for (i in 0..n / 2 - 1) {
        ans += a[i * 2 + 1] - a[i * 2]
    }
    println(ans)
}