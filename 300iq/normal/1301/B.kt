import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

    @Throws(IOException::class)
    internal fun solve() {
        var t = nextInt()
        while (t-- > 0) {
            val n = nextInt()
            val a = IntArray(n)
            for (i in 0 until n) {
                a[i] = nextInt()
            }
            var ans = 0
            val `val` = IntArray(n)
            var sz = 0
            for (i in 1 until n) {
                if (a[i] != -1 && a[i - 1] != -1) {
                    ans = Math.max(ans, Math.abs(a[i] - a[i - 1]))
                }
                if (a[i] == -1 && a[i - 1] != -1) {
                    `val`[sz++] = a[i - 1]
                }
                if (a[i] != -1 && a[i - 1] == -1) {
                    `val`[sz++] = a[i]
                }
            }
            if (sz == 0) {
                out.print(ans)
                out.print(' ')
                out.println(0)
            } else {
                val ok = IntArray(sz)
                for (i in 0 until sz) ok[i] = `val`[i]
                Arrays.sort(ok)
                ans = Math.max(ans, (ok[sz - 1] - ok[0] + 1) / 2)
                out.print(ans)
                out.print(' ')
                out.println((ok[sz - 1] + ok[0]) / 2)
            }
        }
    }

    var br = BufferedReader(InputStreamReader(System.`in`))
    var st: StringTokenizer? = null
    var out = PrintWriter(System.out)
    @Throws(IOException::class)
    internal fun next(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(br.readLine())
        }
        return st!!.nextToken()
    }

    @Throws(IOException::class)
    fun nextInt(): Int {
        return next().toInt()
    }

    @Throws(IOException::class)
    fun nextLong(): Long {
        return next().toLong()
    }

    @Throws(IOException::class)
    private fun run() {
        solve()
        out.close()
    }

        fun main(args: Array<String>) {
            run()
        }