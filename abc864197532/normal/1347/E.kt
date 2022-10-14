import java.util.Scanner
val input = Scanner(System.`in`)

fun main () {
  var t = input.nextInt()
  while (t > 0) {
    t--
    var n = input.nextInt()
    if (n < 4) {
      println(-1)
      continue
    }
    var k = n - (1 - n % 2)
    for (i in k downTo 1 step 2)
      print("${i} ")
    print("4 2 ")
    for (i in 6..n step 2)
      print("${i} ")
    println()
  }
}