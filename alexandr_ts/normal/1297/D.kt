private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (it in 0..t-1) {
        var (n, d) = readInts()
        var a = readInts().toIntArray()
        var b = mutableListOf<MutableList<Int>>()
        var b2 = mutableListOf<MutableList<Int>>()

        for (i in 0..n-1) {
            b.add(mutableListOf(a[i], i))
        }
        b2 = b.sortedWith(compareBy({it[0]}, {it[1]})).toMutableList()
        
        for (i in n - 2 downTo 0) {
            var add = minOf(d, b2[i + 1][0] - b2[i][0] - 1)
            b2[i][0] += add
            d -= add
        }
        if (d > 0) {
            val totaladd = d / n
            var r = d % n
            for (i in n - 1 downTo 0) {
                b2[i][0] += totaladd
                if (r > 0) {
                    b2[i][0] += 1
                    r -= 1
                }
            }
        }
       
        b2 = b2.sortedWith(compareBy({it[1]}, {it[0]})).toMutableList()
        for (i in 0..n-1) {
            print((b2[i][0] - a[i]).toString() + " ")
        }
        println("")
    }
}