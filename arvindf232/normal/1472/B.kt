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
        val t = getInt()
        val arrs = getLine()

        val counts = mutableMapOf<Int,Int>()
        counts[1] = 0
        counts[2] = 0

        for(a in arrs){
            counts[a.toInt()] = counts.getOrDefault(a.toInt(),0) + 1
        }
        val sum = arrs.sum()

        var result = false
        if(sum % 2L == 1L){
            result = false
        }else if(counts[1]!! >= 1){
            result = true
        }else{
            result = (sum % 4L == 0L)
        }
        put(if(result)"YES" else "NO")


    }
    done()
    // Write your solution here
}