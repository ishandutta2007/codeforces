
fun solve(){
    var (a, b) = readLine()!!.split(" ").map {it.toInt()}
    println(a xor b)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}