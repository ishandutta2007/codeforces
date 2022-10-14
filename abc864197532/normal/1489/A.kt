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
    val a = readInts()
    var occ = Array<Int>(1001, {it -> -1})
    var sz = 0
    for (i in 0..n-1) {
        if (occ[a[i]] == -1) sz++
        occ[a[i]] = i
    }
    var ans = Array<Int>(n, {it -> 0});
    println(sz)
    for (i in 1..1000) {
        if (occ[i] != -1) ans[occ[i]] = i
    }
    for (i in 0..n-1) {
        if (ans[i] != 0) print("${ans[i]} ")
    }
}