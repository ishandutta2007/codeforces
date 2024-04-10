// 2022-04-12, Tue, 10:39
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.cos
import kotlin.math.roundToInt
import kotlin.math.sin

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

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
        if(withBruteForce){
            println("Brute force is active")
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
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
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


class complex(val x:Double, val y:Double){
    infix operator fun times(other:complex):complex{
        return complex(this.x * other.x - this.y * other.y , this.x * other.y + this.y * other.x )
    }
    infix operator fun plus(other:complex):complex{
        return complex(this.x + other.x, this.y + other.y)
    }
    infix operator fun minus(other:complex):complex{
        return complex(this.x - other.x, this.y - other.y)
    }
    fun component1(): Double {
        return x
    }
    fun component2():Double{
        return y
    }
}

object FFT_double {
    const val FFT_cut = 80
    const val PI = Math.PI
    fun fft(real:DoubleArray, ima:DoubleArray, invert:Boolean ){
        kotlin.assert(real.size == ima.size)
        val n = real.size
        var j = 0
        for(i in 1 until n){
            var bit = n shr 1
            while(j and bit != 0 ){
                j = j xor bit
                bit = bit shr 1
            }
            j = j xor bit
            if(i < j){
                real[i] = real[j].also { real[j] = real[i] }
                ima[i] = ima[j].also{ima[j] = ima[i]}
            }
        }
        var len = 2
        while(len <= n){
            val ang = 2 * PI / len * (if(invert) -1 else 1 )
            val wlenx = cos(ang)
            val wleny = sin(ang)
            for(i in 0 until n step len){
                var wx = 1.0
                var wy = 0.0
                for(j in 0 until (len shr 1)){
                    val i1 = i + j
                    val i2 = i + j + (len shr 1)
                    val u1 = real[i1]
                    val u2 = ima[i1]
                    val v1 = (real[i2] * wx - ima[i2] * wy)
                    val v2 = (real[i2] * wy + ima[i2] * wx )
                    real[i1] = u1 + v1
                    ima[i1] = u2 + v2
                    real[i2] = u1 - v1
                    ima[i2] = u2 - v2
                    val nwx = wx * wlenx - wy * wleny
                    val nwy = wx * wleny + wy * wlenx
                    wx = nwx
                    wy = nwy
                }
            }
            len = len shl 1
        }

        if(invert){
            for(i in 0 until n){
                real[i] /= n.toDouble()
                ima[i] /= n.toDouble()
            }
        }

    }
    fun convolute(at:DoubleArray, bt:DoubleArray): DoubleArray {
        return fullconvolutionOpt(at,bt,at.size,bt.size)
    }

    fun fullconvolutionOpt(at:DoubleArray,bt:DoubleArray,sizeA:Int,sizeB:Int):DoubleArray{
        // 1 shl 18 done in 77 ms
        val maxSize = (sizeA + sizeB).takeHighestOneBit() * 2
        val a = at.copyOf(maxSize)
        val b = bt.copyOf(maxSize)
        val expectedSize = at.size + bt.size - 1
        val ai = DoubleArray(maxSize)
        val bi = DoubleArray(maxSize)
        fft(a, ai ,false)
        fft(b, bi,false)
        val newR = DoubleArray(maxSize)
        val newI = DoubleArray(maxSize)
        for(i in newR.indices){
            val result = complex(a[i],ai[i]) * complex(b[i], bi[i])
            newR[i] = result.x
            newI[i] = result.y
        }
        fft(newR, newI, true)
        return newR.copyOf(expectedSize)
    }
    fun bruteInt(a:IntArray, b:IntArray):IntArray{
        val ret = IntArray(a.size + b.size - 1)
        for(i in a.indices){
            for(j in b.indices){
                ret[i+j] += a[i] * b[j]
            }
        }
        return ret
    }
    fun convoluteInt(a:IntArray, b:IntArray):IntArray{
        // 100k + 100k, 60ms average with 15 convolutions
        val sizeA = a.size
        val sizeB = b.size
        if(sizeA <= FFT_cut || sizeB <= FFT_cut){
            return bruteInt(a,b)
        }
        val maxSize = (sizeA + sizeB).takeHighestOneBit() * 2
        val ax = DoubleArray(maxSize){ if( it < a.size ) a[it].toDouble() else 0.0}
        val bx = DoubleArray(maxSize){ if(it < b.size ) b[it].toDouble() else 0.0}
        val ai = DoubleArray(maxSize)
        val bi = DoubleArray(maxSize)
        fft(ax, ai ,false)
        fft(bx, bi,false)
        val newR = DoubleArray(maxSize)
        val newI = DoubleArray(maxSize)
        for(i in newR.indices){
//            val result = complex(ax[i],ai[i]) * complex(bx[i], bi[i])
            newR[i] = ax[i] * bx[i] - ai[i] * bi[i]
            newI[i] = ax[i] * bi[i] + ai[i] * bx[i]
        }
        fft(newR, newI, true)
        return IntArray(sizeA + sizeB - 1){(newR[it]).roundToInt()}
    }
}


fun debug(){}
const val withBruteForce = false
const val singleCase = true
fun main(){
    solve.cases{
        val (n,x,y) = getline(3)

        val have = BooleanArray(1000001)
        val L = getline(n+1)

        fun solve(l:Int, r:Int,ll:Int, rr:Int){
//            just dei "$l $r $ll $rr"
//            if(L.slice(ll..rr) != L.filter { it in l..r }){
//                just dei L.slice(ll..rr)
//                just dei  L.filter { it in l..r }
//                crash()
//            }
            if(rr - ll + 1 <= 1 ) return

//            val left = mint
//            val right = mint
            val mid = (l + r) shr 1
            val LA = IntArray(mid-l+1)
            val RA = IntArray(r- mid + 1 )
            var lastleft = ll-1
            for(i in ll..rr) {
                val a = L[i]
//                assert(a in l..r)
                if(a <= mid) {
                    lastleft = i
                    LA[mid-a] ++
                }else{
//                    assert(a >= mid + 1)
                    RA[a - mid] ++
                }
            }
            val new = FFT_double.convoluteInt(LA, RA)
            for(i in new.indices){
                if(new[i] > 0) {
                    have[i] = true
                }
            }
            solve(l,mid,ll,lastleft)
            solve(mid+1,r,lastleft+1,rr)
        }
        solve(0,x,0,n)
        val largest = IntArray(1000001){-1}
        for(i in have.indices){
            val v = 2 * i + 2 * y
            if(v in largest.indices && have[i]) {
                largest[v] = v
            }
        }
        for(i in 1 until largest.size) {
            if(largest[i] == -1) continue
            for(j in 2 * i until largest.size step i) {
                largest[j] = maxOf(largest[j], largest[i])
            }
        }
        val q = getint
        val Qs = getline(q)
        for(a in Qs){
            put(largest[a])
        }






    }
    done()
}

/*
fft or something else

11 minutes if this works
 */