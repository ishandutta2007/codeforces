import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

val inf = 1000000000 + 5

fun main() {
  var (n, k) = readInts()
  var g = Array<MutableList<Int>>(n) { mutableListOf() }
  var ids = Array<MutableList<Int>>(n) { mutableListOf() }
  var ans = mutableListOf<Int>()
  for (i in 1..(n - 1)) {
    var (v, u) = readInts()
    v--
    u--
    g[v].add(u)
    ids[v].add(i)
    g[u].add(v)
    ids[u].add(i)
    ans.add(i)
  }
  for (s in 0..(n - 1)) {
    var tin = IntArray(n)
    var tout = IntArray(n)
    var path = mutableListOf<Int>()
    var pe = IntArray(n)
    var t = 0

    fun dfs(v : Int, p: Int) {
      tin[v] = t++
      path.add(v)
      for (i in 0..(g[v].size - 1)) {
        var u = g[v][i]
        var id = ids[v][i]
        if (u == p) {
          continue
        }
        pe[u] = id
        dfs(u, v)
      }
      tout[v] = t
    }

    pe[s] = -1
    dfs(s, -1)
    var dp = Array(n + 1) { IntArray(k + 1) { inf } }
    var p = Array(n + 1) { IntArray(k + 1) { -1 } }
    var take = Array(n + 1) { IntArray(k + 1) { 0 } }
    dp[0][0] = 0
    for (i in 0..(n - 1)) {
      var v = path[i]
      for (j in 0..k) {
        var cur = dp[i][j]
        if (cur >= inf) {
          continue
        }
        if (j + 1 <= k) {
          if (cur < dp[i + 1][j + 1]) {
            dp[i + 1][j + 1] = cur
            p[i + 1][j + 1] = i
            take[i + 1][j + 1] = 1
          }
        }
        if (i != 0) {
          if (cur + 1 < dp[tout[v]][j]) {
            dp[tout[v]][j] = cur + 1
            p[tout[v]][j] = i
            take[tout[v]][j] = 0
          }
        }
      }
    }
    var i = n
    var j = k
    var a = mutableListOf<Int>()
    while (i > 0) {
      var ni = p[i][j]
      var t = take[i][j]
      var v = path[ni]
      if (t == 0) {
        a.add(pe[v])
      }
      i = ni
      j -= t
    }
    if (a.size < ans.size) {
      ans = a
    }
  }
  println(ans.size)
  println(ans.joinToString(" "))
}