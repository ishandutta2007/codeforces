
fun gcd(c:Long, d:Long): Long {
    var a = c
    var b = d
    while(a > 0 && b > 0) {
        if(a > b) a %= b;
        else b %= a;
    }
    return a + b
}
fun lcm(a:Long, b:Long): Long {
    return a * b/gcd(a, b)
}

fun solve(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map{it.toLong()}.toLongArray()
    a.sort()
    var cur = 1L
    for(x in a) {
        cur = lcm(x, cur)
        if(cur >= 1e13) {
            println(-1)
            return
        }
    }
    if (a[n-1] == cur) {
        cur = a[n-1] * a[0]
    }
    var cnt = 1
    var ans = cur
    for(i in 2 until 1000100) {
        if(cur % i == 0L) {
            var c = 0
            while(cur % i == 0L) {
                c++
                cur /= i
            }
            cnt *= c + 1
        }
    }
    if(cnt == n + 2) {
        println(ans)
    } else {
        println(-1)
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}