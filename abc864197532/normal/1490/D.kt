private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

var a = Array<Int>(100, {it -> 0});
var ans = Array<Int>(100, {it -> 0});

fun dfs(l : Int, r : Int, d : Int) : Int {
    if (l != r) {
        var mx = l;
        for (i in l+1..r-1) {
            if (a[mx] < a[i]) {
                mx = i
            }
        }
        ans[mx] = d
        dfs(l, mx, d + 1)
        dfs(mx + 1, r, d + 1)
    }
    return 0;
}

fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readInt()
        var tmp = readInts()
        for (i in 0..n-1) {
            a[i] = tmp[i]
        }
        dfs(0, n, 0);
        for (i in 0..n-1) {
            print("${ans[i]} ")
        }
        println("")
    }
}