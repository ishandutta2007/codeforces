import kotlin.math.ln

/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */


import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
import kotlin.system.measureTimeMillis
fun GS(start:Int,ratio:Int,count:Int) = sequence {
	var ret = 1
	for(i in 1..count){
		ret *= ratio
		yield(ret)
	}
}

const val sieveMx = 4000000
val primeOf = IntArray(sieveMx + 1)
var primeCounter = 0
val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
val primes = IntArray(primeUpperBound)
var sieveCalculated = false

fun calculateSieveFast(){
	if(sieveCalculated){
		return
	}
	sieveCalculated = true
	for(i in 2..sieveMx){
		if(primeOf[i] == 0 ){
			primeOf[i] = i
			primes[primeCounter] = i
			primeCounter += 1
		}
		for(j in 0 until primeCounter){
			val p = primes[j]
			val pd = p * i
			if(p <= i && pd <= sieveMx){
				primeOf[pd] = p
			}else{
				break
			}
		}
	}
}
fun isPrimeLookup(a:Int):Boolean{
	return primeOf[a] == a
}
inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
	var p = 1
	var count = 0
	var a = this
	while(a > 1){
		val next = primeOf[a]
		a /= next
		if(next == p){
			count += 1
		}else{
			if(count != 0){
				act(p,count)
			}
			p = next
			count = 1
		}
	}
	if(p != 1){
		act(p,count)
	}

}
fun Int.primes():List<Int>{
	val ret = mutableListOf<Int>()
	this.eachPrimePower { a, p -> ret.add(a) }
	return ret
}
fun Int.factors():List<Int>{
	val ret = mutableListOf(1)
	this.eachPrimePower { p, e ->
		val s = ret.toList()
		for(pn in GS(p,p,e)){
			ret.addAll(s.map{it * pn})
		}
	}
	return ret
}
fun totient(a:Int):Int{
	var ret = a
	a.eachPrimePower{
			p, _ ->
		ret /= p
		ret *= (p-1)
	}
	return ret
}
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

fun force(a:Int){
	val DP = IntArray(a+1)
	DP[1] = 1
	for(i in 2 until a){
		var ret = 0
		for(j in 1 until i){
			ret += DP[j]
		}
		for(j in 2..i){
			val new = i/j
			ret += DP[new]
		}
		DP[i] = ret
	}
	println(DP.slice(25..35).joinToString(" "))

	for(i in 1..100){
		println("$i ${DP[i] - 2 * DP[i-1]}")
	}
}


fun main() {
//	force(100)
	calculateSieveFast()
	val a = getint()
	val m = getint()
//	val a = 100
//	val m = 1000000

	val DP = IntArray(a+1)
	val sums = IntArray(a+1)

	fun Int.adjust():Int{
		if(this >= m){
			return this  - m
		}else if (this < 0){
			return this + m
		}
		return this
	}

	fun paired(a:Int):Int{
		return ((sums[a] + DP[a]).adjust() - DP[a-1]).adjust()
	}

	DP[0] = 1
	DP[1] = 1
	for(i in 2..a){
		var ret = 0
		ret += DP[i-1]
		ret = ret.adjust()
		ret += DP[i-1]
		if(i >= 3){
			ret += 1
		}
		ret = ret.adjust()



		val ps = i.primes()
		val ans:Int
		if(ps.size == 1){
			val p = ps[0]
			ans = paired(i/p)
			sums[i] = ans
		}else if(ps.size == 2){
			val p = ps[0]
			val q = ps[1]
			ans = ((paired(i/p) + paired(i/q)).adjust() - paired((i/p)/q)).adjust()
			sums[i] = ans
		}else{
			val k = ps.size
			var ans2 = 0
			for(i4 in 1 until (1 shl k)){
				var here = i
				val parity = i4.countOneBits() % 2 == 1
				for(j in 0 until k){
					if((1 shl j) and i4 >0){
						here /= ps[j]
					}
				}
				if(parity){
					ans2 += paired(here)
				}else{
					ans2 -= paired(here)
				}
				ans2 = ans2.adjust()

			}
			ans = ans2
			sums[i] = ans
		}
		ret += ans
		ret = ret.adjust()

//		for(c in i.factors()){
//			if(c == 1 || c== i) {
//				continue
//			}
//			ret += (DP[c] - DP[c-1])
//			ret = ret.adjust()
//		}
		DP[i] = ret
	}
//	just dei DP.slice(25..35)
//	2 dei sums
	put(DP[a])
	done()
    // Write your solution here
}