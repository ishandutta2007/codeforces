fun main(args: Array<String>) {
 val n = readLine()!!.toInt()
 val a = readLine()!!.split(" ").map{ it.toInt() - 100 }
 var ans = 0
 for(i in 0 until n) {
  var sum = 0
  for(j in i until n) {
   sum += a[j]
   if(sum > 0) ans = maxOf(ans, j-i+1)
  }
 }
 println(ans)
}