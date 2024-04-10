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
        val m = nextInt()
        val b = IntArray(m)
        for (i in 0 until m) b[i] = nextInt()
        var n = 0
        for (i in 0 until m) if (b[i] == -1) n++
        val nxt = IntArray(n)
        val prv = IntArray(n)
        for (i in 0 until n) {
            nxt[i] = (i + 1) % n
            prv[(i + 1) % n] = i
        }
        val grop = arrayOfNulls<ArrayList<Int>>(n)
        for (i in 0 until n)
            grop[i] = ArrayList<Int>()
        var ptr = 0
        for (i in 0 until m) {
            if (b[i] == -1) {
                nxt[prv[ptr]] = nxt[ptr]
                prv[nxt[ptr]] = prv[ptr]
                ptr = nxt[ptr]
            } else {
                grop[ptr]!!.add(b[i]);
                ptr = nxt[ptr]
            }
        }
        out.println(n)
        for (i in 0 until n) {
            out.print(grop[i]!!.size.toString() + " ")
            for (x in grop[i]!!) {
                out.print(x.toString() + " ")
            }
            out.println()
        }
    }


    fun main(args: Array<String>) {
        solve()
        out.close()
    }