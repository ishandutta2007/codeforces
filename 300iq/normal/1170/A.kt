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
        val t = nextInt()
        for (i in 0 until t) {
            val x = nextInt()
            val y = nextInt()
            val a = Math.max(1, Math.min(x - 1, y - 1))
            out.println(a.toString() + " " + (x - a) + " " + (y - a))
        }
    }

   
    fun main(args: Array<String>) {
        solve()
        out.close()
    }