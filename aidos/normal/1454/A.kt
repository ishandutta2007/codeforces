
fun solve(){
    var n = readLine()!!.toInt()
    for(x in 0 until n) {
        print((x+1) % n+1)
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