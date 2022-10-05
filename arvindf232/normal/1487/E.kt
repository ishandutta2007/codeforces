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

internal class segTree(
	private val size: Int
) {
	//indices are 0 until size
	// out of boundary access are perfectly fine
	// if anyone reads this up in codeforces,
	// I have kept all 4 operations for your conveniences
//	val sum: LongArray = LongArray(4 * size)
//	val max: LongArray = LongArray(4 * size)
	val min: LongArray = LongArray(4 * size)
	val lazy: LongArray = LongArray(4 * size)
	fun update(l: Int, r: Int, inc: Int) {
		update(1, 0, size - 1, l, r, inc)
	}

	private fun pushDown(index: Int, l: Int, r: Int) {
		min[index] += lazy[index]
//		max[index] += lazy[index];
//		sum[index] += lazy[index] * (r-l+1);
		if (l != r) {
			lazy[2 * index] += lazy[index]
			lazy[2 * index + 1] += lazy[index]
		}
		lazy[index] = 0
	}

	private fun pullUp(index: Int, l: Int, r: Int) {
		val m = (l + r) / 2
		min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
//		max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
//		sum[index] = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r);
	}

	private fun evaluateMin(index: Int, l: Int, r: Int): Long {
		return min[index] + lazy[index]
	}
//	private fun evaluateMax(index: Int, l: Int, r: Int): Long {
//		return max[index] + lazy[index]
//	}
//	private fun evaluateSum(index: Int, l: Int, r: Int): Long {
//		return sum[index] + lazy[index] * (r-l+1)
//	}

	private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Int) {
		if (r < left || l > right) return
		if (l >= left && r <= right) {
			lazy[index] = lazy[index] + inc
			return
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		update(2 * index, l, m, left, right, inc)
		update(2 * index + 1, m + 1, r, left, right, inc)
		pullUp(index, l, r)
	}

	fun minQuery(l: Int, r: Int): Long {
		return minQuery(1, 0, size - 1, l, r)
	}
//	fun maxQuery(l: Int, r: Int): Long {
//		return maxQuery(1, 0, size - 1, l, r)
//	}
//
//
//	fun sumQuery(l: Int, r: Int): Long {
//		return sumQuery(1, 0, size - 1, l, r)
//	}

	private fun minQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
		if (r < left || l > right) return Long.MAX_VALUE
		if (l >= left && r <= right) {
			return evaluateMin(index, l, r)
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		var ret = Long.MAX_VALUE
		ret = Math.min(ret, minQuery(2 * index, l, m, left, right))
		ret = Math.min(ret, minQuery(2 * index + 1, m + 1, r, left, right))
		pullUp(index, l, r)
		return ret
	}
//	private fun maxQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//		if (r < left || l > right) return Long.MIN_VALUE
//		if (l >= left && r <= right) {
//			return evaluateMax(index, l, r)
//		}
//		pushDown(index, l, r)
//		val m = (l + r) / 2
//		var ret = Long.MIN_VALUE
//		ret = Math.max(ret, maxQuery(2 * index, l, m, left, right))
//		ret = Math.max(ret, maxQuery(2 * index + 1, m + 1, r, left, right))
//		pullUp(index, l, r)
//		return ret
//	}
//	private fun sumQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//		if (r < left || l > right) return 0L
//		if (l >= left && r <= right) {
//			return evaluateSum(index, l, r)
//		}
//		pushDown(index, l, r)
//		val m = (l + r) / 2
//		var ret = 0L
//		ret += sumQuery(2 * index, l, m, left, right)
//		ret += sumQuery(2 * index + 1, m + 1, r, left, right)
//		pullUp(index, l, r)
//		return ret
//	}
	fun printTree(){
		val ret = mutableListOf<Long>()
		for(i in 0 until size){
			ret.add(minQuery(i,i))
		}
		println(ret.joinToString(" "))
	}
}

//Price:  500ms for 400k operations, with all min,max,update present
fun main() {

//	val at = segTree(11)
//
//	for(i in 1..10){
//		at.update(i,i,i)
//	}
//	for(j in 1..10){
//		println(at.minQuery(j,10))
//	}
//	at.printTree()
	val n1 = getint()
	val n2 = getint()
	val n3 = getint()
	val n4 = getint()

	val G21 = List(n2){ mutableListOf<Int>()}
	val G32 = List(n3){ mutableListOf<Int>()}
	val G43 = List(n4){ mutableListOf<Int>()}

	val c1 = getline(n1).toIntArray()
	val c2 = getline(n2).toIntArray()
	val c3 = getline(n3).toIntArray()
	val c4 = getline(n4).toIntArray()

	val m1 = getint()
	repeat(m1){
		val x = getint()-1
		val y = getint()-1
		G21[y].add(x)
	}
	val m2 = getint()
	repeat(m2){
		val x = getint()-1
		val y = getint()-1
		G32[y].add(x)
	}
	val m3 = getint()
	repeat(m3){
		val x = getint() -1
		val y = getint() -1
		G43[y].add(x)
	}
	val big = 1000000000
	val C1 = c1.map { it.toLong() }.toLongArray()
	fun compile(fromCost:IntArray,toCost:IntArray,G:List<MutableList<Int>>):IntArray{
		val all = segTree(fromCost.size)
		for(i in fromCost.indices){
			all.update(i,i,fromCost[i])
		}
		val ret = IntArray(toCost.size)
		for(j in toCost.indices){
			val N = G[j]
			val swapped = mutableListOf<Long>()
			for(v in N){
				val result = all.minQuery(v,v)
				val d = big - result
				swapped.add(d)
				all.update(v,v,d.toInt())
			}
			ret[j] = all.minQuery(0,fromCost.lastIndex).toInt() + toCost[j]
//			println("$j ${ret[j]}")
			for(i in swapped.indices){
				val v = N[i]
				val d = swapped[i]
				all.update(v,v,-d.toInt())
			}
//			all.printTree()
		}
		return ret
	}
	val P2 = compile(c1,c2,G21)
	val P3 = compile(P2,c3,G32)
	val P4 = compile(P3,c4,G43)

	val min = P4.minOrNull()!!

	put(if(min > 999999999) -1 else min)
	done()
//    // Write your solution here
}