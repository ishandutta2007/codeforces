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
        val k = scanInt()

        var a = IntArray(n+1)
        var s = IntArray(n+1)
        for (i in 1 until n+1) {
            a[i] = scanInt()
            s[i] = s[i-1] + a[i]
        }
        a.sort()

        var res = 0
        for (i in 1 until n+1){
            for(j in i until n+1){
                var t = (n-j+1)/k
                res = maxOf(res, s[j+t-1] - s[j-1])
            }
        }
        out.println(res)
    }
}