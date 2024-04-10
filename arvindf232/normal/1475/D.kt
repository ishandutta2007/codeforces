/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

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
fun prefixSum(arr:List<Long>):MutableList<Long>{
    val ret = mutableListOf<Long>()

    var previous = 0L
    for(a in arr){
        previous += a
        ret.add(previous)
    }
    return ret
}

fun main() {

    cases case@{
        val n = getInt()
        val m = getLong()
        val memArr = getLineL(n)
        val conArr = getLine(n)

        val A2 = mutableListOf<Long>()
        val A1 = mutableListOf<Long>()

        for(i in 0 until n){
            if(conArr[i] == 2){
                A2.add(memArr[i])
            }else{
                A1.add(memArr[i])
            }
        }
        A2.sortDescending()
        A1.sortDescending()

        val A2S = prefixSum(A2)
        val A1S = prefixSum(A1)

        var ret = Int.MAX_VALUE
        var p2 = -1
//        val p1 = 0
        outer@ for(p1 in A1.lastIndex downTo -1){
            val p1Freed = if(p1 >= 0) A1S[p1] else 0

            while(p1Freed + (if(p2 >= 0) A2S[p2] else 0) <  m){
                if(p2 < A2.lastIndex){
                    p2 += 1
                }else{
                    break@outer
                }

            }
            ret = minOf(ret, (1+p1) + (1+p2) * 2)
        }
        if(ret != Int.MAX_VALUE){
            put(ret)
        }else{
            put(-1)
        }



    }
    done()
    // Write your solution here
}