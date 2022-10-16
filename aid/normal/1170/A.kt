import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun solve(): String {
  var (x, y) = readInts()
  var a = min(x, y) - 1
  var b = x - a
  var c = y - a
  return intArrayOf(a, b, c).joinToString(" ")
}

fun main(){
  var t = readInt()
  println((1..t).joinToString("\n") { solve() })
}