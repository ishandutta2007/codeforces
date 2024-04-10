
fun solve(){
    var (n, m) = readLine()!!.split(" ").map { it.toInt() }
    if(n >= m) {
        println("YES")
        return
    }
    var a = readLine()!!.split(" ").map { it.toInt() }
    var dp = IntArray(2 * m)
    for(x in a) {
        var y = x % m
        for(j in m downTo 0) {
            if(dp[j] == 1) {
                dp[j+y] = 1
            }
        }
        for(j in 0 until m) {
            if(dp[j + m] == 1) {
                dp[j] = 1
            }
        }
        dp[y] = 1
    }

    if(dp[0] == 1) println("YES")
    else println("NO")
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}