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
		val A = getstr
		val B = getstr

		val opt1 = (0 until n).count{A[it] != B[it]}
		val opt2 = (0 until n).count{A[it] == B[it]}

		var s1 = IntArray(3)
		var s2 = IntArray(2)

		for(t2 in 0..minOf(opt2, k)){
			val remain = k - t2
			val y = opt1 - remain
			val x = remain - y
			if(x in 0..opt1 && y in 0..opt1){

				s1 = intArrayOf(x,y,y)
				s2 = intArrayOf(t2,opt2 - t2)
				break
			}
		}
		if(s1.sum() == 0 && s2.sum() == 0){
			put(-1)
			return@repeat
		}
		val ret = mutableListOf<Char>()
		val short = listOf('a','b','c')

		for(i in 0 until n){
			val case1 = (A[i] != B[i])
			if(case1){
				val kind = (0 until 3).first{s1[it] != 0}
				s1[kind] --
				if(kind == 0){
					ret.add(short.first{it != A[i] && it != B[i]})
				}else if(kind == 1){
					ret.add(A[i])
				}else{
					ret.add(B[i])
				}
			}else{
				val kind = ( 0 until 2).first{s2[it] != 0}
				s2[kind] --
				if(kind == 0){
					ret.add(short.first{it != A[i] && it != B[i]})
				}else{
					ret.add(A[i])
				}
			}
		}
		val ans = ret.joinToString ("")
		if((0 until n).count { ans[it] != A[it] } != k){
			IntArray(100000000)
		}
		if((0 until n).count { ans[it] != B[it] } != k){
			IntArray(100000000)
		}
		put(ans)






	}
	done()
}