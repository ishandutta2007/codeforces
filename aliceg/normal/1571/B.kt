import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val (a, va) = readInts()
        val (c, vc) = readInts()
        val b = readInt()
        println(min(vc, b - a + va))
    }
}