
import kotlin.math.max

fun solve(){
    var a = readLine()!!.split(" ").map { s -> s.toInt() }
    println(a[0] + a[1] + max(max(a[0] - a[1] - 1, a[1] - a[0] - 1), 0))
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}