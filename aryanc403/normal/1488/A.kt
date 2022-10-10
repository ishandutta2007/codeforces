fun min(x:Long, y:Long):Long{
    if (x>y){
        return y
    }
    return x
}

fun sod(y:Long):Long{
    if (y==0.toLong()){
        return 0.toLong()
    }
    return sod(y/10)+y%10
}


fun main() {
    val TC = readLine()!!.toInt()
    for (j in 0 until TC) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        println(sod(y/x)+y%x)
    }
}