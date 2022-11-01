private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, w) = readInts()
    val a = readInts()
    var mn = 0
    var mx = 0
    var cur = 0
    for (i in 0..n-1) {
        cur += a[i]
        mn = minOf(mn, cur)
        mx = maxOf(mx, cur)
    }
    
    print(maxOf(0, (w - mx + mn + 1)))
}