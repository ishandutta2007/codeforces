private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
 
fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, k) = readInts()
        var aa = 1 + k + k * k + k * k * k
        n /= aa
        println("${n} ${n * k} ${n * k * k} ${n * k * k * k}")
    }
}