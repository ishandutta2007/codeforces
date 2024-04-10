
fun solve(){
    var (n, k) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map {it.toInt()}
    var ans = 0L
    var c = n * k - 1
    for(i in 0 until k) {
        ans += a[c-n/2]
        c -= n/2 + 1
    }
    println(ans)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}