import java.util.PriorityQueue
import kotlin.math.max
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var (n, k) = readInts()
    var arr = readInts()
    var a = Array<Int>(n, {it -> 0})
    for (i in 0..n - 1) {
        a[i] = arr[i]
    }
    a.sort()
    var pre = Array<Array<Int>> (n + 1, {it -> Array<Int>(n + 1, {it -> 0})})
    var d = 2;
    while (d <= n) {
        var i = 0;
        while (i + d <= n) {
            pre[i][i + d] = pre[i + 1][i + d - 1] + a[i + d - 1] - a[i]
            //println("${i} ${i + d} ${pre[i][i + d]}")
            ++i
        }
        d += 2
    }
    // 1 100 101 108 109 200 201
    var dp = Array<Array<Int>> (n + 1, {it -> Array<Int>(k + 1, {it -> 0})})
    for (i in 1..n) {
        for (j in 1..k) {
            dp[i][j] = dp[i - 1][j]
            if (i < j * 2) continue
            for (ii in 0..j) {
                dp[i][j] = max(dp[i][j], dp[i - ii * 2][j - ii] + pre[i - ii * 2][i])
            }
            //println("${i} ${j} ${dp[i][j]}")
        }
    }
    println(dp[n][k])
}