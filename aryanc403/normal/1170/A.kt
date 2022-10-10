fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        val b = minOf(x,y)-1;
        val c = maxOf(x,y)-b;
        println("1");
        println(b);
        println(c);
    }
}