fun solve(){
    var n = readLine()!!
    println(n.length)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}