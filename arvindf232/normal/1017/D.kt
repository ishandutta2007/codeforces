/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

want to solve in q  * n
or 100 * n


offline

how many sums have size <= that

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

fun prefixSum(arr:IntArray):MutableList<Int>{
	val ret = mutableListOf<Int>()

	var previous = 0
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}
val powersOf2 = listOf(1,2,4,8,16,32,64,128,256,512,1024,2048,4096)
fun main() {


	// Write your solution here
	val n = getint()
	val m = getint()
	val q = getint()
	val multiSet = IntArray(powersOf2[n])
	val arr = getline(n)
//	val n = getint()

	fun value(a:String):Int{
		var ret = 0
		for(c in a){
			ret *= 2
			val is1 = c == '1'
			if(is1){
				ret += 1
			}
		}
		return ret
	}
	fun wu(a:Int,b:Int):Int{
		var ret = 0
		for(i in 0 until n){
			if((a xor b) and (1 shl i) == 0){
				ret += arr[n-1-i]
			}
		}
		return ret
	}

	fun potentialWu(a:Int):Int{
		var ret = 0
		for(i in 0 until n){
			if(a and (1 shl i) == 0){
				ret += arr[n-1-i]
			}
		}
		return ret
	}



	repeat(m){
		val st = getstr()
		multiSet[value(st)] += 1
	}
	val np = powersOf2[n]
	val ans = List(np){IntArray(102)}

	val wuStock = IntArray(np){potentialWu(it)}

	for(a in 0 until powersOf2[n]){
		for(b in 0 until powersOf2[n]){
			var w = wuStock[a xor b]
			if(w > 100){
				w = 101
			}
			ans[a][w] += multiSet[b]
		}
	}
	val lookUpTable = ans.map{prefixSum(it)}



	repeat(q){
		val str = getstr()
		val v = value(str)
		val k = getint()
		val ans = lookUpTable[v][k]
		put(ans)
	}
	done()


}