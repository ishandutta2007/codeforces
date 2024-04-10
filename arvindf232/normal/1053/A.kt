/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 just consturct by products
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

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
fun just(a:Boolean){
	put(if(a)"YES" else "NO")
}
fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
	get() = this.joinToString("")

tailrec fun gcd(a: Long, b: Long): Long {
	return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
fun main() {
	val n = getlong()
	val m = getlong()
	val k = getlong()

//	for(i in 1..10){
//		for(j in 1..10){
//			for(k in 2..10){
//				ask(i.toLong(),j.toLong(),k.toLong())
//			}
//		}
//	}


	ask(n, m, k)
	done()
	// Write your solution here
}

private fun ask(n:Long, m:Long, k:Long) {
	val div = 2 * n * m
	if(div % k != 0L) {
		put("NO")
		return
	}
//	val need = 2 * n * m / k
	var pick1 =0L
	var pick2 = 0L
	if(k == 2L) {
		pick1 = n
		pick2 = m
	} else if(n * m % k == 0L){
		val halfNeed = n * m / k
		pick1 = gcd(halfNeed, n)
		pick2 = halfNeed / pick1
		if(2 * pick1 <= n) {
			pick1 *= 2
		} else {
			pick2 *= 2
		}
	}else{
		val need = 2 * n * m / k
		pick1 = gcd(need, n)
		pick2 = need / pick1
	}
	put("YES")
	put("0 0")
	put("$pick1 0")
	put("0 $pick2")
	assert(pick1 * pick2 / 2 == n * m / k && pick1 <= n && pick2 <= m)

}