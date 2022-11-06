import java.io.*
import java.lang.Math.max
import java.util.*
import kotlin.collections.ArrayList

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
    val n = nextInt()
    val a = nextInt()
    val b = nextInt()
    val k = nextInt()
    val A = 1e6.toInt() + 31
    val cnt = IntArray(A)
    for (i in 0 until n) {
        val x = nextInt()
        cnt[x]++
    }
    val d = Array<ArrayList<Int>>(A, { ArrayList() })
    var ans = 0
    for (i in 1 until A) {
        if (i % k != 0) {
            for (j in 0 .. cnt[i]) {
                d[i].add(0)
            }
        } else {
            val prev = i / k
            d[i].add(d[prev].last())
            for (j in 1 .. cnt[i]) {
                if (j % b == 0 && j / b * a < d[prev].size) {
                    d[i].add(max(d[i].last(), d[prev][d[prev].size - j / b * a - 1] + j / b))
                } else {
                    d[i].add(d[i].last())
                }
            }
        }
//        print("i: " + i)
//        for (x in d[i]) {
//            print(" " + x)
//        }
//        println()
//        if (i == 20) {
//            break
//        }
        if (i * k >= A) {
            ans += d[i].last()
        }
    }

    println(ans)

}