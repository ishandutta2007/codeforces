private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readInt()
        val a = readInts()
        var c = Array<Int>(3, {it -> -n / 3})
        for (i in 0..n-1) {
            c[a[i] % 3]++
        }
        var ans = 0
        for (t in 0..2) {
            for (i in 0..2) {
                if (c[i] > 0) {
                    ans += c[i]
                    c[(i + 1) % 3] += c[i]
                    c[i] = 0
                }
            }
        }
        println(ans)
    }
}