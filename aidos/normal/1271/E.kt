

fun calc(k: Long, n: Long): Long {
    var ans = 0L
    var cur = 1L
    while(k*cur <= n) {
        if(k * cur + cur - 1 <= n) {
            ans += cur
        } else {
            ans += n - k * cur + 1
        }
        cur *= 2
    }
    return ans
}
fun solve(){
    var (n, k) = readLine()!!.split(" ").map{it.toLong()}
    var L=60
    var cur = 0L
    while(L>=0) {
        cur += 1L shl L
        if(n < cur + k - 1) {
            cur -= 1L shl L
            L--
            continue
        }
        var cnt = calc(cur, n)

        if(cur % 2 == 0L) {
            cnt += calc(cur+1, n)
        }
        if(cnt >= k) {

        } else {
            cur -= 1L shl L
            L--
        }
    }
    println(cur)

}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}