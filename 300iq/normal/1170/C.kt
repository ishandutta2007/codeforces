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
        val q = nextInt()
        for (i in 0 until q) {
            val s = next()
            val t = next()
            if (s.length < t.length) {
                out.println("NO")
            } else {
                val n = s.length
                val x = s.toCharArray()
                val y = t.toCharArray()
                var ptr_i = 0
                var ptr_j = 0
                var bad = false
                while (ptr_i < s.length && ptr_j < t.length) {
                    if (x[ptr_i] == y[ptr_j]) {
                        ptr_i++
                        ptr_j++
                        continue
                    }
                    if (x[ptr_i] == '-') {
                        if (ptr_i + 1 < s.length && x[ptr_i + 1] == '-') {
                            ptr_i += 2
                            ptr_j++
                        } else {
                            bad = true
                            break
                        }
                    } else {
                        bad = true
                        break
                    }
                }
                if (ptr_i != s.length || ptr_j != t.length) bad = true
                if (bad)
                    out.println("NO")
                else
                    out.println("YES")
            }
        }
    }

 
    fun main(args: Array<String>) {
        solve()
        out.close()
    }