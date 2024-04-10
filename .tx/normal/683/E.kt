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
        val a = IntArray(n)
        for (i in 0..n-1) {
            a[i] = nextInt()
        }
        val ans = IntArray(n, {-1})
        for (i in 0..n-1) {
            var x = 0
            var sk = 0
            while (true) {
                if (ans[x] != -1) {
                    x++
                    continue
                }
                if (sk == a[i]) {
                    break
                }
                sk++
                x++
            }
            ans[x] = i
        }

        for (i in ans) {
            print(i + 1)
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