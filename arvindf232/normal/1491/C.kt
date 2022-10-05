/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.max

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
internal class segTree(
	private val size: Int
) {
	//indices are 0 until size
	// out of boundary access are perfectly fine
	// if anyone reads this up in codeforces,
	// I have kept all 4 operations for your conveniences
	val sum: LongArray = LongArray(4 * size)
//	val max: LongArray = LongArray(4 * size)
//	val min: LongArray = LongArray(4 * size)
	val lazy: LongArray = LongArray(4 * size)
	fun update(l: Int, r: Int, inc: Int) {
		update(1, 0, size - 1, l, r, inc)
	}

	private fun pushDown(index: Int, l: Int, r: Int) {
//		min[index] += lazy[index]
//		max[index] += lazy[index];
		sum[index] += lazy[index] * (r-l+1);
		if (l != r) {
			lazy[2 * index] += lazy[index]
			lazy[2 * index + 1] += lazy[index]
		}
		lazy[index] = 0
	}

	private fun pullUp(index: Int, l: Int, r: Int) {
		val m = (l + r) / 2
//		min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
//		max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
		sum[index] = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r);
	}

//	private fun evaluateMin(index: Int, l: Int, r: Int): Long {
//		return min[index] + lazy[index]
//	}
//	private fun evaluateMax(index: Int, l: Int, r: Int): Long {
//		return max[index] + lazy[index]
//	}
	private fun evaluateSum(index: Int, l: Int, r: Int): Long {
		return sum[index] + lazy[index] * (r-l+1)
	}

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

//	fun minQuery(l: Int, r: Int): Long {
//		return minQuery(1, 0, size - 1, l, r)
//	}
//	fun maxQuery(l: Int, r: Int): Long {
//		return maxQuery(1, 0, size - 1, l, r)
//	}


	fun sumQuery(l: Int, r: Int): Long {
		return sumQuery(1, 0, size - 1, l, r)
	}
//
//	private fun minQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//		if (r < left || l > right) return Long.MAX_VALUE
//		if (l >= left && r <= right) {
//			return evaluateMin(index, l, r)
//		}
//		pushDown(index, l, r)
//		val m = (l + r) / 2
//		var ret = Long.MAX_VALUE
//		ret = Math.min(ret, minQuery(2 * index, l, m, left, right))
//		ret = Math.min(ret, minQuery(2 * index + 1, m + 1, r, left, right))
//		pullUp(index, l, r)
//		return ret
//	}
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
	private fun sumQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
		if (r < left || l > right) return 0L
		if (l >= left && r <= right) {
			return evaluateSum(index, l, r)
		}
		pushDown(index, l, r)
		val m = (l + r) / 2
		var ret = 0L
		ret += sumQuery(2 * index, l, m, left, right)
		ret += sumQuery(2 * index + 1, m + 1, r, left, right)
		pullUp(index, l, r)
		return ret
	}
	fun printTree(){
		val ret = mutableListOf<Long>()
		for(i in 0 until size){
			ret.add(sumQuery(i,i))
		}
		println("Tree" + ret.joinToString(" "))
	}
}

//Price:  500ms for 400k operations, with all min,max,update present
fun ask(arrs:List<Int>):Long{
	val arr = arrs.toMutableList()
	var taken = 0L
	val n = arr.size
	for(i in arr.indices){
		val k = arr[i] - 1

		var holding = 0
		val summed = IntArray(n)
//		val simul = IntArray(n)
		taken += k
		arr[i] = 1

		fun update(a:Int,b:Int,inc:Int){
			if(a <= summed.lastIndex){
				summed[a] += inc
			}

			if(b < summed.lastIndex){
				summed[b+1] -= inc
			}
		}
		update(i+2,i+k+1,1)
		for(j in i+1 until n ){
			holding += summed[j]
//			println(holding)
//			println(summed.joinToString(" "))
			val size = holding
			if(size != 0){
				val x = 0
			}
			val properCount = minOf(size,arr[j] - 1)
			val oneCount = size - properCount
			val maxPower = arr[j]

			val result = maxPower - properCount

			arr[j] = result

//			println("one count ${oneCount} proper ${properCount}")

			update(j+maxPower-properCount+1, j + maxPower,1)
			update(j+1,j+1,oneCount)
//			update(j,j,-size)
//			simul.printTree()
		}
//			println(" arr" + arr.joinToString(" "))
	}
	return taken
}
fun concreteSimulatino(arrs:List<Int>):Int{
	val arr = arrs.toMutableList()
	var ret = 0
	while(true){
		var f = arr.indexOfFirst{it != 1}
		if(f == -1){
			return ret
		}
		ret += 1
		var pointer = f
		while(true){
			if(pointer > arr.lastIndex){
				break
			}
			val power = arr[pointer]
			arr[pointer] = maxOf(power - 1, 1)
			pointer += power
		}
//		println(arr.joinToString(" "))
	}
}
//fun concreteSimulatino(arrs:List<Int>):Int{
//	val arr = arrs.toMutableList()
//	var ret = 0
//	fun jumpOn(f:Int){
//
//		ret += 1
//		var pointer = f
//		while(true){
//			if(pointer > arr.lastIndex){
//				break
//			}
//			val power = arr[pointer]
//			arr[pointer] = maxOf(power - 1, 1)
//			pointer += power
//		}
//	}
//	while(true){
//		var f = arr.indexOfFirst{it != 1}
//		if(f == -1){
//			return ret
//		}
//		jumpOn(f)
//
////		println(arr.joinToString(" "))
//	}
//}

fun main() {
//	for(a in 1..3){
//		for(b in 1..3){
//			for(c in 1..3){
//				for(d in 1..3){
//					for(e in 1..3){
//						val arr = listOf(a,b,c,d,e)
//						val ans = ask(arr).toInt()
//						val sim = concreteSimulatino(arr)
//						if(sim != ans){
//							println("${a} ${b} ${c} ${d} ${e} got ${ans}  correct ${sim}")
//						}
//					}
//				}
//
//
//			}
//		}
//	}

	cases{
		val n = getint()
		val arr = getline(n).toMutableList()
		put(ask(arr))
//		put(concreteSimulatino(arr))


	}
	done()
//     Write your solution here
}