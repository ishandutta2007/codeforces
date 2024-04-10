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
    val tests = 1
    for (test in 0 until tests) {
        val n = scanInt()
        val m = scanInt()
        val d = scanInt()

        var a = IntArray(m+1)
        var s = IntArray(m+1)
        var st = IntArray(m+1)
        var ed = IntArray(m+1)
        var res = IntArray(n+1)

        for (i in 1 until m+1) {
            a[i] = scanInt()
            s[i] = s[i-1] + a[i]
        }


        for (i in 1 until m+1) {
            st[i] = minOf(ed[i-1] + d, n - (s[m]-s[i-1]) + 1)
            ed[i] = st[i] + a[i] - 1
            for (j in st[i] until ed[i]+1) {
                res[j] = i
            }
        }
        if (n - ed[m] >= d){
            out.println("NO")
        }
        else{
            out.println("YES")
            for (i in 1 until n+1) {
                out.print(res[i]);
                out.print(" ")
            }
            out.println()
        }
    }
}