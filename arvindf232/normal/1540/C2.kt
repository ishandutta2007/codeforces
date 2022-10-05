/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
}

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`: BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char: Char
		get() {
			while (bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch (e: Exception) {
					return NC
				}
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
		while (c >= '0' && c <= '9') {
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
		while (c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextString():String{
		if (c == NC) c = char
		val ret = StringBuilder()
		while (true){
			c = char
			if(!isWhitespace(c)){ break}
		}
		ret.appendCodePoint(c.toInt())
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.appendCodePoint(c.toInt());

		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}
class reading{
	companion object{
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}
fun put(aa:Any){ reading.pw.println(aa)}
fun done(){ reading.pw.close() }

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
	get() = this.joinToString("")
infix fun Any.dei(a:Any){
	//does not stand for anything it is just easy to type
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
infix fun Int.modM(b:Int):Int{
	return ((this * 1L * b) % pI).toInt()
}

fun prefixSum(arr:List<Int>):MutableList<Int>{
	val ret = mutableListOf<Int>()
	ret.add(0)

	var previous = 0
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}

infix fun Int.divCeil(b:Int):Int{
	//Positives numbers only!
	if(this == 0) {
		return 0
	}
	return (this-1)/b + 1
}
fun Int.adjust():Int{
	if(this >= pI){
		return this  - pI
	}else if (this < 0){
		return this + pI
	}
	return this
}
infix fun Long.divCeil(b:Long):Long{
	//Positives numbers only!
	if(this == 0L) {
		return 0
	}
	return (this-1)/b + 1
}
const val p = 1000000007L
const val pI = p.toInt()
infix fun Long.modM(b:Long):Long{
	return (this * b) % p
}

class tempIntervalSum(val n:Int){
	val things = IntArray(n + 1)

	fun add(l:Int,r:Int,inc:Int){
		val ll = if(l < 0 ) 0 else l
		val rr = if(r > n-1) n else r + 1
		things[ll] += inc
		things[rr] -= inc
		things[ll] = things[ll].adjust()
		things[rr] = things[rr].adjust()
	}
	fun compile():IntArray{
		val ret = IntArray(n)
		var here = 0
		for(i in 0 until n){
			here += things[i]
			here = here.adjust()
			ret[i] = here
		}
		return ret
	}

}


fun main() {
	val n = getint()
	val Ci = getline(n)
	val Bi = getline(n-1)
	val q = getint()
	val qis = getline(q)


	val lowerAllow = IntArray(n)
	val upperAllow = IntArray(n)

	val BprefixSum = prefixSum(Bi)

	for(i in 0 until n){
		lowerAllow[i] = 0 - BprefixSum[i]
		upperAllow[i] = Ci[i] - BprefixSum[i]
	}

	val lowerAllowAverage = prefixSum(lowerAllow.toList()).mapIndexed{i,v -> if(i == 0) 0 else v / i }.drop(1)
	val upperAllowAverage = prefixSum(upperAllow.toList()).mapIndexed{i,v -> if(i == 0) 0 else v / i }.drop(1)


	val lowerBound = lowerAllowAverage.minOrNull()!! - 1
	val upperBound = upperAllowAverage.minOrNull()!! + 1

	val x = 0


	val nothingAnswer = 0L
	val everythingAnswer = Ci.map{it + 1}.reduce{ a, b -> a modM b}
	// Write your solution here


	fun answer(q:Int):Int {
		var DP = IntArray(1)
		DP[0] = 1
		var offSet = 0L
		for(i in 0 until n ){
			val intervalSize = Ci[i]
			val newBT =tempIntervalSum(DP.size + intervalSize)
			val newOffSet = offSet + lowerAllow[i]

			for(t in DP.indices){
				val lower = t
				val upper = t + intervalSize
				newBT.add(lower,upper,DP[t])
			}
			val ret = newBT.compile()

			val banLimit = minOf((q * (i+1)) - newOffSet , ret.size.toLong()).toInt()
//			just dei banLimit
			for( banned in 0 until banLimit){
				ret[banned] = 0
			}
			DP = ret
			offSet = newOffSet

//			offSet dei DP
		}
		return ((DP.reduce{ a, b -> (a+b).adjust()}))
	}

	val cache = mutableMapOf<Int,Int>()
	for(q in qis){
		if( q < lowerBound){
			put(everythingAnswer)
		}else if(q > upperBound){
			put(nothingAnswer)
		}else{
			if(cache[q] != null){
				put(cache[q]!!)
			}else{
				val ret = answer(q)
				cache[q] = ret
				put(ret)
			}
		}
	}
	done()
}

/*
3
2 3 4
0 0
1
1

 */