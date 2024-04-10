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
    var s = Array<String>(n, {it -> ""})
    for (i in 0..n-1) {
        s[i] = readString()
    }
    s.sortBy{it.length}
    var ok = true
    for (i in 1..n-1) {
        var d = s[i].length - s[i - 1].length
        var okk = false
        for (j in 0..d) {
            if (s[i].substring(j, j + s[i - 1].length) == s[i - 1]) {
                okk = true
            }
        }
        if (!okk) ok = false
    }
    if (ok) {
        println("YES")
        for (i in 0..n-1) {
            println(s[i])
        }
    } else {
        println("NO")
    }
}