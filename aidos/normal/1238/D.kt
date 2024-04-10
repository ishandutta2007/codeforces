

fun calc(s: String, c: Char): Long {
    var cnt = 0
    var ans = 0.toLong()
    for(x in s) {
        if(x == c) {
            ans += cnt
            cnt = 0
        } else {
            cnt++
        }
    }
    return ans
}
fun solve(){
    var n = readLine()!!.toInt()
    var s = readLine()!!
    var ans = n.toLong() * (n.toLong() - 1)/2
    ans -= calc(s, 'A')
    ans -= calc(s, 'B')
    ans -= calc(s.reversed(), 'A')
    ans -= calc(s.reversed(), 'B')
    for(i in 1 until n) {
        if(s[i] != s[i-1]) {
            ans++
        }
    }
    println(ans)
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}