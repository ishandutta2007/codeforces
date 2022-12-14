fun main(args: Array<String>) {
  val N = readLine()!!.toInt()
  val A = readLine()!!
  val B = readLine()!!
  val cnt = List(2) { LongArray(2) }
  for(i in 0 until N) {
    cnt[A[i].toInt() - 48][B[i].toInt() - 48] = cnt[A[i].toInt() - 48][B[i].toInt() - 48] + 1
  }
  println(cnt[0][0] * (cnt[1][0] + cnt[1][1]) + cnt[1][0] * cnt[0][1])
}