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
	repeat(1){ _ ->
		val n = getint
		val max = 1000001
		val primeOf = IntArray(max)
		val smallestreach = IntArray(max){it}
//		val canreach = IntArray(max){-1}
		primeOf[1] = 1
		for(p in 2 until max){
			if(primeOf[p] != 0) continue
			primeOf[p] = p
			for(x in 2 * p until max step p ){
				primeOf[x] = p
				smallestreach[x] = minOf(smallestreach[x] , x - p + 1)
//				canreach[x+1] = maxOf(canreach[x+1], x + p )
			}
		}
		var ans = smallestreach[n]
		for(p in 2 until max){
			if(primeOf[p] != p) continue
			if(n % p != 0) continue
			for(i in n - p + 1..n) {
				ans = minOf(ans, smallestreach[i])
			}
		}
		put(ans)
//		for(i in 0 until max-1){
//			canreach[i + 1] = maxOf(canreach[i], canreach[i+1])
//		}
//		val smallestreachby = IntArray(max)
//		for(i in 0 until max) {
//			smallestreachby[i] =
//		}




	}
	done()
}
/*
2 3 5 7 11
furthest you can reach

doubly monoto

 */