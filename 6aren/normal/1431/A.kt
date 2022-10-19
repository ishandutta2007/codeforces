import java.io.*
import java.util.*

var a = LongArray(105)

fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    var nTest = `in`.nextInt()
    while (nTest > 0) {
        nTest--
        val n = `in`.nextInt()
        for (i in 1..n) {
            a[i] = `in`.nextLong()
        }
        Arrays.sort(a, 1, n + 1)
        var ans: Long = 0
        for (i in 1..n) {
            ans = Math.max(ans, a[i] * (n - i + 1))
        }
        println(ans)
    }
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