import java.util.*
import kotlin.math.min
import kotlin.math.max
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

val N = 200087
var sum = Array<Long>(N * 4, {it -> 0})
var lz = Array<Long>(N * 4, {it -> -1L})

fun pull(id : Int) {
    sum[id] = sum[id * 2] + sum[id * 2 + 1]
}

fun give_tag(id : Int, v : Long, l : Int, r : Int) {
    lz[id] = v
    sum[id] = v * (r - l)
}

fun push(id : Int, l : Int, r : Int) {
    var m = (l + r) / 2
    if (lz[id] != -1L) {
        give_tag(id * 2, lz[id], l, m)
        give_tag(id * 2 + 1, lz[id], m, r)
    }
    lz[id] = -1
}

fun add(id : Int, v : Long, a : Int, b : Int, l : Int, r : Int) {
    var m = (l + r) / 2
    if (a <= l && r <= b) give_tag(id, v, l, r)
    else {
        push(id, l, r)
        if (a < m) add(id * 2, v, a, b, l, m)
        if (m < b) add(id * 2 + 1, v, a, b, m, r)
        pull(id)
    }
}

fun query(id : Int, a : Int, b : Int, l : Int, r : Int) : Long {
    var m = (l + r) / 2
    if (a <= l && r <= b) return sum[id]
    else {
        push(id, l, r)
        var ans = 0L
        if (a < m) ans += query(id * 2, a, b, l, m)
        if (m < b) ans += query(id * 2 + 1, a, b, m, r)
        return ans
    }
}

fun main () {
    var n = readInt()
    val a = readInts()
    var Q = Array<Vector <Pair<Int, Int>>>(n + 1, {it -> Vector <Pair<Int, Int>>()})
    var q = readInt()
    for (i in 0..q-1) {
        var (l, r) = readInts()
        Q[r].add(Pair(--l, i))
    }
    var stk = Stack <Int>()
    var ans = Array<Long>(q, {it -> 0L})
    for (r in 1..n) {
        while (!stk.empty() && a[stk.peek()] < a[r - 1]) stk.pop()
        var l = 0
        if (!stk.empty()) l = stk.peek() + 1
        add(1, a[r - 1].toLong(), l, r, 0, n)
        stk.push(r - 1)
        for (i in 0..Q[r].size - 1) {
            ans[Q[r][i].second] = query(1, Q[r][i].first, r, 0, n)
        }
    }
    println(ans.joinToString(" "))
}