fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        var (n, k) = readLine()!!.split(' ').map({ it.toInt() })
        var ans = 0
        for (j in 0 until n) {
            var (l, r) = readLine()!!.split(' ').map({ it.toInt() });
            if (l <= k && r - k + 1 > ans) {
                ans = r - k + 1
            }
        }
        println(ans)
    }
}