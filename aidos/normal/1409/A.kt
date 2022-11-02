import kotlin.math.abs

fun solve(){
    var (a, b) = readLine()!!.split(" ").map {it.toInt()}
    var c = abs(a-b).toInt()
    println((c + 9)/10)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}