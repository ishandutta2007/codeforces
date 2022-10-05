/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
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

fun bruteForce(arr:List<Int>):String{
	val ret = mutableListOf<Char>()
	for(i in 1..arr.size){
		val things = mutableListOf<Int>()
		for(a in arr.windowed(i)){
			things.add(a.minOrNull()!!)
		}
		if(things.toSet().size < things.size || things.max() != things.size){
			ret.add('0')
		}else{
			ret.add('1')
		}
	}
	return ret.joinToString("")
}
fun answer(arr:List<Int>):String{

	val n = arr.size
	val que = ArrayDeque<Int>()

	for( a in arr){
		que.addLast(a)
	}
	var testing = 1
	var ret = mutableListOf<Char>()

	val allDifferent = que.toSet().size == que.size

	val counts = IntArray(n+1)
	for(a in arr){
		counts[a] += 1
	}


	while(true) {
		val lastInd = que.indexOfLast { it != testing }
		val firstInd = que.indexOfFirst { it != testing }
		val lastUsed = que.lastIndex - lastInd
		val firstUsed = firstInd - 0
		if(lastUsed + firstUsed != 1 || counts[testing] != lastUsed + firstUsed) {
			val minSize = que.size

			val has = que.contains(testing)
			if(has){
				ret = (1..n).map { if(it >= minSize) '1' else '0' }.toMutableList()
			}else{
				ret = (1..n).map { if(it > minSize) '1' else '0' }.toMutableList()
			}

			break
		} else {
			repeat(lastUsed) {
				que.removeLast()
			}
			repeat(firstUsed) {
				que.removeFirst()
			}
			testing += 1
			continue
		}
	}
	if(allDifferent) {
		ret[0] = '1'
	}
	return ret.joinToString("")
}
fun main() {
//	for(a in 1..4){
//		for(b in 1..4){
//			for(c in 1..4){
//				for(d in 1..4){
//					val arr = listOf<Int>(a,b,c,d)
//					val ask = answer(arr)
//					val ans = bruteForce(arr)
//					if(ask != ans){
//						println("WRONG ${arr.joinToString(" ")}")
//						println(ask)
//						println("model answer:" + ans)
//					}
//				}
//			}
//		}
//	}
	cases{
		val n = getint()
		val arr = getline(n)
		put(answer(arr))
	}
	done()
    // Write your solution here
}