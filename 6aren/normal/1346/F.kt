import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.Arrays
import java.util.StringTokenizer


var a = Array(1005) { IntArray(1005) }
var r = LongArray(1005)
var c = LongArray(1005)
var n: Int = 0
var m: Int = 0
var q: Int = 0

fun calcr(k: Int): Long {
        var res: Long = 0
        for (i in 1..n) {
            res += r[i] * Math.abs(i - k)
        }
        return res
    }

fun calcc(k: Int): Long {
        var res: Long = 0
        for (i in 1..m) {
            res += c[i] * Math.abs(i - k)
        }
        return res
    }


fun solve(): Long {
        var resr = 2e18.toLong()
        var l = 1
        var r = n
        while (r - l >= 3) {
            val u = (l + l + r) / 3
            val v = (l + r + r) / 3
            if (calcr(u) > calcr(v))
                l = u + 1
            else
                r = v
        }
        for (i in l..r) resr = Math.min(resr, calcr(i))

        var resc = 2e18.toLong()
        l = 1
        r = m
        while (r - l >= 3) {
            val u = (l + l + r) / 3
            val v = (l + r + r) / 3
            if (calcc(u) > calcc(v))
                l = u + 1
            else
                r = v
        }
        for (i in l..r) resc = Math.min(resc, calcc(i))

        return resr + resc
    }

    fun main(args: Array<String>) {
        val `in` = FastScanner()
        n = `in`.nextInt()
        m = `in`.nextInt()
        q = `in`.nextInt()
        for (i in 0..Math.max(m, n)) {
            r[i] = 0
            c[i] = 0
        }
        for (i in 1..n) {
            for (j in 1..m) {
                a[i][j] = `in`.nextInt()
                r[i] += a[i][j].toLong()
                c[j] += a[i][j].toLong()
            }
        }
        print(solve())
        print(' ')
        for (i in 0 until q) {
            val x = `in`.nextInt()
            val y = `in`.nextInt()
            val z = `in`.nextInt()
            r[x] = r[x] - a[x][y] + z
            c[y] = c[y] - a[x][y] + z
            a[x][y] = z
            print(solve())
            print(' ')
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