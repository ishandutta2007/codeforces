import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
object IO{
	private const val BS = 1 shl 16
	private const val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC

	var warningActive = true
	var fakein = StringBuilder()

	private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
	val OUT: PrintWriter = PrintWriter(System.out)

	private val char: Char
		get() {
			while (bId == size) {
				size = IN.read(buf) // no need for checked exceptions
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
		while (c in '0'..'9') {
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
		while (c in '0'..'9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextString():String{
		val ret = StringBuilder()
		while (true){
			c = char
			if(!isWhitespace(c)){ break}
		}
		ret.append(c)
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.append(c)
		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
	return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
	return LongArray(n){getlong}
}
fun main(){
	repeat(1){
		val n = getint
		val k = getint
		val L = getlineL(n)

		val intervals = Array(n){LongArray(n)}

		for(l in 0 until n) {
			for(r in l until n) {
				var here = 0L
				for(i in l..r){
					here += L[i].toLong()
				}
				intervals[l][r] = here
			}
		}
//		val start = (1L shl 62) - 1

		fun can(v:Long):Boolean{
			val able = Array(k+1){x -> BooleanArray(n+1){v -> if(v == 0 && x == 0) true else false} }
			for(r in 1..n){
				for(here in 1..k){
					for(left in 0 until r){
						if(!able[here-1][left]){
							continue
						}
						val trans = intervals[left][r-1]
						if(trans.inv() and v == 0L){
							able[here][r] = true
						}
					}
				}
			}
			return able[k][n]
		}
		var now = 0L
		for(d in 61 downTo 0){
			val here = (1L shl d)
			if(can(now + here)){
				now = now + here
			}else{
				now = now
			}
		}
		put(now)
	}
	done()
}