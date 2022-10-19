class DSU {
    var n : Int
    var pr: MutableList<Int>
    var h: MutableList<Int>

    constructor(nn: Int) {
        n = nn
        pr = MutableList(n) { index -> index }
        h = MutableList(n) {1}
    }

    fun get(v: Int): Int {
        if (v == pr[v]) {
            return v
        }
        pr[v] = get(pr[v])
        return pr[v]
    }

    fun unite(a: Int, b: Int): Int {
        var v = get(a)
        var u = get(b)
        if (v == u) {
            return 0
        }
        if (h[v] < h[u]) {
            pr[v] = u
        } else if (h[v] > h[u]) {
            pr[u] = v
        } else {
            pr[u] = v
            h[v] += 1
        }
        return 1
    }
}

data class edge(val v: Int, val u: Int, var w: Long)

fun main() {
    var args = readLine()!!.split(' ').map{ it.toInt() }
    var n = args[0]
    var m = args[1]
    var a = readLine()!!.split(' ').map{ it.toLong() }
    var ar = MutableList<edge>(n + m) {edge(0, 0, 0)}
    var mn = 0
    for (i in 1 until n) {
        if (a[i] < a[mn]) {
            mn = i
        }
    }
    for (i in 0 until n) {
        ar[i] = edge(mn, i, a[i] + a[mn])
    }
    for (i in 0 until m) {
        var args2 = readLine()!!.split(' ').map{ it.toLong() }
        ar[i + n] = edge(args2[0].toInt() - 1, args2[1].toInt() - 1, args2[2].toLong())
    }
    var dsu = DSU(n)
    ar.sortWith(compareBy({it.w}, {it.u}, {it.v}))
    var ans: Long = 0
    for (it in ar) {
        if (dsu.unite(it.u, it.v) == 1) {
            ans += it.w
        }
    }
    print(ans)
}