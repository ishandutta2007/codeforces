private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toLong() }
 
fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readInt()
        var arri = readInts()
        var arr = Array<Long>(n, {it -> 0})
        for (i in 0..n-1) {
            arr[i] = arri[i]
        }
        arr.sort()
        var ans : Long = 0
        for (i in 0..n-1) {
            if (ans < (arr[i].toLong()) * (n - i)) {
                ans = (arr[i].toLong()) * (n - i)
            }
        }
        println(ans)
    }
}