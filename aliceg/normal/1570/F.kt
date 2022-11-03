import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val (n, m) = readInts()
    val a = List(n) { readInts() }
    val b = List(n) { MutableList(m) {0} }
    val ans : MutableList<Pair<Int, Int>> = mutableListOf()
    for (i in 0 until n - 1) {
        for (j in 0 until m - 1) {
            if (a[i][j] == 1 && a[i + 1][j] == 1 &&
                    a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                b[i][j] = 1
                b[i + 1][j] = 1
                b[i][j + 1] = 1
                b[i + 1][j + 1] = 1
                ans.add(Pair(i + 1, j + 1))
            }
        }
    }
    if (a == b) {
        println(ans.size)
        println(ans.joinToString("\n") { "${it.first} ${it.second}" })
    }else
        println(-1)
}