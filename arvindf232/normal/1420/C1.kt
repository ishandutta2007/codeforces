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
fun getLong():Int{ return reading.jin.nextInt() }
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
    cases{
        val n = getInt()
        val q = getInt()
        val arr = getLine(n).toIntArray()

        fun value(i:Int):Long{
            if(arr.size == 1){
                return arr[i].toLong()
            }
            if(i == 0){
                if(arr[i] > arr[1]){
                    return arr[0].toLong()
                }else{
                    return 0
                }
            }else if(i == arr.lastIndex){
                if(arr[i] > arr[i-1]){
                    return arr[i].toLong()
                }else{
                    return 0L
                }

            }else{
                if(arr[i] < arr[i+1] && arr[i] < arr[i-1]){
                    return -arr[i].toLong()
                }else if(arr[i] > arr[i+1] && arr[i] > arr[i-1]){
                    return arr[i].toLong()
                }else{
                    return 0L
                }
            }
        }
        var basic = (0 until arr.size).map{value(it)}.sum()
        put(basic)
        repeat(q){
            val u1 = getInt()-1
            val u2 = getInt()-1

            val changes = mutableSetOf<Int>(u1-1,u1,u1+1,u2-1,u2,u2+1)
            changes.remove(-1)
            changes.remove(n)

            val previous = changes.map{value(it)}.sum()

            val a1 = arr[u1]
            val a2 = arr[u2]

            arr[u1] = a2
            arr[u2] = a1

            val new = changes.map{value(it)}.sum()

            basic += (new - previous)
            put(basic)

        }

    }
    done()
    // Write your solution here
}