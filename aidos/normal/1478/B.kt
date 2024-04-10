
fun solve(){
    var (_, d) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toInt() }
    var dp = IntArray(1234)
    dp[0] = 1
    for (i in 1 until 123) {
        for (x in 1 until i+1) {
            if(x.toString().contains(d.toString())) {
                if(dp[i - x] > 0) dp[i] = 1
            }
        }
    }
    for(x in a) {
        if(x >= 123) println("YES")
        else if(dp[x] == 0) println("NO")
        else println("YES")
    }
}

fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}