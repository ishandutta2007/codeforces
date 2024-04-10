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

fun prefixSum(arr:List<Int>):MutableList<Int>{
	val ret = mutableListOf<Int>()
	ret.add(0)

	var previous = 0
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}
fun main() {
	val n = getint()
	val m = getint()

	val voters = List(m){ mutableListOf<Int>()}
	val vot2 = mutableListOf<Pair<Int,Int>>()
	repeat(n){
		val t = getint()
		val price = getint()
		voters[t-1].add(price)
		vot2.add(Pair(t-1,price))
	}
	vot2.sortBy { it.second }
	val totalPrices = voters.map{prefixSum(it)}

	for(a in voters){
		a.sort()
	}
	val oneVotes = voters[0].size
	val baseVotes = voters.map{it.size}

	fun tryWinWithVotes(a:Int):Long?{
		//a-1 for all other
		val buy1 = maxOf(0,a - oneVotes)

		val haveBought = BooleanArray(n)
		val currentVoteCounts = baseVotes.toIntArray()
		var totalCost = 0L

		for((i,x) in vot2.withIndex()){
			val (p,price) = x
			if(p == 0){
				continue
			}
			if(currentVoteCounts[p] > a - 1){
				haveBought[i] = true
				totalCost += price
				currentVoteCounts[p] -= 1
				currentVoteCounts[0] += 1
			}
		}
		for((i,x) in vot2.withIndex()){
			val (p,price) = x
			if(p == 0){
				continue
			}
			if(haveBought[i]){
				continue
			}
			if(currentVoteCounts[0] < a){
				haveBought[i] = true
				totalCost += price
				currentVoteCounts[p] -= 1
				currentVoteCounts[0] += 1
			}else{
				break
			}
		}
		if(currentVoteCounts[0] >= a){
			return totalCost
		}else{
			return Long.MAX_VALUE
		}

	}

	var ans = Long.MAX_VALUE
	for(a in 0..n){
		val new = tryWinWithVotes(a)
		if(new != null){
			ans = minOf(ans,new )
		}
	}
	put(ans)
	done()

    // Write your solution here
}