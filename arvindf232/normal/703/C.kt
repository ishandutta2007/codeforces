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

val Long.highestBitPlace:Int
	get(){
		return (0..62).last last@{
			return@last (1L shl it) <= this
		}
	}

fun cross(a:Pair<Long,Long>,b:Pair<Long,Long>):Long{
	val (x,y) = a
	val (z,w) = b
	return (x * w - z * y )
}

fun Pair<Long,Long>.clockwise():Pair<Long,Long>{
	return Pair(this.second, -this.first)
}
fun Pair<Long,Long>.antiClockwise():Pair<Long,Long>{
	return Pair(- this.second, this.first)
}
fun dot(a:Pair<Long,Long>,b:Pair<Long,Long>):Long{
	val (x,y) = a
	val (z,w) = b
	return (x * z + y * w)
}


fun main(){
	val n = getint()
	val w = getint()
	val v = getlong()
	val u = getlong()

	val startVector = Pair(v,u)
//	println(startVector)

	val points = mutableListOf<Pair<Long,Long>>()

	repeat(n){
		val x = getlong()
		val y = getlong()
		points.add(Pair(x,y))
	}

	val good = points.all{
//		println(cross(it,startVector))
		cross(it,startVector) <= 0
	}
	val good2 = points.all{
//		println(cross(it,startVector))
		cross(it,startVector) >= 0
	}
	if(good||good2){
		put(w.toDouble() / u.toDouble())
	}else{
		val wantTo = startVector.clockwise()
		val (lx,ly) = points.maxByOrNull { dot(wantTo,it) }!!

		val remainingY  = w - ly
		val timeTaken = (lx).toDouble() / (v).toDouble()
		put((remainingY.toDouble() / (u).toDouble()) + timeTaken)
	}
	done()

//	for(i in 1..100){
//		println("$i ${i.toLong().highestBitPlace}")
//	}

	/*


	 */
}