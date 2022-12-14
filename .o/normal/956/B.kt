fun main(args:Array<String>) {
  val (n, U) = readLine()!!.split(" ").map{ it.toInt() }
  val E = readLine()!!.split(" ").map{ it.toInt() }
  var j = 0
  var ans = -1.toDouble()
  for(i in 0 until n) {
    while(j < n && E[j] - E[i] <= U) {
      j += 1
    }
    j -= 1
    if(i + 1 < j) {
      ans = Math.max(ans, (E[j] - E[i+1]).toDouble() / (E[j] - E[i]).toDouble())
    }
    j += 1
  }
  println(ans)
}