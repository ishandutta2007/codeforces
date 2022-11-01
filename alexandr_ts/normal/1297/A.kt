private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (i in 0..t-1) {
        var n = readInt()
        if (n <= 999) {
            println(n)
        } else if (n >= 999500) {
            println(((n + 500000) / 1000000).toString() + "M")
        } else {
            println(((n + 500) / 1000).toString() + "K")
        }
    }
}