private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
 
fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, k1, k2) = readInts()
        var arr = readLn()
        var ans = 0
        var tmp = 2 * k1
        if (tmp > k2)
            tmp = k2;
        var arra = Array<Int>(n, {it -> 0})
        for (i in 0..n-1)
            if (arr[i] == '1')
                arra[i] = 1
        for (i in 1..n-1) {
            if (arra[i] == 1 && arra[i - 1] == 1) {
                ans += tmp
                arra[i] = 0
                arra[i - 1] = 0
            }
        }
        for (i in 0..n-1) {
            if (arra[i] == 1)
                ans += k1
        }
        println(ans)
    }
}