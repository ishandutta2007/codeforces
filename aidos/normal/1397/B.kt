

import kotlin.math.abs
import kotlin.math.min
import kotlin.math.pow

fun calc(a: LongArray): Long{
    var ans = 1L shl 60
    var b = mutableListOf<Long>()
    if(a.size < 100) {
        for (x in a) {
            b.add(x)
            for (i in 2 until 32) {
                b.add((x.toDouble().pow(1.toDouble() / i) + 0.5).toLong())
                b.add((x.toDouble().pow(1.toDouble() / i)).toLong())
            }
        }
        for (i in (1L until 1020)) {
            b.add(i)
        }
        b.sort()
    } else {
        b.add(1)
        b.add(2)
    }
    var lim = 1L shl 47
    var last = -1L
    for(x in b) {
        if (last == x){
            continue
        }
        last = x
        var sum = 0L
        var cur = 1L
        var bad = false
        for(y in a) {
            if(bad) {
                sum = ans + 1
                break
            }
            sum += abs(cur - y)
            if(sum > ans) break
            if(cur > lim/x || cur * x > lim) {
                bad = true
            }
            cur *= x
        }
        if(ans > sum) ans = sum
    }
    return ans
}
fun solve(){
    readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toLong() }.toLongArray()
    var b = a
    b.sort()
    println(min(calc(a), calc(b) + 1))
}

fun main() {
    var t = 1//readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}