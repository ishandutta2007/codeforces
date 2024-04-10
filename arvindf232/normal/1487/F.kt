// 2022.06.17 at 18:59:23 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
object Reader{
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
            put("Custom test enabled")
            println("Custom test enabled")
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
fun put(aa:Any){ Reader.OUT.println(aa)}
fun done(){ Reader.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){Reader.fakein.append(aa.toString())}
    else{Reader.fakein.append(aa.toString())}
    Reader.fakein.append("\n")
}

val getintfast:Int get() = Reader.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
var dmark = -1
infix fun Any.dei(a:Any){
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
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
val just = " "
fun crash(){
    throw Exception("Bad programme")}
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Not usual primes!")
        }
        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                Reader.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                Reader.rerouteInput()
            }
            onecase()
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
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}
fun debug(){}
const val singleCase = true


class cache<T,V> {
    val map = mutableMapOf<T,V>()
    fun get(a:T,ow:(T)->V):V{
        if(a in map){
            return map[a]!!
        }
        val new = ow(a)
        map[a] = new
//        just dei map.size
        return new
    }
    fun debug(a:T,ow:(T)->V):V{
        if(a in map){
            return map[a]!!
        }
        val new = ow(a)
        map[a] = new
        println("$a $new")
        return new
    }
}
infix fun Int.divceil(b:Int):Int{
    return (this/b) + if(this % b > 0) 1 else 0
}
infix fun Long.divceil(b:Long):Long{
    return (this/b) + if(this % b > 0) 1L else 0L
}
infix fun Int.div_neg_floor(b:Int):Int{
    return (this/b) - if(this % b < 0) 1 else 0
}
infix fun Long.div_neg_floor(b:Long):Long{
    return (this/b) - if(this % b < 0) 1L else 0L
}
fun modCount(x:Long, mod:Long, l:Long, r:Long):Long{
    val ans = ((r -x) div_neg_floor mod ) - ((l - x) divceil mod) + 1
    return maxOf(ans,0)
    //coun number of x mod mod in [l..r]
}
class largedecimal(var arr:LongArray){
    companion object{
        const val baselen = 17
        const val mod = 1_000_000_000_000_000_00L
        val zeros = List(baselen){'0'}.joinToString("")
    }
    constructor(a:Int):this(longArrayOf(a.toLong())){

    }
    constructor(str:String):this(longArrayOf(0)){
        for(c in str){
            val v = c.toInt() - '0'.toInt()
            this.shlonce()
            this.adding(v)
        }
    }
    fun copy():largedecimal{
        return largedecimal(arr.copyOf())
    }
    fun clean(){
        val max = arr.lastIndex
        for(i in 0..max){
            if(arr[i] >= mod){
                val extra = arr[i] / mod
                arr[i] -= extra * mod
                if(i == arr.lastIndex){
                    arr = arr.copyOf(arr.size + 1 )
                }
                arr[i+1] += extra
            }
        }
    }
    fun doubleclean(){
        val max = arr.lastIndex
        for(i in 0..max){
            if(arr[i] >= mod){
                val extra = arr[i] / mod
                arr[i] -= extra * mod
                if(i == arr.lastIndex){
                    arr = arr.copyOf(arr.size + 1 )
                }
                arr[i+1] += extra
            }else if(arr[i] < 0){
                val extra = arr[i] div_neg_floor mod
                arr[i] -= extra * mod
                if(i == arr.lastIndex){
                    arr = arr.copyOf(arr.size + 1 )
                }
                arr[i+1] += extra
            }
        }
    }
    fun smallmultiply(x:Int){
        // x <= 10 is needed
        for(i in arr.indices){
            arr[i] *= x.toLong()
        }
        clean()
    }
    fun adding(x:Int){
        arr[0] += x.toLong()
        doubleclean()
    }
    fun shlonce(){
        for(i in arr.indices){
            arr[i] *= 10L
        }
        clean()
    }
    fun shronce(){
        for(i in arr.indices){
            val new = arr[i] % 10
            arr[i] /= 10L
            if(i != 0){
                arr[i-1] += new * mod / 10
            }
        }
    }
    fun unitdigit():Int{
        return (arr[0] %10).toInt()
    }
    fun iszero():Boolean{
        return arr.all { it == 0L }
    }
    fun isnegative():Boolean{
        return arr.any { it < 0 }
    }

    override fun toString():String {
        val ret = mutableListOf<String>()
        var stuff = false
        for(i in arr.lastIndex downTo 0){
            val here = arr[i]
            if(here != 0L){
                stuff = true
                ret.add(here.toString())
            }else{
                if(stuff){
                    ret.add(zeros)
                }
            }
        }
        if(!stuff){
            return "0"
        }
        return ret.joinToString(
            ""
        )
    }
    override fun equals(other:Any?):Boolean {
        if(this === other) return true
        if(javaClass != other?.javaClass) return false

        other as largedecimal

        if(!arr.contentEquals(other.arr)) return false

        return true
    }
    override fun hashCode():Int {
        return arr.contentHashCode()
    }
}
val okcache = cache<arg,Int>()

data class arg(val num:largedecimal, val balance:Int, val rank:Int){

}

fun ok(num:largedecimal,balance:Int, rank:Int):Int{
    if(num.iszero()){
        return if(balance == 0) 0 else plarge
    }
    if(balance !in -600..600) return plarge
    return okcache.get(arg(num,balance,rank)){
        it ->
        with(it){
            val ld = num.unitdigit()
            val t1 = num.copy()
            t1.adding(-ld)
            t1.shronce()
            var best = plarge
            best = minOf(best,ok(t1,balance - ld,rank + 1) + ld * rank )
            val t2 = num.copy()
            t2.adding(10 - ld)
            t2.shronce()
            best = minOf(best,ok(t2, balance + (10-ld), rank + 1) + (10-ld) * rank)
            return@get best
        }

    }
}

fun main(){

//    var v = largedecimal(1)
//    repeat(100){
//        v.smallmultiply(2)
//        just dei v
//    }
    solve.tc {
        share("12345678901234567890123456789012345678901234567890")
    }
//    solve.usetc()
    solve.cases{
        val str = getstr
        val C = largedecimal(str)
        C.smallmultiply(9)


//        just dei ok(largedecimal(92),2,1)
//        just dei C

//        just dei ok(largedecimal(92),2,7,1)

//        return@cases

        var best = plarge
        for(balance in -600..600){
            val now = C.copy()
            now.adding(balance)
            if(now.unitdigit() != 0 || now.isnegative()) continue
            now.shronce()
            val new = ok(now, balance, 1)
//            balance dei new
            best = minOf(best, new)
        }
        put(best)




    }
    done()
}
/*
less greedy

uses at most 10

answer is no more than 500
500,500


 */