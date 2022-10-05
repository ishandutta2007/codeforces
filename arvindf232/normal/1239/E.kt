
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
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
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

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == '1'}
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
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }

        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
const val withBruteForce = false
const val randCount = 100
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }

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
            onecase()
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
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor b.toLong()
val Long.first get() = (this shr 32).toInt()
val Long.second get() = this.toInt()



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
//infix fun Int.modPlus(b:Int):Int{
//    val ans = this + b
//    return if(ans >= pI) ans - pI else ans
//}
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
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
fun intPowEXP(x:Int,e:Long,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0L){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
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
fun min_rem(m:Int, r:Int, c:Int):Int {
    if(c < 1){
        return Int.MIN_VALUE
    }else if(r == 0){
        return 0
    }else{
        val step = m % r
        val mx = ((1L * c * r) /m ).toInt()
        val t = max_rem(r,step,mx)
        return r- t
    }
}
fun max_rem(m:Int, r:Int, c:Int):Int {
    if(r == 0|| c <= m/r){
        return r * c
    }else{
        val step =  m % r
        val mx = ((1L * (c+1) * r )/m).toInt()
        val t = min_rem(r,step,mx)
        return  m - t
    }
}
fun Int.reconstruct():String{
    val num = min_rem(pI,this, 10000)
    val denom = (this modDivide num).inverse()
    return "$num / $denom"
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
            ret = ret modM (invStore[r])
            return ret
        }

    }
}

class bitset (val n:Int ,val all:LongArray){
    constructor(n:Int):this(n,LongArray((n shr wordSizeShift) + 1 )){
    }
    companion object{
        const val wordSize = 64
        const val wordMask = 63
        const val wordSizeShift = 6
        const val allfalse = 0L
        const val alltrue = allfalse.inv()
        val allmask = LongArray(wordSize){1L shl it}
        val invertAllMask = LongArray(wordSize){(1L shl it).inv()}
    }
    val size:Int get() = all.sumOf { it.countOneBits() }
    fun Long.element(a:Int):Boolean{
        return (this and (1L shl a)!= 0L)
    }
    operator fun get(i:Int):Boolean{
        return all[i shr wordSizeShift].element(i and wordMask)
    }
    operator fun set(i:Int,v:Boolean){
        if(v){
            all[i shr wordSizeShift] = all[i shr wordSizeShift] or allmask[i and wordMask]
        }else{
            all[i shr wordSizeShift] = all[i shr wordSizeShift] and invertAllMask[i and wordMask]
        }
    }
    infix fun and(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] and other.all[i]
        }
        return new
    }
    infix fun or(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] or other.all[i]
        }
        return new
    }
    infix fun xor(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] xor other.all[i]
        }
        return new
    }
    fun copy():bitset{
        return bitset(n,all.copyOf())
    }



    fun andAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] and other.all[i]
        }
    }
    fun orAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] or other.all[i]
        }
    }
    fun xorAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] xor other.all[i]
        }
    }

    fun orAssignShifted(other:bitset,otherShift:Int){
        //obviously, used in knapsacking, safe to use itself
        kotlin.assert(otherShift >= 0)
        if(otherShift and wordMask == 0){
            val take = otherShift shr wordSizeShift
            for(i in all.lastIndex downTo take){
                all[i] = all[i] or other.all[i - take]
            }
        }else{
            val bins = otherShift shr wordSizeShift
            val extra = otherShift and wordMask
            for(i in all.lastIndex downTo bins){
                var now = all[i]
                now = now or (other.all[i - bins] shl extra)
                if(i != bins) now = now or (other.all[i - bins - 1] ushr (wordSize - extra))
                all[i] = now
            }
        }
    }

    override fun toString(): String {
        return (0 until n).map { if(this[it]) '1' else '0' }.joinToString("")
    }

    fun prefixMask(upto:Int): Long {
        return alltrue ushr (63 - upto)
    }
    fun suffixMask(downto:Int):Long {

        return alltrue shl downto
    }
    fun negate(from:Int, to:Int){
        val a = from shr wordSizeShift
        all[a] = all[a] xor suffixMask(from and wordMask)
        val b = to shr wordSizeShift
        all[b] = all[b] xor prefixMask(to and wordMask)
        if(a== b){
            all[a] = all[a].inv()
        }
        for(i in a+1 until b){
            all[i] = all[i].inv()
        }
    }
}
fun bitsetPacker(exactly:Int, available:List<Int>, wantMax:Int, wantMin:Int):List<Int>?{
    val DP = List(exactly + 1){ bitset(wantMax + 1 )}
    DP[0][0] = true
    for(a in available){
        for(left in exactly -1 downTo 0){
            DP[left + 1].orAssignShifted(DP[left],a)
        }
    }
    var endat = -1
    for(i in wantMax downTo wantMin){
        if(DP[exactly][i]){
            endat = i
            break
        }
    }
    if(endat == -1){
        return null
    }
    val ret = mutableListOf<Int>()
    var remCount = exactly
    var remSize = endat
    for((i,v) in available.withIndex().reversed()){
        if(remSize - v < 0) continue
        if(DP[remCount-1][remSize - v]){
            remCount --
            remSize -= v
            ret.add(i)
            if(remCount == 0) break
        }
    }
    kotlin.assert(ret.sumOf { available[it] } == endat && ret.size == exactly)
    return ret
}


const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val A = getline(n)
        val B = getline(n)
        var all = A.toList() + B.toList()
        all = all.sorted()

        val firsttwo = all.take(2)
        val remain = all.slice(2 until all.size)
        val t = remain.sumOf { it }
        val atmost = t/2

        val result = bitsetPacker((n-1),remain ,atmost, 0)!!
        val ret = BooleanArray(2 * n - 2)
        for(a in result){
            ret[a] = true
        }
        val toprow = mint
        val bottomrow = mint
        toprow.add(firsttwo[0])
        bottomrow.add(firsttwo[1])
        for(i in ret.indices){
            if(ret[i]){
                toprow.add(remain[i])
            }else{
                bottomrow.add(remain[i])
            }
        }
        toprow.sort()
        bottomrow.sortDescending()

        put(toprow.conca())
        put(bottomrow.conca())
    }
    done()
}


/*
n *

5
1 2 4 8 16
1 1 1 1 1
 */