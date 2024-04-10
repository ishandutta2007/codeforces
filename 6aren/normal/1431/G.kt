import java.io.*
import java.util.*

var dp = Array(405) { Array(205) { IntArray(205) } }
var a = IntArray(405)

fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    val n = `in`.nextInt()
    val m = `in`.nextInt()
    for (i in 1..n) {
        a[i] = `in`.nextInt()
    }
    Arrays.sort(a, 1, n + 1)
    for (i in 0..m + 1) {
        for (j in 0..m + 1) {
            dp[0][i][j] = -1000000000
        }
    }
    dp[0][0][0] = 0
    for (i in 1..n) {
        for (j in 0..m) {
            for (k in 0..m) {
                dp[i][j][k] = dp[i - 1][j][k]
                if (j > 0) {
                    dp[i][j][k] = dp[i - 1][j - 1][k] - a[i]
                }
                if (k > 0) {
                    dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j + 1][k - 1] + a[i])
                }
            }
        }
    }
    println(dp[n][0][m])
}

internal class FastScanner {
    var br: BufferedReader? = null
    var st: StringTokenizer? = null

    constructor(f: File?) {
        try {
            br = BufferedReader(FileReader(f))
        } catch (e: FileNotFoundException) {
            e.printStackTrace()
        }
    }

    constructor(f: InputStream?) {
        br = BufferedReader(InputStreamReader(f))
    }

    operator fun next(): String? {
        while (st == null || !st!!.hasMoreTokens()) {
            var s: String? = null
            try {
                s = br!!.readLine()
            } catch (e: IOException) {
                e.printStackTrace()
            }
            if (s == null) return null
            st = StringTokenizer(s)
        }
        return st!!.nextToken()
    }

    fun hasMoreTokens(): Boolean {
        while (st == null || !st!!.hasMoreTokens()) {
            var s: String? = null
            try {
                s = br!!.readLine()
            } catch (e: IOException) {
                e.printStackTrace()
            }
            if (s == null) return false
            st = StringTokenizer(s)
        }
        return true
    }

    fun nextInt(): Int {
        return next()!!.toInt()
    }

    fun nextLong(): Long {
        return next()!!.toLong()
    }

    fun nextDouble(): Double {
        return next()!!.toDouble()
    }
}