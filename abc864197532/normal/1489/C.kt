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
    var n = readInt()
    var s = readString()
    var ans = 0
    var cnt = 0
    for (i in 0..n-1) {
        if (s[i] == 'x') cnt++
        else cnt = 0
        if (cnt == 3) {
            ans++
            cnt--
        }
    }
    println(ans)
}