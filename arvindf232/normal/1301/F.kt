// 2022-03-29, Tue, 14:15
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.absoluteValue

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

typealias sparse2type = Long
typealias sparse2Col = LongArray
class sparseTable2D (val n :Int, val m:Int, val arr:Array<sparse2Col>){
	val ln = (31 - n.countLeadingZeroBits()) + 1
	val lm = (31 - m.countLeadingZeroBits()) + 1

	val st = Array(ln){Array(lm){Array(0){sparse2Col(0)} } }

	val empty = 0L
	fun combine(a:sparse2type, b:sparse2type):sparse2type{
		return a or b
	}
	init{
		for(ly in 0 until lm){
			if(ly == 0) {
				st[0][0] = Array(n) { x -> sparse2Col(m){y -> arr[x][y]} }
			}else{
				st[0][ly] = Array(n){x -> sparse2Col(m-(1 shl ly) + 1){y ->  combine(st[0][ly-1][x][y], st[0][ly-1][x][y+(1 shl (ly-1))])}}
			}
		}
		for(ux in 1 until ln){
			st[ux][0] = Array(n - (1 shl ux) +1){x -> sparse2Col(m){y -> combine(st[ux-1][0][x][y],st[ux-1][0][x+(1 shl (ux-1))][y]) } }
			for(ly in 1 until lm){
				st[ux][ly] = Array(n - (1 shl ux) + 1 ){x -> sparse2Col(m-(1 shl ly) + 1){y ->  combine(st[ux][ly-1][x][y], st[ux][ly-1][x][y+(1 shl (ly-1))])}}
			}
		}
	}
	fun query(x1:Int, x2:Int, y1:Int, y2:Int): Long {
		if(x2 < x1 || y2 < y1) {
			return empty
		}
		val dx = x2 - x1 + 1
		val ix = 31 - dx.countLeadingZeroBits()
		val sx = 1 shl ix
		val a1 = x1
		val a2 = x2 - sx + 1

		val dy = y2 - y1 + 1
		val iy = 31 - dy.countLeadingZeroBits()
		val sy = 1 shl iy
		val b1 = y1
		val b2 = y2 - sy + 1

		var ret = empty
		ret = combine(ret, st[ix][iy][a1][b1])
		ret = combine(ret, st[ix][iy][a1][b2])
		ret = combine(ret, st[ix][iy][a2][b1])
		ret = combine(ret, st[ix][iy][a2][b2])
		return ret
	}
}

inline fun Int.eachBits(act:(Int)->Unit){
    for(i in 30 downTo 0){
        if(this and (1 shl i) != 0){
            act(1 shl i)
        }
    }
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
    for(i in 30 -1  downTo 0){
        if(this and (1 shl i) != 0){
            act(i)
        }
    }
}
inline fun Long.eachBits(act:(Long)->Unit){
    for(i in 62 downTo 0){
        if(this and (1L shl i) != 0L){
            act(1L shl i)
        }
    }
}
inline fun Long.eachBitIndex(act:(Int)->Unit){
    for(i in 62 downTo 0){
        if(this and (1L shl i) != 0L){
            act(i)
        }
    }
}
inline fun Int.submask(act:(Int)->Unit){
    var here = this
    while (here > 0) {
        act(here)
        here = (here - 1) and this
    }
    act(here)
}
inline fun Int.eachDown1(act:(Int)->Unit){
    for(i in 0 until 30){
        if(this and (1 shl i) != 0){
            act(this - (1 shl i))
        }
    }
}
inline fun Int.eachUp1(act:(Int)->Unit){
    for(i in 0 until 30){
        if(this and (1 shl i) == 0){
            act(this + (1 shl i))
        }
    }
}
fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}
fun Long.hasElement(a:Int):Boolean{
    return (this and ( 1L shl a)) != 0L
}
fun Int.allexceptlast(a:Int):Int{
    return (this and ((1 shl a) - 1).inv())
}
inline fun Int.breakIntoIntervals(act:(Int,Int)->Unit){ // inclusive
    val a = this + 1
    for(k in 30 downTo 0){
        if(!a.hasElement(k)) continue
        act(allexceptlast(k + 1),k)
    }
}
inline fun Long.breakIntoIntervals(act:(Long,Int)->Unit){ // inclusive
    val a = this + 1
    for(k in 63 downTo 0){
        if(!a.hasElement(k)) continue
        act((this and ((1L shl (k+1)) - 1).inv()),k)
    }
}
data class br(val start:Int,val i:Int){// binary range
init{
    assert(start and (( 1 shl i ) - 1)== 0)
}
    fun print(){
        println("[$start, ${start + (1 shl i) - 1 }]")
    }
}
fun rangeIntervalBreaks(left:Int,right:Int,act:(Int,Int)->Unit){
    var left = left
    val right = right + 1
    for(k in 0..30){
        if(left.hasElement(k) && left + (1 shl k) <= right){
            act(left,k)
            left += 1 shl k
        }
    }
    for(k in 30 downTo 0 ){
        if(right.hasElement(k) && !left.hasElement(k)){
            act(left,k)
            left += 1 shl k
        }
    }
}

