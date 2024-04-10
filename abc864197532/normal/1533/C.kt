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
        var (n, k) = readInts()
        var s = readString()
        var now = 0
        var ans = 0
        var has = Vector <Int>()
        var like = 0
        for (i in 0..n - 1) {
            has.add(i)
            if (s[i] == '1') like++
        }
        if (like == 0) {
            println(0)
            continue
        }
        while (true) {
            if (s[has[now]] == '1') like--
            ans++
            if (like == 0) break
            var nxt = Vector <Int>()
            for (i in 0..has.size - 1) {
                if (i != now) nxt.add(has[i])
            }
            has = nxt
            if (now == has.size) now = 0
            now += k - 1
            now %= has.size
        }
        println(ans)
    }
}