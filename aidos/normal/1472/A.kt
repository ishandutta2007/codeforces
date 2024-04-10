
fun solve(){
    var (w, h, n) = readLine()!!.split(" ").map{it.toInt()}
    var W = w
    var H = h
    while(W % 2 == 0) {
        W/=2;
    }
    while(H % 2 == 0) {
        H/=2;
    }
    if((w/W) * (h/H) >= n) println("YES")
    else println("NO")
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}