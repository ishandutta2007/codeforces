
fun solve(){
    var n = readLine()!!.toLong()
    while (n % 2 == 0L) {
        n/=2
    }
    if(n == 1L) {
        println("NO")
    } else {
        println("YES")
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}