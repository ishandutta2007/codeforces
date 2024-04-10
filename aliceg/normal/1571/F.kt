import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun solve(a : MutableList<Pair<Int, Int>>, sum : Int) : Triple<Int, List<Int>, List<Int>> {
    val n = a.size
    val dp = List(n + 1) {MutableList(sum / 2 + 1) {0} }
    val p = List(n + 1) {MutableList(sum / 2 + 1) {-1} }
    dp[0][0] = 1
    for (i in 0 until n) {
        for (j in 0..sum / 2) {
            if (dp[i][j] == 1) {
                dp[i + 1][j] = 1
                p[i + 1][j] = 0
                if (j + a[i].first <= sum / 2) {
                    dp[i + 1][j + a[i].first] = 1
                    p[i + 1][j + a[i].first] = 1
                }
            }
        }
    }
    var mn = 2 * sum + 1
    var s = 0
    for (i in 0..sum / 2) {
        if (dp[n][i] == 0)
            continue
        var x = max(i, sum - i) * 2 - 1
        if (i == sum - i)
            ++x
        if (x < mn) {
            mn = x
            s = i
        }
    }
    val ch = MutableList(n) {0}
    var i = n
    var j = s
    while (i != 0) {
        if (p[i][j] == 1) {
            ch[i - 1] = 1
            j -= a[i - 1].first
        }
        --i
    }
    val lst1 : MutableList<Int> = mutableListOf()
    val lst2 : MutableList<Int> = mutableListOf()
    for (i in 0 until n) {
        if (ch[i] == 1)
            lst1.add(i)
        else
            lst2.add(i)
    }
    return Triple(mn, lst1, lst2)
}

fun main() {
    val (n, m) = readInts()
    val a1 : MutableList<Pair<Int, Int>> = mutableListOf()
    val a2 : MutableList<Pair<Int, Int>> = mutableListOf()
    for (i in 0 until n) {
        val (k, t) = readInts()
        if (t == 1)
            a1.add(k to i)
        else
            a2.add(k to i)
    }
    val sum1 = a1.sumOf { it.first }
    val sum2 = a2.sumOf { it.first }
    if (sum1 + sum2 > m) {
        println(-1)
        return
    }
    val (mn, lst1, lst2) = solve(a2, sum2)
    if (sum1 + mn > m) {
        println(-1)
        return
    }
    val ans = MutableList(n) {0}
    var cur = 1
    a1.forEach {
        ans[it.second] = cur
        cur += it.first
    }
    var st = cur
    var s = 0
    for (i in lst1)
        s += a2[i].first
    if (s < sum2 - s)
        st += 1
    var cur1 = st
    for (i in lst1) {
        ans[a2[i].second] = cur1
        cur1 += a2[i].first * 2
    }
    cur1 = cur * 2 + 1 - st
    for (i in lst2) {
        ans[a2[i].second] = cur1
        cur1 += a2[i].first * 2
    }
    println(ans.joinToString(" "))
}