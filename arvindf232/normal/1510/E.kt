// 2022.06.21 at 18:38:00 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.absoluteValue
import kotlin.math.roundToInt
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
fun Double.almostequal(other:Double):Boolean{
    return (this - other).absoluteValue <= 1e-7
}
fun debug(){}
data class q(val x:Int, val y:Int){

}
const val singleCase = true
fun main(){
    solve.tc {
        share("36 -1 -1")
    }
//    solve.usetc()
    solve.cases{
        val n = getint /2
        val x = getstr.toDouble()
        val y = getstr.toDouble()

        //xm multiplied by 6
        val ret = mutableListOf<Char>()
        var ok = false

        val downX = Array(2 * n){phase -> IntArray(2 * n){level -> (phase * 6 + 3) * (level -1) + (phase * 3 + 1)} }
        val upX = Array(2 * n){phase -> IntArray(2 * n){level ->  (phase * 6 + 3) * (level) + (phase * 3+ 2)}}
        val downY = Array(2 * n){phase -> IntArray(2 * n){level -> (level - 1) * 3 * (level - 1) + (level * 3 - 3 + 1 ) }}
        val upY = Array(2 * n){phase -> IntArray(2 * n){level -> (level) * 3 * (level) + (level * 3+ 1 ) }}


        val prod1 = DoubleArray(n * n +1 ){x * it * 6 }
        val prod2 = DoubleArray(n * n +1 ){y * it * 6 }
        var count  = 0

//        var maxx = 0
//        var maxy = 0
//        var maxsum =0
//        val had = Array(2*n+1){Array(n+1){Array(n * n +1){ mutableSetOf<q>()}}}
        val typebylevel = Array(n * n + 1){Array(  n + 1){ mutableMapOf<q,String>() } }
        fun check(phase:Int,level:Int,xm:Int, ym:Int, sum:Int, str:String){
//            val new = q(xm,ym)
//            val where = had[phase][level][sum]
//            if(new in where){
//                return
//            }
//            where.add(new)
//            maxx = maxOf(maxx, xm)
//            maxy = maxOf(maxy,ym)
//            maxsum = maxOf(maxsum, sum)
            if(phase == n){
                typebylevel[sum][level][q(xm,ym)] = str
                return
            }
//            if(phase == 2 * n){
//                val realpiece = sum + n
//                if(xm.toDouble().almostequal(prod1[realpiece]) && ym.toDouble().almostequal(prod2[realpiece])) {
//                    ok = true
//                }
////                just dei "$x1 $y1"
//                return
//            }
            count ++
            if(level >= 1){
                val xnew = downX[phase][level]
                val ynew = downY[phase][level]
//                val xnew = (phase + 0.5) * (level -1) + (phase + 1/3.0)/2.0
//                val ynew = (level - 1) / 2.0 * (level - 1) + (level - 1 + 1/3.0 )/2.0
                check(phase + 1, level - 1, xm + xnew, ym + ynew, sum + (level-1), str + ')')
//                if(ok){
//                    ret.add(')')
//                    return
//                }
            }
            if(level + phase < 2 * n){
                val xnew = upX[phase][level]
                val ynew = upY[phase][level]
//                val xnew = (phase + 0.5) * (level) + (phase + 2/3.0)/2.0
//                val ynew = (level) / 2.0 * (level) + (level+ 1/3.0 )/2.0
                check(phase + 1, level + 1, xm + xnew, ym + ynew, sum + (level), str + '(')
//                if(ok){
//                    ret.add('(')
//                    return
//                }
            }
        }
        check(0,0,0,0,0,"")

        for(sum in 0..n * n){
            val tx = (x * sum * 6).roundToInt()
            val ty = (y * sum * 6 ).roundToInt()
            if(tx.toDouble().almostequal(x * sum * 6 ) && ty.toDouble().almostequal(y * sum * 6 )){
                for(level in 0..n){
                    for(one_sum in 0..sum-n){
                        for((k,v) in typebylevel[one_sum][level]){
                            val twosum = sum - n - one_sum
                            val wantx = (twosum * 6 + n * 3) * (2 * n)  - (tx - k.x)
                            val wanty = ty - k.y

                            if(typebylevel[twosum][level].containsKey(q(wantx,wanty))){
                                val ret =  typebylevel[twosum][level][q(wantx,wanty)]!!
                                put(v + ret.map { if(it == ')') '(' else ')' }.reversed().conca())
                                return@cases
                            }
                        }
                    }
                }
            }

        }

//        just dei count
        put(ret.conca().reversed())




    }
    done()
}
/*
6 3.4 0.6

34996
11664
306
 */