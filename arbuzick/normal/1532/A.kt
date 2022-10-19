fun main() {
    var t = readLine()!!.toInt()
    for (i in 0 until t) {
        var (a, b) = readLine()!!.split(' ').map( {it.toInt()} )
        println(a + b)
    }
}