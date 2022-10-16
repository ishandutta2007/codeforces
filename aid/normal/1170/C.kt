import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

private fun solve(): String {
  var s = readLn()
  var t = readLn()
  var i = 0
  var j = 0
  while (i < t.length) {
    if (j >= s.length) {
      return "NO"
    }
    if (t[i] == s[j]) {
      i++
      j++
      continue
    }
    if (t[i] == '-') {
      return "NO"
    }
    if (s[j] == '+' || j + 1 >= s.length || s[j + 1] == '+') {
      return "NO"
    }
    i++
    j += 2
  }
  if (j < s.length) {
    return "NO"
  }
  return "YES"
}

fun main(){
  var t = readInt()
  println((1..t).joinToString("\n") { solve() })
}