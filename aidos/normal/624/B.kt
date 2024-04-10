
fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    var ans = 0L
    a.sort()
    var cur = a[n-1] + 1
    for (i in n - 1 downTo 0) {
        if (cur <= a[i]) {
            a[i] = cur-1
        }
        if(a[i] < 0) break
        ans += a[i]
        cur = a[i]
    }
    println(ans)

}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}