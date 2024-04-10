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
        if (n > 26 || n == 1) {
            out.println("Yes")
            return
        }
        val s = next()
        for (i in 0 until n) {
            var kek = 0
            for (j in 0 until n) {
                if (s[i] == s[j]) {
                    kek++
                }
            }
            if (kek > 1) {
                out.println("Yes")
                return
            }
        }
        out.println("No")
    }


    fun main(args: Array<String>) {
        solve()
        out.close()
    }