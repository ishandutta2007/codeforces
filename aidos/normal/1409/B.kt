
import kotlin.math.min

fun solve(){
    var (a, b, x, y, n) = readLine()!!.split(" ").map { it.toLong() }
    if(a - x + b - y <= n) {
        println(x * y)
        return
    }
    var ans = a * b
    if (a-x >= n) ans = min(ans, (a-n) * b)
    else ans = min(ans, x * (b - (n + x - a)))
    if(b-y >= n) ans = min(ans, a * (b-n))
    else ans = min(ans, y * (a - (n + y - b)))
    println(ans)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}