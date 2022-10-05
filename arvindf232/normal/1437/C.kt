import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.abs

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
        val arr = getLine().sorted()

        var done = MutableList<Int>(401,{x -> 0}) // -200
        var pointer = 0

        for(i in 0 until 200){
            done[i] = 100000000
        }

        for(v in arr){
            val leftMin = MutableList<Int>(0,{x -> 0})

            var current = 100000000
            for(a in done){
                current = minOf(current,a)
                leftMin.add(current)
            }

            val newDone = MutableList(401,{x -> 0})
            for(i in -200..200){
                val couldUseUpto = maxOf((i) + (v - pointer) - 1,-200)
                val shouldUse = minOf(couldUseUpto+200,400)
                val cost = leftMin[shouldUse.toInt()] + abs(i)
                val index = i + 200
                newDone[index] = cost

            }
//            val result = newDone.withIndex().minByOrNull { x -> x.value }!!
//            put("${result.index - 200 + v} ${result.value}")




            pointer = v.toInt()
            done = newDone
        }
//        put("OK")
        put(done.minOrNull()!!)

    }
    done()
    // Write your solution here
}

// no greeddy

// 2
//[1, 1, 1, 3, 4, 5, 8, 8, 8, 9, 11, 11, 11, 12, 13, 15, 19, 21, 21, 21, 21]

// 0,1,2,3,4,5,6,7,8,9