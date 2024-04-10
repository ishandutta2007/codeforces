private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts().toIntArray()
    val used = mutableSetOf<Int>()
    for (i in n-1 downTo 0) {
        if (used.contains(a[i])) {
            a[i] = -1
        }
        used.add(a[i])
    }
    var cnt = 0
    for (i in 0..n-1) {
        if (a[i] != -1) {
            cnt = cnt + 1
        }
    }
    println(cnt)
    for (i in 0..n-1) {
        if (a[i] != -1) {
            print(a[i].toString() + " ")
        }
    }
}