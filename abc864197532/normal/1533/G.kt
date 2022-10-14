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

fun main () {
    var t = readInt()
    while (t --> 0) {
        var (n, m) = readInts()
        var a = Array <Array <Int>> (n, {it -> Array <Int> (m, {it -> 0})})
        var cnt = 0
        for (i in 0..n - 1) {
            var tmp = readInts()
            for (j in 0..m - 1) {
                a[i][j] = tmp[j]
                if (a[i][j] != 0) cnt++
            }
        }
        var vis = Array <Array <Int>> (n, {it -> Array <Int> (m, {it -> 0})})
        var cnt2 = 0
        var ans = Vector <Int>()
        fun dfs(x : Int, y : Int) : Void? {
            ans.add(a[x][y])
            cnt2++
            vis[x][y] = 1
            if (0 <= x + 1 && x + 1 < n && 0 <= y && y < m && vis[x + 1][y] == 0 && a[x + 1][y] != 0) {
                dfs(x + 1, y)
                ans.add(a[x][y])
            }
            if (0 <= x - 1 && x - 1 < n && 0 <= y && y < m && vis[x - 1][y] == 0 && a[x - 1][y] != 0) {
                dfs(x - 1, y)
                ans.add(a[x][y])
            }
            if (0 <= x && x < n && 0 <= y + 1 && y + 1 < m && vis[x][y + 1] == 0 && a[x][y + 1] != 0) {
                dfs(x, y + 1)
                ans.add(a[x][y])
            }
            if (0 <= x && x < n && 0 <= y - 1 && y - 1 < m && vis[x][y - 1] == 0 && a[x][y - 1] != 0) {
                dfs(x, y - 1)
                ans.add(a[x][y])
            }
            return null
        }
        out@ for (i in 0..n - 1) {
            for (j in 0..m - 1) {
                if (a[i][j] != 0) {
                    dfs(i, j)
                    break@out
                }
            }
        }
        if (cnt != cnt2) {
            println(-1)
        } else {
            println("${cnt} ${cnt}")
            for (i in 0..cnt - 1) {
                var tmp = Array <Int>(cnt, {it -> 0})
                for (j in 0..cnt - 1) {
                    tmp[j] = ans[i + j]
                }
                println(tmp.joinToString(" "))
            }
        }
    }
}