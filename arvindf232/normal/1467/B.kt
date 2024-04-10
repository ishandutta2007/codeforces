/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

change number to 0

what choices are good

modify 3 things

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
    cases {
        val n = getInt()
        val things = IntArray(n)
        repeat(n){
            things[it] = getInt()
        }

        fun value(i:Int):Int{
            if(i == 0 || i == things.lastIndex){
                return 0
            }else if(things[i] > things[i-1] && things[i] > things[i+1]){
                return 1
            }else if(things[i] < things[i-1] && things[i] < things[i+1]){
                return 1
            }else{
                return 0
            }
        }
        val basic = (things.indices).map{value(it).toLong()}.sum()
        var ret = basic

        for( i in things.indices){
            val right = minOf(i+1,things.lastIndex)
            val left = maxOf(i-1,0)
            val toChange = left..right


            val p1 = if(i > 0 )things[i-1] else 0
            val p2 = if(i < things.lastIndex) things[i+1] else 0
//            val p3 = 0
            val tries = listOf<Int>(p1,p2)

            for( t in tries){
                val old = toChange.map { value(it).toLong() }.sum()
                val before = things[i]
                things[i] = t
                val new = toChange.map { value(it).toLong() }.sum()

                val ans = basic - old + new

                things[i] = before
                ret = minOf(ret,ans)

            }

        }
        put(ret)

    }
    done()
    // Write your solution here
}