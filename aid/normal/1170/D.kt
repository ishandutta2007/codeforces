import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var m = readInt()
  var b = readInts().toIntArray()
  var n = 0
  for (x in b) {
    if (x == -1) {
      n++
    }
  }
  var a = Array<MutableList<Int>>(n, { mutableListOf() })
  var nxt = IntArray(n)
  var prv = IntArray(n)
  for (i in 0..(n - 1)) {
    var j = i + 1
    if (j == n) {
      j = 0
    }
    nxt[i] = j
    j = i - 1
    if (j == -1) {
      j = n - 1
    }
    prv[i] = j
  }
  var i = 0
  var j = 0
  while (i < m) {
    if (b[i] != -1) {
      a[j].add(b[i])
      i++
      j = nxt[j]
    } else {
      var pj = prv[j]
      var nj = nxt[j]
      nxt[pj] = nj
      prv[nj] = pj
      j = nj
      i++
    }
  }
  println(n)
  println((0..(n - 1)).joinToString("\n") { a[it].size.toString() + " " + a[it].joinToString(" ")})
}