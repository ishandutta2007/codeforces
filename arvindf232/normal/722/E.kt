import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}

infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}

infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
    return ((this * 1L * b) % p).toInt()
}
infix fun Int.modPlus(b:Int):Int{
    val ans = this + b
    return if(ans >= pI) ans - pI else ans
}
infix fun Int.modMinus(b:Int):Int{
    val ans = this - b
    return if(ans < 0) ans + pI else ans
}
infix fun Int.modDivide(b:Int):Int{
    return this modM (b.inverse())
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}


fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0){
            X = ((1L * X * X) % m).toInt()
            E /= 2
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}

fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E /= 2
        }else{
            Y = (X * Y) % m
            E -= 1
        }
    }
    return Y
}
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
fun Int.inverse():Int{
    return intPow(this,pI-2,pI)
}
//make this int instead
class FACT{
    companion object {
        var store = IntArray(0)
        var invStore = IntArray(0)

        var slowStore:IntArray = IntArray(0)

        fun preCal(upto:Int){
            store = IntArray(upto+1)
            invStore = IntArray(upto + 1 )
            store[0] = 1
            invStore[0] = 1

            for(i in 1..upto) {
                store[i] = store[i-1] modM i
                invStore[i] = invStore[i-1] modM (i.inverse())
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM (n - i)
            }
            for(i in 1..r){
                ret = ret modM (invStore[i])
            }
            return ret
        }

    }
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


const val withBruteForce = false
const val randCount = 100
class cell(val x:Int, val y:Int):Comparable<cell>{
    val DP = IntArray(max)
    override fun compareTo(other:cell):Int {
        return ( this.x + this.y )- (other.x + other.y)
    }
    fun multipleOf(other:cell):Int{
        if((this.x > other.x) || (this.y > other.y)){
            return 0
        }else{
            val xx = other.x - this.x
            val yy = other.y - this.y
            return FACT.choose(xx +yy, xx)
        }
    }

    override fun equals(other:Any?):Boolean {
        if(this === other) return true
        if(javaClass != other?.javaClass) return false

        other as cell

        if(x != other.x) return false
        if(y != other.y) return false

        return true
    }

//    override fun hashCode():Int {
//        var result = x
//        result = 31 * result + y
//        return result
//    }
}
const val max = 24

fun main(){
    FACT.preCal(200_005)
    solve.cases{

        val n = getint()
        val m = getint()
        val k = getint()
        val s = getint()
        val CS = mutableListOf<cell>()
        var bonus = 0
        for(i in 0 until k){
            val c = cell(getint()-1, getint() -1 )
            CS.add(c)
        }
        if(CS.contains(cell(0,0))){
            bonus ++
        }else{
            CS.add(cell(0,0))
        }
        if(CS.contains(cell(n-1,m-1))){
            if(n + m > 2)
            bonus++
        }else{
            CS.add(cell(n-1,m-1))
        }
        CS.sort()
        CS[0].DP[0] = 1

        for(i in 0 until CS.lastIndex){
            val a = CS[i]
            if(i != 0){
                for(level in max-2 downTo 0){
                    a.DP[level+1] = (a.DP[level+1] + a.DP[level].additiveInverse()).snap()
                }
            }

            for(j in i+1 until CS.size){
                val b = CS[j]
                val multiples = a.multipleOf(b).additiveInverse()
                for(level in 0 until max-1){
                    b.DP[level] = (b.DP[level] + (a.DP[level] modM multiples)).snap()
                }
            }
        }
        var base = s
        repeat(bonus){
            base = base divCeil 2
        }
        val paths = FACT.choose(n+m-2, n-1)
        var totalvalue = 0
        val end = CS.last()
        for(i in 0 until max){
            totalvalue += (end.DP[i]).additiveInverse() modM (base - 1)
            totalvalue = totalvalue.snap()
            base = base divCeil 2
        }

        put((totalvalue modDivide paths) modPlus 1)
    }
    done()
}
const val singleCase = true

/*
mistake 1 :
    did not notice transition isn't that easy

not unrolling

various transformatios:
    straight up don't care

    1
    3
    5
    7
    9
    11 13
    15
    17 19

Strategy :
    easy looking things based
    start from easy to code straetgy does it work

convolution 1 is to slow
    - unless seg tree like maintainnec

Colvoultion 2 takes too many staes
    - impossbile to make work

keep 20-th deriavite on -1

-1 trick can work

memory limit is differetn from processing time



1. Wrong sorting implementations ( a+b) (c-d) , ridiculous
2. triangular loop missing (i+1 until end)
3. careful wrong precalculation constant and TLE ( because hard to ese )
4. forgot to snap
 */