

fun solve(){
    readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { s->s.toLong() }
    var ans = 0L;
    for (x in a) {
        var cur = 0L;
        for(y in a) {
            if(x <= y) cur += x;
        }
        if(ans<cur) ans = cur;
    }
    println(ans);
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}