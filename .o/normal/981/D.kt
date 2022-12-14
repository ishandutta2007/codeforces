fun main(args: Array<String>) {
  val (N, K) = readLine()!!.split(" ").map{ it.toInt() }
  val A = ("0 " + readLine()!!).split(" ").map{ it.toLong() }
  val S = run {
    var i = 0
    generateSequence(A[0], { A[++i] + it }).take(N+1).toList()
  }

  var ans = 0L
  for(bit in 60 downTo 0) {
    val cand = ans or (1L shl bit)

    val tb = List(K+1) { BooleanArray(N+1) { false } }
    tb[0][0] = true
    for(k in 1..K) for(i in 1..N) {
      tb[k][i] = (0 until i).any{ j -> (S[i] - S[j]) and cand == cand && tb[k-1][j] }
    }

    if(tb[K][N]) {
      ans = cand
    }
  }

  println(ans)
}