import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var t = readInt()
  for (tt in 1..t) {
    var s = readLn()
    var n = s.length
    var pos = -1
    for (i in 1..(n - 1)) {
      if (s[i] != s[0]) {
        pos = i
        break
      }
    }
    if (pos == -1) {
      println(-1)
      continue
    }
    var ss = s.toCharArray()
    var tmp = ss[n - 1]
    ss[n - 1] = ss[pos]
    ss[pos] = tmp
    s = String(ss);
    println(s)
  }
}