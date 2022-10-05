
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.absoluteValue
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
const val p = 998244353L
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



class type(val lead:Long, val level:Int){
    fun output(){
        just dei (lead until (lead + (1L shl level))).joinToString(" ")
    }
    inline fun act(a:(Long)->Unit){
        for(x in lead until (lead + (1L shl level))){
            a(x)
        }
    }
    fun xor(other:type):type{
        val newlevel = maxOf(this.level, other.level)
        val newlead = (this.lead xor other.lead) and ((1L shl newlevel) - 1 ).inv()
        return type(newlead, newlevel)
    }

}
fun divide(l:Long, r:Long):List<MutableList<type>> {
    var left = l
    var right = r + 1
    var level = 0
    val L = mutableListOf<type>()
    val R =  mutableListOf<type>()
    while(left < right){
        if(left and 1L != 0L){
            L.add(type(left shl level, level ))
            left += 1
        }
        if(right and 1L != 0L){
            right -=  1
            R.add(type(right shl level, level ))
        }
        left = left shr 1
        right = right shr 1
        level ++
    }
    return listOf(L,R)
}


private const val radixLogL = 10
private const val radixBaseL = 1 shl radixLogL
private const val radixMaskL = radixBaseL - 1

fun countSortL(arr: LongArray, n: Int, expB: Int) {
    val output = LongArray(n)
    val count = IntArray(radixBaseL)
    for(i in 0 until n) {
        count[(arr[i] shr expB).toInt() and radixMaskL]++
    }
    for(i in 1 until radixBaseL){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        output[count[(arr[i] shr expB).toInt() and radixMaskL] - 1] = arr[i]
        count[(arr[i] shr expB).toInt() and radixMaskL]--
    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
}
fun LongArray.radixsort(){
    val n = this.size
    var b = 0
    repeat(7){
        countSortL(this, n, b)
        b += radixLogL
    }
}
fun countSortLCarry(arr: LongArray, n: Int, expB: Int,carried:LongArray) {
    val output = LongArray(n)
    val newcarry = LongArray(n)
    val count = IntArray(radixBaseL)
    for(i in 0 until n) {
        count[(arr[i] shr expB).toInt() and radixMaskL]++
    }
    for(i in 1 until radixBaseL){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        val id = (arr[i] shr expB).toInt() and radixMaskL
        count[id]--
        output[count[id]] = arr[i]
        newcarry[count[id]] = carried[i]

    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
    for(i in 0 until n){
        carried[i] = newcarry[i]
    }
}
fun radixCarry(main:LongArray, carry:LongArray){
    val n = main.size
    var b = 0
    repeat(7){
        countSortLCarry(main, n, b,carry)
        b += radixLogL
    }
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
class pp(val first:Long, val second:Long){

}

const val singleCase = true
fun main(){
    solve.cases{
        val n = getint

        val left = List(n){Pair(getlong, getlong)}

        val m = getint
        val right = List(m){Pair(getlong, getlong)}


        var pt = -1
        var lb = LongArray(10)
        var rb = LongArray(10)
        fun add(l:Long, r:Long){
            if(pt + 1 == lb.size){
                lb = lb.copyOf(lb.size * 2)
                rb = rb.copyOf(rb.size * 2 )
            }
            pt++
            lb[pt] = l
            rb[pt] = r
        }
        val leftpiece = left.flatMap{divide(it.first, it.second)}
        val rightpiece = right.flatMap{divide(it.first, it.second)}
        for(a in leftpiece){
            a.sortBy { it.level }
        }
        for(b in rightpiece){
            b.sortBy { it.level }
        }

        fun consider(x:type, y:type){
            val new = x.xor(y)
            add(new.lead, new.lead + (1L shl new.level) - 1 )
        }


        fun joindivide(a:List<type>, b:List<type>,doubletake:Boolean){
            for(x in a){
                var last:type? = null
                for(y in b){
                    if(y.level > x.level ) break
                    if(doubletake && y.level == x.level){
                        consider(x,y)
                    }
                    if(y.level  < x.level){
                        last = y
                    }
                }
                if(last != null){
                    consider(x,last)
                }
            }
        }
        for(l in leftpiece){
            for(r in rightpiece){
                joindivide(l,r,true)
                joindivide(r,l,false)
            }
        }

//        val leftpieces = left.flatMap { divide(it.first, it.second) }
//        val rightpieces = right.flatMap { divide(it.first, it.second) }
//
//        fun solve(left:List<type>, right:List<type>, level:Int){
//            if(left.isEmpty() && right.isEmpty()) return
//            val l1 = mutableListOf<type>()
//            val l2 = mutableListOf<type>()
//            val r1 = mutableListOf<type>()
//            val r2 = mutableListOf<type>()
//
//
//
//        }

//        val lb = LongArray(leftpieces.size * rightpieces.size)
//        val rb = LongArray(leftpieces.size * rightpieces.size)
//        var pt = 0
//
//        for(a in leftpieces) {
//            for(b in rightpieces) {
//                val newlevel = maxOf(a.level, b.level)
//                val newlead = (a.lead xor b.lead) and ((1L shl newlevel) - 1).inv()
//                lb[pt] = newlead
//                rb[pt] = newlead + (1L shl newlevel) - 1
//                pt++
//            }
//        }
//        val lb = LongArray(all.size){all[it].first}
//        val rb = LongArray(all.size){all[it].second}
//        all = mutableListOf()

        lb = lb.copyOf(pt +1)
        rb = rb.copyOf(pt + 1 )
        val inv2 = (2).inverse()
        radixCarry(lb,rb)
        var rcovered = -1L
        var now = 0L
        for(i in lb.indices){
            var ll = lb[i]
            val rr = rb[i]
            ll = maxOf(ll,rcovered + 1)
            if(ll > rr) continue
            val len = rr-ll + 1
            val av2 = ll + rr
            now += (av2 % pI).toInt() modM (len % pI).toInt() modM inv2
            if(now >= pI){
                now -= pI
            }
            rcovered = maxOf(rcovered,rr)
        }

//        val all = mutableSetOf<Long>()
//        for(i in leftpieces){
//            for(j in rightpieces){
//                val new = i.xor(j)
//                new.act {
//                    all.add(it)
//                }
//            }
//        }
//        var now = 0L
//        for(v in all){
//            now += v
//            now %= pI
//        }
        put(now)

    }
    done()
}