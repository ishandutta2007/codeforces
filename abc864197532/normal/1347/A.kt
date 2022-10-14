import java.util.Scanner
val input = Scanner(System.`in`)

fun main () {
  var t = input.nextInt()
  while (t > 0) {
    var a = input.nextInt()
    var b = input.nextInt()
    println(a + b)
    t--
  }
}