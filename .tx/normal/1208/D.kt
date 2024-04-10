import java.io.*
import java.util.*
import java.lang.Math.*

var stok = StringTokenizer("")
var br = BufferedReader(InputStreamReader(System.`in`))

fun nextToken(): String? {
    while (!stok.hasMoreTokens()) {
        val s = br.readLine() ?: return null
        stok = StringTokenizer(s)
    }
    return stok.nextToken()
}

fun nextInt() = nextToken()!!.toInt()
fun nextDouble() = nextToken()!!.toDouble()
fun nextLong() = nextToken()!!.toLong()

fun main(args: Array<String>) {
    if (args.isNotEmpty()) br = BufferedReader(FileReader("input.txt"))
    PrintWriter(System.out, false).use { it.solve() }
}

fun PrintWriter.solve() {
    class Fenw {
        val a: LongArray

        constructor(n: Int) {
            a = LongArray(n)
        }

        fun get(r: Int): Long {
            var r = r
            var res = 0L
            while (r >= 0) {
                res += a[r]
                r = (r and (r + 1)) - 1
            }
            return res
        }

        fun add(i: Int, x: Int) {
            var i = i
            while (i < a.size) {
                a[i] += x.toLong()
                i = i or (i + 1)
            }
        }
    }

    val n = nextInt()

    val f = Fenw(n + 1)
    for (i in 0 until n) {
        f.add(i + 1, i + 1)
    }

    val s = LongArray(n)
    for (i in 0 until n) {
        s[i] = nextLong()
    }

    val ans = IntArray(n)

    for (i in n - 1 downTo 0) {
        var l = 0
        var r = n + 1
        while (l + 1 < r) {
            var m = (l + r) shr 1
            var x = f.get(m)
            if (x <= s[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        ans[i] = r
        f.add(r, -r)
    }

    for (i in ans) {
        print(i)
        print(" ")
    }
}