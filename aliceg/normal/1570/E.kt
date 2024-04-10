import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val s = readLn()
        var l = -1
        var r = -1
        for (i in s.indices) {
            if (s[i] == '1'){
                if (l == -1)
                    l = i
                r = i
            }
        }
        var cnt = 0
        for (i in l until r) {
            if (s[i] == '0')
                ++cnt
        }
        println(cnt)
    }
}