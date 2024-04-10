import java.util.PriorityQueue
import kotlin.math.abs
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var (n, k, x) = readInts()
    var arra = readInts()
    var a = Array<Int>(n, {it -> 0})
    for (i in 0..n-1) {
        a[i] = arra[i]
    }

    var l : Long = -1;
    var r : Long = 100000000000L
    while (r - l > 1) {
        var mid : Long = (l + r) / 2
        var ans = 0
        var now : Long = 0
        var cnt = 0
        var pq : PriorityQueue<Int> = PriorityQueue<Int>()
        for (i in 0..n - 1) {
            now += a[i]
            pq.add(-a[i])
            cnt++
            while (now > mid) {
                var tt = pq.remove()
                now += tt
                cnt--
                ans++
            }
            if (cnt == x) {
                while (!pq.isEmpty()) {
                    pq.remove()
                }
                cnt = 0
                now = 0
            }
        }
        if (ans <= k) r = mid
        else l = mid
    }
    println(r)
}