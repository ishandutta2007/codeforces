private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readLong()
        var ans = 0
        for (i in 1..10000) {
            if (n <= i.toLong() * i * i) break
            var re = n - i.toLong() * i * i
            var l : Long = 1
            var r : Long = 10000
            while (r - l > 1) {
                var mid : Long = (l + r) / 2
                if (mid * mid * mid <= re) l = mid
                else r = mid;
            }
            if (l * l * l == re) {
                ans = 1
                break
            }
        }
        if (ans == 1) {
            println("YES")
        } else {
            println("NO")
        }
    }
}