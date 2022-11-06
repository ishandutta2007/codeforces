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
    val t = nextInt()
    for (it in 0 until t) {
        val n = nextInt()
        val l = IntArray(n)
        val r = IntArray(n)
        val p = Array<Int>(n, { it })
        for (i in 0 until n) {
            l[i] = nextInt()
            r[i] = nextInt()
            p[i] = i
        }
        Arrays.sort(p, { i: Int, j: Int -> l[i].compareTo(l[j]) })

        var x = -1
        var t = -1
        for (i in 0 until n) {
            if (i != 0 && l[p[i]] > t) {
                x = i
                break
            }
            t = max(t, r[p[i]])
        }

        if (x == -1) {
            println(-1)
            continue
        }

        val ans = IntArray(n)
        for (i in 0 until n) {
            if (i < x) {
                ans[p[i]] = 1
            } else {
                ans[p[i]] = 2
            }
        }
        for (i in 0 until n) {
            print(ans[i])
            print(" ")
        }
        println()
    }
}