import java.io.*
import java.util.*
import java.lang.Math.*
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
    var k = nextInt()
    var ans = 0L
    val m = TreeMap<Int, ArrayList<Int>>()
    for (i in 0 until n) {
        val a = nextInt()
        val b = nextInt()
        val c = nextInt()
        ans += a.toLong() * c
        k -= a
        if (k < 0) {
            println(-1)
            return
        }
        if (!m.containsKey(c)) {
            m[c] = ArrayList()
        }
        m[c]!!.add(b - a)
    }

    for (i in m.entries) {
        for (j in i.value) {
            val t = min(k, j)
            k -= t
            ans += i.key.toLong() * t
        }
    }

    if (k != 0) {
        println(-1)
        return
    }

    println(ans)
}