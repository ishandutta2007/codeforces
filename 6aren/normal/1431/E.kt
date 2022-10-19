import java.io.*
import java.util.*

var a = IntArray(3005)
var ans = IntArray(3005)
var b = IntArray(3005)
var check = BooleanArray(3005)
var p = IntArray(3005)

fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    var nTest = `in`.nextInt()
    while (nTest > 0) {
        nTest--
        val n = `in`.nextInt()
        for (i in 1..n) {
            a[i] = `in`.nextInt()
        }
        for (i in 1..n) {
            b[i] = `in`.nextInt()
        }
        var mx = 0
        var id = -1
        for (i in 0..n) {
            var tmp = 10000000
            for (j in 1..i) {
                tmp = Math.min(tmp, Math.abs(a[j] - b[n - i + j]))
            }
            for (j in 1..n - i) {
                tmp = Math.min(tmp, Math.abs(b[j] - a[i + j]))
            }
            //                System.out.println(tmp);
            if (tmp > mx) {
                mx = tmp
                id = i
            }
        }
        for (i in 1..id) {
            val foo = n - id + i;
            print("$foo ")
        }
        for (i in 1..n - id) {
            print("$i ")
        }
        println()
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