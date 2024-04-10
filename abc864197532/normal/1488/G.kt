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
    var ans = Array<Int>(n, {it -> 0})
    var p = Array<Int> (n, {it -> 0})
    var f = Array<Int> (n + 1, {it -> 1})
    for (i in 1..n) {
        p[i - 1] = i
        var j = 2
        var tmp = i
        while (j * j <= tmp) {
            if (tmp % j == 0) {
                var cnt = 0
                while (tmp % j == 0) {
                    tmp /= j
                    cnt++
                }
                f[i] *= (cnt + 1)
            }
            j++
        }
        if (tmp > 1) f[i] *= 2
    }
    p.sortByDescending{n / it - f[it]}
    var curans = 0
    var vis = Array<Boolean>(n + 1, {it -> false})
    for (i in 0..n-2) {
        curans += n / p[i] - f[p[i]]
        ans[n - 2 - i] = curans
    }
    println(ans.joinToString(" "))
}