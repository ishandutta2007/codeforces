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

data class pair(val a:Int , val b:Int){
	val aa:Int get() = minOf(a,b)
	val bb:Int get() = maxOf(a,b)

	fun pos(c:Int):Boolean{
		if(c <bb && c > aa){
			return true
		}
		return false
	}

	fun intersect(other:pair):Boolean {
		return !(pos(other.a) == pos(other.b))
	}
}

fun main() {
	cases{
		val n = getint()
		val k = getint()
		val items = mutableListOf<pair>()
		repeat(k){
			items.add(pair(getint() - 1,getint() - 1 ))
		}
		val taken:IntArray = IntArray(2 * n)
		for(a in items){
			taken[a.a] = 1
			taken[a.b] = 1
		}
		val order:IntArray = IntArray(2 * n)
		var now = 0
		for(i in 0 until 2 * n) {
			if(taken[i] > 0) continue
			order[now] = i
			now += 1
		}
		for(i in 0 until (n-k)){
			val b = i + (n-k)
			items.add(pair(order[i],order[b]))
		}
		var ret = 0
		for(i in items.indices){
			for(j in i+1..items.lastIndex){
				if(items[i].intersect(items[j])){
					ret += 1
				}
			}
		}
		put(ret)
//		fun pair.slice():Int{
//			var left:Int = 0
//			var right = 0
//			for(i in 0 until 2 * n){
//				if(taken[i] > 0){
//					continue
//				}
//				if(i < this.bb && i > this.aa){
//					right += 1
//				}else{
//					left += 1
//				}
//			}
//			return minOf(left,right)
//		}
//		var ret = 0
//		for(i in items){
//			ret += i.slice()
//		}
//		val rem = n - k
//		val count = (rem) * (rem -1 )/2
//		ret += count
//		put(ret)
	}
	done()
    // Write your solution here
}