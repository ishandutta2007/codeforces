import kotlin.math.*

fun main() {
    var a1 = readLine()!!.toInt()
    var a2 = readLine()!!.toInt()
    var k1 = readLine()!!.toInt()
    var k2 = readLine()!!.toInt()
    var n = readLine()!!.toInt()
    if (k1 > k2) {
        a1 = a2.also { a2 = a1 }
        k1 = k2.also { k2 = k1 }
    }
    print(max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)))
    print(' ')
    var ans = min(n / k1, a1)
    n -= ans * k1
    ans += n / k2
    print(ans)
}