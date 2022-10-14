private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var s = readString()
        var n = s.length
        var ans = 0
        var cnt = 0
        var i = 0
        while (i < n) {
            if (s[i] == 'v') {
                cnt++
            } else if (s[i] == 'w') {
                ans++
                ans += cnt / 2
                cnt = 0
            }
            i++
        }
        println(ans + cnt / 2)
    }
}