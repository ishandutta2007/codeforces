/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
seems like simple first strike time

 isolation:
 	boundary of a photo set must be negative
 	any initial segments must be negative

 this must be a stupid problem

 try just to DP
 	O(n^2)

 if heights are decending
 	- this reduces to sum of all >= 0 things

 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
val no = Long.MIN_VALUE
internal class segTree(
	private val size: Int
) {
	//indices are 0 until size
	// out of boundary access are perfectly fine
	// if anyone reads this up in codeforces,
	// I have kept all 4 operations for your conveniences
	val max: LongArray = LongArray(4 * size){no}
	val lazy: LongArray = LongArray(4 * size){no}
	fun update(l: Int, r: Int, inc: Long) {
		update(1, 0, size - 1, l, r, inc)
	}

	private fun pushDown(index: Int, l: Int, r: Int) {
		max[index] = maxOf(max[index],lazy[index])
		if (l != r) {
			lazy[2 * index] = maxOf(lazy[2 * index],lazy[index])
			lazy[2 * index + 1] = maxOf(lazy[2 * index + 1],lazy[index])
		}
		lazy[index] = no
	}

	private fun pullUp(index: Int, l: Int, r: Int) {
		val m = (l + r) / 2
		max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
	}

	private fun evaluateMax(index: Int, l: Int, r: Int): Long {
		return maxOf(max[index], lazy[index])
	}

	private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Long) {
		if (r < left || l > right) return
		if (l >= left && r <= right) {
			lazy[index] = maxOf(lazy[index],inc)
			return
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		update(2 * index, l, m, left, right, inc)
		update(2 * index + 1, m + 1, r, left, right, inc)
		pullUp(index, l, r)
	}

	fun maxQuery(l: Int, r: Int): Long {
		return maxQuery(1, 0, size - 1, l, r)
	}

	private fun maxQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
		if (r < left || l > right) return Long.MIN_VALUE
		if (l >= left && r <= right) {
			return evaluateMax(index, l, r)
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		var ret = Long.MIN_VALUE
		ret = Math.max(ret, maxQuery(2 * index, l, m, left, right))
		ret = Math.max(ret, maxQuery(2 * index + 1, m + 1, r, left, right))
		pullUp(index, l, r)
		return ret
	}
	fun printTree(){
		val ret = mutableListOf<Long>()
		for(i in 0 until size){
			ret.add(maxQuery(i,i))
		}
		println(ret.joinToString(" "))
	}
}


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

fun prefixMax(a:List<Int>):List<Int>{
	val ret = mutableListOf<Int>()
	var current = Int.MIN_VALUE
	for(i in a.lastIndex downTo 0){
		current = maxOf(current,a[i])
		ret.add(current)
	}
	return ret.reversed()
}
fun suffixMax(a:List<Int>):List<Int>{
	val ret = mutableListOf<Int>()
	var current = Int.MIN_VALUE
	for(i in a.indices){
		current = maxOf(current,a[i])
		ret.add(current)
	}
	return ret
}

class rmq(val arr:List<Int>){
	val n = arr.size
	val store = mutableListOf<IntArray>()
	fun preprocess(){
		var s = 1
		var olds = 0
		while(s <= n){
			if(s == 1){
				val new = arr.toIntArray()
				store.add(new)
			}else{
				val size = n-s+1
				val old = store.last()
				val new = IntArray(size)
				for(i in 0 until size){
					new[i] = minOf(old[i],old[i+olds])
				}
				store.add(new)
			}
			olds = s
			s = s shl 1
		}
	}
	fun minQuery(l:Int,r:Int):Int{
		val d = r - l + 1
		val i = 31 - d.countLeadingZeroBits()
		val s = 1 shl i
		val a1 = l
		val a2 = r - s + 1
		val ret1 = store[i][a1]
		val ret2 = store[i][a2]
		return minOf(ret1,ret2)
	}
	init {
		preprocess()
	}
}

inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
	//inclusive
	var L = l
	var R = r
	while(L<R){
		val m = (L + R)/2
		if(isTrue(m)){
			R = m
		}else{
			L = m + 1
		}
	}
	return if(isTrue(L)){
		L
	}else{
		if(L == r){
			null
		}else{
			L + 1
		}
	}
}

inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
	//inclusive
	var L = l
	var R = r
	while(L<R){
		val m = (L + R)/2 + 1
		if(isTrue(m)){ L = m }else{ R = m - 1 }
	}
	return if(isTrue(L)){ L }else{ null }
}

fun main() {
	val n = getint()
	val hi = getline(n)
	val bi = getlineL(n)
	val st = segTree(n+1)

	val hq = rmq(hi)
	hq.preprocess()

	fun leftEP(c:Int):Int{
		return BinarySearchFirstTrue(0,c){
				a -> hq.minQuery(a,c) == hi[c]
		}!!
	}

	val leftEndPoint = (0 until n).map{ leftEP(it)}
	val rightEndPoint = (0 until n).map{BinarySearchLastTrue(it,n-1){a -> hq.minQuery(it,a) == hi[it]}!! }

	for( i in 0 until n ){
		val le = leftEndPoint[i]
		val hasStart = (le == 0)
		var best = st.maxQuery(le-1,i-1)
		if(hasStart){
			best = maxOf(0,best)
		}
		val re = rightEndPoint[i]
		st.update(i,re,best+bi[i])
//		st.printTree()
	}
	put(st.maxQuery(n-1,n-1))
	done()
}