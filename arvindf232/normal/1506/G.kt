/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.reflect.KProperty0

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
fun put(aa:Any){
	reading.pw.println(aa)
}
fun done(){
	reading.pw.close()
}

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}


inline fun cases(ask:()->Unit){
	val t = getint()
	repeat(t){
		ask()
	}
}
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
fun minEndTransform(a:IntArray):IntArray{
	val ret = a.copyOf()
	for(i in a.lastIndex downTo 0){
		if(i == a.lastIndex){
			continue
		}
		ret[i] = minOf(ret[i],ret[i+1])
	}
	return ret
}
val just = " "
fun main() {
	cases{
		val str = getstr()
		val n = str.length
		val diversityMask = IntArray(n)
		for(i in n-1 downTo 0){
			val last = if(i == n-1) 0 else diversityMask[i+1]
			val here = str[i].toInt() - 'a'.toInt()
			val mod = 1 shl here
			val new = last or mod
			diversityMask[i] = new
		}
		val total = diversityMask[0]
		val k = total.countOneBits()


		val nextOccurence = List(26){IntArray(n){Int.MAX_VALUE} }
		for((i,a) in str.withIndex()){
			val here = a.toInt() - 'a'.toInt()
			nextOccurence[here][i] = i
		}
		val locater = nextOccurence.map{minEndTransform(it)}

		var ret = mutableListOf<Char>()
		var remaining = total
		var pointer = 0
		first@for(i in 0 until k){
			for(j in 25 downTo 0){
				if(remaining and (1 shl j) > 0 ){
					val new = remaining - (1 shl j)
					val check = locater[j][pointer]
					val mask = if(check == n-1) 0 else diversityMask[check+1]
					if(new and (mask.inv()) == 0){
						ret.add(('a'.toInt() + j).toChar())
						pointer = check + 1
						remaining = new
						continue@first
					}
				}
			}
		}
		put(ret.joinToString(""))

	}
	done()
    // Write your solution here
}