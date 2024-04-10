/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

class reading{
    companion object{
        var jin = BufferedReader(InputStreamReader(System.`in`))
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{
    return reading.jin.readLine().toInt()
}
fun getLine():List<Long>{
    return reading.jin.readLine().split(" ").map { it.toLong() }
}
fun getString():String{
    return reading.jin.readLine()
}

inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}

infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}

fun main() {
//    for(i in -10..10){
//        put("${i divCeil 3} ${i}")
//    }

    cases{
        val n = getInt()
        val str = getString()

        var sums = 0
        var to = false
        var first = true
        for(c in str){
            val b = (c == '1')
            if(first){
                sums += 1
                to = b
                first = false
                continue
            }
            if(to == b){
                continue
            }else{
                to = !to
                sums += 1
            }
        }
//        put("sums ${sums} n ${n}")
        val x = n - sums
        put(x divCeil 2 )
    }
    done()
    // Write your solution here
}
// 101001