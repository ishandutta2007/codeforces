
fun solve(){
    var n = readLine()!!.toInt()
    var s = readLine()!!
    for(i in 0 until n) {
        print(s[i + i])
    }
    println()
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}