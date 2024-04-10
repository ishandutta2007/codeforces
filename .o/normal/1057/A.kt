fun main(args: Array<String>) {
 val n = readLine()!!.toInt()
 val a = ("-1 0 " + readLine()!!).split(" ").map{ it.toInt() }
 println(generateSequence(n, { a[it].takeIf{ it > 0 } }).toList().reversed().joinToString(" "))
}