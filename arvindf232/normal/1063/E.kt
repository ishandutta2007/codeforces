/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 almost always n -1?

 at least n - cycle lengths

 */
import java.io.BufferedInputStream
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

fun main() {
//	val n = 5
//	val arr = List(n){n - 1 - it}
	val n = getint()
	val arr = getline(n).map{it-1}


	if(arr.withIndex().all{(i,v) -> i == v}){
		put(n)
		repeat(n){
			put(List(n){'.'}.ret)
		}
		done()
		return
	}
	fun rightMostPermu(a:List<Int>):List<Int>{
		val most = a.indexOf(a.maxOrNull()!!)

		val left = a.slice(0 until most)
		val right = a.slice((most) until a.size)
		return right + left
	}

	//2 : right
	//1  left
	val ret = mutableListOf<IntArray>()

	fun layers(permu:List<Int>,sacr:Int):List<IntArray>{
		if(permu.size < 2){
			return listOf()
		}
		val permu = permu.reversed()
		val s = permu.size
		val f = permu[0]
		val l = permu[s-1]

		val ret = mutableListOf<IntArray>()
		if(sacr != -1){
			val l1 = IntArray(n)
			l1[f] = 2
			l1[sacr] = 2
			ret.add(l1)
		}

		for(i in 1 until permu.size){
			val from = permu[i]
			val to = permu[i-1]
			val new = IntArray(n)
			if(from > to){
				new[from] = 1
				new[to] = 1
			}else{
				new[from] = 2
				new[to] = 2
			}
//			println("$from $to")
			ret.add(new)
		}
		if(sacr != -1){
			val la = ret.last()
			la[sacr] = 1
		}
		return ret
	}
	var final:List<Int> = listOf()
	val sa = n-1
	val done = BooleanArray(n)
	var haveDone = 0
	var pointer = 0
	while(haveDone < n){
		while(done[pointer]){
			pointer++
		}
		haveDone += 1
		val x = pointer
		val todo = mutableListOf<Int>(x)
		var cur = x
		done[x] = true
		while(true){
			val next = arr[cur]
			if(done[next]){
				break
			}
			done[next] = true
			todo.add(next)
			haveDone += 1
			cur = next
		}
		val clean = rightMostPermu(todo)
//		just dei clean
		if(clean.contains(sa)){
			final = clean
		}else{
			ret.addAll(layers(clean,sa))
		}
	}
	val fcount = final.size
	val finalR =  final.slice(1 until (fcount )) + listOf(final[0])
//	just dei finalR
	ret.addAll(layers(finalR,-1))

	while(ret.size < n){
		ret.add(IntArray(n){0})
	}
//	ret.addAll(layers(listOf(0,2,4),-1))
	put(n-1)
	for(at in ret.reversed()){
		val str = at.map{
			when(it){
				1 -> '\\'
				2 -> '/'
				else -> '.'
			}
		}
		put(str.ret)
	}
	done()

    // Write your solution here
}