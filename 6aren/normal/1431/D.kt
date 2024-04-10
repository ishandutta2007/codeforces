import java.io.*
import java.util.*

var a = IntArray(505)
var `val` = IntArray(505)
var id = IntArray(505)

fun main(args: Array<String>) {
    val `in` = FastScanner(System.`in`)
    var nTest = `in`.nextInt()
    while (nTest > 0) {
        nTest--
        val n = `in`.nextInt()
        for (i in 1..n) {
            a[i] = `in`.nextInt()
            a[i] = a[i] * 505 + i
        }
        Arrays.sort(a, 1, n + 1)
        for (i in 1..n) {
            `val`[i] = a[i] / 505
            //                System.out.println(val[i]);
            id[i] = a[i] % 505
        }
        var upper = n
        for (i in 1..n) {
            var nUpper = upper - `val`[i]
            if (i != 1) nUpper++
            upper = if (nUpper <= i) {
                for (j in upper downTo i + 1) {
                    print(id[j].toString() + " ")
                }
                print(id[i])
                break
            } else {
                for (j in upper downTo nUpper + 1) {
                    print(id[j].toString() + " ")
                }
                print(id[i].toString() + " ")
                nUpper
            }
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