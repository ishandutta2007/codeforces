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
    val tests = scanInt()
    for (test in 0 until tests) {
        val n = scanInt()

        var a = IntArray(n+1)
        var b = IntArray(n+1)
        var r = IntArray(n+1)

        val za = ArrayList<PP>()
        val zb = ArrayList<PP>()

        for (i in 0 until n){
            a[i] = scanInt()
        }
        for (i in 0 until n){
            b[i] = scanInt()
            za.add(PP(a[i],i))
            zb.add(PP(b[i],i))
        }
        za.sortWith(ComparatorOne())
        zb.sortWith(ComparatorOne())

        /*for(i in 0 until n){
            out.println("${za[i].a} ${za[i].b}")
        }
        for(i in 0 until n) {
            out.println("${zb[i].a} ${zb[i].b}")
        }*/

        var res = -1
        var pv = 0

        for (i in 0 until n){
            var m = 99999999
            for(j in 0 until n){
                var t = za[j].a-zb[(i+j)%n].a
                if (t < 0)t = -t
                m = minOf(m, t)
            }
            if(res < m){
                res = m
                pv = i
            }
        }

        for(i in 0 until n){
            r[za[i].b] = zb[(i+pv)%n].b
        }
        for(i in 0 until n){
            out.print(r[i] + 1)
            out.print(" ")
        }
        out.println()
    }
}