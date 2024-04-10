

fun solve(){
    var s = readLine()!!
    var t = "heidi"
    var i = 0
    for (x in s) {
        if (t[i] == x) {
            i++
        }
        if(i == t.length) {
            println("YES")
            return
        }
    }
    println("NO")
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}