/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
fun getInt():Int{
    return readLine()!!.toInt()
}
fun getLine():List<Int>{
    return readLine()!!.split(" ").map { it.toInt() }
}

fun ask(xx:List<Int>,yy:List<Int>):Int{
    val xx1 = xx.toSet()
    var count = 0
    for (i in yy){
        if(i in xx1){
            count++
        }
    }
    return count
}

fun main() {
    val t = getInt()
    repeat(t){
        val (n,m) = getLine()
        val xx = getLine()
        val yy = getLine()
        println(ask(xx,yy))
    }
    // Write your solution here
}