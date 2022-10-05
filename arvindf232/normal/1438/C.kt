/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
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
        val (n,m) = getLine()
        var bad = true

        repeat(n){
            val ret = mutableListOf<Int>()
            var good = true
            for(x in getLine()){
                val iseven = (x % 2) == 0
                ret.add(x + if(good xor bad xor iseven) 1 else 0)
                good = !good
            }
            println(ret.joinToString(" "))
            bad = !bad
        }

    }
    // Write your solution here
}