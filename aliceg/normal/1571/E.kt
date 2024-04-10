import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val s = readLn()
        val a = readLn()
        val b = MutableList(n) {' '}
        var flag = true
        for (i in 0 until n - 4) {
            if (a[i] == '1' && a[i + 1] == '1') {
                flag = false
                break
            }
            if (i < n - 6 && a[i] == '1' && a[i + 3] == '1') {
                flag = false
                break
            }
            if (i < n - 5 && a[i] == '1' && a[i + 2] == '1') {
                b[i] = '('
                b[i + 1] = ')'
                b[i + 2] = '('
                b[i + 3] = ')'
                b[i + 4] = '('
                b[i + 5] = ')'
            }
        }
        if (!flag)
            println(-1)
        else {
            var cnt = 0
            for (i in 0 until n) {
                if (b[i] != ' ' && s[i] != b[i])
                    ++cnt
                if (b[i] == ' ' && i < n - 3 && a[i] == '1') {
                    if (s[i] != '(')
                        ++cnt
                    if (s[i + 3] != ')')
                        ++cnt
                    if (s[i + 1] == s[i + 2])
                        ++cnt
                }
            }
            println(cnt)
        }
    }
}