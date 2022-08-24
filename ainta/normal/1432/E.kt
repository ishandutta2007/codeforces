import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null

fun main() {
    solve()
    inp.close()
    out.close()
}

fun solve() {
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()
        val m = scanLong()
        val p = scanString()
        var u = IntArray(n)
        var pv = 0
        var tp = m
        for (i in 0 until n) {
            if (p[i] == '0') {
                var z = minOf((i-pv).toLong(), tp)
                u[i-z.toInt()] = 1
                tp -= z
                pv += 1
            }
        }
        for (i in 0 until n){
            out.print(1-u[i])
        }

        out.println()
    }
}