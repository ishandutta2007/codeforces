/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * free -> filled
 * free -> free
 * one filled ->
 */
//import com.sun.org.apache.xpath.internal.operations.Bool
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


fun transition(from:Int,current:Int):List<Int>{
    if(from == 3){
        if(current == 3){
            return listOf(0,3)
        }else{
            return listOf(current)
        }
    }else{
        if(from and current == 0 && from != 0) {
            return listOf()
        }
        return listOf(current xor from)
    }
}


fun main() {
    cases{
        getString()
        val (n,m) = getLine()
        val R1 = mutableSetOf<Int>()
        val R2 = mutableSetOf<Int>()
        val All = mutableListOf<Int>()

        repeat(m.toInt()){
            val (a,b) = getLine()

            if(a == 1L){
                R1.add(b.toInt() -1 )
            }else{
                R2.add(b.toInt() -1 )
            }
            All.add(b.toInt() - 1)
        }

        val sA = All.sorted()


        var previousI = 0
        val previous = mutableMapOf<Int,Boolean>(0 to true, 1 to false, 2 to false, 3 to false)
        for(i in sA){

            if(i - previousI > 1){
                if(previous[0]!! or previous[3]!!){
                    previous[3] = true
                    previous[0] = true
                }
                val toggle = (i-previousI) % 2 == 0
                if(toggle){
                    val a1 = previous[1]!!
                    val a2 = previous[2]!!
                    previous[2] = a1
                    previous[1] = a2
                }
            }
            previousI = i

            val r1 = 1 - if(R1.contains(i)) 1 else 0
            val r2 = 1 - if(R2.contains(i)) 1 else 0
            val total = r1.toInt() * 2 + r2.toInt() * 1

            val new = mutableMapOf<Int,Boolean>()
            for(l in 0..3){
                new[l] = false
            }

            for((k,v) in previous){
                if(v == true){
                    val news = transition(k,total)
                    for(a in news){
                        new[a] = true
                    }
                }
            }
            for((k,v) in new){
                previous[k] = v
            }
        }

        val result = previous[0]!! ||  previous[3]!!
        put(if(result) "YES" else "NO")




    }
    done()
    // Write your solution here


}