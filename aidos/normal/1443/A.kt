fun solve(){
    var n = readLine()!!.toInt()
    for (i in 0 until n) {
        print(4 * n - 2 * i)
        print(" ")
    }
    println()
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}