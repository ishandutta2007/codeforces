
import kotlin.math.max

fun solve(){
    var n = readLine()!!.toInt()
    var s = readLine()!!.split(" ").map {s->s.toInt()}
    var ans = 0
    for (x in s) {
        ans += x;
    }
    if(ans % 2 == 0 && (n * 2 != ans || n % 2 == 0))
        println("YES");
    else
        println("NO");
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}