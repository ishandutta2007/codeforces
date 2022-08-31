import java.io.*
import java.math.BigDecimal
import java.math.BigInteger
import java.nio.charset.IllegalCharsetNameException
import java.util.*

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
        val m = nextInt()
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        val pr = IntArray(n + 1)
        for (i in 0 until n) pr[i + 1] = pr[i] + a[i]
        val q = nextInt()
        for (z in 0 until q) {
            val s = nextInt()
            val c = IntArray(s)
            for (i in 0 until s) c[i] = nextInt()
            val b = IntArray(s + 1)
            b[0] = c[0] - 1
            for (i in 0 until s - 1) b[i + 1] = c[i + 1] - c[i] - 1
            b[s] = m - c[s - 1]
            var l = 0
            var i = 0
            while (i <= s && l < n) {
                val last = l
                var r = n + 1
                while (r - l > 1) {
                    val x = (l + r) / 2
                    if (pr[last] + b[i] >= pr[x]) {
                        l = x
                    } else {
                        r = x
                    }
                }
                i++
            }
            if (l == n) {
                out.println("YES")
            } else {
                out.println("NO")
            }
        }
    }

    
    fun main(args: Array<String>) {
        solve()
        out.close()
    }