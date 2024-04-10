private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var n = readInt()
        var arri = readInts()
        var arr = Array<Int>(n, {it -> 0})
        var choose = Array<Boolean>(n, {it -> false})
        for (i in 0..n-1) {
            arr[i] = arri[i]
        }
        var now = 0
        var tmp = 0
        var ans = Array<Int>(n, {it -> 0})
        while (now < n) {
            var ss: Boolean = false
            for (i in 0..n - 1) {
                if (!choose[i] && arr[i] <= tmp) {
                    ans[now] = i
                    now++
                    tmp = 1
                    choose[i] = true
                    ss = true
                    break
                }
            }
            if (ss) continue
            var p = -1
            for (i in 0..n - 1) {
                if (!choose[i] && (p == -1 || arr[p] < arr[i])) {
                    p = i
                }
            }
            ans[now] = p
            now++
            tmp++
            choose[p] = true
        }
        for (i in 0..n - 1) {
            print("${ans[i] + 1} ")
        }
        println("")
    }
}