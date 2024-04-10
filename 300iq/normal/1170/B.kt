import java.io.*
import java.math.BigDecimal
import java.math.BigInteger
import java.util.Arrays
import java.util.Comparator
import java.util.Random
import java.util.StringTokenizer



    internal var br = BufferedReader(InputStreamReader(System.`in`))
    internal var st: StringTokenizer? = null
    internal var out = PrintWriter(System.out)

    @Throws(IOException::class)
    internal  fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(br.readLine())
        }
        return st!!.nextToken()
    }

    @Throws(IOException::class)
    internal fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    @Throws(IOException::class)
    internal fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }

    @Throws(IOException::class)
    internal fun solve() {
        val n = nextInt()
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        var m1 = 0
        var m2 = 0
        var ans = 0
        for (i in 0 until n) {
            if (m2 > a[i]) {
                ans++
            }
            var x = a[i]
            if (x > m1) {
                val t = m1
                m1 = x
                x = t
            }
            if (x > m2) {
                m2 = x
            }
        }
        out.println(ans)
    }

    fun main(args: Array<String>) {
        solve()
        out.close()
    }