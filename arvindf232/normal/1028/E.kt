/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

coudl have 0s

 3 0 0 3

 0 1 1 3

		3


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
		private get() {
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


fun ask(arr:LongArray):LongArray?{
	val n = arr.size
	val max = arr.maxOrNull()!!
	if(arr.all{it == max}){
		if(max == 0L){
			return LongArray(n){1}
		}else{
			return null
		}

	}

	var previousOk = arr.last() != max
	var pivot = -1
	for((i,a) in arr.withIndex()){
		if(a == max){
			if(previousOk){
				pivot = i
				break
			}
		}else{
			previousOk = true
		}
	}
	val big = 1000000000000L
	val mod = arr[pivot]
	val modified = (big / mod) * mod

	val s = arr.sum() + modified
	var carrying = s
	val ret = LongArray(n)
	for(offset in 1..n){
		val ai = (pivot + offset)% n
		if(ai !=pivot){
			ret[ai] = carrying
			carrying -= arr[ai]
		}else{
			ret[ai] = arr[ai]
		}

	}
	return ret
}

fun main() {
	val n = getint()
	val arr = getlineL(n).toLongArray()
//	println(arr.joinToString(" ")  + "OK")
	val ret = ask(arr)
	if(ret == null){
		put("NO")
		done()
		return
	}

	fun validateAnswer(from:LongArray,ans:LongArray):Boolean{
		val n = from.size
		return (0 until n).all{
			ans[(it)%n] %ans [(it+1)%n] == from[it]
		}
	}
	assert(validateAnswer(arr,ret))

	put("YES")
	put(ret.joinToString(" "))
	done()





    // Write your solution here
}