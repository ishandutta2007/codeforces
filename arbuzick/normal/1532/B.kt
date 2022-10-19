fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        var (a, b, k) = readLine()!!.split(' ').map( {it.toLong()} )
        var ans = (k + 1) / 2 * a - k / 2 * b;
        println(ans)
    }
}