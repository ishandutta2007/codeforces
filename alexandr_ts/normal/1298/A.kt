private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val a = readInts().toIntArray()
    a.sort()
    for (x in 0..2) {
        print(a[3] - a[x])
        print(" ")
    }
}