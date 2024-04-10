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


fun main() {
	cases{
		val n = getint()
		val L = getline(n).map{it - 1 }.toIntArray()

//		val Lcount = IntArray(n)
//		for(l in L){
//			Lcount[l]++
//		}
//		val maximum = Lcount.count{it >= 1 }

		val ret = IntArray(n){it}
		val by = IntArray(n){it}

		for(i in 0 until n){
			val to = L[i]
			val other = by[to]

			ret[other] = ret[i]
			by[ret[i]] = other
			ret[i] = to
			by[to] = i
		}
		for(i in 0 until n){
			if(ret[i] == i){
				val to = L[i]
				val other = by[to]

				ret[other] = ret[i]
				by[ret[i]] = other
				ret[i] = to
				by[to] = i
			}
		}

		val valid = (0 until n).count{L[it] == ret[it]}
		put(valid)
		put(ret.map{it+1}.joinToString(" "))

//		val given = IntArray(n)
//		val ret = IntArray(n)
//		for(i in 0 until n){
//			val giving = L[i]
//			if(given[giving] >= 1 ){
//				ret[i] = -1
//			}else{
//				given[giving] = 1
//				ret[i] = giving
//			}
//		}
//		val badSizes = ret.count{it == -1}
//		if(badSizes == 1){
//			val didNotGet  = given.indexOfFirst { it == 0 }
//			val didNotgive = ret.indexOfFirst { it == -1 }
//			if(didNotGet != didNotgive){
//				ret[didNotgive] = didNotGet
//			}else{
//				val tryingToGift = L[didNotgive]
//				val swapping = ret.indexOfFirst { it == tryingToGift }
//				ret[swapping] = didNotgive
//				ret[didNotgive] = tryingToGift
//			}
//		}



	}
	done()
    // Write your solution here
}