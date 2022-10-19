import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.Arrays
import java.util.StringTokenizer


var res = IntArray(5005)

fun main(args: Array<String>) {
    val `in` = FastScanner()
    var ntest = `in`.nextInt()
    while (ntest-- > 0) {
        val n = `in`.nextInt()
        val k1 = `in`.nextInt()
        val k2 = `in`.nextInt()
        val s = `in`.next()
        for (i in 0..n + 1) res[i] = 0
        for (i in 1..n) {
            if (s[i - 1] == '0') continue
            res[i] = Math.min(k1, k2 - res[i - 1])
        }
        var ans: Long = 0
        for (i in 1..n) ans += res[i].toLong()
        println(ans)
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