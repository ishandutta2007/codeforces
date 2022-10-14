import java.util.Vector
import kotlin.math.min
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

val N = 200000

var a = Array<Int>(N, {it -> 0})

fun ask(n : Int, m : Int, k : Int) : Boolean {
    var need = 1
    var al = 0
    for (i in 0..n-1) {
        if (al + a[i] <= k) al += a[i]
        else {
            al = a[i]
            need++
        }
    }
    return need <= m;
}

fun main () {
    var (n, m, k) = readInts()
    var arr = readInts()
    for (i in 0..n-1) {
        a[i] = arr[n - 1 - i]
    }
    var l = 0
    var r = n + 1
    while (r - l > 1) {
        var mid = (l + r) / 2
        if (ask(mid, m, k)) l = mid
        else r = mid
    }
    println(l)
}