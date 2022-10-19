import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.Arrays
import java.util.StringTokenizer


var a = IntArray(200005)

fun main(args: Array<String>) {
    val `in` = FastScanner()
    var ntest = `in`.nextInt()
    while (ntest-- > 0) {
        val n = `in`.nextInt()
        val k = `in`.nextInt()
        val x = `in`.nextInt()
        val y = `in`.nextInt()
        var sum: Long = 0
        for (i in 1..n) {
            a[i] = `in`.nextInt()
            sum += a[i].toLong()
        }
        var res = 1e18.toLong()
        Arrays.sort(a, 1, n + 1)
        if (sum <= k.toLong() * n) res = y.toLong()

        var temp: Long = 0
        for (i in n downTo 1) {
            if (a[i] > k) temp += x.toLong()
        }
        res = Math.min(temp, res)
        temp = 0
        for (i in n downTo 1) {
            sum -= a[i].toLong()
            temp += x.toLong()
            if (sum <= k.toLong() * n) {
                temp += y.toLong()
                break
            }
        }
        res = Math.min(temp, res)
        println(res)
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