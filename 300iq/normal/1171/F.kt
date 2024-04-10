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
        for (tc in 0 until t) {
            val n = nextInt()
            val l = IntArray(n)
            val r = IntArray(n)
            val id = arrayOfNulls<Int>(n)
            for (i in 0 until n) {
                l[i] = nextInt()
                r[i] = nextInt()
                id[i] = i
            }
            Arrays.sort<Int>(id) { o1, o2 ->
                val a = r[o1!!.toInt()]
                val b = r[o2!!.toInt()]
                a - b
            }
            var mx_l = 1000 * 1000 * 1000
            var good = false
            for (i in n - 1 downTo 0) {
                if (mx_l != 1000 * 1000 * 1000 && mx_l > r[id[i]!!.toInt()]) {
                    for (j in 0 until n) {
                        if (r[j] <= r[id[i]!!.toInt()]) {
                            out.print(1.toString() + " ")
                        } else {
                            out.print(2.toString() + " ")
                        }
                    }
                    out.println()
                    good = true
                    break
                }
                mx_l = Math.min(mx_l, l[id[i]!!.toInt()])
            }
            if (!good) {
                out.println("-1")
            }
        }
    }

    fun main(args: Array<String>) {
        solve()
        out.close()
    }