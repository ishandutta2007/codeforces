import java.io.*
import java.util.*


fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    var nTest = `in`.nextInt()
    while (nTest > 0) {
        nTest--
        val n = `in`.nextInt()
        val a = ArrayList<Int>()
        for (i in 0 until n) {
            a.add(`in`.nextInt())
        }
        var sum = 0
        for (i in 0 until n) {
            sum += a[i]
        }
        var res = sum / n
        if (sum % n != 0) {
            res++
        }
        println(res)
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