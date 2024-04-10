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
	repeat(1){ tc->

		val n = getint
		val ST = mutableListOf<String>()
		val maxlength = mutableListOf<String>()
		repeat( 2 * n -2){
			val s = getstr
			ST.add(s)
			if(s.length == n-1){
				maxlength.add(s)
			}
		}

		val S = ST.toMutableList()
		S.sort()
		fun isOk(a:String):Boolean {
			val all= mutableListOf<String>()
			for(r in 0 until n-1){
				all.add(a.slice(0..r))
			}
			for(l in 1..n - 1) {
				all.add(a.slice(l..n-1))
			}
			all.sort()
			return all == S
		}
		var ansstring:String? = null
		fun check(c1:String, c2:String):String? {
			if(c1.slice(1 until c1.length) != c2.slice(0 until c2.length-1)){
				return null
			}else{
				val s = c1 + c2.last().toString()
				if(isOk(s)){
					return s
				}
			}
			return null
		}
		ansstring = check(maxlength[0],maxlength[1])
		if(ansstring == null){
			ansstring = check(maxlength[1], maxlength[0])
		}
//		assert(ansstring != null)

		val final = mutableMapOf<String,MutableList<Char>>()

		fun add(s:String, type:Char){
			if(final[s] == null) {
				final[s] = mutableListOf()
			}
			final[s]!!.add(type)
		}
		for(r in 0 until n-1){
			add(ansstring!!.slice(0..r),'P')
		}
		for(l in 1..n - 1) {
			add(ansstring!!.slice(l..n-1),'S')
		}

		val ret = mutableListOf<Char>()
		for(s in ST){
			val g = final[s]!!.removeLast()
			ret.add(g)
		}
		put(ret.joinToString(""))



	}
	done()
}