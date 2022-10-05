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
            ret.appendCodePoint(c.toInt());
            if(isWhitespace(c)){ break}
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


inline fun cases(ask:()->Unit) {
    val t = getInt()
    repeat(t) {
        ask()
    }
}

val p = 1000000007L
infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
// any start , end in specific place
fun main() {

    val xx = mutableListOf<LongArray>()
//    put(x[0][0])
    val n = getInt()
    val k = getInt()
    val q = getInt()


    var start = LongArray(n) { 1L }
    xx.add(start)

    repeat(k){
        val additionalArray = LongArray(n){1L}
        for(i in 0 until n){
            additionalArray[i] = ((if(i>0) start[i-1] else 0L) + (if(i<start.lastIndex) start[i+1] else 0L)) % p
//            mul[i] = (mul[i] + additionalArray[i]) % p
        }
        xx.add(additionalArray)
        start = additionalArray
    }
    val mul = LongArray(n)
    for(i in 0..k){
        for(j in 0 until n){
            val x = xx[i][j]
//            println(xx[1].toString())
//            println(xx[2].toString())
//            println(k-i)
            val y = xx[k-i][j]
            mul[j] = (mul[j] + (xx[i][j] modM xx[k-i][j])) % p
        }
    }


    val weights = getLineL(n).toMutableList()
    var total = 0L
    for(i in 0 until n){
        total += weights[i] modM mul[i]
    }
//    put(total)

    repeat(q){
        val i = getInt() - 1
        val cha = getLong()

        val old = mul[i] modM weights[i]
        val new = mul[i] modM cha

        total = (total - old + new + p) % p
        put(total)

        weights[i] = cha
    }
    done()

    // Write your solution here
}