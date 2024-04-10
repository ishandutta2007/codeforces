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
    var b = readInts()
    var q = readInt()
    var Q = readInts()
    a = a.sorted()
    b = b.sorted()
    var pre = Array <Int>(n + 1, {it -> 0})
    var suf = Array <Int>(n + 1, {it -> 0})
    pre[0] = -1000000000
    for (i in 0..n - 1) {
        pre[i + 1] = max(pre[i], b[i] - a[i])
    }
    suf[n] = -1000000000
    for (i in n - 1 downTo 0) {
        suf[i] = max(suf[i + 1], b[i + 1] - a[i])
    }
    var ans = Array <Int>(q, {it -> 0})
    for (i in 0..q - 1) {
        var x = Q[i]
        var l = 0
        var r = n
        while (r - l > 1) {
            var mid = (l + r) / 2
            if (a[mid] < x) l = mid
            else r = mid
        }
        if (x < a[0]) ans[i] = max(suf[0], b[0] - x)
        else ans[i] = max(max(pre[r], suf[r]), b[r] - x)
    }
    /*
    1 3 4 6 10
    2 4 5 8 9 9
     */
    println(ans.joinToString(" "))
}