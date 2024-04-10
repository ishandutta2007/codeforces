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

inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}


fun main() {
    val t = getInt()
    repeat(t){

        val (n,x) = getLine()
        val A = getLine()
        val B = getLine()
        if(it != t-1){
            val s = reading.jin.readLine()
        }


        val BX = B.reversed()
        val stuff:List<Long> = A.zip(BX).map{ (x,y) -> x + y }
        val result:Long = stuff.max()!!
        val final = (result <= x)

        put(if(final) "Yes" else "No")
    }
    done()
    // Write your solution here
}