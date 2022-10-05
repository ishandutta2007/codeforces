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
	repeat(getint){
		val n = getint
		val str = getstr
		val runs = mutableListOf<Int>()
		var left = 0
		while(left < n){
			val right = (left.. n).first{it == n || str[it] != str[left]} - 1
			runs.add(right - left + 1 )
			left = right + 1

		}
		var deletept = 0
		var pt = 0
		var ret = 0
		outer@while(true){
//			println(runs.joinToString(" "))
			if(deletept >= runs.size){
				break@outer
			}
			while(runs[deletept] == 0){
				deletept ++
				if(deletept >= runs.size){
					break@outer
				}
			}
			while(pt <= runs.lastIndex && runs[pt] <= 1 ){
				pt ++
				if(pt >= runs.size){
					break
				}
			}
			if(pt in runs.indices && runs[pt] > 1 ){
				runs[pt] --
				runs[deletept] = 0
				ret ++
				continue
			}else{
				runs[deletept] = 0
				deletept ++
				ret ++
				if(deletept in runs.indices){
					runs[deletept] = 0
				}
			}
		}
		put(ret)




	}
	done()
}