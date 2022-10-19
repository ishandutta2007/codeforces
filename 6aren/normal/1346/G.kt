import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.ArrayList
import java.util.Arrays
import java.util.StringTokenizer


var n: Int = 0
var k: Int = 0
var divs = arrayOfNulls<ArrayList<*>>(1000005) as Array<ArrayList<Int>>
var p = IntArray(100005)
var x = IntArray(100005)

fun solve2(a: ArrayList<Int>): Int {
    val t = a[1] - a[0]
    for (e in divs[t]) {
        var ok = true
        for (v in a) {
            if (v % e != a[0] % e) ok = false
        }
        if (ok) return e
    }
    return -1
}

fun solve(u: Int, v: Int): Boolean {
    val t = x[v] - x[u]
    for (e in divs[t]) {
        val a = ArrayList<Int>()
        for (i in 1..n) {
            if (x[i] % e != x[u] % e) {
                val foo = x[i]
                a.add(foo)
            }
        }
        if (a.size == 0) {
            println("YES")
            print(x[u])
            print(' ')
            println(e)
            print(1)
            print(' ')
            print(p[1])
            return true
        }

        if (a.size == 1) {
            println("YES")
            print(x[u])
            print(' ')
            println(e)
            print(a[0])
            print(' ')
            print(p[1])
            return true
        }

        val tt = solve2(a)
        if (tt != -1) {
            println("YES")
            print(x[u])
            print(' ')
            println(e)
            print(a[0])
            print(' ')
            print(tt)
            return true
        }
    }
    return false
}

fun main(args: Array<String>) {
    val `in` = FastScanner()
    k = `in`.nextInt()
    n = `in`.nextInt()
    for (i in 0..1000004) divs[i] = ArrayList()
    for (i in 1..k) p[i] = `in`.nextInt()
    for (i in 1..n) x[i] = `in`.nextInt()
    for (i in 1..k) {
        if (divs[p[i]].size > 0) continue
        var j = p[i]
        while (j < 1000005) {
            val foo = p[i]
            divs[j].add(foo)
            j += p[i]
        }
    }

    if (n == 2) {
        println("YES")
        print(x[1])
        print(' ')
        println(p[1])
        print(x[2])
        print(' ')
        print(p[1])
        return
    }

    if (solve(1, 2)) return
    if (solve(2, 3)) return
    if (solve(1, 3)) return

    println("NO")

}

class FastScanner {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer("")
    operator fun next(): String {
        while (!st.hasMoreTokens())
            try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }

        return st.nextToken()
    }

    fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    fun readArray(n: Int): IntArray {
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        return a
    }

    fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }
}