/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools



iff
    - S connected
    - vextex covered
 */
//import Main.FastReader
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import java.io.*
import kotlin.concurrent.thread
import kotlin.system.measureTimeMillis

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}
//    fun main(args: Array<String>) {
//        val s = FastReader()
//        var n = s.nextInt()
//        val k = s.nextInt()
//        var count = 0
//        while (n-- > 0) {
//            val x = s.nextInt()
//            if (x % k == 0) count++
//        }
//        println(count)
//    }


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
    val jin = FastScanner()
//        val s = FastReader()
        val t = jin.nextInt()
//    val t = 1
        repeat(t) {
//            val n = 300000
//            val m = 300000
            val n = jin.nextInt()
            val m = jin.nextInt()
            val time = measureTimeMillis {
                val G = Array(n + 1) { mutableListOf<Int>() }
//                for (i in 1..n) {
//                    G[i] = mutableListOf()
//                }
                repeat(m) {
//            val (a,b) = getLine()
                    val a = jin.nextInt()
                    val b = jin.nextInt()
//                val a = it + 1
//                val b = (it/2) + 1
                    G[a]!!.add(b)
                    G[b]!!.add(a)
                }


                val banned = IntArray(n + 1)
                val picked = mutableListOf<Int>()
                val toDo = ArrayDeque<Int>()
                val explored = IntArray(n + 1)
                toDo.add(1)
                explored[1] = 1
                var total = 1

                while (toDo.size > 0) {
                    val x = toDo.removeLast()
                    val things = G[x]!!
//            println(distances[x])


                    val picking = banned[x] == 0

                    if (picking) {
                        banned[x] = 1
                        picked.add(x)
                    }
                    for (a in things) {
                        if (picking) {
                            banned[a] = 1
                        }
                        if (explored[a] == 0) {
                            explored[a] = 1
                            total += 1
                            toDo.add(a)

                        }
//            distances[a] = minOf(distances[a],distances[x]+1)
                    }
                }
                if (total != n) {
                    put("NO")
                } else {
                    put("YES")
                    put(picked.size)
                    for (p in picked) {
                        put(p)
                    }
//            put(picked.joinToString(" "))
                }
            }
//            put(time)

        }
        done()



    // Write your solution here
}