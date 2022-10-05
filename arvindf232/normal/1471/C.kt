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
        val (n,m) = getLineL()
        val friends = getLineL()
        val presents = getLineL()

        val FS = friends.sortedDescending()
        val FSPrice = FS.map{presents[it.toInt() - 1]}

        val preFSP = mutableListOf<Long>()

        var current = 0L
        for(i in FSPrice.indices){
            current += FSPrice[i]
            preFSP.add(current)
        }

        val prePresentPrice = mutableListOf<Long>()

        var current2 = 0L
        for(i in presents.indices){
            current2 += presents[i]
            prePresentPrice.add(current2)
        }

        val basePrice = FSPrice.sum()
        var ret = basePrice

        for(i in 0..minOf(preFSP.size,presents.size)){



            val presentsPrice = if(i>0) prePresentPrice[i-1] else 0
            val savedPrice = if(i>0) preFSP[i-1] else 0

            val final = basePrice + presentsPrice - savedPrice
            ret = minOf(final,ret)
        }
        put(ret)

    }
    done()

    // Write your solution here
}