import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

private fun solve(): String {
  var (x, y) = readInts()
  var a = min(x, y) - 1
  var b = x - a
  var c = y - a
  return intArrayOf(a, b, c).joinToString(" ")
}

fun main(){
  var (n, m) = readInts()
  var a = readInts().toIntArray()
  var s = IntArray(n + 1)
  s[0] = 0
  for (i in 0..(n - 1)) {
    s[i + 1] = s[i] + a[i]
  }
  var q = readInt()
  fun solve() : String {
    var b = readInts().toIntArray()
    var j = 0
    var pr = 0
    for (i in 1..(b.size - 1)) {
      var p = b[i] - 1
      var len = p - pr
      var l = j
      var r = n + 1
      while (l < r - 1) {
        var mid = (l + r) / 2
        if (s[mid] - s[j] <= len) {
          l = mid
        } else {
          r = mid
        }
      }
      pr = p + 1
      j = l
    }
    var len = m - pr
    var need = s[n] - s[j]
    if (need <= len) {
      return "YES"
    }
    return "NO"
  }
  println((1..q).joinToString("\n") { solve() })
}