/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 Concept s
 	- information lfiting
 	- using existing information to ask for a shorter path



 A: OK
 	-> B Ok unless it is blocked
 	 Case: Yes
 		-> Must know presence of cell
 	Case: No
 		->

 	Can deduce after knowing the good path


 this costs 6n


 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

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
		private get() {
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
fun put(aa:Any){
	reading.pw.println(aa)
}
fun done(){
	reading.pw.close()
}

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}


inline fun cases(ask:()->Unit){
	val t = getint()
	repeat(t){
		ask()
	}
}
fun just(a:Boolean){
	put(if(a)"YES" else "NO")
}
fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
	get() = this.joinToString("")

fun main() {
	val n = getint()

	var qs = 0

	fun ask(a:Int,b:Int,c:Int,d:Int):Boolean{
		qs += 1

		if(qs > 4 * n){
			IntArray(1000000000)
		}
		println("? $a $b $c $d")
		System.out.flush()
		val ans = getstr()
		if(ans == "BAD"){
			IntArray(1000000000)
			System.exit(0)
			return false
		}else{
			return ans == "YES"
		}
	}
//	val ask1 = BooleanArray(n)
//	val ask2 = BooleanArray(n)
//
//	for(i in 0 until n){
//		ask1[i] = ask(1,1,1+i,n-i)
//		ask2[i] = ask(1+i,n-i,n,n)
//	}
//	val first = (0 until n).first{ask1[it] && ask2[it]}
//
//	val coordX = 1 + first
//	val coordY = n - first

	val downRightPath = mutableListOf<Char>()
	var currentX = 1
	var currentY = 1

	while(currentX + currentY <= n){
		val q = ask(currentX ,currentY+1,n,n)
		if(q){
			downRightPath.add('D')
			currentY += 1
		}else{
			downRightPath.add('R')
			currentX += 1
		}
	}

	val upLeftPath = mutableListOf<Char>()
	currentX = n
	currentY = n

	while(currentX + currentY > n+1){
		val q = ask(1,1,currentX - 1,currentY,)
		if(q){
			upLeftPath.add('L')
			currentX -= 1
		}else{
			upLeftPath.add('U')
			currentY -= 1
		}
	}

	val reversed = upLeftPath.reversed().map{if(it == 'U')'D' else 'R'}
	val sol = downRightPath + reversed
	val ans = sol.map{if(it == 'D')'R' else 'D'}.joinToString("")
	println("! ${ans}")
	// Write your solution here
}