private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (it in 0..t-1) {
        var n = readInt()
        val ar = mutableListOf<Pair<Int, Int>>()
        for (i in 0..n-1) {
            val (l, r) = readInts()
//            a[2 * i] = Pair(l, 0))
//            a[2 * i + 1] = Pair(r, 1))

            ar.add(Pair(l, 0))
            ar.add(Pair(r+1, 1))
        }
        var ans = -1
        val a = ar.sortedWith(compareBy({it.first}, {it.second}))
        var bal = 0 
        var i = 0
        while (i < 2 * n) {
            while (i + 1 < 2 * n && a[i + 1].first == a[i].first) {
                if (a[i].second == 0) {
                    bal += 1 
                } else {
                    bal -= 1
                }
                i += 1
            }
            if (i < 2 * n) {
                if (a[i].second == 0) {
                    bal += 1
                } else {
                    bal -= 1
                }
            }
            if (bal == 1) {
                ans = a[i].first
            }
            i += 1
        }
        println(ans)
    }
}