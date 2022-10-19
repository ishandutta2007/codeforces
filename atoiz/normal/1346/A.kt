fun main(vararg args: String) {
    val t = readLine()!!.toInt()
    for (i in 0 until t)  {
        val (n, k) = readLine()!!.split(' ').map(String::toInt)
        val x = n / (1 + k + k * k + k * k * k)
        val output = "%d %d %d %d".format(x, x * k, x * k * k, x * k * k * k)
        println(output)
    }
}