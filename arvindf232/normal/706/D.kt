import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
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
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}

fun main(){
    val q = getint()

    val sa = TreeMap<Int,Int>()

    fun has(l:Int,r:Int):Boolean{
        val k = sa.ceilingKey(l) ?: return false
        return k <= r
    }
    sa[0] = 1

    repeat(q){
        val c = getstr()
        val x = getint()

        if(c == "+"){
            sa[x] = sa.getOrDefault(x,0) + 1
        }else if(c == "-"){
            sa[x] = sa[x]!! -1
            if(sa[x] == 0){
                sa.remove(x)
            }
        }else{
            var i = 29
//            while(i > 0){
//                if((1 shl i) and x > 0){
//                    break
//                }
//                i -= 1
//            }
            var lower  = 0
            var upper = (1 shl (i+1)) - 1

            for(t in i downTo 0){
                val bit = ((1 shl t) and x) > 0

                var mid = (lower + upper + 1)/2 - 1

                val a1 = has(lower,mid)
                val a2 = has(mid+1, upper)
                var take2:Boolean = false


                if(bit){
                    if(a1){
                        take2 = false
                    }else{
                        take2 = true
                    }

                }else{
                    if(a2){
                        take2 = true
                    }else{
                        take2 = false
                    }
                }
                if(a2){
                    val x =0
                }
//                put("${bit}bit  ${a1} ${a2} ${lower} ${upper}")

                if(take2){
                    lower = mid + 1
                }else{
                    upper = mid
                }
            }
            put(lower xor x)
        }
    }
    done()
}

// 2 minutes reading
// 3 minutes coding
// 2 minutes finding debug