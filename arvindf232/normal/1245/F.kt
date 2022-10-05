import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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
    fun rerouteInput(){
        if(warningActive){
            System.err.println("Not accepting inputs!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
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
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

const val HighestBit = 30
inline fun Int.eachBits(act:(Int)->Unit){
    for(i in HighestBit - 1 downTo 0){
        if(this and (1 shl i) != 0){
            act(1 shl i)
        }
    }
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
    for(i in HighestBit -1  downTo 0){
        if(this and (1 shl i) != 0){
            act(i)
        }
    }
}
inline fun Int.submask(act:(Int)->Unit){
    var here = this
    while (here > 0) {
        act(here)
        here = (here - 1) and this
    }
    act(here)
}
inline fun Int.eachDown1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) != 0){
            act(this - (1 shl i))
        }
    }
}
inline fun Int.eachUp1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) == 0){
            act(this + (1 shl i))
        }
    }
}
fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}

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
fun assert(a:Boolean){if(!a){
    throw Exception("Failed Assertion")}}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
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
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }

const val singleCase = false
const val withBruteForce = false
const val randCount = 100
fun Int.allexceptlast(a:Int):Int{
    val mask = (1 shl a) - 1
    return (this and (mask).inv())
}
inline fun Int.breakrun(act:(Int,Int)->Unit){
    for(k in 30 downTo 0){
        if(!this.hasElement(k)) continue
        act(allexceptlast(k + 1),k)
    }
}
data class br(val start:Int,val i:Int){// binary range
init{
    kotlin.assert(start and ((1 shl i) - 1) == 0)
}
    fun print(){
        println("[$start, ${start + (1 shl i) - 1 }]")
    }
}
fun rangeIntervalBreaks(left:Int,right:Int):MutableList<br> {
    val ret = mutableListOf<br>()
    var left = left
    val right = right + 1
    for(k in 0 until HighestBit){
        if(left.hasElement(k) && left + (1 shl k) <= right){
            ret.add(br(left,k))
            left += 1 shl k
        }
    }
    for(k in HighestBit -1 downTo 0 ){
        if(right.hasElement(k) && !left.hasElement(k)){
            ret.add(br(left,k))
            left += 1 shl k
        }
    }
    return ret
}

fun main(){

    val powerOf3 = LongArray(35)
    for(i in 0 until powerOf3.size){
        if(i == 0) powerOf3[0] = 1L
        else powerOf3[i] = powerOf3[i-1] * 3
    }

    val preorder = List(32){LongArray(32)}
    for(i in 0 until 32){
        for(j in 0 until 32){
            val m = minOf(i,j)
            val dif = maxOf(i,j) - m
            preorder[i][j] = powerOf3[m] * (1L shl dif)
        }
    }
    fun brute(a:Int,b:Int):Long{
        var ret = 0L
        for(i in a..b){
            for(j in a..b ){
                if(i and j == 0){
                    ret ++
                }
            }
        }
        return ret
//        put(ret)
    }
    fun brutezero(a:Int,b:Int):Long{
        var ret = 0L
        for(i in 0 until a ){
            for(j in 0 until b  ){
                if(i and j == 0){
                    ret ++
                }
            }
        }
        return ret
//        put(ret)
    }



    fun fullquery(a:Int,b:Int):Long {
        var ret = 0L
        for(x in rangeIntervalBreaks(a,b)){
            for(y in rangeIntervalBreaks(a,b)){
                val v = x.start
                val w = y.start
                val i = x.i
                val j = y.i
                if( v and w > 0 ){

                }else{
                    val swap = i > j
                    var v = v
                    var w = w
                    var i = i
                    var j = j
                    if(swap){
                        i = j.also { j = i  }
                        v = w.also{ w = v}
                    }

                    val free = minOf(i,j)
                    val mask = ( 1 shl j) - (1 shl i)
                    val availble = (j -i ) -  (v and mask).countOneBits()

                    val count = powerOf3[free] * (1L shl availble)
//                    var BFcount = 0L

//                    for(x in 0 until (1 shl i) ){
//                        for(y in 0 until (1 shl j)){
//                            val xx = x + v
//                            val yy = y + w
//                            if(xx and yy == 0) BFcount ++
//                        }
//                    }
//                    assert(BFcount == count)

                    ret += count
                }
            }
        }
//        val bs = brutezero(a,b)
//        assert(ret == bs)
        return ret
    }
//    fun symmetricQuery(a:Int,b:Int):Long{
//        return fullquery(b,b) - 2 * fullquery(a-1,b) + fullquery(a-1,a-1)
//    }
//
//    println(brute(1,2))
//    println(brute(1,4))
//    println(brute(2,4))


    solve.cases{
        val a = getint()
        val b = getint()
        put(fullquery(a,b))
//        println(brute(a,b))

    }
    done()
}
/*

mistake: not translational invariant
have to be digit DP but annoying

 */