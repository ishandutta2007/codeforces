fun solve(){
    var (n, m) = readLine()!!.split(" ").map{it.toInt()}
    var a = readLine()!!.split(" ").map{it.toInt()}
    if(a.sum() == m) println("YES")
    else println("NO")
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}