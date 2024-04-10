
fun solve(){
    var n = readLine()!!.toInt()
    if (n > 45) {
        println(-1)
    } else {
        var s = ""
        for(i in 9 downTo  1) {
            if (n >= i) {
                n -= i
                s = i.toString() + s
            }
        }
        println(s)
    }

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}