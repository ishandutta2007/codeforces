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
fun getLineL():List<Long>{
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
        val (n,x) = getLineL()

        val things = getLineL()
        val modA = things.toMutableList()

        var total = things.sum()
        outer@ for(c in 1..100){
            for(i in modA.indices){
                if(modA[i] % x == 0L){
                    modA[i] = modA[i] / x
                    total += things[i]
                }else{
                    break@outer
                }
            }
        }

        put(total)
    }
    done()
    // Write your solution here
}