import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.math.abs

val powersOfTwo =
	intArrayOf(1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144)

class DisjointUnionSets(n:Int) {
	var rank:IntArray
	var parent:IntArray
	var n:Int

	fun makeSet() {
		for(i in 0 until n) {
			parent[i] = i
		}
	}

	fun find(x:Int):Int {
		if(parent[x] != x) {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}

	fun union(x:Int, y:Int) {
		val xRoot = find(x)
		val yRoot = find(y)
		if(xRoot == yRoot) return
		if(rank[xRoot] < rank[yRoot])
			parent[xRoot] = yRoot else if(rank[yRoot] < rank[xRoot])
			parent[yRoot] = xRoot else {
			parent[yRoot] = xRoot
			rank[xRoot] = rank[xRoot] + 1
		}
	}

	init {
		rank = IntArray(n)
		parent = IntArray(n)
		this.n = n
		makeSet()
	}
}

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`:BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char:Char
		private get() {
			while(bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch(e:Exception) {
					return NC
				}
				if(size == -1) return NC
				bId = 0
			}
			return buf[bId++].toChar()
		}

	fun nextInt():Int {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextLong():Long {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0L
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextString():String {
		if(c == NC) c = char
		val ret = StringBuilder()
		while(true) {
			c = char
			if(!isWhitespace(c)) {
				break
			}
		}
		ret.appendCodePoint(c.toInt())
		while(true) {
			c = char
			if(isWhitespace(c)) {
				break
			}
			ret.appendCodePoint(c.toInt());
		}
		return ret.toString()
	}

	fun isWhitespace(c:Char):Boolean {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}

class reading {
	companion object {
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}

fun put(aa:Any) {
	reading.pw.println(aa)
}

fun done() {
	reading.pw.close()
}

fun getint():Int {
	return reading.jin.nextInt()
}

fun getlong():Long {
	return reading.jin.nextLong()
}

fun getline(n:Int):List<Int> {
	return (1..n).map { reading.jin.nextInt() }
}

fun getlineL(n:Int):List<Long> {
	return (1..n).map { reading.jin.nextLong() }
}

fun getstr():String {
	return reading.jin.nextString()
}

inline fun cases(ask:() -> Unit) {
	val t = getint()
	repeat(t) {
		ask()
	}
}

fun just(a:Boolean) {
	put(if(a) "YES" else "NO")
}

fun List<Int>.out() {
	put(this.joinToString(" "))
}

val List<Char>.ret:String
	get() = this.joinToString("")

infix fun Long.divCeil(b:Long):Long{
	//Positives numbers only!
	if(this == 0L) {
		return 0
	}
	return (this-1)/b + 1
}
fun prefixSumL(arr:List<Long>):MutableList<Long>{
	val ret = mutableListOf<Long>()

	var previous = 0L
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}
//fun TreeSet<Int>.interval(){
//	val things = this.ob
//}
fun main() {
	val n = getint()
	val arr = getline(n).map{it.toLong()}

	val ps = prefixSumL(arr)

	val dp = LongArray(n-1)
	var currentMax = Long.MIN_VALUE


	for(i in n-2 downTo 0){
		if(i == dp.lastIndex){
			dp[i] = ps.last()
			currentMax = ps.last()
			continue
		}
		dp[i] = ps[i+1] - currentMax
		currentMax = maxOf(currentMax,dp[i])
	}
	put(currentMax)
	done()

}