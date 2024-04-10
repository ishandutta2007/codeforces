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


data class permutation(val p:IntArray){
	// 0 based
	fun inverse():permutation{
		val ret = IntArray(p.size)
		for(i in 0..p.lastIndex){
			ret[p[i]] = i
		}
		return permutation(ret)
	}
	infix fun compose(other:permutation):permutation{
		val ret = IntArray(p.size)
		for(i in 0..p.lastIndex){
			ret[p[other.p[i]]] = i
		}
		return permutation(ret)
	}
	fun swapDistances():Int{
		var ret = 0
		cyclesOfPermutations { ret += it.size - 1  }
		return ret
	}

	inline fun cyclesOfPermutations(doit:(List<Int>)->Unit){
		val arr = this.p
		val n = arr.size
		val done = BooleanArray(n)
		var haveDone = 0
		var pointer = 0
		while(haveDone < n){
			while(done[pointer]){
				pointer++
			}
			haveDone += 1
			val x = pointer
			val todo = mutableListOf(x)
			var cur = x
			done[x] = true
			while(true){
				val next = arr[cur]
				if(done[next]){
					break
				}
				done[next] = true
				todo.add(next)
				haveDone += 1
				cur = next
			}
			doit(todo)
		}
	}

	override fun equals(other: Any?): Boolean {
		if (this === other) return true
		if (javaClass != other?.javaClass) return false

		other as permutation

		if (!p.contentEquals(other.p)) return false

		return true
	}

	override fun hashCode(): Int {
		return p.contentHashCode()
	}
	fun shiftRightBy(a:Int):permutation{
		val ret = IntArray(p.size)
		var here = a - 1
		for(i in 0 until p.size){
			here += 1
			if(here >= p.size){
				here -= p.size
			}
			ret[here] = p[i]
		}
		return permutation(ret)
	}
	companion object{
		fun identity(n:Int): permutation {
			return permutation((0 until n).toList().toIntArray())
		}
	}
}
fun main() {
	cases{
		val n = getint()
		val m = getint()
		val p = getline(n).map{it - 1}
		val ppermu = permutation(p.toIntArray())
		val shiftsOK = IntArray(n)
		for(i in 0 until n){
			val c  = p[i]
			val result = i - c
			val finResult = if(result < 0) result + n else result
			shiftsOK[finResult] += 1
		}
		val atleast = n - (2 * m)
		val ok = (0 until n).filter{shiftsOK[it] >= atleast}
//		just dei ok
		val ret = mutableListOf<Int>()
		for(test in ok){
			val new = permutation.identity(n).shiftRightBy(test)
			val asked = ppermu.compose(new.inverse())
			val ans = asked.swapDistances()
			if( ans <= m ){
				ret.add(test)
			}
		}
		put(ret.size)
		for(a in ret){
			put(a)
		}
	}
	done()
    // Write your solution here
}