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
//        if (c == NC) c = char
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
		IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
	}
	fun takeFile(name:String){
		IN = BufferedInputStream(File(name).inputStream(),BS)
	}

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
	if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
	else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
	else if(aa is List<*>){IO.fakein.append(aa.toString())}
	else{IO.fakein.append(aa.toString())}
	IO.fakein.append("\n")
}

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

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
fun crash(){
	throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
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
	inline fun cases(a:solve.()->Unit){
		val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount

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
			a()
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
var p = 1000000007L
var pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteritsic function

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
infix fun Int.modM(b:Int):Int{
	return ((this * 1L * b) % p).toInt()
}
infix fun Int.modPlus(b:Int):Int{
	return (this + b).adjust()
}
infix fun Int.modMinus(b:Int):Int{
	return (this - b).adjust()
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
			for(i in 1..r){
				ret = ret modM (invStore[i])
			}
			return ret
		}

	}
}
const val HighestBit = 30
inline fun Int.eachBits(act:(Int)->Unit){
	for(i in HighestBit - 1 downTo 0){
		if(this and (1 shl i) != 0){
			act(1 shl i)
		}
	}
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
	for(i in HighestBit -1  downTo 0){
		if(this and (1 shl i) != 0){
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
	for(i in 0 until HighestBit){
		if(this and (1 shl i) != 0){
			act(this - (1 shl i))
		}
	}
}
inline fun Int.eachUp1(act:(Int)->Unit){
	for(i in 0 until HighestBit){
		if(this and (1 shl i) == 0){
			act(this + (1 shl i))
		}
	}
}
fun Int.hasElement(a:Int):Boolean{
	return (this and ( 1 shl a)) != 0
}
fun Int.allexceptlast(a:Int):Int{
	val mask = (1 shl a) - 1
	return (this and (mask).inv())
}
inline fun Int.breakIntoIntervals(act:(Int,Int)->Unit){ // inclusive
	val a = this + 1
	for(k in 30 downTo 0){
		if(!a.hasElement(k)) continue
		act(allexceptlast(k + 1),k)
	}
}
data class br(val start:Int,val i:Int){// binary range
init{
	kotlin.assert(start and ((1 shl i) - 1) == 0)
}
	fun print(){
		println("[$start, ${start + (1 shl i) - 1 }]")
	}
}
fun rangeIntervalBreaks(left:Int,right:Int,act:(Int,Int)->Unit){
	var left = left
	val right = right + 1
	for(k in 0 until HighestBit){
		if(left.hasElement(k) && left + (1 shl k) <= right){
			act(left,k)
			left += 1 shl k
		}
	}
	for(k in HighestBit -1 downTo 0 ){
		if(right.hasElement(k) && !left.hasElement(k)){
			act(left,k)
			left += 1 shl k
		}
	}
}
class matrix(val n:Int,val m:Int) {
	companion object{
		const val modded = true
		var p = 1000000007

		fun localMul(a:Int,b:Int):Int{
			return ((1L * a * b) % p).toInt()
		}
		fun Int.localAdjust():Int{
			return if(this > p) this - p else if(this <0) this + p else this
		}
		fun localDivide(a:Int,d:Int):Int{
			return localMul(a, intPow(d,p-2,p))
		}

		fun identity(n:Int):matrix{
			val ret = matrix(n,n)
			for(i in 0 until n){
				ret.A[i][i] = 1
			}
			return ret
		}
		fun standardTriangle(n:Int):matrix{
			val ret = matrix(n,n)
			for(i in 0 until n){
				ret.A[i][i] = 1
			}
			for(i in 1 until n){
				ret.A[i-1][i] = 1
			}
			return ret
		}
	}
	val A = MutableList(n){IntArray(m)}

	operator fun get(i:Int):IntArray{
		return A[i]
	}

	infix fun multiply(other:matrix):matrix{
		assert(m == other.n)
		val ret = matrix(n,other.m)
		for(i in 0 until n){
			for(k in 0 until m){
				for(j in 0 until other.m){
					if(modded){
						ret.A[i][j] += ((1L * A[i][k] * other.A[k][j]) % p).toInt()
						if(ret.A[i][j] >= p){
							ret.A[i][j] -= p
						}
					}else{
						ret.A[i][j] += A[i][k] * other.A[k][j]
					}

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

	fun elimination():IntArray?{
		assert(modded)
//        assert(answer.size == this.n)
		//Always vertical

		val where = IntArray(m){-1}
		var row = 0
		val m = this.m - 1
		for(col in 0 until m){
			for(i in row until n){
				if(A[i][col] != 0){
					Collections.swap(A,i,row)
					break
				}
			}
			if(A[row][col] == 0) continue
			where[col] = row
			for(i in 0 until n){
				val inv = intPow(A[row][col],p-2,p)
				if(i != row && A[i][col] != 0){
					val c = localMul(A[i][col],inv)
					for(j in col..m){
						A[i][j] -= localMul(A[row][j],c)
						A[i][j] = A[i][j].localAdjust()
					}
				}
			}
			row ++
		}
		val ret = IntArray(m){0}
		for(i in 0 until m){
			if(where[i] != -1){
				ret[i] = localDivide(A[where[i]][m],A[where[i]][i])
			}
		}
		for(i in 0 until n){
			var sum = 0
			for(j in 0 until m){
				sum += localMul(ret[j],A[i][j])
				sum = sum.localAdjust()
			}
			if( sum != A[i][m]){
				return null
			}
		}
		if(where.any { it == -1 }){
			//infinity
		}
		return ret



	}
}

data class instr(val type:Int,val first:Int, val second:Int){

}

sealed class high{

}
object X:high()
object Y:high()
object ONE:high()
 class sum(val a:high, val b:high):high()
 class lift(val a:high):high()
class square(val a:high):high()
 class subtract(val a:high,val b:high ):high()
 class times(val a:high, val c:Int):high()


fun ret():high{
	val A = subtract(square(sum(X,Y)),sum(square(X),square(Y)))
	return times(A,(2).inverse())
}

const val singleCase = true
const val withBruteForce = false
const val randCount = 100

var eliminator = IntArray(0)

var d:Int  = 0
fun main(){
//	solve.tc{
//		share("5 1299827")
//	}
//	solve.usetc()
	solve.cases{
		d = getint()
		val pg = getint()
		p = pg.toLong()
		pI = pg
		FACT.preCal(20)
		matrix.p = pg

		val M = matrix(d+1,d+2)
		M[d][0] = 1
		for(i in 0..d){
			for(j in 0 until d){
				M[i][j+1] = FACT.choose(d,i) modM intPow(j,i,pI)
			}
		}

		M[d-2][d+1] = 1
//		M.print()
		eliminator = M.elimination()!!
		ZERO = times(ONE,pI)



		constants = MutableList<high>(d+1){ONE}
		for(i in 2..constants.lastIndex){
			val new = sum(ONE,constants[i-1])
			constants[i] = new
		}
//		val a = times(ONE,100)
//		println(a.prim().depth())
//		val b = times(a,100)
//		println(b.prim().depth())
//		val c = sum(a,b)
//		println(c.prim().depth())
//		val d = square(c)
//		println(d.depth())
//		val e = square(d)
///		val e = d.prim()
//		println(d.prim().depth())
//		println(e.prim().depth())

//		0 dei ret().depth()
		val final2 = ret().prim()
//		1 dei final2.depth()
		val final = final2.compile()
		inst.add(instructions('f', intArrayOf(final)))

		for(i in inst){
			put("${i.c} ${i.arr.joinToString(" ")}")
		}
	}
	done()
}
val primestore:MutableMap<high,high> = mutableMapOf()

var constants = MutableList<high>(d+1){ONE}


fun square.equiv():high{
	val A = this.a.prim()
	val summed = MutableList<high>(d){sum(A,constants[it])}
	summed[0] = A
	val lifted = summed.map{lift(it)}
	val facted = lifted.mapIndexed{i,v -> times(v,eliminator[i+1]).prim()}
	val extra = times(ONE,eliminator[0]).prim()
	var total:high = extra
	for(f in facted){
		total = sum(total,f)
	}
	return total
}

fun times.equiv():high{
	val A = this.a.prim()
	val BI = MutableList(31){A}
	for(i in BI.indices){
		if(i == 0) continue
		BI[i] = sum(BI[i-1],BI[i-1])
	}
	var ret:high? = null
	c.eachBitIndex {
		if(ret == null){
			ret = BI[it]
		}else{
			ret = sum(ret!!,BI[it])
		}
	}
//	ret?.run { assert(isPrimitive()) }
	return if(ret != null) ret!! else ZERO.prim()

}
var ZERO:high = ONE


fun subtract.equiv():high{
	return sum(this.a.prim(),times(this.b.prim(),pI-1).prim())
}
fun sum.equiv():high{
	return sum(this.a.prim(),this.b.prim())
}
fun lift.equiv():high{
	return lift(this.a.prim())
}
fun high.isPrimitive():Boolean{
	return when(this){
		is X,Y,ONE -> true
		is sum -> this.a.isPrimitive() && this.b.isPrimitive()
		is lift -> this.a.isPrimitive()
		else -> return false
	}
}

fun high.prim():high{
	if(primestore[this] != null){
		return primestore[this]!!
	}
	val new = when(this){
		is X -> X
		is Y -> Y
		is ONE -> ONE
		is sum -> this.equiv()
		is lift -> this.equiv()
		is square -> this.equiv()
		is subtract -> this.equiv()
		is times -> this.equiv()
	}
//	assert(new.isPrimitive())
	primestore[this] = new
	return new
}
fun high.depth():Int{
	val counts = mutableSetOf<high>()

	fun search(x:high){
		if(counts.contains(x)) return
		counts.add(x)
		when(x){
			is X,Y,ONE -> return
			is sum ->{
				search(x.a)
				search(x.b)
			}

			is lift -> search(x.a)
			is square -> search(x.a)
			is subtract -> {
				search(x.a)
				search(x.b)
			}
			is times -> search(x.a)
		}
	}
	search(this)
	return counts.size
}
val compileHead = mutableMapOf<high,Int>()
data class instructions(val c:Char,val arr:IntArray){}
val inst = mutableListOf<instructions>()
var instructionhead = 3

fun sum.cc():Int{
	val x = a.compile()
	val y = b.compile()
	instructionhead++
	inst.add(instructions('+', intArrayOf(x,y,instructionhead)))
	return instructionhead
}
fun lift.cc():Int{
	val x = a.compile()
	instructionhead++
	inst.add(instructions('^', intArrayOf(x,instructionhead)))
	return instructionhead
}


fun high.compile():Int{
	if(compileHead[this] != null){
		return compileHead[this]!!
	}
	val ret = when(this){
		is X -> 1
		is Y -> 2
		is ONE -> 3
		is sum -> this.cc()
		is lift -> this.cc()
		else -> crash()
	} as Int
	compileHead[this] = ret
	return ret
}

/*
mistake: recursion: have to do full recursions
map taking mistake! HUge
data classes, but why
 */