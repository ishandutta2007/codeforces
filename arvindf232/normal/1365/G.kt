// 2022-05-29, Sun, 13:21
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

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
class HopcroftKarp constructor(val n1: Int, val n2: Int, maxedges:Int) {
	var edges = 0
	var last: IntArray
	var prev: IntArray
	var head: IntArray
	var matching: IntArray
	var dist: IntArray
	var Q: IntArray
	var used: BooleanArray
	var vis: BooleanArray

	init {
		last = IntArray(n1+2)
		prev = IntArray(maxedges + 5)
		head = IntArray(maxedges + 5)
		matching = IntArray(n2+2)
		dist = IntArray(n1+2)
		Q = IntArray(n1+2)
		used = BooleanArray(n1+2)
		vis = BooleanArray(n1+2)
		Arrays.fill(last, -1)
	}

	fun addEdge(u: Int, v: Int) {
		head[edges] = v
		prev[edges] = last[u]
		last[u] = edges++
//        just dei "$u $v"
	}

	fun bfs() {
		Arrays.fill(dist, -1)
		var sizeQ = 0
		for (u in 0 until n1) {
			if (!used[u]) {
				Q[sizeQ++] = u
				dist[u] = 0
			}
		}
		var i = 0
		while(i < sizeQ){
			val u1 = Q[i]
			var e = last[u1]
			while (e >= 0) {
				val u2 = matching[head[e]]
				if (u2 >= 0 && dist[u2] < 0) {
					dist[u2] = dist[u1] + 1
					Q[sizeQ++] = u2
				}
				e = prev[e]
			}
			i ++
		}
	}

	fun dfs(u1: Int): Boolean {
		vis[u1] = true
		var e = last[u1]
		while (e >= 0) {
			val v = head[e]
			val u2 = matching[v]
			if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
				matching[v] = u1
				used[u1] = true
				return true
			}
			e = prev[e]
		}
		return false
	}

	fun maxMatching(): Int {
		Arrays.fill(used, false)
		Arrays.fill(matching, -1)
		var res = 0
		while (true) {
			bfs()
			Arrays.fill(vis, false)
			var f = 0
			for (u in 0 until n1) {
				if (!used[u] && dfs(u)) {
					f++
				}
			}
			if (f == 0) {
				return res
			}
			res += f
		}
	}
}
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
fun debug(){}
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
const val fake = false
var fakeans = longArrayOf(1,2,4)
//var fakeans = LongArray(4){kotlin.random.Random.nextLong(88888)}
//var fakeans = LongArray(4){kotlin.random.Random.nextLong(1L shl 62)}
const val singleCase = true
fun main(){

	solve.rand{
		fakeans = LongArray(1000){kotlin.random.Random.nextLong(1L shl 62 )}
	}
//	solve.userand()
//	fun attemptfilter(n:Int,st:List<Int>):Boolean {
//		val clean = mutableSetOf<Int>()
//		val bad = mutableSetOf<Int>()
//		for(m in 0 until (1 shl n)){
//			var ret = 0
//			for((j,s) in st.withIndex()){
//				val new = (s and m) != 0
//				ret += (new.chi) shl j
//			}
//			if(m.countOneBits() == 1){
//				clean.add(ret)
//			}else{
//				bad.add(ret)
//			}
//		}
//		return bad.all { it !in clean }
//	}
//	repeat(10000){
//		val new = List(6){Random.nextInt(256)}
//		if(attemptfilter(8,new)){
//			for(a in new){
//				just dei a.toString(2).padStart(8,'0')
//			}
//			return
//		}
//	}
//

    solve.cases{
		val n = if(fake) fakeans.size else getint
		val embedding = mint
		for(i in 0 until ( 1 shl 13)){
			if(i.countOneBits() == 6){
				embedding.add(i)
			}
		}

		var qs = 0
		fun ask(a:List<Int>):Long {
			if(a.size ==0 ){
				return 0L
			}
			qs ++
			if(qs > 13){
				println("QUERIES DIED")
			}

			println("? ${a.size}")
			println(a.map{it+1}.conca())
			System.out.flush()
			if(fake){
				var ret = 0L
				for(c in a){
					ret = ret or fakeans[c]
				}
				return ret
			}
			return getlong
		}

		val info = LongArray(13)
		for(i in 0 until 13){
			val uses = (0 until n).filter { embedding[it].has(i)}
			if(uses.isEmpty()) continue

			info[i] = ask(uses)
		}
		val guess = IntArray(63)
		for(i in 0 until 63){
			var new = 0
			for((j,ans) in info.withIndex()){
				if(ans.has(i)) {
					new += (1 shl j )
				}
			}
			guess[i] = new
		}
		val haveAny = BooleanArray(63){guess[it].countOneBits() > 0}
		val doubles = BooleanArray(63){guess[it].countOneBits() > 6}

		val finalret = LongArray(n)
		for(i in 0 until 63){
			if(haveAny[i] == false) continue
			if(doubles[i]){
				for(j in 0 until n){
					finalret[j] = finalret[j] xor ( 1L shl i )
				}
			}else{
				for(j in 0 until n){
					if(embedding[j] != guess[i]){
						finalret[j] = finalret[j] xor ( 1L shl i )
					}
				}
			}
		}
		println("! ${finalret.conca}")
		System.out.flush()
		if(fake){
			val got = LongArray(n)
			for(i in 0 until n){
				for(j in 0 until n){
					if(i == j ) continue
					got[i] = got[i] or fakeans[j]
				}
			}
			assert(got.contentEquals(finalret))
		}
    }
    done()
}




/*
 a or b = c
 mod 3 ?


 slow on each of the deductions
 not hard overall
 just that each deductions are hard to see
 slow
 slow


 first deduction: notice issuse with or
 second deductio:

 */