/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 think in prime sets


 A B C D

 eexcatly equal


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

var knownPrimes = mutableListOf<Int>()

fun isPrime(a:Int):Boolean{
    for(i in 2..a){
        if(i * i > a){
            return true
        }
        if( a% i == 0){
            return false
        }
    }
    return false
}
fun writePrimes(){
    for(i in 1..1000){
        if(isPrime(i)){
            knownPrimes.add(i)
        }
    }
}
fun radical(a:Int):Int{
    var aa = a
    var final = 1
    for(p in knownPrimes){
        var value = 0
        while(aa % p ==0){
            value += 1
            aa = aa/p
        }
        if(value % 2 == 1){
            final *= p
        }
    }
    final *= aa
    return final
}

fun main() {
    writePrimes()
//    radical(8)
    cases{
        val n = getInt()
        val arr = getLine()


        val prestuff = mutableMapOf<Int,Int>()

        for(a in arr){
            val r = radical(a)
//            println("r $r")
            prestuff[r] = prestuff.getOrDefault(r,0) + 1
        }

        val transform = mutableMapOf<Int,Int>()
        for((k,v) in prestuff){
            if(v % 2 == 0){
                transform[1] = transform.getOrDefault(1,0) + v
            }else{
                transform[k] = transform.getOrDefault(k,0) + v
            }
        }

        val preMax = prestuff.values.maxOrNull()!!
        val postMax = transform.values.maxOrNull()!!

        val q = getInt()
        repeat(q){
            val ask = reading.jin.readLine().toLong()
            put(if(ask > 0) postMax else preMax)
        }
    }
    done()
    // Write your solution here
}