private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
 
fun main () {
    var t = readInt()
    var inf = 1000000087
    while (t --> 0) {
        var(n, m) = readInts()
        var a = Array<Int>(m, {it -> 0})
        var b = Array<Int>(m, {it -> 0})
        var c = Array<Int>(m, {it -> 0})
        var v = Array<Int>(n, {it -> 0})
        for (i in 0..m-1) {
            var (aa, bb, cc) = readInts()
            aa -= 1
            bb -= 1
            a[i] = aa
            b[i] = bb
            c[i] = cc
            if (v[a[i]] < c[i])
                v[a[i]] = c[i]
            if (v[b[i]] < c[i])
                v[b[i]] = c[i]
        }
        var iss = true
        for (i in 0..m-1) {
            if (v[a[i]] > v[b[i]] && v[b[i]] != c[i])
                iss = false
            if (v[a[i]] <= v[b[i]] && v[a[i]] != c[i])
                iss = false
        }
        if (iss) {
            println("YES")
            println(v.joinToString(" "))
        } else {
            println("NO")
        }
    }
}