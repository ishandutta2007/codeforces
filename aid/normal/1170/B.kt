import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var n = readInt()
  var a = readInts().toIntArray()
  var mx0 = -1
  var mx1 = -1
  var res = 0
  for (x in a) {
    if (x >= mx0) {
      mx1 = mx0
      mx0 = x
    } else if (x >= mx1) {
      mx1 = x
    } else {
      res++
    }
  }
  println(res)
}