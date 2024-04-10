import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var (x, y, z) = readInts()
  var (a, b, c) = readInts()
  if (a < x) {
    println("NO")
    return
  }
  a -= x
  b += a
  if (b < y) {
    println("NO")
    return
  }
  b -= y
  c += b
  if (c < z) {
    println("NO")
    return
  }
  println("YES")
}