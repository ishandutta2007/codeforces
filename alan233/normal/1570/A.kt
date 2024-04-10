fun main() {
  var T = readLine()!!.toInt()
  for (i in 0 until T) {
    var s = readLine()!!.split(' ')
    var a = s[0].toInt()
    var b = s[1].toInt()
    println("${a + b}")
  }
}