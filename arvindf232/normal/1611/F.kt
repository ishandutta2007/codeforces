
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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
	repeat(getint){
		val n = getint
		val s = getint
		val L = getline(n)

		val prefixsum = LongArray(n+1)
		for(i in 0 until n){
			prefixsum[i+1] = prefixsum[i] + L[i]
		}
		var sack = TreeMap<Long,Int>()
		fun addone(v:Long){
			sack[v] = sack.getOrDefault(v,0) + 1
		}
		fun removeone(v:Long){
			val new = sack.getOrDefault(v,0)
			assert(new != 0)
			if(new == 1){
				sack.remove(v)
			}else{
				sack[v] = new - 1
			}
		}

		var ret = 0
		var ans = Pair(-1,-1)

		var right = -1
		for(left in 0 until n){
			val cannotgo = prefixsum[left] - s
			while(right < n-1){
				val v = prefixsum[right+2]
				addone(v)
				if(sack.firstKey() >= cannotgo){
					right ++
					continue
				}
				removeone(v)
				break
			}

			val len = right - left + 1
			if(len > ret){
				ret = len
				ans = Pair(left, right)
			}
		}
		if(ret == 0){
			put(-1)
		}else{
			val (left,R) = ans
			put("${left + 1} ${R + 1}")

		}
		



	}
	done()
}