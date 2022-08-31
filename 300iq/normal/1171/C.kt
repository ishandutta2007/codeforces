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
    private fun solve() {
        val t = nextInt()
        for (tc in 0 until t) {
            val s = next()
            val c = s.toCharArray()
            for (i in 1 until s.length) {
                if (c[i] != c[0]) {
                    val temp = c[i]
                    c[i] = c[s.length - 1]
                    c[s.length - 1] = temp
                }
            }
            if (c[0] == c[s.length - 1]) {
                out.println(-1)
            } else {
                for (i in 0 until s.length) out.print(c[i])
                out.println()
            }
        }
    }

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
    private fun run() {
        solve()
        out.close()
    }

  
        fun main(args: Array<String>) {
           run()
        }