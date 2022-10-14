import java.util.Scanner
val input = Scanner(System.`in`)

fun main () {
  var t = input.nextInt()
  while (t > 0) {
    var n = input.nextInt()
    var length = 0
    var now = 1
    var ans = IntArray(7)
    while (n > 0) {
      if (n % 10 != 0) {
        ans[length] = now * (n % 10)
        length++
      }
      n /= 10
      now *= 10
    }
    println(length)
    for (i in 0..length - 1) {
      print("${ans[i]} ")
    }
    println()
    t--
  }
}