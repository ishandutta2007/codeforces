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
        var (n, q) = readInts()
        val a = readInts()
        val b = readInts()
        var pre = Array<Pair<Long, Int>>(n, {it -> Pair(0L, 0)})
        var mn = Array<Int>(n, {it -> 0})
        for (i in 0..n-1) {
            if (i > 0) {
                pre[i] = Pair(pre[i - 1].first + a[i], i)
            } else {
                pre[i] = Pair(a[i].toLong(), i);
            }
        }
        var all : Long = pre[n - 1].first
        pre.sortByDescending { it.first }
        for (i in 0..n-1) {
            if (i > 0) {
                mn[i] = min(mn[i - 1], pre[i].second)
            } else {
                mn[i] = pre[i].second
            }
        }
        var ans = Array<Long>(q, {it -> 0L})
        for (i in 0..q-1) {
            var x : Long = b[i].toLong()
            if (x <= pre[0].first) {
                var l = 0
                var r = n
                while (r - l > 1) {
                    var mid = (l + r) / 2
                    if (x <= pre[mid].first) l = mid
                    else r = mid
                }
                ans[i] = mn[l].toLong()
            } else {
                if (all <= 0) {
                    ans[i] = -1
                } else {
                    var round : Long = (x - pre[0].first + all - 1) / all
                    var l = 0
                    var r = n
                    while (r - l > 1) {
                        var mid = (l + r) / 2
                        var roundnow : Long = (x - pre[mid].first + all - 1) / all
                        if (round == roundnow) l = mid
                        else r = mid
                    }
                    ans[i] = round * n + mn[l]
                }
            }
        }
        println(ans.joinToString(" "))
    }
}