import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val (n, m) = readInts()
    val a = List(n) { MutableList(n) {0} }
    val b = MutableList(n) {0}
    val c = MutableList(n) {0}
    val (f1, l1) = readInts().map {it - 1}
    a[f1][l1]++
    b[f1]++
    c[l1]++
    repeat(m - 1) {
        val (f, l) = readInts().map {it - 1}
        a[f][l]++
        b[f]++
        c[l]++
    }
    var ans = 0
    for (x in 0 until n) {
        for (y in 0 until n) {
            if (x == y)
                continue
            ans = if (x == f1 && y == l1)
                max(ans, 1)
            else if (x == f1 || y == l1)
                max(ans, a[x][y] + 1)
            else
                max(ans, b[x] + c[y] - a[x][y] + 1)
        }
    }
    println(ans)
}