/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

bad case :
  	1 will be bad


 all x : has a unique solution

 definitly a local strategy


 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`: BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char: Char
		get() {
			while (bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch (e: Exception) {
					return NC
				}
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
		while (c >= '0' && c <= '9') {
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
		while (c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if (neg) -res else res
	}
	fun nextString():String{
		if (c == NC) c = char
		val ret = StringBuilder()
		while (true){
			c = char
			if(!isWhitespace(c)){ break}
		}
		ret.appendCodePoint(c.toInt())
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.appendCodePoint(c.toInt());

		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}
class reading{
	companion object{
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}
fun put(aa:Any){ reading.pw.println(aa)}
fun done(){ reading.pw.close() }

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
	get() = this.joinToString("")
infix fun Any.dei(a:Any){
	//does not stand for anything it is just easy to type
	var str = ""
	if(this is String){ str = this
	}else if(this is Int){ str = this.toString()
	}else if(this is Long){ str = this.toString()
	}
	if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
	}else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
	}else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
	}else{ println("$str : $a")
	}
}
val just = " " // usage: just dei x , where x is the debug variable


fun except(a:Int):Pair<Int,Int>{
	if(a == 1){
		return Pair(2,3)
	}else if(a == 2){
		return Pair(1,3)
	}else{
		return Pair(1,2)
	}
}


fun main() {
	val n = getint()
	val board = List(n){IntArray(n)}
	var done = 0

	val c1 = mutableListOf<Pair<Int,Int>>()
	val c2 = mutableListOf<Pair<Int,Int>>()

	var c1Filled = 0
	var c2Filled = 0
	fun fill(a:Int,b:Int,col:Int){
		board[a][b] = col

		println("$col ${a+1} ${b+1}")
		System.out.flush()
//		println()
//		println("State $done")
//		for(l in board){
//			println(l.joinToString(" "))
//		}

//		if(done == n * n ){
//			System.exit(0)
//		}
	}

	for(i in 0 until n ){
		for(j in 0 until n){
			if((i + j) %2  == 0){
				c1.add(Pair(i,j))
			}else{
				c2.add(Pair(i,j))
			}
		}
	}
	val cs = 1
	val ct = 2
	fun putC1(c:Int){
		val (x,y) = c1[c1Filled]
		c1Filled += 1
		fill(x,y,c)
	}
	fun putC2(c:Int){
		val (x,y) = c2[c2Filled]
		c2Filled += 1
		fill(x,y,c)
	}
	while(c1Filled < c1.size && c2Filled < c2.size){
		val c = getint()
		if(c != cs){
			putC1(cs)
		}else{
			putC2(ct)
		}
	}
	while(c1Filled < c1.size || c2Filled < c2.size){
		val c = getint()

		if(c1Filled < c1.size){
			if(c != 1){
				putC1(1)
			}else{
				putC1(3)
			}
		}else{
			if(c != 2){
				putC2(2)
			}else{
				putC2(3)
			}
		}
	}



    // Write your solution here
}