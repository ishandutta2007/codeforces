import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val n = readInt()
    val a = readInts().mapIndexed() {idx, value -> Pair(value, idx) }.toMutableList()
    a.sortBy { it.first }
    a.reverse()
    var sum = 0
    for (i in a.indices)
        sum += a[i].first * i + 1
    println(sum)
    println(a.map {it.second + 1}.joinToString(" "))
}