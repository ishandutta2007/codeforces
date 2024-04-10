import java.util.Scanner
val input = Scanner(System.`in`)

fun main () {
  var t = input.nextInt()
  while (t > 0) {
    t--
    var n = input.nextInt()
    var arr = IntArray(n)
    for (i in 0..n - 1)
      arr[i] = input.nextInt()
    var ans1 = 1
    var ans2 = arr[0]
    var ans3 = 0
    var i = 1
    var j = n - 1
    var now = arr[0]
    while (i <= j) {
      var tmp = 0
      ans1++
      while (i <= j && tmp <= now) {
        tmp += arr[j]
        j--
      }
      ans3 += tmp
      now = tmp
      tmp = 0
      if (i > j) break
      ans1++
      while (i <= j && tmp <= now) {
        tmp += arr[i]
        i++
      }
      ans2 += tmp
      now = tmp
      tmp = 0
    }
    println("${ans1} ${ans2} ${ans3}")
  }
}