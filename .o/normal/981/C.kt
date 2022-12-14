fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val gph = List(n+1) { mutableListOf<Int>() }
  repeat(n-1) {
    val (x, y) = readLine()!!.split(" ").map{ it.toInt() }
    gph[x].add(y)
    gph[y].add(x)
  }
  val ans = mutableListOf<Int>()
  fun dfs(u: Int, p: Int = -1) {
    for(v in gph[u]) {
      if(v != p) {
        dfs(v, u)
      }
    }
    if(gph[u].size == 1) {
      if(p > 0) ans.add(u)
    }else if(gph[u].size > 2 && p != -1) {
      ans.add(-1)
    }
  }

  val root = (1..n).maxBy{ gph[it].size }!!
  dfs(root)

  if(-1 in ans) {
    println("No")
  }else {
    println("Yes")
    println(ans.size)
    println(ans.map{ "$root $it" }.joinToString("\n"))
  }
}