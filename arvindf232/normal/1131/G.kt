import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    var warningActive = true
    var fakein = StringBuilder()

    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
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
    fun rerouteInput(){
        if(warningActive){
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
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
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            currentAnswer = null
            currentBruteAnswer = null
            a()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentBruteAnswer != null){
            checkAnswer()
        }
    }
    fun put2(a:Any){answer(a);put(a) }

    fun bruteAnswer(a:Any){
        currentBruteAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun checkAnswer(){
        if(currentAnswer != currentBruteAnswer){
            throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
        }
        answersChecked ++
    }
}
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
const val huge = 2_727_000_000_000_000_000L // used for seg tree things
val Char.code :Int get() = this.toInt() -  'a'.toInt()

class block(val k:Int, val hs:IntArray, val cs:IntArray){}
class PI(val first:Int, val second:Int)
const val withBruteForce = false
const val randCount = 100

class primitevStacks(val m:Int){
    val s1 = IntArray(m)
    val s2 = IntArray(m)
    var size = 0

    fun add(a:Int, b:Int){

        s1[size] = a
        s2[size] = b
        size ++
    }
    fun isEmpty():Boolean{
        return size == 0
    }
    fun isNotEmpty():Boolean{
        return size != 0
    }
    fun lastFirst():Int{
        return s1[size-1]
    }
    fun lastSecond():Int{
        return s2[size-1]
    }
    fun removeLastA():Int{
        size --
        return s1[size]
    }
    fun removeLastB():Int{
        size --
        return s2[size]
    }

}

fun main(){
    solve.cases{
        val n = getint()
         val m = getint()
        val C = LongArray(m)
        val H = IntArray(m)

        val blocks = mutableListOf<block>()

        repeat(n){
            val k = getint()
            val newblock = block(k,getline(k),getline(k))
            blocks.add(newblock)
        }
        val q = getint()
        var cur = 0
        repeat(q){
            val id = getint() - 1
            val mul = getlong()
            val B = blocks[id]

            for(i in 0 until B.k){
                H[cur + i] = B.hs[i]
                C[cur + i] = B.cs[i] * mul
            }
            cur += B.k
        }
        val leftHit = IntArray(m)
        val firstCover = IntArray(m)
        val ST = primitevStacks(m)
        for(i in m-1 downTo 0){
            while(ST.isNotEmpty() && ST.lastSecond() > i){
                leftHit[ST.removeLastA()] = i + 1
            }
            firstCover[i] = if(ST.isNotEmpty()){ ST.lastFirst()} else -1
            ST.add(i,i-H[i]+1)
        }
        while(ST.isNotEmpty()){
            val a = ST.removeLastA()
            leftHit[a] = 0
        }
        val rightHit = IntArray(m)

        for(i in 0 until m){
            while(ST.isNotEmpty() && ST.lastSecond() < i){
                rightHit[ST.removeLastA()] = i - 1
            }
            ST.add(i,i+H[i]-1)
        }
        while(ST.isNotEmpty()){
            val a = ST.removeLastA()
            rightHit[a] = m - 1
        }

        val DP = LongArray(m){huge}
        var last = 0L
        val minRes = LongArray(m){huge}
        minRes[0] = 0
        for(i in 0 until m){
            //right side
            val r = rightHit[i]
            DP[r] = minOf(DP[r], last + C[i])
            //left side
            val leftCost = minRes[i]
            DP[i] = minOf(DP[i], leftCost + C[i])

            val fc = firstCover[i]
            if(fc != -1){
                if(i != 0)
                    minRes[i] = minOf(minRes[i],DP[i-1])
                minRes[fc] = minOf(minRes[fc],minRes[i])
            }
            last = DP[i]
        }
        put(DP.last())
    }
    done()
}
const val singleCase = true

/*
correct branching to reduce annoyance
first and last on stack
still off by 1 , when the definitions are complex
    still cannot!

 */