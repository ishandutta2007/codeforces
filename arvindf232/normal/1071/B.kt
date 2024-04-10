/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * equivalent to first find maximum number of xes
 *
 * 2000 , so no flows
 *
 * max a count :
 *
 * calculate a extras
 * valid path, or not valid
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

fun main() {
	val n = getint()
	val k = getint()

	val arr = mutableListOf<String>()
	repeat(n){
		arr.add(getstr())
	}

	val acount  = List(n){IntArray(n)}
	val good = 0..(n-1)
	var bestReach = -1

	for(s in 0..2*(n-1)) {
		for(a in good) {
			val b = s - a
			if(!good.contains(b)) {
				continue
			}
			val isA = arr[a][b] == 'a'
			acount[a][b] = 1000000000
			if(a == 0 && b == 0){
				acount[a][b] = 0
			}
			if(a > 0) {
				acount[a][b] = minOf(acount[a][b], acount[a - 1][b])
			}
			if(b > 0) {
				acount[a][b] = minOf(acount[a][b - 1], acount[a][b])
			}
			if(!isA) {
				acount[a][b] += 1
			}
			if(acount[a][b] <= k){
				bestReach = s
			}
		}
	}
	val ret = mutableListOf<Char>()
	val valid = List(n){BooleanArray(n)}

	if(bestReach == -1){
		valid[0][0] = true
		bestReach = 0
		ret.add(arr[0][0])
	}else{
		repeat(bestReach +1){
			ret.add('a')
		}
		for(a in good){
			val b = bestReach - a
			if(!good.contains(b)){
				continue
			}
			if(acount[a][b] <= k){
				valid[a][b] = true
			}
		}
	}
	for(s in bestReach+1 .. 2*(n-1)){
		var earliest:Char = 'z'
		for(a in good){
			val b = s - a
			if(!good.contains(b)){
				continue
			}
			var pass = false
			if(a > 0 && valid[a-1][b]){
				pass = true
			}
			if(b > 0 && valid[a][b-1]){
				pass = true
			}
			if(!pass){
				continue
			}
			if(arr[a][b].toInt() < earliest.toInt()){
				earliest = arr[a][b]
			}
		}
		ret.add(earliest)
		for(a in good) {
			val b = s - a
			if(!good.contains(b)) {
				continue
			}
			var pass = false
			if(a > 0 && valid[a - 1][b]) {
				pass = true
			}
			if(b > 0 && valid[a][b - 1]) {
				pass = true
			}
			if(!pass) {
				continue
			}
			if(arr[a][b] == earliest) {
				valid[a][b] = true
			}
		}
	}
	put(ret.ret)
	done()

    // Write your solution here
}