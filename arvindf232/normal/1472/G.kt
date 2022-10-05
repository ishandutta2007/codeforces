/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import java.util.Queue

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
        getString()
        val (n,m) = getLine()
        val G = mutableMapOf<Int,MutableList<Int>>()
        val pG = mutableMapOf<Int,MutableList<Int>>()

        for(i in 1..n){
            G[i] = mutableListOf()
            pG[i] = mutableListOf()
        }

        repeat(m){
            val(a,b) = getLine()
            G[a]!!.add(b)
            pG[b]!!.add(a)
        }

        val distances = MutableList<Int>(n+1,{300000})
        distances[1] = 0

        val toDo:Queue<Int> = LinkedList<Int>()
        val explored = mutableSetOf<Int>()
        toDo.add(1)
        explored.add(1)

        while(toDo.size > 0){

            val x = toDo.remove()

            val things = G[x]!!
//            println(distances[x])
            for( a in things){
                if(!explored.contains(a)){
                    explored.add(a)
                    toDo.add(a)

                }
                distances[a] = minOf(distances[a],distances[x]+1)
            }
        }

        val minReach = distances.toMutableList()

        for((v,ns) in G){
            for(n in ns){
                if(distances[n] <= distances[v]) {
                    minReach[v] = minOf(minReach[v], distances[n])
                }
            }
        }

        val finalAnswer = minReach.toMutableList()

        val things = distances.withIndex().sortedBy { it.value }.reversed()

        for((v,d) in things){

            if(v == 0){
                continue
            }

            for(p in pG[v]!!){
                if(distances[p] < distances[v]){
                    finalAnswer[p] = minOf(finalAnswer[v],finalAnswer[p])
                }
            }
        }

        val ret = (1..n).map{finalAnswer[it]}.joinToString(" ")

        put(ret+ " ")
    }
    done()
    // Write your solution here
}