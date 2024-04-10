import java.io.*
import java.util.*
import java.lang.Math.*
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
    val ans = CharArray(n)
    val A = 2e5.toInt()
    val pos = Array<ArrayList<Int>>(A, { ArrayList() })
    val a = IntArray(n)
    for (i in 0 until n) {
        ans[i] = 'B'
        val x = nextInt() - 1
        a[i] = x
        pos[x].add(i)
    }

    var l = 0
    var r = n + 1
    val a1 = IntArray(n)
    val a2 = IntArray(n)
    while (l + 1 < r) {
        ans.fill('B')
        val m = (l + r) shr 1
        var mc = m
        var p1 = -1
        var p2 = -1
        for (i in 0 until n) {
            if (pos[i].size != 2) {
                break
            }
            if (p1 < pos[i][0] && p2 < pos[i][1] || p1 > pos[i][0] && p2 > pos[i][1]) {
                p1 = pos[i][0]
                p2 = pos[i][1]
                ans[p1] = 'R'
                ans[p2] = 'G'
                mc--
                if (mc <= 0) {
                    break
                }
            } else {
                break
            }
        }

        if (mc != 0) {
            r = m
            continue
        }
        var i1 = 0
        var i2 = 0
        for (i in 0 until n) {
            if (ans[i] == 'R') {
                a1[i1++] = a[i]
            } else if (ans[i] == 'G') {
                a2[i2++] = a[i]
            }
        }

        var ok = true
        for (i in 0 until m) {
            if (a1[i] != a2[i]) {
                ok = false
                break
            }
        }
        if (ok) {
            l = m
        } else {
            r = m
        }
    }

    val m = l

    ans.fill('B')
    var mc = m
    var p1 = -1
    var p2 = -1
    for (i in 0 until n) {
        if (pos[i].size != 2) {
            break
        }
        if (p1 < pos[i][0] && p2 < pos[i][1] || p1 > pos[i][0] && p2 > pos[i][1]) {
            p1 = pos[i][0]
            p2 = pos[i][1]
            ans[p1] = 'R'
            ans[p2] = 'G'
            mc--
            if (mc <= 0) {
                break
            }
        } else {
            break
        }
    }

    for (c in ans) {
        print(c)
    }

}