
fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map {it.toInt()}
    if(a[0] + a[1] > a[n-1]) {
        println(-1)
    } else {
        print("1 2 ")
        println(n)
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}