fun Int.anybitindex():Int{
    return this.highestBitsIndex
}
fun Int.isSubsetOf(other:Int):Boolean{
    return (this and other.inv()) == 0
}
fun Int.isSupersetOf(other:Int):Boolean{
    return (this.inv() and other) == 0
}
fun Long.isSubsetOf(other:Long):Boolean{
    return (this and other.inv()) == 0L
}
fun Long.isSupersetOf(other:Long):Boolean{
    return (this.inv() and other) == 0L
}
val Long.highestBitsIndex:Int
    get(){
        return 63 - this.countLeadingZeroBits()
    }

val Int.highestBitsIndex:Int
    get(){
        return 31 - this.countLeadingZeroBits()
    }
fun debug(){}
const val withBruteForce = false
const val singleCase = true
fun main(){
    solve.cases{
		val n = getint
		val m = getint
		val k = getint

		val shifts = m
		val table = Array(n){IntArray(m)}
//		val arr = Array(n+m){ LongArray(n+m+1)}

		val ans = Array(n){Array(m){ShortArray(k){6000} } }
		fun solve(reversed:Boolean){
			val last = Array(m){ShortArray(k){6000} }
			var x = if(reversed) n-1 else 0
			while(x in 0 until n){
				for(y in 0 until m){
					for(c in 0 until k){
						last[y][c] ++
					}
					val here = table[x][y]
					last[y][here] = 0
				}
				val dist = ShortArray(k){6000}
				for(y in 0 until m){
					for(c in 0 until k){
						var s = dist[c]
						s++
						dist[c] = minOf(s, last[y][c])
						ans[x][y][c] = minOf(ans[x][y][c],dist[c])
					}
				}
				dist.fill(6000)
				for(y in m-1 downTo 0){
					for(c in 0 until k){
						var s = dist[c]
						s ++
						dist[c] = minOf(s, last[y][c])
						ans[x][y][c] = minOf(ans[x][y][c],dist[c])
					}
				}

				if(reversed) x-- else x++
			}
		}
		for(x in 0 until n){
			for(y in 0 until m){
				table[x][y] = getint - 1
//				arr[x+y][x-y + shifts] = 1L shl table[x][y]
			}
		}
		solve(false)
		solve(true)


//		val Q = sparseTable2D(n+m,n+m+1,arr)

		val M = Array(k){IntArray(k){plarge} }

		fun eachdone(x:Int, y:Int):ShortArray{
			return ans[x][y]

		}

		for(x in 0 until n){
			for(y in 0 until m){
				val here = table[x][y]
				val dist = eachdone(x,y)
				for(other in 0 until k){
					M[here][other] = minOf(M[here][other],dist[other] + 2)
				}
			}
		}
		for(i in 0 until k){
			M[i][i] = 1
		}
		val s = k
		for(k in 0 until s){
			for(i in 0 until s){
				for(j in 0 until s){
					M[i][j] = minOf(M[i][j], M[i][k] + M[k][j]-1)
				}
			}
		}
		val q = getint
		repeat(q){
			val A = getline(4)
			for(i in 0 until 4) A[i] --
			val (x1,y1,x2,y2) = A
			val s = eachdone(x1,y1)
			val t = eachdone(x2,y2)
			val sc = table[x1][y1]
			val tc = table[x2][y2]
			if(x1 == x2 && y1 == y2){
				put(0)
				return@repeat
			}else if(sc == tc){
				put(1)
				return@repeat
			}
			var ret = (x1 - x2).absoluteValue + (y1 - y2).absoluteValue
			for(l in 0 until k ){
				for(r in 0 until k){
					ret = minOf(ret,s[l] + t[r] + M[l][r])
					val x = 0
				}
			}
			put(ret)

		}

        




    }
    done()
}



/*

100 mintues at least
WA
broken path pivots , is not clean
cannot just guess


MLEd because I didn't calculate it out


then another set of mistakes from the new table implementations
 */