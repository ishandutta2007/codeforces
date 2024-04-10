import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.ArrayList
import java.util.Collections
import java.util.StringTokenizer


fun main(args: Array<String>) {
    val `in` = FastScanner()
    var ntest = `in`.nextInt()
    while (ntest-- > 0) {
        val a = `in`.nextInt()
        val b = `in`.nextInt()
        println(a + b)
    }
}

internal class FastScanner {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer("")
    operator fun next(): String {
        while (!st.hasMoreTokens())
            try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }

        return st.nextToken()
    }

    fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    fun readArray(n: Int): LongArray {
        val a = LongArray(n)
        for (i in 0 until n) a[i] = nextLong()
        return a
    }

    fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }
}