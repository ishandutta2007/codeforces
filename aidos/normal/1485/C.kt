
fun solve(){
    var (x, y) = readLine()!!.split(" ").map { it.toLong() }
    var ans = 0L
    for(i in 1 until 100000) {
        var l = i + 1
        var r = x/i - 1
        if(r > y) r = y
        if(l <= r) ans += r - l + 1
    }
    println(ans)
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}