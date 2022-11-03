import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun ask(q : List<Int>) : Int {
    println("? " + q.joinToString(" "))
    return readInt()
}

fun main() {
    val q1 = List(100) { (it + 1) }
    val q2 = List(100) { (it + 1) shl 7 }
    val x1 = ask(q1)
    val x2 = ask(q2)
    val x = (x2 and ((1 shl 7) - 1)) + (x1 and (((1 shl 7) - 1) shl 7))
    println("! $x")
}