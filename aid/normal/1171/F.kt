import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun solve() : String {
  var n = readInt()
  var s = Array<Pair<Pair<Int, Int>, Int>>(n, { Pair(Pair(-1, -1), -1) })
  for (i in 0..(n - 1)) {
    var (l, r) = readInts()
    s[i] = Pair(Pair(l, r), i)
  }
  s.sortBy({ x -> x.first.first })
  var ans = IntArray(n, { 0 })
  var mx = s[0].first.second
  var found = false
  for (i in 1..(n - 1)) {
    var seg = s[i].first
    if (mx < seg.first) {
      for (j in i..(n - 1)) {
        var id = s[j].second
        ans[id] = 1
      }
      found = true
      break;
    }
    mx = max(mx, seg.second)
  }
  if (!found) {
    return "-1"
  }
  for (i in 0..(n - 1)) {
    ans[i]++
  }
  return ans.joinToString(separator = " ")
}

fun main(){
  var t = readInt()
  println((1..t).joinToString("\n") { solve() })
}