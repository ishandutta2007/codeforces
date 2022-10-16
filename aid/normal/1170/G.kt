import java.util.*
import java.lang.Math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var (n, m) = readInts()
  var g = Array<MutableList<Int>>(n, { mutableListOf() })
  var ids = Array<MutableList<Int>>(n, { mutableListOf() })
  var del = IntArray(m)
  var deg = IntArray(n)
  for (i in 0..(m - 1)) {
    var (v, u) = readInts()
    v--
    u--
    g[v].add(u)
    ids[v].add(i)
    g[u].add(v)
    ids[u].add(i)
    deg[v]++
    deg[u]++
  }
  for (v in 0..(n - 1)) {
    if (deg[v] % 2 == 1) {
      println("NO")
      return
    }
  }

  var p = mutableListOf<Int>()

  fun dfs(v : Int) {
    while (!g[v].isEmpty()) {
      var u = g[v].last()
      var id = ids[v].last()
      g[v].removeAt(g[v].size - 1)
      ids[v].removeAt(ids[v].size - 1)
      if (del[id] == 1){
        continue
      }
      del[id] = 1
      dfs(u)
      p.add(u)
    }
  }

  var ans = mutableListOf<MutableList<Int>>()

  var used = IntArray(n)
  var curu = 0

  for (s in 0..(n - 1)) {
    if (!g[s].isEmpty()) {
      dfs(s)
      curu++
      var pp = mutableListOf<Int>()
      for (i in 0..(p.size - 1)) {
        var v = p[i]
        if (used[v] != curu) {
          used[v] = curu
          pp.add(v)
          continue
        }
        var cycle = mutableListOf<Int>()
        while (pp.last() != v) {
          cycle.add(pp.last())
          used[pp.last()] = 0
          pp.removeAt(pp.size - 1)
        }
        cycle.add(pp.last())
        used[v] = curu
        ans.add(cycle)
      }
      ans.add(pp)
      p = mutableListOf<Int>()
    }
  }
  for (cycle in ans) {
    cycle.add(cycle[0])
    for (i in 0..(cycle.size - 1)) {
      cycle[i]++
    }
  }
  println("YES")
  println(ans.size)
  println((0..(ans.size - 1)).joinToString("\n") {
    ans[it].size.toString() + " " + ans[it].joinToString(" ")})
}