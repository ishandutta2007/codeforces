import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.Arrays
import java.util.StringTokenizer


fun main(args: Array<String>) {
    val `in` = FastScanner()
    var ntest = `in`.nextInt()
    while (ntest-- > 0) {
        val n = `in`.nextInt()
        val k = `in`.nextInt()
        val foo = 1 + k + k * k + k * k * k
        val res = n / foo
        print(res)
        print(' ')
        print(res * k)
        print(' ')
        print(res * k * k)
        print(' ')
        println(res * k * k * k)
    }
}

class FastScanner {
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

    fun readArray(n: Int): IntArray {
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        return a
    }

    fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }
}