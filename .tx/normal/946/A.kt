import java.io.*
import java.util.*
import java.lang.Math.*

fun PrintWriter.solve() {
    val n = nextInt()
    println((1..n).map { abs(nextInt()) }.sum())
}

fun main(args: Array<String>) {
    PrintWriter(System.out, false).use { it.solve() }
}

val br = BufferedReader(InputStreamReader(System.`in`))
var stok = StringTokenizer("")

fun nextToken(): String? {
    while (!stok.hasMoreTokens()) {
        val s = br.readLine() ?: return null
        stok = StringTokenizer(s)
    }
    return stok.nextToken()
}

fun nextInt(): Int {
    return nextToken()!!.toInt()
}

fun nextLong(): Long {
    return nextToken()!!.toLong()
}

fun nextDouble(): Double {
    return nextToken()!!.toDouble()
}