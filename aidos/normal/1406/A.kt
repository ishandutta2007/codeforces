

fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }
    var cnt = IntArray(120)
    for (x in a) {
        cnt[x]++
    }
    var ans = 0
    for (i in 0 until 2) {
        var c = 0
        while (cnt[c] > 0) {
            cnt[c]--
            c++
        }
        ans += c
    }
    println(ans)

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}