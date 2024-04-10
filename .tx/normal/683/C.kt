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
        val s1 = TreeSet<Int>()
        for (i in 0..n-1) {
            s1.add(nextInt())
        }

        val m = nextInt()
        val s2 = TreeSet<Int>()
        for (i in 0..m-1) {
            s2.add(nextInt())
        }

        val ans = TreeSet<Int>()

        for (i in s1) {
            if (!s2.contains(i)) {
                ans.add(i)
            }
        }

        for (i in s2) {
            if (!s1.contains(i)) {
                ans.add(i)
            }
        }

        print(ans.size);
        for (i in ans) {
            print(" ")
            print(i);
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