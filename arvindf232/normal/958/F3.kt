
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.cos
import kotlin.math.sin
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
            ret = ret modM (invStore[r])
            return ret
        }

    }
}

class FFT {
    companion object{
        //        val fftmod = 7340033
//        val root = 5
//        val root_1 = 4404020
//        val root_pw = 1 shl 20
        private const val fftmod = 998244353
        private const val root = 15311432
        private const val root_1 = 469870224
        private const val root_pw = 1 shl 23

        fun calculateRoot(){
            println("root :$root")
            //   intPow(3,7 * 17,fftmod)
            println("root_1 : $root_1")
            //       intPow(root,fftmod -2,fftmod)
        }

        fun fft(a:IntArray,invert:Boolean){
            val n = a.size
            var j = 0


            for(i in 1 until n){
                var bit = n shr 1
                while(j and bit > 0){
                    j = j xor bit
                    bit = bit shr 1
                }
                j = j xor bit
                if(i < j){
                    val temp = a[i]
                    a[i] = a[j]
                    a[j] = temp
                }
            }
            var len = 2
            while(len <= n){
                var wlen = if(invert) root_1 else root
                var i = len
                while(i < root_pw){
                    wlen = (1L * wlen * wlen % fftmod).toInt()
                    i = i shl 1
                }
                i = 0
                while(i < n){
                    var w = 1
                    for(j in 0 until len/2){
                        val u = a[i+j]
                        val v = (1L * a[i+j+len/2] * w % fftmod).toInt()
                        a[i+j] = if(u+v < fftmod) u + v else u + v - fftmod
                        a[i+j+len/2] = if(u-v >= 0) u-v else u-v+fftmod
                        w = (1L * w * wlen % fftmod).toInt()
                    }
                    i += len
                }
                len = len shl 1
            }
            if(invert){
                val n_1 = pow(n.toLong(),(fftmod-2).toLong(),fftmod.toLong())
                for((i,x) in a.withIndex()){
                    a[i] = (1L * x * n_1 % fftmod).toInt()
                }
            }
        }
        fun fullconvolution(at:IntArray,bt:IntArray):IntArray{
            return fullconvolutionOpt(at,bt,at.size,bt.size)
        }
        fun fft1009(a:IntArray, b:IntArray):IntArray {
            val ret = fullconvolution(a,b)
            for(i in ret.indices){
                ret[i] = ret[i] % 1009
            }
            return ret
        }

        fun fullconvolutionOpt(at:IntArray,bt:IntArray,sizeA:Int,sizeB:Int):IntArray{
            // 1 shl 18 done in 77 ms
            val maxSize = (sizeA + sizeB).takeHighestOneBit() * 2
            val a = at.copyOf(maxSize)
            val b = bt.copyOf(maxSize)
            val expectedSize = at.size + bt.size - 1
            fft(a,false)
            fft(b,false)
            val new = IntArray(maxSize)
            for(i in new.indices){
                new[i] = (1L * a[i] * b[i] % fftmod).toInt()
            }
            fft(new,true)
            return new.copyOf(expectedSize)
        }
    }
}
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
    const val PI = Math.PI
    const val epsilon = 0.5
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
    fun convoluteInt(a:IntArray, b:IntArray):IntArray{
        // 100k + 100k, 60ms average with 15 convolutions
        val sizeA = a.size
        val sizeB = b.size
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
        return IntArray(sizeA + sizeB - 1){((newR[it] + epsilon).toLong() % 1009).toInt()}
    }
}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val k = getint

        val L = getline(n)
        val counts = IntArray(m+1)
        for(a in L){
            counts[a] ++
        }
        val actualthings = mutableListOf<Int>()
        for(a in counts){
            if(a == 0) continue
            actualthings.add(a)
        }
        fun solve(l:Int,r:Int):IntArray{
            if(l == r){
                val here = actualthings[l]
                return IntArray(here+1){1}
            }
            val mid = (l + r) shr 1

            val left = solve(l,mid)
            val right = solve(mid+1,r)
            return FFT_double.convoluteInt(left,right)
        }
        val ret = solve(0,actualthings.lastIndex)
        put(ret[k])

    }
    done()
}