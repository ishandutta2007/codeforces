
fun solve() {
    var (n, a, b) = readLine()!!.split(" ").map { it.toLong() }
    if(b > 2 * a) {
        b = 2 * a
    }
    println(n/2 * b + (n % 2) * a)
}


fun main(args: Array<String>) {
    //println("Hello World!")
    var t = 1
    t = readLine()!!.toInt()
    for (i in 0 until t) {
        solve()
    }
}