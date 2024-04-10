

fun main() {
    var q = readLine()!!.toInt()
    for (i in 0 until q) {
        var args = readLine()!!.split(' ').map { it.toLong() }
        var n = args[0]
        var a = args[1]
        var b = args[2]
        if (a * 2 <= b) {
            println(n * a)
        } else {
            println(n / 2 * b + n % 2 * a)
        }
    }
}