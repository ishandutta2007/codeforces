import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.properties.Delegates

class Main : PrintWriter {
    val `in`: BufferedReader
    var stok: StringTokenizer? = null
    var g: Array<MutableList<Int>> by Delegates.notNull()

    val inf = 1e9.toInt()

    fun solve() {
        val n = nextInt()
        val m = nextInt()
        val a = Array<String>(n, {next()!!})
        val bm = Array<Array<Array<IntArray>>>(n, { Array(m, { Array(n, { IntArray(m, {inf}) }) }) })
        val bp = Array<Array<Array<IntArray>>>(n, { Array(m, { Array(n, { IntArray(m, {inf}) }) }) })
        val pp = Array<Array<Array<CharArray>>>(n, { Array(m, { Array(n, { CharArray(m, {0.toChar()}) }) }) })


        var smx = -1
        var smy = -1
        var sgx = -1
        var sgy = -1

        var ex = -1
        var ey = -1

        for (i in 0..n-1) {
            for (j in 0..m-1) {
                if (a[i][j] == 'Y') {
                    smx = i
                    smy = j
                }
                if (a[i][j] == 'B') {
                    sgx = i
                    sgy = j
                }
                if (a[i][j] == 'T') {
                    ex = i
                    ey = j
                }
            }
        }

        bm[smx][smy][sgx][sgy] = 0
        bp[smx][smy][sgx][sgy] = 0

        val q: Queue<Int> = ArrayDeque<Int>()

        q.add(smx)
        q.add(smy)
        q.add(sgx)
        q.add(sgy)

        val dx = intArrayOf(1, -1, 0, 0)
        val dy = intArrayOf(0, 0, 1, -1)

        val pc = charArrayOf('s', 'n', 'e', 'w')

        val dcx = IntArray(256)
        dcx['w'.toInt()] = 0
        dcx['e'.toInt()] = 0
        dcx['n'.toInt()] = -1
        dcx['s'.toInt()] = 1

        val dcy = IntArray(256)
        dcy['w'.toInt()] = -1
        dcy['e'.toInt()] = 1
        dcy['n'.toInt()] = 0
        dcy['s'.toInt()] = 0

        while (!q.isEmpty()) {
            val mx = q.poll()
            val my = q.poll()
            val gx = q.poll()
            val gy = q.poll()

            val cm = bm[mx][my][gx][gy]
            val cp = bp[mx][my][gx][gy]

            for (i in 0..3) {
                val x = mx + dx[i]
                val y = my + dy[i]

                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 'X') {
                    continue
                }

                var ngx = gx
                var ngy = gy

                var ncm = cm + 1
                var ncp = cp

                var cc = pc[i]

                if (x == gx && y == gy) {
                    ngx = gx + dx[i]
                    ngy = gy + dy[i]
                    ncp++
                    cc = Character.toUpperCase(cc)
                }

                if (ngx < 0 || ngx >= n || ngy < 0 || ngy >= m || a[ngx][ngy] == 'X') {
                    continue
                }

                val ccm = bm[x][y][ngx][ngy]
                val ccp = bp[x][y][ngx][ngy]

                if (ncp < ccp || (ncp == ccp && ncm < ccm)) {
                    bm[x][y][ngx][ngy] = ncm
                    bp[x][y][ngx][ngy] = ncp
                    pp[x][y][ngx][ngy] = cc
                    q.add(x)
                    q.add(y)
                    q.add(ngx)
                    q.add(ngy)
                }
            }
        }

        var amx = -1
        var amy = -1
        var agx = -1
        var agy = -1
        var ap = inf
        var am = inf

        for (i in 0..n-1) {
            for (j in 0..m-1) {
                val cp = bp[i][j][ex][ey]
                val cm = bm[i][j][ex][ey]
                if (cp == inf) {
                    continue
                }

                if (cp < ap || (cp == ap && cm < am)) {
                    ap = cp
                    am = cm
                    amx = i
                    amy = j
                    agx = ex
                    agy = ey
                }
            }
        }

        if (ap == inf) {
            println("NO")
            return
        }

        val ans = ArrayList<Char>()

        while (true) {
            val c = pp[amx][amy][agx][agy]
            if (c == 0.toChar()) {
                break
            }

            ans.add(c)

            val lc = Character.toLowerCase(c)
            amx -= dcx[lc.toInt()]
            amy -= dcy[lc.toInt()]

            if (Character.isUpperCase(c)) {
                agx -= dcx[lc.toInt()]
                agy -= dcy[lc.toInt()]
            }
        }

        println("YES")
        Collections.reverse(ans)
        for (i in ans) {
            print(i)
        }
    }

    constructor() : super(System.out) {
        `in` = BufferedReader(InputStreamReader(System.`in`))
    }

    fun next(): String? {
        while (stok == null || !stok!!.hasMoreTokens()) {
            val s = `in`.readLine() ?: return null
            stok = StringTokenizer(s)
        }
        return stok!!.nextToken()
    }

    fun nextInt(): Int {
        return next()!!.toInt()
    }

    fun nextLong(): Long {
        return next()!!.toLong()
    }

    fun nextDouble(): Double {
        return next()!!.toDouble()
    }

    fun <T> createAdjacencyList(n: Int): Array<MutableList<T>> {
        return Array(n, { ArrayList<T>() })
    }
}


fun main(args: Array<String>) {
    Main().use { it.solve() }
}