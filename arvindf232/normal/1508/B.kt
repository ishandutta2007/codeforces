/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */import java.io.BufferedInputStream
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

fun <T> Set<T>.subsets(): Sequence<Set<T>> = sequence {
	when (size) {
		0 -> yield(emptySet<T>())
		else -> {
			val head = first()
			val tail = this@subsets - head
			yieldAll(tail.subsets())
			for (subset in tail.subsets()) {
				yield(setOf(head) + subset)
			}
		}
	}
}
fun <T> permutations(list: List<T>): Set<List<T>> {
	if (list.isEmpty()) return setOf(emptyList())

	val result: MutableSet<List<T>> = mutableSetOf()
	for (i in list.indices) {
		permutations(list - list[i]).forEach{
				item -> result.add(item + list[i])
		}
	}

	return result
}
fun standardPermutations(n:Int):List<IntArray>{
	val list = List(n){it + 1 }
	return permutations(list).map{(listOf(0) + it).toIntArray()}
}

fun IntArray.good():Boolean{
	return (0 until this.size - 1).all{this[it+1] >= this[it] -1 }
}
/*
9
4 1
4 2
4 3
4 4
4 5
4 6
4 7
4 8
4 9


 */
fun main() {
	cases{
		val n = getint()
		var k = getlong() - 1

		val ret1 = IntArray(n-1)
		var pointer = n-2
		while(k > 0){
			if(pointer < 0 && k > 0){
				put(-1)
				return@cases
			}
			val r = k % 2
			ret1[pointer] = r.toInt()
			k /= 2
			pointer -= 1
			if(pointer < 0 && k > 0){
				put(-1)
				return@cases
			}
		}
		val ret = IntArray(n){it + 1}

//		just dei ret1

		var pt = 0
		first@while(true){
			if(pt >= n-1){
				break
			}
			while(ret1[pt] == 0){
				pt += 1
				if(pt >= n-1){
					break@first
				}
			}
			val here = pt
			val last = (here+1 until n-1).firstOrNull { ret1[it] == 0 } ?: n-1

//			1 dei here
//			2 dei last

			for(s in here..last){
				ret[s] = here + last - s + 1
			}
			pt = last
		}
		put(ret.joinToString(" "))

	}
//
//	println("BF")
//	val goodstuff = mutableListOf<IntArray>()
//	for(p in standardPermutations(4)){
//		if(p.good()){
//			goodstuff.add(p)
//		}
//	}
//	goodstuff.sortWith(Comparator { a, b ->
//		val first = (a.indices).first { a[it] != b[it] }
//		a[first] - b[first]
//	})
//	for(p in goodstuff){
//		just dei p
//	}
//	println(goodstuff.size)

	done()
}