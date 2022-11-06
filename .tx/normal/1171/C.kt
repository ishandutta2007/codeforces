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
fun next() = nextToken()!!

fun main(args: Array<String>) {
    if (args.isNotEmpty()) br = BufferedReader(FileReader("input.txt"))
    PrintWriter(System.out, false).use { it.solve() }
}

fun PrintWriter.solve() {
    val t = nextInt()
    for (it in 0 until t) {
        var s = next().toCharArray()
        s.sort()
        if (s[0] == s.last()) {
            println(-1)
        } else {
            println(String(s))
        }
    }
}