private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val s = readLn()
    var cur = 0
    var ans = 0
    for (i in 0..n-1) {
        if (s[i] == 'x') {
            cur += 1
        } else {
            cur = 0
        }
        if (cur >= 3) {
            ans += 1
        }
    }
    println(ans)
}