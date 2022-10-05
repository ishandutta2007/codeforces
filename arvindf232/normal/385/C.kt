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
		val L = getline(n)
//		val m = getint

		val primeof = IntArray(10_000_007)
		primeof[1] = 1
		for(i in 2 until primeof.size){
			if(primeof[i] != 0) continue
			primeof[i] = i
			for(j in 2 * i until primeof.size step i){
				if(primeof[j] == 0 ){
					primeof[j] = i
				}
			}
		}
		val haveprimes = TreeMap<Int,Int>()
		for(a in L){
			var here = a
			while(here != 1){
				val np = primeof[here]
				while(primeof[here] == np){
					if(np == 0){
						IntArray(100000000)
					}
					here /= np

//					assert(np != 0)
				}

				haveprimes[np] = haveprimes.getOrDefault(np, 0) + 1
			}
		}
		val new = TreeMap<Int,Int>()
		var recu = 0
		for((a,b) in haveprimes){
			recu += b
			new[a] = recu
		}

		val q = getint
		repeat(q){
			val l = getint
			val r = getint
			val down = new.floorEntry(l-1)?.value ?: 0
			val up = new.floorEntry(r)?.value ?: 0
			put(up - down )
		}







	}
	done()
}