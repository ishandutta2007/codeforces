/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
1,4 divide

 n , n + 3, n +6


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

fun isPrime(n:Int):Boolean{
    for (i in 2..n){
        if( i * i > n){
            break
        }
        if(n % i == 0 ){
            return false
        }
    }
    return true
}

fun main() {
    cases{
        val n = getInt()
        var selecting = 0


        val base = if(n % 2 == 0) (n+3) else (n+6)
        val TwoThrees = (n %2 != 0 )

        for(k in 0..1000){
            if(isPrime((base + 2 * k).toInt())) {
                selecting = k
                break
            }
        }
        for(i in 0 until n){
            val ret = mutableListOf<Int>()
            for(j in 0 until n){
                var new = if((i+j)%n == 0) (4 + 2 * selecting) else 1
                if(TwoThrees && (i+j)%n == 1){
                    new = 4
                }
                ret.add(new)
            }
            put(ret.joinToString(" ") )
        }
    }
    done()
    // Write your solution here
}