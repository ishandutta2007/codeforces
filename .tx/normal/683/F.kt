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
        var s = `in`.readLine()
        while (s[0] == ' ') {
            s = s.substring(1)
        }


        s = s.replace(Regex("[ ]+\\,"), ",").replace(Regex("[ ]+[\\.]"), ".")
        s = s.replace(",", ", ")
        s = s.replace(".", ". ")
        s = s.replace(Regex("[ ]+"), " ")
        s = s.toLowerCase()

        while (s.last() == ' ') {
            s = s.substring(0, s.length - 1)
        }

        var start = true

        for (i in 0..s.length - 1) {
            var c = s[i]
            if (start) {
                if (c == ',') {
                    start = false
                } else if (c >= 'a' && c <= 'z') {
                    c = Character.toUpperCase(c)
                    start = false
                }
            }
            print(c)
            if (c == '.') {
                start = true
            }
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