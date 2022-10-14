import kotlin.math.abs
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
        var arra = readInts()
        var arrb = readInts()
        var a = Array<Int>(n, {it -> 0})
        var b = Array<Int>(n, {it -> 0})
        for (i in 0..n-1) {
            a[i] = arra[i]
            b[i] = arrb[i]
        }
        var p = -1
        var cur = -1
        for (i in 0..n-1) {
            var tmp = 100000000
            for (j in 0..n-1) {
                if (tmp > abs(a[j] - b[(i + j) % n])) {
                    tmp = abs(a[j] - b[(i + j) % n])
                }
            }
            if (cur < tmp) {
                p = i
                cur = tmp
            }
        }
        for (i in 0..n-1) {
            print("${(i + p) % n + 1} ")
        }
        println("")
    }
}