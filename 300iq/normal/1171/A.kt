import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.StringTokenizer

    internal var br = BufferedReader(InputStreamReader(System.`in`))
    internal var st: StringTokenizer? = null
    internal var out = PrintWriter(System.out)

    @Throws(IOException::class)
    private fun solve() {
        val t = nextInt()
        for (i in 0 until t) {
            val x = nextInt()
            out.println(x / 2)
        }
    }

    internal fun next(): String {
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