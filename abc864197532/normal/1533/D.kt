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
    var (n, m) = readInts()
    val set1: MutableSet<String> = mutableSetOf()
    for (tt in 1..n) {
        var s = readString()
        set1.add(s)
    }
    var q = readInt()
    var ans = Array <Int> (q, {it -> 0})
    for (i in 0..q - 1) {
        var s = readString()
        var cnt = 0
        val set2: MutableSet<String> = mutableSetOf()
        for (i in 0..m) {
            var t = ""
            for (j in 0..m) if (i != j) t += s[j]
            if (set1.contains(t)) set2.add(t)
        }
        for ((i, v) in set2.withIndex()) {
            if (set1.contains(v)) cnt++
        }
        ans[i] = cnt
    }
    println(ans.joinToString("\n"))
}