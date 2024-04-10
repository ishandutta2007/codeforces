fun solve() {
    val (a, b) = readLine()!!.split(' ').map(String::toInt)
    val x = minOf(a, b) - 1
    println(x.toString() + " " + (a - x).toString() + " " + (b - x).toString())
}

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        solve()
    }
}