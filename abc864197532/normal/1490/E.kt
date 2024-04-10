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
        val b = readInts()
        var a = Array<Pair<Int, Int>>(n, {it -> Pair(0, 0)})
        for (i in 0..n-1) {
            a[i] = Pair(b[i], i)
        }
        a.sortBy({it.first})
        var out = 0
        var pre : Long = a[0].first.toLong()
        for (i in 1..n-1) {
            if (pre < a[i].first) out = i
            pre += a[i].first
        }
        var ans = Array<Int>(n - out, {it -> 0})
        for (i in out..n-1) {
            ans[i - out] = a[i].second
        }
        ans.sort()
        println("${n - out}")
        for (i in 0..n-out-1) {
            print("${ans[i] + 1} ")
        }
        println("")
    }
}