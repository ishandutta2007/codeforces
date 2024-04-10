import java.util.Vector
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
        var n = readInt()
        val a = readInts().sorted()
        var cnt = Vector<Int>()
        var ans = 0
        var l = 0
        var r = 0
        while (r < n) {
            l = r;
            while (r < n && a[l] == a[r]) r++
            cnt.add(r - l)
        }
        cnt.sort()
        for (i in 0..cnt.size-1) {
            if (ans < cnt[i] * (cnt.size - i)) {
                ans = cnt[i] * (cnt.size - i)
            }
        }
        println("${n - ans}")
    }
}