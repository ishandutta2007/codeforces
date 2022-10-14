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
    var s = readString()
    var n = s.length
    var ans = Array <Int>(n, {it -> 0})
    var pre = Array <Int>(n + 1, {it -> 0})
    for (i in 0..n - 1) {
        pre[i + 1] = pre[i]
        if (s[i] == '1') pre[i + 1]++
    }
    for (k in 1..n) {
        var now = 0
        while (now < n) {
            var l = now
            var r = n + 1
            while (r - l > 1) {
                var mid = (l + r) / 2
                var all = pre[mid] - pre[now]
                if (min(all, mid - now - all) <= k) l = mid
                else r = mid
            }
            now = l
            ans[k - 1]++
        }
    }
    println(ans.joinToString(" "))
}