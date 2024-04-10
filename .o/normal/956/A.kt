fun main(args: Array<String>) {
  val (n, m) = readLine()!!.split(" ").map{ it.toInt() }
  val X = 200
  val grp = IntArray(X+X+1) { it }
  fun go(x: Int): Int {
    if(grp[x] != x) {
      grp[x] = go(grp[x])
    }
    return grp[x]
  }
  val S = Array<String>(n) { readLine()?: return }
  for(i in 0 until n) {
    for(j in (0 until m).filter{ j -> S[i][j] == '#'}) {
      grp[go(i)] = grp[go(j + X)]
    }
  }

  println(if((0 until n).all{ i -> (0 until m).all{ j -> S[i][j] == '#' || go(i) != go(j + X) }}) "Yes" else "No")
}