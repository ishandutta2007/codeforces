import kotlin.math.max

fun solve(){
    var n = readLine()!!.toInt()
    var s = readLine()!!.split(" ").map {s->s.toInt()}
    var a = IntArray(n)
    var ans = 0
    for (x in s) {
        a[x-1]++;
        ans = max(ans, a[x-1]);
    }
    println(ans);
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}