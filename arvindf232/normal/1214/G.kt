
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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



class bitset (val n:Int ,val all:LongArray){
    constructor(n:Int):this(n,LongArray((n shr wordSizeShift) + 1 )){
    }
    companion object{
        const val wordSize = 64
        const val wordMask = 63
        const val wordSizeShift = 6
        const val allfalse = 0L
        const val alltrue = (0L).inv()
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
    fun findBad(other:bitset):Long{
        var first = -1
        var second = -1
        for(i in all.indices){
            val a = all[i]
             val b = other.all[i]
            if(a != b ){
                val onezero = a and (b.inv())
                if(onezero != 0L){
                    first = 63 - onezero.countLeadingZeroBits() + i * 64
                    if(second != -1){
                        return makepair(first,second)
                    }
                }
                val zeroone = a.inv() and b
                if(zeroone != 0L){
                    second = 63 - zeroone.countLeadingZeroBits() + i * 64
                    if(first != -1){
                        return makepair(first,second)
                    }
                }
            }
        }
        return -1L
    }
}

val T = TreeSet<item>()
val baditems = mutableSetOf<item>()

class item(val b:bitset, val id:Int):Comparable<item>{
    var size = b.size
    var isbad = false
    var badpartner = -1
    var badpositions:Long = 0L

    override fun compareTo(other:item):Int {
        return if(this.size != other.size) this.size .compareTo(other.size) else this.id.compareTo(other.id)
    }
    fun setbadness(newbad:Boolean){
        if(newbad != isbad){
            if(newbad == false){
                baditems.remove(this)
            }else{
                baditems.add(this)
            }
        }
        isbad = newbad
    }

    fun updateThis(){
        val other = T.higher(this)
        if(other == null){
            setbadness(false)
            return
        }
        val fb = this.b.findBad(other.b)
        if(fb == -1L){
            setbadness(false)
            return
        }else{
            setbadness(true)
            badpartner = other.id
            badpositions = fb
        }
    }
    fun negateThis(l:Int, r:Int){
        val left = T.lower(this)
        T.remove(this)
        left?.updateThis()
        this.b.negate(l,r)
        this.size = b.size
        T.add(this)
        val newleft = T.lower(this)
        this.updateThis()
        if(newleft != null){
            newleft.updateThis()
        }
    }
    fun outputme():IntArray {
        assert(isbad)
        val  x1 = this.id
        val  x2 = badpartner
        val y1 = badpositions.first
        val y2 = badpositions.second
        return intArrayOf(minOf(x1,x2), maxOf(x1,x2), minOf(y1,y2), maxOf(y1,y2))

    }


}
const val singleCase = true
fun main(){
//    val a = bitset(2)
//    val b = bitset(2)
//    a[0] = true
//    b[1] = true
//    just dei a.findBad(b)
    solve.cases{
        val (n,m,q) = getline(3)
        val things = Array(n){item(bitset(m), it)}

        fun output(){
            for(i in 0 until n){
                i dei things[i].b
            }
        }
        repeat(q){v ->
            var (a,l,r) = getline(3)
            a--
            l--
            r--
            things[a].negateThis(l,r)
//            output()
            if(baditems.isEmpty()){
                put(-1)
            }else{
                val (a,b,c,d) = baditems.first().outputme()
                val A = things[a].b[c]
                val B = things[a].b[d]
                val C = things[b].b[c]
                val D = things[b].b[d]
                assert((A != B) && (A != C) && (A == D) )
                put("${a+1} ${c+1} ${b+1} ${d+1}")
            }
        }
    }
    done()
}

/*
100 100 3
3 2 83
3 83 100
66 2 83

 */