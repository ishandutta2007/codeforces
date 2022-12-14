fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val m = readLine()!!.split(" ").map{ it.toLong() + 1 }.toTypedArray()
  val tb = LongArray(n) { i -> m[i].toLong() }
  for(i in 1 until n) tb[i] = Math.max(tb[i], tb[i-1])
  for(i in n-2 downTo 0) tb[i] = Math.max(tb[i], tb[i+1]-1)
  println(tb.mapIndexed{ i, v -> v - m[i] }.sum())
}