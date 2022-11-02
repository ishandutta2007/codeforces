
import kotlin.math.max

fun solve(){
    var x = readLine()!!.split(" ").map { s->s.toInt() }
    var n = x[0]
    var m = x[1]
    var a = readLine()!!.split(" ").map{it.toInt()}
    var b = readLine()!!.split(" ").map{it.toInt()}
    for (i in 0 until n) {
        if (a[i] + b[n-i-1] > m) {
            println("NO")
            return
        }
    }
    println("YES")
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
        if (i!=t-1) readLine()
    }
}