import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.sql.SQLOutput
import java.util.Arrays
import java.util.StringTokenizer


var dp = IntArray(200005)

fun main(args: Array<String>) {
    val `in` = FastScanner()
    val n = `in`.nextInt()
    val m = `in`.nextInt()
    val k = `in`.nextInt()
    for (i in 1..n) dp[i] = 1e9.toInt()
    dp[k] = 0
    for (i in 1..m) {
        val u = `in`.nextInt()
        val v = `in`.nextInt()
        val temp_u = Math.min(dp[u] + 1, dp[v])
        dp[v] = Math.min(dp[u], dp[v] + 1)
        dp[u] = temp_u
    }
    for (i in 1..n) {
        if (dp[i] == 1e9.toInt())
            print(-1)
        else
            print(dp[i])
        print(' ')
    }
}

class FastScanner {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer("")
    operator fun next(): String {
        while (!st.hasMoreTokens())
            try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }

        return st.nextToken()
    }

    fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    fun readArray(n: Int): IntArray {
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        return a
    }

    fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }
}