/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 strategy: independent:
 	whoever has the larger decscendign sequence wins

 Strategy: Blocking:

 	if a choosese a two way peak, he can block the lower end, kill

 A must choose peak
  	- B choose greater of two peaks
 	- of an odd number so he would win this


 A must choose equal descending both peaks

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

fun main() {
	val n = getint()
	val arr = getline(n)

	//max ascending that stops here

	val up = IntArray(n)
	val down = IntArray(n)

	for(a in 0 until n ){
		if(a == 0){
			up[a] = 1

		}else{
			if(arr[a] > arr[a-1]){
				up[a] = up[a-1] + 1

			}else{

				up[a] = 1
			}
		}
	}
	for(a in n-1 downTo 0){
		if(a == down.lastIndex){
			down[a] = 1
		}else{
			if(arr[a] > arr[a+1]){
				down[a] = down[a+1] + 1
			}else{
				down[a] = 1
			}
		}
	}
	val maxPeak = maxOf(up.maxOrNull()!!,down.maxOrNull()!!)
	val isPeak = BooleanArray(n)
	for(i in up.indices){
		if(up[i] == maxPeak){
			isPeak[i] = true
		}
		if(down[i] == maxPeak){
			isPeak[i] = true
		}
	}
	val totalPeaks = isPeak.count { it }
	if(totalPeaks >= 2){
		put(0)
		done()
		return
	}

	var ret = 0
	for(i in up.indices){
		if(up[i] == maxPeak && down[i] == maxPeak && maxPeak % 2 == 1){
			ret += 1
//			put(i)
		}
	}
	put(ret)
	done()

    // Write your solution here
}