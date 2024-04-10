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
        val m = scanInt()
        val K = scanLong()

        var A = LongArray(n+1)
        var B = LongArray(m+1)
        var C = LongArray(n+m)

        var w = Array(n+1) {Array(m+1) {0L} }

        for (i in 1 until n+1){
            A[i] = scanLong()
            C[i-1] = A[i]
        }
        for (i in 1 until m+1){
            B[i] = scanLong()
            C[i+n-1] = B[i]
        }
        C.sort()
        for (i in 1 until n+1){
            for (j in 1 until m+1){
                w[i][j] = scanLong()
                w[i][j] = maxOf(maxOf(w[i-1][j],w[i][j-1]),maxOf(w[i-1][j-1],w[i][j]))
            }
        }

        var Ans = 999999999999999999L
        for (i in 0 until n+m){
            var px = 0
            var py = 0
            for (j in 1 until n+1){
                if(A[j] <= C[i])px = j
            }
            for (j in 1 until m+1){
                if(B[j] <= C[i])py = j
            }
            var sx = 0
            var sy = 0

            for (j in 1 until n+1){
                if(A[j] <= 0)sx = j
            }
            for (j in 1 until m+1){
                if(B[j] <= 0)sy = j
            }
            var sum = 0L
            var cc = 0L
            while(sx < n || sy < m){
                if(sx<n && sum>=A[sx+1]){
                    sx+=1
                    continue
                }
                if(sy<m && sum>=B[sy+1]){
                    sy+=1
                    continue
                }
                var tp = w[sx][sy]
                if(sx >= px && sy >= py){
                    tp = maxOf(tp, w[px][py]+K)
                }
                var nxt = 999999999999999999L
                if(sx<n)nxt = minOf(nxt, A[sx+1])
                if(sy<m)nxt = minOf(nxt, B[sy+1])
                var ct = (nxt - sum + tp - 1) / tp
                cc += ct
                sum += ct * tp
            }
            Ans = minOf(Ans,cc)
        }
        out.println(Ans)

    }
}