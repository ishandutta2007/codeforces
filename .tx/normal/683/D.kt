import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.properties.Delegates

class Main : PrintWriter {
    val `in`: BufferedReader
    var stok: StringTokenizer? = null
    var g: Array<MutableList<Int>> by Delegates.notNull()

    fun solve() {
        val q = nextInt()
        mf@
        for (tt in 0..q-1) {
            val nn = nextInt()
            val mm = nextInt()
            val n = Math.min(nn, mm)
            val m = Math.max(nn, mm)
            val p = nextInt()

            var i = 1
            var ok = false
            while (i * i <= p) {
                if (p % i == 0) {
                    val l = i
                    var r = p / i
                    if (l <= n && r <= m) {
                        ok = true
                        break
                    }
                }
                i++
            }
            println(if (ok) "Yes" else "No")
        }

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