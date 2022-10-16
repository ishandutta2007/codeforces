private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(){
  var t = readInt()
  for (i in 1..t) {
    var x = readInt()
    println((x + 6) / 7)
  }
}