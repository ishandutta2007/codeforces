import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    private val IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf) // no need for checked exceptions
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
        while (c in '0'..'9') {
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
        while (c in '0'..'9') {
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
        ret.append(c)
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.append(c)
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
get() = this.joinToString("")
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    var str = ""
    if(this is String){ str = this
    }else if(this is Int){ str = this.toString()
    }else if(this is Long){ str = this.toString()
    }
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){throw Exception("Bad programme")} // because assertion does not work
fun main(){

    cases{
        val n = getint()
        val things = List<List<Int>>(n){
            val a = getint()
            getline(a).map{it - 1}
        }
        val requisite = IntArray(n)
        for(i in 0 until n){
            requisite[i] = things[i].size
        }
        val inverseRequire = List<MutableList<Int>>(n){ mutableListOf()}
        for((i,a) in things.withIndex()){
            for(c in a){
                inverseRequire[c].add(i)
            }
        }
        var toread = PriorityQueue<Int>()
        var nextQueue = PriorityQueue<Int>()
        for(i in 0 until n){
            if(requisite[i] == 0){
                toread.add(i)
            }
        }
        var amountRead = 0
        var cycles = 0
        while(true){
            cycles ++
            while(toread.isNotEmpty()){
                val first = toread.remove()
                amountRead ++
                for(a in inverseRequire[first]){
                    requisite[a] --
                    if(requisite[a] == 0){
                        if(a < first){
                            nextQueue.add(a)
                        }else{
                            toread.add(a)
                        }
                    }
                }
            }
            if(nextQueue.isNotEmpty()){
                toread = nextQueue
                nextQueue = PriorityQueue<Int>()
            }else{
                break
            }
        }
        if(amountRead == n){
            put(cycles)
        }else{
            put(-1)
        }
    }
    done()
    
}