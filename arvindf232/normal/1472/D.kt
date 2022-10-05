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
        val arr = getLine()

        val stuff = arr.sorted().reversed()
        var bannedTotal = 0L

        for(i in 1 until stuff.size step 2){
            bannedTotal += stuff[i]
        }

        var baseScore = 0L
        for(a in arr){
            if(a%2L == 0L){
                baseScore += a
            }
        }
        val finalScore = baseScore - bannedTotal
        var jud = ""

        if(finalScore == 0L){
            jud = "Tie"
        }else if(finalScore > 0L){
            jud = "Alice"
        }else{
            jud = "Bob"
        }
        put(jud)
    }
    done()
    // Write your solution here
}