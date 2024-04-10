import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var n = readInt()
  var s = readLn()
  if (n == 1) {
    println("Yes")
    return
  }
  val sigma = 26
  var cnt = IntArray(sigma)
  var ok = false
  for (c in s) {
    cnt[c - 'a']++
    if (cnt[c - 'a'] > 1) {
      ok = true
    }
  }
  if (ok) {
    println("Yes")
  } else {
    println("No")
  }
}