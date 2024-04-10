import java.util.Vector
import kotlin.math.min
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

val dsu = Array<Int>(200000, {it -> 0})

fun Find(x : Int) : Int {
    if (dsu[x] == x) return x;
    dsu[x] = Find(dsu[x])
    return dsu[x]
}

fun Union(u : Int, v : Int) : Boolean {
    var u = Find(u)
    var v = Find(v)
    if (u == v) return false
    dsu[u] = v
    return true
}

class edge {
    var u : Int
    var v : Int
    var w : Long

    constructor(_u : Int, _v : Int, _w : Long) {
        this.u = _u
        this.v = _v
        this.w = _w
    }
}

fun main () {
    var (n, m) = readInts()
    var E = Vector <edge>()
    val a = readLongs()
    var p = Array<Int>(n, {it -> 0})
    for (i in 0..n-1) {
        p[i] = i
    }
    p.sortBy{a[it]}
    for (i in 1..n-1) E.add(edge(p[0], p[i], a[p[0]] + a[p[i]]))
    for (i in 0..m-1) {
        var (a, b, w) = readLongs()
        var u = a.toInt() - 1
        var v = b.toInt() - 1
        E.add(edge(u, v, w));
    }
    E.sortBy{it.w}
    for (i in 0..n-1) dsu[i] = i
    var ans : Long = 0
    for (i in 0..E.size - 1) {
        if (Union(E[i].u, E[i].v)) {
            ans += E[i].w
        }
    }
    println(ans)
}