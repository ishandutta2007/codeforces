/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools


 iff some segments < segment disjoint to the right

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

fun previousPowerOf2(a:Int):Int{
	if(a == 0){
		return 0
	}
	var a = a
	a = a or (a shr 1)
	a = a or (a shr 2)
	a = a or (a shr 4)
	a = a or (a shr 8)
	a = a or (a shr 16)
	return a - (a shr 1)
}
fun main() {
	val n = getint()
	val arr = getline(n)

	var pp = 1
	var ppcount = 0
	for(a in arr){
		val new = previousPowerOf2(a)
		if( new == pp){
			ppcount += 1
			if(ppcount >= 3){
				put("1")
				done()
				return
			}
		}else{
			pp = new
			ppcount = 0
		}
	}

	var min = Int.MAX_VALUE
	val prexorSum = IntArray(n)

	for((i,a) in arr.withIndex()){
		val last = if(i != 0) prexorSum[i-1] else 0
		prexorSum[i] = last xor a
	}
	fun getSum(a:Int,b:Int):Int{
		if(a == 0){
			return prexorSum[b]
		}else{
			return prexorSum[b] xor prexorSum[a-1]
		}
	}

	for(i in arr.indices){
		for(j in i until n){
			for(k in j+1 until n){
				for(l in k until n){
					val left = getSum(i,j)
					val right = getSum(k,l)
					if(left > right){
						val new = (l - k) + (j - i)
						min = minOf(min,new)
//						println("${left} ${right} $i $j $k $l")
					}
				}
			}
		}
	}
	if(min == Int.MAX_VALUE){
		put("-1")
	}else{
		put(min)
	}
	done()

    // Write your solution here
}