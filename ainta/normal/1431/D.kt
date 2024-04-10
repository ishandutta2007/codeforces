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

        var a = IntArray(n+1)
        var v = IntArray(n+1)

        for (i in 1 until n+1){
            a[i] = scanInt()
        }

        var c = 0
        for (i in 1 until n+1){
            var ck = 0
            for(j in 1 until n+1){
                if(v[j] == 1){
                    continue
                }
                if(c >= a[j]){
                    v[j] = 1
                    ck = 1
                    out.print(j)
                    out.print(" ")
                    break
                }
            }
            if (ck == 0){
                c += 1
                var pv = 0
                for(j in 1 until n+1){
                    if(v[j] == 1){
                        continue
                    }
                    if(a[pv] < a[j]){
                        pv = j
                    }
                }
                out.print(pv)
                out.print(" ")
                v[pv] = 1
            }
            else{
                c = 1
            }
        }
        out.println()
    }
}