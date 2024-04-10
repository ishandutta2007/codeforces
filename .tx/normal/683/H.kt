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
        val n = nextInt()
        val k = nextLong()
        val a = IntArray(n)
        for (i in 0..n-1) {
            a[nextInt() - 1] = i
        }

        var ci = 0
        val cn = IntArray(n, {-1})
        val cp = IntArray(n)
        val cc = ArrayList<ArrayList<Int>>()
        for (i in 0..n-1) {
            if (cn[i] != -1) {
                continue
            }
            val c = ArrayList<Int>()
            var x = i
            do {
                cn[x] = ci
                cp[x] = c.size
                c.add(x)
                x = a[x]
            } while (x != i)
            cc.add(c)
            ci++
        }

        for (i in 0..n-1) {
            val c = cc[cn[i]]
            val x = (   (cp[i] + k) % c.size).toInt()
            print(c[x] + 1)
            print(" ")
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