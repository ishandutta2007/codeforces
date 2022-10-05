import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.abs

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

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }

fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
    get() = this.joinToString("")
fun just(a:Boolean){
    put(if(a)"YES" else "NO")
}

inline fun cases(ask:()->Unit){
    val t = getint()
    repeat(t){
        ask()
    }
}


fun main(){
    cases case@{

    val n = getint()
    val k = getint()

    val x = mutableListOf<Int>()
    val y = mutableListOf<Int>()

    repeat(n){
        x.add(getint())
        y.add(getint())
    }
        
        val co = x zip y 

    val ans = co.any{
        val (a,b) = it 
        co.all{
            val (c,d) = it 
            val m = abs(c-a) + abs(d-b)
            m <= k
        }
    }
        put(if(ans)"1" else "-1")


//        val things = arr.groupBy { it }.mapValues { it.value.toSet()}
//
//        while(things.any()){
//            val a = things.an
//        }
//        val things = arr.withIndex().sortedBy{it.value}
//
//        for(i in 0 until n/2){
//            put(things[i].index+1 )
//            put(things[n-i-1].index+1)
//        }


    }
    done()
}

// 2 minutes reading
// 3 minutes coding
// 2 minutes finding debug