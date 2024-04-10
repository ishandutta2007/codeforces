import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.properties.Delegates

class Main : PrintWriter {
    val `in`: BufferedReader
    var stok: StringTokenizer? = null
    var g: Array<MutableList<Int>> by Delegates.notNull()

    fun gcd(a: Int, b: Int): Int {
        if (b == 0) {
            return a
        }
        return gcd(b, a % b)
    }

    fun solve() {
        val s = next()!!.substring(2)
        var a = 0
        var al = 0
        var i = 0
        var b = 0
        while (s[i] != '(') {
            a = a * 10 + (s[i] - '0').toInt()
            b = b * 10 + (s[i] - '0').toInt()
            al++
            i++
        }

        var bl = 0
        i++
        while (s[i] != ')') {
            b = b * 10 + (s[i] - '0').toInt()
            bl++
            i++
        }

        var d = 0
        for (i in 0..bl-1) {
            d = d * 10 + 9
        }

        for (i in 0..al-1) {
            d = d * 10
        }

        val u = (b - a)

        val g = gcd(d, u)

        print(u / g)
        print("/")
        print(d / g)
    }

    constructor() : super(System.out) {
        `in` = BufferedReader(InputStreamReader(System.`in`))
    }

    fun next(): String? {
        while (stok == null || !stok!!.hasMoreTokens()) {
            val s = `in`.readLine() ?: return null
            stok = StringTokenizer(s)
        }
        return stok!!.nextToken()
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

    fun <T> createAdjacencyList(n: Int): Array<MutableList<T>> {
        return Array(n, { ArrayList<T>() })
    }
}


fun main(args: Array<String>) {
    Main().use { it.solve() }
}