import java.util.Scanner
val input = Scanner(System.`in`)

fun main () {
  var t = input.nextInt()
  while (t > 0) {
    var a = input.nextInt()
    var b = input.nextInt()
    var c = input.nextInt()
    var d = input.nextInt()
    if (a > b) {
      var k = a
      a = b
      b = k
    }
    if (c > d) {
      var k = c
      c = d
      d = k
    }
    if (b == d && a + c == b) {
      println("YES")
    } else {
      println("NO")
    }
    t--
  }
}