import java.io.*
import java.util.*
import java.lang.Math.*

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
    val a = IntArray(n)
    var ans = 0L
    var f = 0
    for (i in 0 until n) {
        a[i] = nextInt()
        f = max(f, a[i] - 1)
    }

    ans = f.toLong() * n
    var mx = 0
    for (i in 0 until n) {
        if (a[i] > f) {
            mx = i
        }
    }
    ans += mx + 1
    println(ans)
}