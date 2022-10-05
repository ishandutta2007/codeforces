/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Integer.min
import java.lang.Math.max

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
fun Line():String{
    return reading.jin.readLine()
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
        val (a,b) = getLine()
        var c0:Long = 0
        var c1:Long = a.toLong()
        val str = Line()
        for(c in str){
            if(c == '0'){
                val nc1 = c1 + b
                val nc0 = minOf(c0,c1)
                c0 = nc0
                c1 = nc1
            }else{
                c1 = minOf(c1,c0+a)
                c0 = 100000000000
            }
        }
        put(minOf(c0,c1))

    }
    done()
    // Write your solution here
}