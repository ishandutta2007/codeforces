import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var (a, b, c) = readInts()
  var x = min(min(a, b - 1), c - 2)
  println(3 * x + 3)
}