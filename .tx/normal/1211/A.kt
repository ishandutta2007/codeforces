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
    val m = TreeMap<Int, Int>()
    for (i in 0 until n) {
        m[nextInt()] = i
    }
    if (m.size < 3) {
        println("-1 -1 -1")
        return
    }
    var ll = 3
    for (i in m.values) {
        print(i + 1)
        print(" ")
        --ll
        if (ll == 0) {
            break
        }
    }
}