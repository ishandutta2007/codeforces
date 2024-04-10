

fun main() {
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var ans = 0
    var cur = 0
    for (i in 0 until n) {
        if (s[i] == 'x') {
            cur++
        } else {
            if (cur >= 3) {
                ans += cur - 2
            }
            cur = 0
        }
    }
    if (cur >= 3) {
        ans += cur - 2
    }
    print(ans)
}