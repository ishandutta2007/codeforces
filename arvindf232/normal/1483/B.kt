/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

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

infix fun Int.divCeil(b:Int):Int{
	//Positives numbers only!
	if(this == 0) {
		return 0
	}
	return (this-1)/b + 1
}
tailrec fun gcd(a: Int, b: Int): Int {
	return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
fun main() {
	cases{
		val n = getint()
		val arr = getline(n)

		val tree = TreeMap<Int,Int>()
		val badSet = TreeSet<Int>()

		fun checkBadness(i:Int,j:Int){
			val a1 =arr[i]
			val a2 = arr[j]
			if(gcd(a1,a2) == 1){
				badSet.add(j)
			}
		}
		for(i in 0 until arr.size - 1){
			checkBadness(i,i+1)
		}
		checkBadness(arr.lastIndex,0)
		var pointer = 0

		fun circularFloorEntry(i:Int):Int?{
			val et1 = tree.floorKey(i-1)
			if(et1 == null){
				val et2 = tree.floorKey(n+1)
				if(et2 == null){
					return null
				}
				return et2
			}
			return et1
		}
		fun circularCeilingEntry(i:Int):Int?{
			val et1 = tree.ceilingKey(i+1)
			if(et1 == null){
				val et2 = tree.ceilingKey(-1)
				if(et2 == null){
					return null
				}
				return et2
			}
			return et1
		}
		val ret = mutableListOf<Int>()
		fun removeBadness(i:Int){
			ret.add(i + 1)
			badSet.remove(i)
			tree.remove(i)

			val fl = circularFloorEntry(i)
			val ce = circularCeilingEntry(i)
//			println("removing $i ceil $ce Bot $fl")
			if(fl == null || ce == null){
				return
			}
			pointer = ce
			badSet.remove(ce)
			checkBadness(fl,ce)
		}
		for((i,a) in arr.withIndex()){
			tree[i] = a
		}

		while(badSet.isNotEmpty()){
//			println(badSet.joinToString(" "))
//			println(tree.values.joinToString(" ") + "     $pointer")
			val nextBad = badSet.ceiling(pointer + 1) ?: badSet.ceiling(-1)!!
			removeBadness(nextBad)

		}
		put(ret.size)
		put(ret.joinToString(" "))
	}
	done()
    // Write your solution here
}