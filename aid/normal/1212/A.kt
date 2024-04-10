import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
  var (n, k) = readInts()
  for (i in 1..k) {
    if (n % 10 == 0) {
      n /= 10
    } else {
      n--
    }
  }
  println(n)
}