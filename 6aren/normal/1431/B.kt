import java.io.*
import java.util.*

fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    var nTest = `in`.nextInt()
    while (nTest > 0) {
        nTest--
        val s = `in`.next()!!.toCharArray()
        val n = s.size
        var cur = 0
        var ans = 0
        for (i in 0 until n) {
            if (s[i] == 'v') {
                cur++
            } else {
                ans += 1 + cur / 2
                cur = 0
            }
        }
        ans += cur / 2
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