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
private fun readLn() = readLine()!!
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

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

        var p = scanString()

        var n = p.length

        var d0 = 0
        var d1 = 0

        for (i in 0 until n){
            var t = p[i]
            var t0 = 9999999
            var t1 = 9999999
            if (t=='v'){
                t1 = minOf(t1, d0)
                t0 = minOf(t0, minOf(d0,d1)+1)
            }
            if(t=='w'){
                t0 = minOf(t1, minOf(d0,d1)+1)
            }
            d0 = t0
            d1 = t1
        }
        out.println(minOf(d0,d1))
    }
}