private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
 
fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, k, x, y) = readInts()
        var arri = readInts()
        var ans = 0
        var arr = Array<Int>(n, {it -> 0})
        var all : Long = 0
        for (i in 0..n-1) {
            arr[i] = arri[i]
            all += arr[i]
            if (arr[i] > k)
                ans++;
        }
        arr.sort()
        ans *= x;
        var tmp = 0
        for (i in n-1 downTo 0) {
            if (all <= (k.toLong()) * n) {
                tmp = (n - i - 1) * x + y
                break
            }
            all -= arr[i]
        }
        if (ans > tmp)
            ans = tmp
        println(ans)
    }
}