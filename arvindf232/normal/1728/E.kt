// 2022.09.08 at 15:55:21 BST
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
infix fun Int.modMinus(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this modM (b.inverse()) }
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
// 3. convenience conversions
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
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
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun eat(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>()}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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

tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
fun lcm(a:Long, b:Long):Long{
	return (a * b) / gcd(a,b)
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
fun firstpositive(x:Int,mod:Int):Int{
	return x - (x div_neg_floor mod) * mod
}
fun firstpositive(x:Long,mod:Int):Int{
	return (x - (x div_neg_floor mod.toLong()) * mod ).toInt()
}

fun extendedGCD(p: Int, q: Int): IntArray {
	if (q == 0) return intArrayOf(p, 1, 0)
	val vals: IntArray = extendedGCD(q, p % q)
	val d = vals[0]
	val a = vals[2]
	val b = vals[1] - p / q * vals[2]
	return intArrayOf(d, a, b)
}
fun extendedInverse(a:Int,m:Int):Int?{
	val ans = extendedGCD(a,m)

	if(ans[0] != 1){
		return null
	}else{
		val ret = ans[1]
		return if(ret < 0) ret + m else ret
	}
}

// try to solve mx + ny = s
//find smallest possible x
fun diophatine(m:Int, n:Int, s:Int):Int? {
	val g = gcd(m,n)
	if(s % g != 0) return null
	val m = m/g
	val n = n/g
	val s = s/g

	val attempt = (extendedInverse(m,n)) !!

	val xguess = firstpositive(s.toLong() * attempt, n )
	if(xguess.toLong() * m <= s){
		return xguess
	}else{
		return null
	}
}
//m,c,x:  ma+c for a in 0..x
fun diophatineFull(m:Int, n:Int, s:Int):Triple<Int,Int,Int>? {
	val g = gcd(m,n)
	if(s % g != 0) return null
	val m = m/g
	val n = n/g
	val s = s/g

	val attempt = (extendedInverse(m,n)) !!

	val xguess = firstpositive(s.toLong() * attempt, n )
	if(xguess.toLong() * m <= s){
		val slope = n
		val start = xguess
		val max = (s - xguess * m.toLong())/(m.toLong() * n.toLong())
		return Triple(slope,start,max.toInt())
	}else{
		return null
	}
}

inline fun intTenarySearch(l:Int, r:Int, f:(Int)->Long):Int{
	var l = l-1
	var r = r
	while(r -l >1 ){
		val mid = (l + r ) shr 1
		if(f(mid) > f(mid+1)){
			r = mid
		}else{
			l = mid
		}
	}
	return l + 1
}
const val singleCase = true
fun main(){


//	just dei diophatineFull(12542,19,300000)!!
	solve.tc {
		share(300000)
		repeat(300000){
			share(Random.nextInt(plarge))
			share(Random.nextInt(plarge))
		}
		share(300000)
		repeat(300000){
			share(Random.nextInt(1..300000))
			share(Random.nextInt(1..300000))
		}
	}
//	solve.usetc()

//	just dei diophatineFull(2,3,10)!!
//
//	repeat(10000){
//		val x = Random.nextInt(1..300000)
//		val y = Random.nextInt(1..300000)
//		val k =  diophatineFull(x,y,300000)
//	}
//	just dei "ok"
//	val (slope,start,max) = diophatineFull(2,3,11)!!
//
//	for(i in 0..max){
//		just dei (slope * i + start)
//	}
//	just dei diophatine(4,5,21)!!
    solve.cases{
		val n = getint
		val A= IntArray(n)
		val B = IntArray(n)
		val options = mint
		var base = 0L
		repeat(n){
			A[it] = getint
			B[it] = getint

			base += B[it]
			options.add(A[it] - B[it])
		}
		options.sortDescending()
		val answer = LongArray(n+1){base}
		var now = 0L
		for(i in 0 until n){
			now += options[i]
			answer[i+1] += now
		}

		val m = getint
		repeat(m){
			val x = getint
			val y = getint

			val possible = diophatineFull(x,y,n)

			if(possible == null){
				put(-1)
				return@repeat
			}
			val (slope, start, max) = possible

			val best = intTenarySearch(0,max){
				answer[(it * slope + start) * x]
			}
			put(answer[(best * slope + start) * x])



//			val inv = extendedInverse(x)

		}
//		just dei answer




    }
    done()
}



/*


12542
19

55  18975
 */