// 2022.06.29 at 22:42:36 HKT
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

class element(val curvalue:Int,val curcount:Int, val totalvalue:Long, val totalsize:Int){

}

inline fun BinarySearchFirstTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l
    var R = r+1
    while(L < R){
        val m = (L + R) shr 1
        if(m == r+1 || isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(L == r+1) null else L
}
inline fun BinarySearchLastTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l-1
    var R = r
    while(L < R){
        val m = ((L + R) shr 1) + 1
        if(m == l-1 || isTrue(m)){
            L = m
        }else{
            R = m - 1
        }
    }
    return if(L == l-1) null else L
}


inline fun BinarySearchExact(value:Int,l:Int,r:Int,find:(Int)->Int):Int?{
    //find shoudl be increasing
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(value <= find(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(find(L) == value){ L}else{null}
}

class sack(){
    var cost = 0L
    val st = ArrayDeque<element>()
    private fun addone(v:Int,mul:Int){

        val newtotal = (st.lastOrNull()?.totalvalue ?: 0L) + (mul.toLong() * v)
        val newsize = (st.lastOrNull()?.totalsize ?: 0) + mul
        st.addLast(element(v,mul,newtotal, newsize))
    }
    fun down(v:Int){
        var mul = 0
        while(st.isNotEmpty() && st.last().curvalue >= v){
            mul += st.removeLast().curcount
        }
        addone(v,mul)
    }
    fun new(v:Int){
        addone(plarge,1)
        down(v)
    }
    fun largest(k:Int):Long{
        val totalsize = st.lastOrNull()?.totalsize ?: 0
        val totalvalue = st.lastOrNull()?.totalvalue ?: 0
        val where = BinarySearchFirstTrue(0,st.lastIndex){
            st[it].totalsize >= totalsize - k
        }!!
        val deleteextra = (st[where].totalsize - (totalsize - k))
        val ret1 = st[where].totalvalue - deleteextra.toLong() * st[where].curvalue
        return totalvalue - ret1
    }
}
class query(val l:Int, val r:Int, val id:Int){
    var ans:Long = 0L

}
typealias rmqType = Int
typealias rmqArrayType = IntArray

class rmq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = false
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
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

fun debug(){}
const val singleCase = true
fun main(){

    solve.cases{
        val n = getint
        val q = getint
        val k  = getint
        val L = getline(n)

        val queries = List(q){
            query(getint - 1 , getint - 1, it)
        }
        val min = rmq(L)
        val bins = Array<MutableList<query>>(n){ mutableListOf<query>() }
        for(q in queries){
            bins[q.l].add(q)
        }
        for(i in 0 until n){
            if(i + k in 0 until n) continue
            var now = i
            val start = sack()
            for(v in i downTo 0 step k ){
                if(v != i && k != 1){
                    val best = min.query(v+1, v+k-1)
                    start.down(best)
                }
                start.new(L[v])
                for(q in bins[v]){
                    val len = q.r - q.l + 1
                    val convert = len divceil k
                    q.ans = start.largest(convert)
                }
            }
        }
        for(q in queries){
            put(q.ans)
        }





    }
    done()
}