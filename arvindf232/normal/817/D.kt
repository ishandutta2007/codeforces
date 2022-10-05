
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.absoluteValue
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

fun IntArray.doit(forward:Boolean,compare:(Int,Int)->Boolean):IntArray {
	val stack = ArrayDeque<Pair<Int,Int>>()
	val n = this.size
	val ret = IntArray(n)
	if(forward){
		for(i in 0 until n){
			val v = this[i]
			while(stack.isNotEmpty() && compare(stack.last().second, v)){
				stack.removeLast()
			}
			val last = if(stack.isEmpty()) 0 else (stack.last().first + 1 )
			stack.add(Pair(i,v))
			ret[i] = last
		}
	}else{
		for(i in n-1 downTo 0){
			val v = this[i]
			while(stack.isNotEmpty() && compare(stack.last().second, v)){
				stack.removeLast()
			}
			val last = if(stack.isEmpty()) n-1 else (stack.last().first - 1 )
			stack.add(Pair(i,v))
			ret[i] = last
		}
	}
	return ret
}
fun main(){
	repeat(1){ _ ->
		val n = getint
		val L = getline(n)



		val One = L.doit(true) { a, b -> a < b }
		val two = L.doit(false){a , b -> a <= b}

		val d1 = L.doit(true){a , b -> a > b}
		val d2 = L.doit(false){a, b -> a >= b}


		var total = 0L
		for(i in 0 until n){
			val v = L[i].toLong()
			total += v * ( 1 + (One[i] - i).absoluteValue) *  ( 1 + (two[i] - i).absoluteValue)
			total -= v * ( 1 + (d1[i] - i).absoluteValue) *  ( 1 + (d2[i] - i).absoluteValue)
		}
		put(total)







	}
	done()
}
/*
9
3 3 3 2 2 2 1 1 1


4
4 2 3 1
 */