
import kotlin.math.min

fun find_palindrome(a: String): String {
    var s = a + "#" + a.reversed()
    var n = s.length
    var z = IntArray(n)
    var l = 0; var r = 0;
    for (i in 1 until n) {
        if(i <= r) {
            z[i] = min(z[i-l], r - i);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++
        if(i + z[i] > r) {
            r = i + z[i] - 1;
            l = i
        }
        if(i + z[i] == n) {
            return s.substring(0, z[i])
        }
    }

    return ""
}
fun solve(){
    var s = readLine()!!
    var l = 0; var r = s.length - 1
    while(l + 1 < r - 1 && s[l] == s[r]) {
        l++
        r--
    }
    var st = s.substring(0 until l)
    var en = s.substring(r+1)
    var t = s.substring(l until r + 1)
    var a = find_palindrome(t)
    t = t.reversed()
    var b = find_palindrome(t)
    if(a.length < b.length) {
        a = b
    }
    println(st + a + en)

}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}