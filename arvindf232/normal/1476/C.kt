/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 * max interval sums or
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.absoluteValue

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
    fun nextLong(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextString():String{
        if (c == NC) c = char
        val ret = StringBuilder()
        while (true){
            c = char
            if(!isWhitespace(c)){ break}
        }
        ret.appendCodePoint(c.toInt())
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.appendCodePoint(c.toInt());

        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
}
class reading{
    companion object{
        var jin = FastScanner()
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{ return reading.jin.nextInt() }
fun getLong():Long{ return reading.jin.nextLong() }
fun getLine(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getLineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getString():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}

/*
3
4
3 4 3 3
-1 1 2 2
-1 2 3 3
 */

fun main() {
    cases{
        val n = getInt()
        val size = getLineL(n)
        val A = getLineL(n)
        val B = getLineL(n)

        val bad = BooleanArray(n-1){
            B[it+1] == A[it+1]
        }
        val added = LongArray(n-1){
            size[it] - ((B[it+1] - A[it+1]).absoluteValue - 1)
        }
        val start = LongArray(n-1){
            (B[it+1] - A[it+1]).absoluteValue + 1
        }


        fun ask(from:Int,to:Int):Long{
            var ans = 0L
            val offSet = from
            val segTo = LongArray(to-from+1)

            var last = size[to]
            segTo[segTo.lastIndex] = last

            for(i in to - 1 downTo from){


                last = maxOf(last + added[i],size[i])
                segTo[i-offSet] = last
                val ret = segTo[i-offSet+1] + start[i]
                ans = maxOf(ans,ret)
            }
            return ans

        }
        var ret = 0L
        var from = 0
        for(i in 0 until n){
            if(i == n-1 || bad[i]){
                ret = maxOf(ret,ask(from,i))
                from = i
            }
        }
        put(ret)
//        ask(0,3)

    }
    done()
    // Write your solution here
}