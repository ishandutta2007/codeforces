/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.ln
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
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
const val p = 998244353L
const val pI = p.toInt()
infix fun Long.modM(b:Long):Long{
	return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
	return ((this * 1L * b) % p).toInt()
}

fun GS(start:Int,ratio:Int,count:Int) = sequence {
	var ret = 1
	for(i in 1..count){
		ret *= ratio
		yield(ret)
	}
}

const val sieveMx = 1000000
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
fun Int.numOfDivisors():Int{
	var ret = 1
	this.eachPrimePower { _, e -> ret *= (e+1) }
	return ret
}


fun Int.adjust():Int{
	if(this >= pI){
		return this  - pI
	}else if (this < 0){
		return this + pI
	}
	return this
}


fun main() {
	val n = getint()
	val DP = IntArray(n+1)
	DP[0] = 1
	var sumUpToNow = 1
	calculateSieveFast()
	for(i in 1..n){
//		i dei sumUpToNow
		val ret = sumUpToNow + i.numOfDivisors() -1
		DP[i] = ret
		sumUpToNow += DP[i]
		sumUpToNow = sumUpToNow.adjust()
	}
	put(DP[n])
	done()
    // Write your solution here
}