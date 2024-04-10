/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
fun getInt():Int{
    return readLine()!!.toInt()
}
fun getLine():List<Int>{
    return readLine()!!.split(" ").map { it.toInt() }
}

inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}

fun main() {
    cases{
        val n = getInt()
        val result = List(n,{1})
        println(result.joinToString(" "))
    }
    // Write your solution here
}