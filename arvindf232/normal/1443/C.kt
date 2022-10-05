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
fun getLine():List<Int>{
    return reading.jin.readLine().split(" ").map { it.toInt() }
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
        val A = getLine()
        val B = getLine()
        val things = A.zip(B).sortedBy { - it.first }

        var sumNow:Long = 0
        var bestNow:Long = 1000000000
        for((a,b) in things){

            bestNow = minOf(bestNow,maxOf(a.toLong(),sumNow))
            sumNow += b.toLong()
//            put(" ${bestNow} ${sumNow}")
        }
        bestNow = minOf(bestNow,sumNow)
        put(bestNow)

    }
    done()

    // Write your solution here
}