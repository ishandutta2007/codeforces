
fun solve(){
    var (n, q) = readLine()!!.split(" ").map { it.toInt() }
    var s = readLine()!!
    for(i in 0 until q) {
        var (l, r) = readLine()!!.split(" ").map { it.toInt() }
        var st = 0
        while(s[st] != s[l-1]) st++
        var en = n - 1
        while(s[en] != s[r-1]) en--
        if(st == l - 1 && en == r - 1) {
            println("NO")
        } else {
            println("YES")
        }
    }

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}