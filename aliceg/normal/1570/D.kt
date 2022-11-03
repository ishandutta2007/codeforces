import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var ans = 0
    if (n >= 10)
        ans += 1
    while(n >= 10) {
        ans += (9 - n % 10)
        n /= 10
    }
    ans += 9
    println(ans)
}