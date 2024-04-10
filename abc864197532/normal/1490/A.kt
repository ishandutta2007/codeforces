private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readInt()
        val a = readInts()
        var ans = 0
        for (i in 1..n-1) {
            var A = a[i - 1]
            var B = a[i]
            if (A > B) {
                var tmp = A
                A = B
                B = tmp
            }
            while (A * 2 < B) {
                A *= 2;
                ans++
            }
        }
        println(ans)
    }
}