/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*
import kotlin.math.sin
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
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

//class setup(val max:Int ){
//
//	val tp = IntArray(max +2 ){-1}
//	val state = BooleanArray(max + 2)
//
//
//	fun add(from:Int,to:Int,stated:Boolean){
//		state[from] = stated
//		tp[from] = to
//	}
//
//	fun simulate(){
//		var sim = 0
//
//		val used = IntArray(max + 2 )
//		while(sim < max + 1){
//			sim += 1
//			if(tp[sim] != -1){
//				if(state[sim] == false){
//					state[sim] = true
//				}else{
//					state[sim] = false
//					used[sim] += 1
//					sim = tp[sim]
//
//				}
//			}
//		}
//		"used" dei used
//	}
//}

//fun simulate(from:IntArray,to:IntArray,state:IntArray){
//	val max = from.maxOrNull()!! + 1
//	val s = setup(max)
//	just dei state
//	for(i in from.indices){
//		s.add(from[i],to[i],state[i] > 0)
//	}
//	s.simulate()
//
//}

inline fun product(a:List<Int>,act:(List<Int>)->Unit){
	val current = MutableList(a.size){0}
	while(true){
		act(current)
		val lastGood = (0 until a.size).lastOrNull{a[it]-1 != current[it]}
		if(lastGood == null){
			return
		}
		current[lastGood] += 1
		for(i in lastGood+1 until a.size){
			current[i] = 0
		}
	}
}
inline infix fun Long.modM(b:Long):Long{
	return (this * b) % p
}
const val p = 998244353L
const val pI = 998244353
internal class segTreewithP(
	private val size: Int
) {
	//indices are 0 until size
	// out of boundary access are perfectly fine
	// if anyone reads this up in codeforces,
	// I have kept all 4 operations for your conveniences
	val sum = IntArray(4 * size)
	//    val max: LongArray = LongArray(4 * size)
//    val min: LongArray = LongArray(4 * size)
	val lazy = IntArray(4 * size)
	fun update(l: Int, r: Int, inc: Int) {
		update(1, 0, size - 1, l, r, inc)
	}
	private fun Int.reduce():Int{
		return if(this > pI) this - pI else this
	}

	private fun pushDown(index: Int, l: Int, r: Int) {
//        min[index] += lazy[index]
//        max[index] += lazy[index];
		sum[index] = ((sum[index] + (lazy[index] * (r-l+1).toLong())) % p).toInt()
		if (l != r) {
			lazy[2 * index] = (lazy[2 * index]+lazy[index]).reduce()
			lazy[2 * index + 1] = (lazy[2 * index + 1]+lazy[index]).reduce()
		}
		lazy[index] = 0
	}

	private fun pullUp(index: Int, l: Int, r: Int) {
		val m = (l + r) / 2
//        min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
//        max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
		val ret = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r)
		sum[index] = if(ret > pI) ret - pI else ret
	}

	//    private fun evaluateMin(index: Int, l: Int, r: Int): Long {
//        return min[index] + lazy[index]
//    }
//    private fun evaluateMax(index: Int, l: Int, r: Int): Long {
//        return max[index] + lazy[index]
//    }
	private fun evaluateSum(index: Int, l: Int, r: Int): Int {
//        println("Evaluate $l $r")
//    println((sum[index] + (lazy[index] modM (r-l+1).toLong())) % p)
		return ((sum[index] + (lazy[index] * (r-l+1).toLong())) % p).toInt()
	}

	private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Int) {
		if (r < left || l > right) return
		if (l >= left && r <= right) {
			lazy[index] = (lazy[index] + inc).reduce()
			return
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		update(2 * index, l, m, left, right, inc)
		update(2 * index + 1, m + 1, r, left, right, inc)
		pullUp(index, l, r)
	}

//    fun minQuery(l: Int, r: Int): Long {
//        return minQuery(1, 0, size - 1, l, r)
//    }
//    fun maxQuery(l: Int, r: Int): Long {
//        return maxQuery(1, 0, size - 1, l, r)
//    }


	fun sumQuery(l: Int, r: Int): Int {
		return sumQuery(1, 0, size - 1, l, r)
	}

	//    private fun minQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//        if (r < left || l > right) return Long.MAX_VALUE
//        if (l >= left && r <= right) {
//            return evaluateMin(index, l, r)
//        }
//        pushDown(index, l, r)
//        val m = (l + r) / 2
//        var ret = Long.MAX_VALUE
//        ret = Math.min(ret, minQuery(2 * index, l, m, left, right))
//        ret = Math.min(ret, minQuery(2 * index + 1, m + 1, r, left, right))
//        pullUp(index, l, r)
//        return ret
//    }
//    private fun maxQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//        if (r < left || l > right) return Long.MIN_VALUE
//        if (l >= left && r <= right) {
//            return evaluateMax(index, l, r)
//        }
//        pushDown(index, l, r)
//        val m = (l + r) / 2
//        var ret = Long.MIN_VALUE
//        ret = Math.max(ret, maxQuery(2 * index, l, m, left, right))
//        ret = Math.max(ret, maxQuery(2 * index + 1, m + 1, r, left, right))
//        pullUp(index, l, r)
//        return ret
//    }
	private fun sumQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Int {
		if (r < left || l > right) return 0
		if (l >= left && r <= right) {
			return evaluateSum(index, l, r)
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		var ret = 0
		ret += sumQuery(2 * index, l, m, left, right)
		ret += sumQuery(2 * index + 1, m + 1, r, left, right)
		pullUp(index, l, r)
		return if(ret >= pI) ret - pI else ret
	}
	fun printTree(){
		val ret = mutableListOf<Int>()
		for(i in 0 until size){
			ret.add(sumQuery(i,i))
		}
		println(ret.joinToString(" "))
	}
}

class portal(val oldy:Int, val oldx :Int, val s:Int){
	var hits:Long = 0L
	var x:Int = -1
	var y:Int = -1
}
fun main() {
//	val n = 200000
	val n = getint()
//	TIME {
		val original = mutableListOf<portal>()
		repeat(n) {
//			val new = portal((it) * 250, (it + n) * 250, 1)
			val new = portal(getint(),getint(),getint())
			original.add(new)
		}
		val indices = TreeSet<Int>()
		for(a in original) {
			indices.add(a.oldx)
			indices.add(a.oldy)
		}
		val sindices = indices.sorted()
		val reverse = TreeMap<Int, Int>()
		for((v, a) in sindices.withIndex()) {
			reverse[a] = v
		}
		for(p in original) {
			p.x = reverse[p.oldx]!!
			p.y = reverse[p.oldy]!!
		}
		val psorted = original.sortedByDescending { it.y }
		val max = sindices.size + 5
		val landed = segTreewithP(max)
		for(a in psorted) {
			val size = landed.sumQuery(0, a.y)
			val total = size + if(a.s == 1) 1 else 0
			a.hits = total % p
			landed.update(a.x, a.x, a.hits.toInt())
		}
		val actualMax = original.maxOf { it.oldy } + 1
		var ret = actualMax.toLong() % p
		for(pt in psorted) {
			val new = (pt.oldy - pt.oldx).toLong() % p
			ret += new modM (pt.hits)
			ret %= p
		}
		put(ret)
		done()
//	}
    // Write your solution here
}