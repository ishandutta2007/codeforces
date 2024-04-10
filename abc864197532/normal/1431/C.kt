private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, k) = readInts()
        var arri = readInts()
        var arr = Array<Int>(n, {it -> 0});
        for (i in 0..n-1) {
            arr[i] = arri[i]
        }
        arr.sort()
        var ans = 0
        for (x in k..n) {
            var tmp = 0
            for (i in n - x..n - x + x / k - 1) {
                tmp += arr[i]
            }
            if (ans < tmp)
                ans = tmp
        }
        println(ans)
    }
}