
fun solve(){
    var (l, r) = readLine()!!.split(" ").map{it.toInt()}
    if (2 * l <= r){
        println(l.toString() + " " + (2*l).toString())
    } else {
        println("-1 -1")
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}