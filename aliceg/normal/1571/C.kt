import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        var l = -1
        var r = 1e6.toInt()
        repeat(n) {
            val (s1, s2, x) = readStrings()
            var cnt = 0
            while (cnt < s1.length && cnt < s2.length &&
                s1[s1.length - cnt - 1] == s2[s2.length - cnt - 1])
                ++cnt
            if (x == "1")
                r = min(r, cnt)
            else
                l = max(l, cnt)
        }
        if (l >= r)
            println(0)
        else {
            println(r - l)
            println((l + 1..r).joinToString(" "))
        }
    }
}