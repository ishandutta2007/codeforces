import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main(){
  var (n, m, k) = readInts()
  var a = readLongs().toMutableList()
  a.sort()
  var s = LongArray(n + 1)
  s[0] = 0
  for (i in 0..(n - 1)) {
    s[i + 1] = s[i] + a[i]
  }
  var j = 0
  var sum = 0L
  var res = 1000000000000000000L
  for (i in 0..(n - m)) {
    while (j + 1 < n && sum + (a[j + 1] - a[j]) * (j - i + 1) <= k) {
      sum += (a[j + 1] - a[j]) * (j - i + 1)
      j++
    }
    if ((j - i + 1) * 2 >= m) {
      var mid = i + (m - 1) / 2
      var cur = a[mid] * (mid - i) - (s[mid] - s[i])
      cur += (s[i + m] - s[mid]) - a[mid] * (i + m - mid)
      res = min(res, cur)
    } else {
      var x = (a[j] + (k - sum) / (j - i + 1))
      var cur = x * (j + 1 - i) - (s[j + 1] - s[i])
      cur += (s[i + m] - s[j + 1]) - x * (i + m - j - 1)
      res = min(res, cur)
    }
    if (j == i) {
      j++
    } else {
      sum -= a[j] - a[i]
    }
  }
  println(res)
}