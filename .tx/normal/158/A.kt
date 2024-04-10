fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(" ").map(String::toInt)
    val a = readLine()!!.split(" ").map(String::toInt)
    println(a.filter { it > 0 && it >= a[k - 1] }.size)
}