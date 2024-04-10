import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.absoluteValue

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
	fun rerouteInput(){
		if(warningActive){
			put("You forgot to disable tests you digital dummy!")
			println("You forgot to disable tests you digital dummy!")
			warningActive = false
		}
		val S = fakein.toString()
		println("New Case ")
		println(S.take(80))
		println("...")
		fakein.clear()
		IN = BufferedInputStream(S.byteInputStream(),BS)
	}
	fun takeFile(name:String){
		IN = BufferedInputStream(File(name).inputStream(),BS)
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
		val (x,y) = getlineL(2)
		val (ax,ay) = getlineL(2)
		val (bx,by) = getlineL(2)

		val (startx,starty,t) = getlineL(3)

		 val points = mutableListOf<Pair<Long,Long>>()
		points.add(Pair(x,y))
		while(true){

			val (la,lb) = points.last()
			val trya = (la.toDouble() * ax + bx.toDouble())
			val tryb = (lb.toDouble() * ay + by.toDouble())
			if(trya >= 1e18 || tryb >= 1e18){
				break
			}
			points.add(Pair(la * ax + bx, lb * ay + by))
		}
		fun dist(a:Int, b:Int):Long {
			val pa = points[a]
			val pb = points[b]
			return (pa.first - pb.first).absoluteValue + (pa.second - pb.second).absoluteValue
		}

		var ret = 0
		val nn = points.size
		for((i,p) in points.withIndex()){
			val timeleft = t - (startx - p.first).absoluteValue - (starty - p.second).absoluteValue
			if(timeleft < 0){
				continue
			}
			for(left in 0 until nn){
				for(right in 0 until nn){
					val t1 = dist(left,i)
					val t2 = dist(right,left)
					if(t1 + t2 <= timeleft){
						val lower = minOf(left, right, i)
						val upper = maxOf(left, right,i)
						ret = maxOf(ret,upper - lower + 1 )
					}
				}
			}
		}
		put(ret)



	}
	done()
}