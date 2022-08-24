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
        val n = scanInt()

        var a = LongArray(n+1)

        for (i in 1 until n+1){
            a[i] = scanLong()
        }
        var res = 0L
        for(i in 1 until n+1){
            var s = 0L
            for(j in 1 until n+1){
                if (a[i] <= a[j]){
                    s += a[i]
                }
            }
            res = maxOf(s, res)
        }
        out.println(res)
    }
}