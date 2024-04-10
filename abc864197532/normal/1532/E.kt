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
    var a = readLongs()
    var mx = -1
    var smx = -1
    var tot : Long = 0
    for (i in 0..n - 1) {
        if (mx == -1 || a[mx] < a[i]) {
            smx = mx
            mx = i
        } else if (smx == -1 || a[smx] < a[i]) {
            smx = i
        }
        tot += a[i]
    }
    var ans = Vector <Int>()
    for (i in 0..n - 1) {
        var p = mx
        if (p == i) p = smx
        if (tot - a[i] == a[p] * 2) ans.add(i + 1)
    }
    println(ans.size)
    println(ans.joinToString(" "))
}