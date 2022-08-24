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

class PP(val a: Int,val b: Int){
}

// A comparator to compare first names of Name
class ComparatorOne: Comparator<PP>{
    override fun compare(o1: PP?, o2: PP?): Int {
        if(o1 == null || o2 == null){
            return 0;
        }
        return o1.a.compareTo(o2.a)
    }
}


fun solve() {
    val tests = 1
    for (test in 0 until tests) {
        val n = scanInt()
        val K = scanInt()

        var a = IntArray(n+1)
        var s = IntArray(n+1)
        var D = Array(n+1) {Array(n+1) {0} }

        for (i in 1 until n+1){
            a[i] = scanInt()
        }
        a.sort()

        for (i in 1 until n+1){
            s[i] = s[i-1] + a[i]
        }

        for (i in 1 until n+1){
            for(j in 0 until n+1){
                D[i][j] = maxOf(D[i][j],D[i-1][j])
            }
            for(j in i until n+1){
                if((j-i+1)%2 == 0){
                    var t = (i+j)/2
                    var c = (j-i+1)/2
                    var sum = (s[j]-s[t]) - (s[t]-s[i-1])
                    for(k in 0 until K-c+1) {
                        D[j][k + c] = maxOf(D[j][k + c], D[i - 1][k] + sum)
                    }
                }
            }
        }
        out.println(D[n][K])
    }
}