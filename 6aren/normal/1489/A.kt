import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var n = readInt()
    var a = readInts()
    var to_print = BooleanArray(n)
    var last_appeared = IntArray(1001) {-1}
    for (i in 0 until n) {
        last_appeared[a[i]] = i
    }
    var cnt = 0
    for (i in 0 until 1001) {
        if (last_appeared[i] != -1) {
            to_print[last_appeared[i]] = true
            cnt++
        }
    } 
    println(cnt)
    for (i in 0 until n) {
        if (to_print[i]) print("${a[i]} ")
    }
    println()
}