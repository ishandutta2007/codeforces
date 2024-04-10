import kotlin.math.max

fun solve(){
    var n = readLine()!!.toInt()
    if(n <= 3) println(n-1)
    else println(2 + n % 2)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}