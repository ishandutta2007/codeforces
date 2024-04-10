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
        var n = readInt()
        var a = readInts()
        var ans = false
        for (i in 1..n-1) {
            if ((a[i] + a[i - 1]) % 2 == 0) {
                ans = true
            }
        }
        if (ans) println("YES")
        else println("NO")
    }
}