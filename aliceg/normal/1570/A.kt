fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (a, b) = readLine()!!.split(' ').map { it.toInt() }
        println(a + b)
    }
}