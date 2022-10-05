/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 iff last colour is valid
and sufficent replacement otherwise


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



fun main() {
    cases case@{
        val n = getInt()
        val m = getInt()
        val A = getLine(n)
        val B = getLine(n)
        val C = getLine(m)

        val hasColour = IntArray(n+1)

//        val colourOccurence = In/

        val needColourCount = mutableMapOf<Int,MutableList<Int>>()
        val CLS = mutableMapOf<Int,MutableList<Int>>()

        for((i,c) in B.withIndex()){
            hasColour[c] = i + 1
        }

        for(i in A.indices){
            if(B[i] != A[i]){
                val cl = B[i]
                if(needColourCount[cl] == null){
                    needColourCount[cl] = mutableListOf()
                }
                needColourCount[cl]!!.add(i + 1)
            }
        }

        for((i,a) in C.withIndex()){
//            hasColour[a] += 1

            if(CLS[a] == null){
                CLS[a] = mutableListOf()
            }
            CLS[a]!!.add(i + 1)
        }

        val lastColour = C.last()
        if(hasColour[lastColour] == 0){
            put("NO")
            return@case
        }

        val ret = IntArray(m+1)
        for((k,need) in needColourCount) {
            val cR = CLS[k]
            if (cR == null || cR.size < need.size) {
                put("NO")
                return@case
            }
            for ((j, a) in cR.takeLast(need.size).withIndex()) {
                ret[a] = need[j]
            }
        }
        if(ret[m] == 0){
            val any = hasColour[C[m-1]]
            ret[m] = any
        }
        put("YES")
        val lastPaint = ret[m]
        for(i in 1..ret.lastIndex){
            put(if(ret[i] != 0)ret[i] else lastPaint)
        }

    }
    done()
    // Write your solution here
}