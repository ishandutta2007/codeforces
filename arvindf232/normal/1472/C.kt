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


fun main() {
    cases{
        val n = getInt()
        val arrs = getLine()

        val endIn = MutableList<Long>(n,{0})

        for( i in arrs.lastIndex downTo 0){
           val a = arrs[i]
            if(a + i >= n){
                endIn[i] = a + i
            }else{
                endIn[i] = endIn[i+a.toInt()]
            }
        }
        var finalScore = 0L
        for((k,a) in arrs.withIndex()){
            val score = endIn[k] - k
            finalScore = maxOf(finalScore,score)
        }
        put(finalScore)
    }
    done()
    // Write your solution here
}