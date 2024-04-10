/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

any
 	- pick the least

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
		val acode = 'a'.toInt()
		val codes = CharArray(26)

		for(i in 0 until 26){
			val newc = (acode + i).toChar()
			codes[i] = newc
		}
		val str = getstr()
		val cas = IntArray(26)
		for(c in str){
			val code = c.toInt() - 'a'.toInt()
			cas[code] += 1
		}
		val totalChars = str.length
		val is0 = cas.any{it == 1}
		val ret = mutableListOf<Char>()

		fun Int.asChar():Char{
			return codes[this]
		}
		if(is0){
			val first0 = cas.indexOfFirst { it == 1 }
			ret.add(first0.asChar())
			cas[first0] = 0
			for(i in 0 until 26){
				repeat(cas[i]){
					ret.add(i.asChar())
				}
			}
		}else{
			val smallest = cas.indexOfFirst { it >= 1  }
			val atmost = (totalChars /2 ) + 1
			val smallestCount = cas[smallest]

				val leftPile = mutableListOf<Char>()
				val rightPile = mutableListOf<Char>()

			if(smallestCount <= atmost) {
				repeat(smallestCount) {
					leftPile.add(smallest.asChar())
				}
				for(i in 25 downTo smallest + 1) {
					repeat(cas[i]) {
						rightPile.add(i.asChar())
					}
				}

				ret.add(leftPile.removeLast())
				ret.add(leftPile.removeLast())

				while(leftPile.size > 0 || rightPile.size > 0) {
					rightPile.removeLastOrNull()?.let { ret.add(it) }
					leftPile.removeLastOrNull()?.let { ret.add(it) }
				}
			}else{
				val nextSmallest = (0 until 26).firstOrNull{it != smallest && cas[it] >= 1}
				val thirdSmallest = (0 until 26).firstOrNull{it != smallest && it != nextSmallest && cas[it] >= 1}
				if(nextSmallest == null){
					repeat(cas[smallest]){
						ret.add(smallest.asChar())
					}
				}else if(thirdSmallest == null){

					ret.add(smallest.asChar())
					cas[smallest] --
					repeat(cas[nextSmallest]){
						ret.add(nextSmallest.asChar())
					}
					repeat(cas[smallest]){
						ret.add(smallest.asChar())
					}
				}else{
					ret.add(smallest.asChar())
					ret.add(nextSmallest.asChar())
					cas[smallest] --
					cas[nextSmallest] --
					repeat(cas[smallest]){
						ret.add(smallest.asChar())
					}
					cas[smallest] = 0
					ret.add(thirdSmallest.asChar())
					cas[thirdSmallest] --
					for(i in 0 until 26){
						repeat(cas[i]){
							ret.add(i.asChar())
						}
					}
				}
			}

		}
		put(ret.joinToString(""))
	}
	done()
    // Write your solution here
}