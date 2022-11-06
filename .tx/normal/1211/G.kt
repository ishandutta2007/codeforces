import java.io.*
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
    val t = nextInt()
    for (tt in 0 until t) {
        val n = nextInt()
        val c = IntArray(n)
        for (i in 0 until n) {
            c[i] = nextInt()
        }
        val d = IntArray(n)
        for (i in 0 until n) {
            d[i] = nextInt()
        }

        val g = Array<ArrayList<Int>>(n, { ArrayList() })
        for (i in 1 until n) {
            val x = nextInt() - 1
            val y = nextInt() - 1
            g[x].add(y)
            g[y].add(x)
        }

        val dist = IntArray(n)
        val par = IntArray(n, { -1 })
        fun dfsDist(v: Int, p: Int, d: Int) {
            dist[v] = d
            for (i in g[v]) {
                if (i == p) {
                    continue
                }
                par[i] = v
                dfsDist(i, v, d + 1)
            }
        }

        dfsDist(0, -1, 0)

        var p1 = -1
        var mxd = -1
        for (i in 0 until n) {
            if (c[i] != d[i] && dist[i] > mxd) {
                mxd = dist[i]
                p1 = i
            }
        }
        if (p1 == -1) {
            println("Yes")
            println(0)
            continue
        }

        dist.fill(0)
        par.fill(-1)
        dfsDist(p1, -1, 0)
        var p2 = -1
        mxd = -1
        for (i in 0 until n) {
            if (c[i] != d[i] && dist[i] > mxd) {
                mxd = dist[i]
                p2 = i
            }
        }

        val path = ArrayList<Int>()
        var x = p2
        while (x != -1) {
            path.add(x)
            x = par[x]
        }

//        print("path: ")
//        for (i in path) {
//            print((i + 1).toString() + " ")
//        }
//        println()

        fun ceqd(): Boolean {
            for (i in 0 until n) {
                if (c[i] != d[i]) {
                    return false
                }
            }
            return true
        }

        var z = c[path[0]]
        for (i in 0 until path.size - 1) {
            c[path[i]] = c[path[i + 1]]
        }
        c[path[path.size - 1]] = z
        if (ceqd()) {
            println("Yes")
            println(path.size)
            for (i in path) {
                print(i + 1)
                print(" ")
            }
            println()
            continue
        }

        for (i in path.size - 1 downTo 1) {
            c[path[i]] = c[path[i - 1]]
        }
        c[path[0]] = z

        path.reverse()

        z = c[path[0]]
        for (i in 0 until path.size - 1) {
            c[path[i]] = c[path[i + 1]]
        }
        c[path[path.size - 1]] = z
        if (ceqd()) {
            println("Yes")
            println(path.size)
            for (i in path) {
                print(i + 1)
                print(" ")
            }
            println()
            continue
        }

        println("No")
        continue
    }
}