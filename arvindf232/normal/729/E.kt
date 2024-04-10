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
	repeat(1){ _ ->
		val n = getint
		val s = getint  - 1

		val L = getline(n)
		var ret = 0
		if(L[s] != 0){
			ret ++
		}
		val S = TreeMap<Int,Int>()
		for(i in 0 until n) {
			if(i == s) {
				continue
			}
			val v = L[i]
			S[v] = S.getOrDefault(v,0) + 1
		}
		ret += S.getOrDefault(0,0)
		
		var resv = S.getOrDefault(0,0)
		S.remove(0)
		var pt = 1
		while(S.isNotEmpty()){
			if(S.getOrDefault(pt,0) != 0){
				S.remove(pt)
				pt ++
				continue
			}else{
				if(resv > 0){
					resv -- 
					pt ++ 
					continue
				}else{
					val last = S.lastKey()
					val new = S[last]!! -1
					if(new == 0){
						S.remove(last)
					}else{
						S[last] = new
					}
					pt ++

					ret ++
					continue
				}
				
			}
		}
		put(ret)




	}
	done()
}