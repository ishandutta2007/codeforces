/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 cannot exceed sum


 Q: can always attain sum?
 	hardest : exact

 : yes, just any combination that sums upto it


 if 1..k sums to something
 and has a

 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max
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


inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
	//inclusive
	var L = l
	var R = r
	while(L<R){
		val m = (L + R)/2
		if(isTrue(m)){
			R = m
		}else{
			L = m + 1
		}
	}
	return if(isTrue(L)){
		L
	}else{
		if(L == r){
			null
		}else{
			L + 1
		}
	}
}

inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
	//inclusive
	var L = l
	var R = r
	while(L<R){
		val m = (L + R)/2 + 1
		if(isTrue(m)){ L = m }else{ R = m - 1 }
	}
	return if(isTrue(L)){ L }else{ null }
}


inline fun BinarySearchExact(value:Int,l:Int,r:Int,find:(Int)->Int):Int?{
	//find shoudl be increasing
	var L = l
	var R = r
	while(L<R){
		val m = (L + R)/2
		if(value <= find(m)){
			R = m
		}else{
			L = m + 1
		}
	}
	return if(find(L) == value){ L}else{null}
}


fun main() {
	val a = getlong()
	val b = getlong()

	val ans = BinarySearchLastTrue(0,100000){
		val s = it.toLong()
		s * (s + 1)/2 <= (a+b)
	}!!.toInt()
	val done = BooleanArray(ans)
	val aret = mutableListOf<Int>()
	var areamining = a
	for(i in ans downTo 1){
		if(areamining >= i){
			areamining -= i
			done[i-1] = true
			aret.add(i)
		}else{
			continue
		}
	}
	val bret = mutableListOf<Int>()

	for(x in 0 until ans){
		if(!done[x]){
			bret.add(x + 1)
		}
	}

	put(aret.size)
	put(aret.joinToString(" "))

	put(bret.size)
	put(bret.joinToString(" "))

	done()
    // Write your solution here
}