
fun solve(){
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var t = ""
    for (i in 0 until 4) {
        var tt = t
        for (j in 4 - i downTo 1) {
            tt += s[n - j]
        }
        if (tt == "2020") {
            println("YES")
            return
        }
        t += s[i]
    }
    if(t == "2020") {
        println("YES")
    } else {
        println("NO")
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}