import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var tt = readInt()
    while (tt > 0) {
        tt--
        var (n, s) = readLongs()
        var l : Long = 1
        var r : Long = s
        var ans : Long = 0
        while (r >= l) {
            var mid = (l + r) / 2
            var baz = (s / n)
            if (s % n > 0) baz += 1
            var upper : Boolean = baz <= mid
            var cnt = 1
            var sum = mid
            var foo = mid
            while (mid > 1 && cnt < n) {
                mid = (mid / 2) + mid % 2
                sum += mid
                cnt++
            }
            var lower : Boolean = false
            if (cnt.toLong() == n && sum <= s) lower = true
            if (cnt < n) sum += (n - cnt)
            if (sum <= s) lower = true
            if (lower && upper) {
                ans = foo
                l = foo + 1
            } else {
                if (upper == false) l = foo + 1
                else r = foo - 1
            }
            // print("{$foo} {$sum} {$s}\n")
        }
        println(ans)
    }
}