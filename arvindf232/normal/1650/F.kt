// 2022.07.31 at 20:51:03 HKT
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
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
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

class fastmint (var array:IntArray){
    val size:Int get() = pt + 1
    var pt = array.lastIndex
    //iterate with 0..pt
    val lastIndex:Int get() = pt
    init{
        if(array.size < 5){
            array = array.copyOf(5)
        }
    }
    constructor(initialCapacity:Int = 10):this(IntArray(initialCapacity)){
        pt = -1
    }
    inline fun foreach(act:(Int)->Unit){
        for(i in 0..pt){
            act(array[i])
        }
    }
    inline fun withIndex(act:(i:Int, v:Int)->Unit){
        for(i in 0..pt){
            act(i,array[i])
        }
    }
    operator fun get(v:Int):Int{
        return array[v]
    }
    operator fun set(i:Int, v:Int){
        array[i] = v
    }
    fun add(v:Int){
        if(pt + 1 == array.size){
            array = array.copyOf(array.size * 3 / 2  )
        }
        pt ++
        array[pt] = v
    }
    fun addLast(v:Int) = add(v)
    fun removeLast():Int{
        pt--
        return array[pt+1]
    }
    fun clear(){
        pt = -1
    }
    fun reduceMemory(){
        array = array.copyOf(size)
    }
    override fun hashCode(): Int {
        return array.hashCode()
    }
    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as fastmint

        if (pt != other.pt) return false
        if (!array.contentEquals(other.array)) return false

        return true
    }
}

class option(val task:Int, val time:Int, val opt:Int, val id:Int){

}

fun pack(opt:IntArray, time:IntArray):BooleanArray?{
    val earliest = LongArray(101){phuge}
    val statenow = IntArray(101){-1}
    earliest[0] = 0L
    statenow[0] = 0
    val par = fastmint()
    val how = fastmint()
    par.add(-1)
    how.add(-1)
    for(i in time.indices){
        val t = time[i]
        val p = opt[i]
        for(start in 100 downTo 0){
            val next = minOf(100,start + p)
            val nexttime = earliest[start] + t
            if(nexttime < earliest[next]){
                earliest[next] = nexttime
                val sn = par.size
                par.addLast(statenow[start])
                how.add(i)
                statenow[next] = sn
            }
        }
    }

    if(earliest[100] >= phuge){
        return null
    }
    val ret = BooleanArray(opt.size)
    var sn = statenow[100]
    while(sn != 0){
        val taking = how[sn]
        ret[taking] = true
        sn = par[sn]
    }
    return ret
}
fun debug(){}
const val singleCase = false
fun main(){
    solve.cases{
        val n = getint
        val m = getint

        val L = getline(n)
        val bins = Array(n){ mutableListOf<option>() }
        repeat(m){
            val q = option(getint - 1 , getint, getint, it)

            bins[q.task].add(q)
        }
        val order = (0 until n).sortedBy { L[it] }
        var tn = 0L
        val take = mint
        for(c in order){
            val all = bins[c]
            val opts = all.map { it.opt }.toIntArray()
            val time = all.map { it.time }.toIntArray()

            val solution = pack(opts, time)
            if(solution == null) {
                put(-1)
                return@cases
            }
            for(i in solution.indices){
                if(solution[i]){
                    take.add(all[i].id)
                    tn += all[i].time
                }
            }
            if(tn > L[c]){
                put(-1)
                return@cases
            }
        }
        put(take.size)
        put(take.map{it + 1}.conca())


//        just dei pack(intArrayOf(10,20,30,40,40), intArrayOf(4,3,2,8,3))!!




    }
    done()
}