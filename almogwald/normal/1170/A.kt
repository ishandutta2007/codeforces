fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (a,b)=readLine()!!.split(" ").map { it.toInt()}
        val min = minOf(a,b)
        val max = maxOf(a,b)
        val num1 = min - 1
        val num2 = max - num1
        println("1 $num1 $num2")
    }
}