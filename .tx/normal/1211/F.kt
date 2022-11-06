import com.sun.xml.internal.fastinfoset.util.StringArray
import java.io.*
import java.util.*
import kotlin.collections.ArrayList

var stok = StringTokenizer("")
var br = BufferedReader(InputStreamReader(System.`in`))

fun nextToken(): String? {
    while (!stok.hasMoreTokens()) {
        val s = br.readLine() ?: return null
        stok = StringTokenizer(s)
    }
    return stok.nextToken()
}

fun nextInt() = nextToken()!!.toInt()
fun nextDouble() = nextToken()!!.toDouble()
fun nextLong() = nextToken()!!.toLong()

fun main(args: Array<String>) {
    if (args.isNotEmpty()) br = BufferedReader(FileReader("input.txt"))
    PrintWriter(System.out, false).use { it.solve() }
}

fun PrintWriter.solve() {
    val n = nextInt()

    val A = 3e5.toInt() + 31
    val alph = "kotlin"

    fun toId(c: Char): Int {
        for (i in 0 until alph.length) {
            if (alph[i] == c) {
                return i
            }
        }
        return -1
    }

    val g = Array<ArrayList<Int>>(alph.length, { ArrayList() })
    val strs = ArrayList<String>()
    val to = IntArray(n)
    val id = IntArray(n)
    for (i in 0 until n) {
        val s = nextToken()!!
        strs.add(s)
        val f = toId(s.first())
        val t = (toId(s.last()) + 1) % alph.length
        g[f].add(i)
        to[i] = t
        id[i] = i
    }

    val ans = ArrayList<Int>()

    fun dfs(v: Int) {
        while (g[v].isNotEmpty()) {
            val e = g[v].last()
            g[v].removeAt(g[v].size - 1)
            val t = to[e]
            val i = id[e]
            dfs(t)
            ans.add(i)
        }
    }

    dfs(0)

    ans.reverse()
    for (i in ans) {
        print(i + 1)
        print(" ")
    }
}