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
        val K = scanInt()


        var a = IntArray(n+1)

        var bb = 0L
        var ee = 99999999999999999L
        var res = 0L
        for (i in 1 until n+1){
            a[i] = scanInt()
        }

        while (bb <= ee) {
            var mid = (bb + ee) / 2
            var s = 0L
            var used = 0

            val PQ = PriorityQueue<Int>(Collections.reverseOrder())
            for (i in 1 until n+1){
                var x = a[i]
                PQ.add(x)
                s += x
                while(s > mid){
                    s -= PQ.remove()
                    used+=1
                }
                if(PQ.size == K){
                    PQ.clear()
                    s = 0
                }
            }
            if (used<=m){
                res = mid
                ee = mid-1
            }
            else bb= mid+1
        }
        out.println(res)
    }
}