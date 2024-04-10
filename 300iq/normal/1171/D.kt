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
    val x = nextInt()
    val y = nextInt()
    val z = nextInt()
    val a = nextInt()
    val b = nextInt()
    val c = nextInt()
    if (a + b + c < x + y + z || a + b < x + y || a < x) {
        out.println("NO")
    } else {
        out.println("YES")
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