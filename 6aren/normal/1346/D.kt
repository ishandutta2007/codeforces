import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.Arrays
import java.util.StringTokenizer



var res = IntArray(200005)
var u = IntArray(200005)
var v = IntArray(200005)
var w = IntArray(200005)

fun main(args: Array<String>) {
    val `in` = FastScanner()
    var ntest = `in`.nextInt()
    while (ntest-- > 0) {
        val n = `in`.nextInt()
        val m = `in`.nextInt()
        for (i in 1..n) res[i] = 0
        for (i in 0 until m) {
            u[i] = `in`.nextInt()
            v[i] = `in`.nextInt()
            w[i] = `in`.nextInt()
            res[u[i]] = Math.max(res[u[i]], w[i])
            res[v[i]] = Math.max(res[v[i]], w[i])
        }
        var ok = true
        for (i in 0 until m) {
            if (Math.min(res[u[i]], res[v[i]]) != w[i]) ok = false
        }
        if (!ok)
            println("NO")
        else {
            println("YES")
            for (i in 1..n) {
                print(res[i])
                print(' ')
            }
            println()
        }
    }
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