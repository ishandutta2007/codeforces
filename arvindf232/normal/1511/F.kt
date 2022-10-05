// 2022.06.22 at 22:34:08 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 998244353L
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
fun Array<IntArray>.transpose():Array<IntArray>{
    val ret = Array(this[0].size){IntArray(this.size)}
    for(i in this.indices){
        for(j in this[0].indices){
            ret[j][i] = this[i][j]
        }
    }
    return ret
}
class matrixP(val n:Int, val m:Int) {
    companion object{
        //        const val modded = false
        const val p = 998244353
        private inline fun normalize(int: Int) = (int shr Int.SIZE_BITS - 1 and p) + int
        infix fun Int.modm(other:Int) = (this.toLong() * other % p).toInt()
        infix fun Int.modplus(other: Int) = normalize(this + other - p) // overflow-safe even if MOD >= 2^30
        infix fun Int.modminus(other: Int) = normalize(this - other)

        fun Int.localAdjust():Int{
            return if(this > p) this - p else if(this <0) this + p else this
        }
        fun localDivide(a:Int,d:Int):Int{
            return a modm intPow(d, p -2, p)
        }

        fun identity(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            return ret
        }
        fun standardTriangle(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            for(i in 1 until n){
                ret.A[i-1][i] = 1
            }
            return ret
        }
    }
    val A = Array(n){IntArray(m)}

    infix operator fun times(other: matrixP): matrixP {
        assert(m == other.n)
        val ret = matrixP(n,other.m)
        for(i in 0 until n){
            for(k in 0 until m){
                for(j in 0 until other.m){
                    ret.A[i][j] = ret.A[i][j] modplus ( A[i][k] modm other.A[k][j])
//                    if(ret.A[i][j] >= p) {
//                        ret.A[i][j] -= p
//                    }
//                    }else{
//                        ret.A[i][j] += A[i][k] * other.A[k][j]
//                    }
                }
            }
        }
        return ret
    }
    fun print(){
        for(i in 0 until n){
            println(A[i].joinToString(" "))
        }
        println()
    }
    operator fun get(i:Int):IntArray{
        return A[i]
    }

}
typealias genericMatrix = matrixP
class quickPower(val m: genericMatrix){
    companion object{
        const val final = 30
    }
    val allm = mutableListOf<genericMatrix>(m)
    init{
        kotlin.assert(m.n == m.m)
        for(i in 1..final){
            allm.add(allm.last().times(allm.last()))
        }
    }
    fun getMatrix(e:Int): genericMatrix {
        var ret = genericMatrix.identity(m.n)
        for(i in 0 until final){
            if(e and (1 shl i) != 0){
                ret = ret * allm[i]
            }
        }
        return ret
    }
    fun matrixVector(e:Int, other: genericMatrix): genericMatrix {
        kotlin.assert(m.m == other.n)
        var ret = other
        for(i in 0 until final){
            if(e and ( 1 shl i)!= 0){
                ret = allm[i] * ret
            }
        }
        return ret
    }
    fun rowVectorMatrix(e:Int, left:genericMatrix):genericMatrix{
        kotlin.assert(m.n == left.m)
        var ret = left
        for(i in 0 until final){
            if(e and ( 1 shl i)!= 0){
                ret = ret * allm[i]
            }
        }
        return ret
    }
}
fun debug(){}
const val singleCase = true
fun main(){
    solve.tc{
        share("8 ${(1 shl 29) - 1 }")
        repeat(8){
            share("aaaaa")
        }

    }
    solve.tc(1){
        share("""
            8 1000000000
            aaaaa
            aaaa
            bbbbb
            bbbb
            ccccc
            cccc
            ddddd
            dddd

        """.trimIndent())
    }
//    solve.usetc(1)
    solve.cases{
        val n = getint
        val m = getint
        val L = List(n){getstr}
        var now = 0
        val root = 0
        val states = List(n){val ret = (now + 1..now + L[it].size).toList(); now += L[it].size; return@List ret }
        val total = now + 1
        val len = IntArray(n){L[it].size}


        fun process(vec:IntArray, c:Char):IntArray {
            val new = IntArray(total)
            for(sc in 0 until n){
                if(L[sc][0] == c){
                    if(len[sc] != 1){
                        new[states[sc][1]] += vec[0]
                    }else{
                        new[0] = new[0] modPlus vec[0]
                    }

                }
            }
            for(sc in 0 until n){
                for(i in 1 until len[sc]){
                    val s =states[sc][i]

                    if(c == L[sc][i]){
                        if(i == len[sc] -1){
                            new[0] = new[0] modPlus vec[s]
                        }else{
                            val next = states[sc][i+1]
                            new[next] = new[next] modPlus vec[s]
                        }
                    }
                }
            }
            return new
        }
        fun process(start:Int,str:String):IntArray{
            var new = IntArray(total)
            new[start] = 1
            for(c in str){
                new = process(new, c)
            }
            return new
        }
        val pt = Array(total){start ->Array(n){str -> process(start, L[str])} }
        val fill = Array(5 * total){IntArray(5 * total)}
        for(level in 0 until 5){
            for(i in 0 until total ){
                val now = level  * total + i
                if(level != 4){
                    fill[now][now + total] = 1
                }
                for(add in 0 until n){
                    if(level +1 == len[add]){
                        for(got in 0 until total){
                            fill[now][got] = fill[now][got] modPlus pt[i][add][got]
                        }
                    }
                }
            }
        }
        val M = matrixP(5 * total, 5* total)
        for(i in 0 until 5 * total){
            for(j in 0 until 5 * total){
                M[i][j] = fill[j][i]
            }
        }
//        just dei total
        val xx = quickPower(M)
        val v = matrixP(5 * total,1)
        v[0][0] = 1
        put(xx.matrixVector(m,v)[0][0])




    }
    done()
}