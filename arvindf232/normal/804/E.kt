/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
 */

import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
data class permutation(val p:IntArray){
	val n:Int get() = p.size
	companion object{
		fun identity(n:Int): permutation {
			return permutation((0 until n).toList().toIntArray())
		}
		fun standard(n:Int): MutableList<permutation> {
			val ret = mutableListOf<permutation>()
			val A = IntArray(n){it}
			val c = IntArray(n)

			ret.add(permutation(A.copyOf()))

			var i = 0
			while(i < n){
				if(c[i] < i){
					if(i %2 == 0){
						A[0] = A[i].also { A[i] = A[0] }
					}else{
						A[c[i]] = A[i].also { A[i] = A[c[i]] }
					}
					ret.add(permutation(A.copyOf()))
					c[i] += 1
					i = 0
				}else{
					c[i] = 0
					i += 1
				}
			}
			return ret
		}
	}
	// 0 based
	fun inverse():permutation{
		val ret = IntArray(p.size)
		for(i in 0..p.lastIndex){
			ret[p[i]] = i
		}
		return permutation(ret)
	}
	infix fun compose(other:permutation):permutation{
		val ret = IntArray(p.size)
		for(i in 0..p.lastIndex){
			ret[p[other.p[i]]] = i
		}
		return permutation(ret)
	}
	fun swapDistances():Int{
		var ret = 0
		cyclesOfPermutations { ret += it.size - 1  }
		return ret
	}
	fun shiftRightBy(a:Int):permutation{
		val ret = IntArray(p.size)
		var here = a - 1
		for(i in 0 until p.size){
			here += 1
			if(here >= p.size){
				here -= p.size
			}
			ret[here] = p[i]
		}
		return permutation(ret)
	}
	fun swapAt(a:Int,b:Int):permutation{
		val new = p.copyOf()
		new[a] = new[b].also{new[b] = new[a]}
		return permutation(new)
	}
	inline fun cyclesOfPermutations(doit:(List<Int>)->Unit){
		val arr = this.p
		val n = arr.size
		val done = BooleanArray(n)
		var haveDone = 0
		var pointer = 0
		while(haveDone < n){
			while(done[pointer]){
				pointer++
			}
			haveDone += 1
			val x = pointer
			val todo = mutableListOf(x)
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
			doit(todo)
		}
	}

	fun subpermutation(mask:Int):permutation{
		val things = mutableListOf<Int>()
		for(i in 0 until p.size){
			if(mask and 1 shl i != 0){
				things.add(i)
			}
		}
		val firstThings = things.withIndex().sortedBy { it.value }
		return (permutation(firstThings.map{it.index}.toIntArray()).inverse())
	}

	override fun equals(other: Any?): Boolean {
		if (this === other) return true
		if (javaClass != other?.javaClass) return false

		other as permutation

		if (!p.contentEquals(other.p)) return false

		return true
	}

	override fun hashCode(): Int {
		return p.contentHashCode()
	}

	override fun toString(): String {
		return p.joinToString(" ")
	}
}

data class answer(var n:Int, val list:MutableList<Pair<Int,Int>>){
	companion object{
		fun getFor(k:Int){
			val swaps = mutableListOf<Pair<Int,Int>>()
			for(i in 0 until k){
				for(j in (i+1) until k){
					swaps.add(Pair(i,j))
				}
			}
			val ps = swaps.size
			for(ts in permutation.standard(ps)){
				var tryThis = permutation.identity(k)
				for(i in 0 until ps){
					val s = swaps[ts.p[i]]
					val (a,b) = s
					tryThis = tryThis.swapAt(a,b)
				}
				if(tryThis == permutation.identity(k)){
					for(i in 0 until ps){
						println(swaps[ts.p[i]])
					}
					break
				}
			}
		}
		val ans4 = listOf(Pair(0,1),Pair(0,3),Pair(1,2),Pair(0,2),Pair(1,3),Pair(2,3))
		val ans5 = listOf(Pair(0,3),Pair(0,1),Pair(1,3),Pair(0,4),Pair(1,2),Pair(0,2),Pair(1,4),Pair(2,3),Pair(2,4),Pair(3,4))
		val A4 = answer(4,ans4.toMutableList())
		val A5 = answer(5,ans5.toMutableList())
	}

	fun validate():Boolean{
		var here = permutation.identity(n)
		for((a,b) in this.list){
			here = here.swapAt(a,b)
		}
		return here == permutation.identity(n)
	}

	fun add4(){
		val k = n
		n += 4
		for(i in 0 until k){
			list.add(Pair(i,k))
		}
		for(i in k-1 downTo 0 ){
			list.add(Pair(i,k+1))
		}
		for(i in 0 until k){
			list.add(Pair(i,k+2))
		}
		list.add(Pair(k,k+3))
		for(i in k-1 downTo 0 ){
			list.add(Pair(i,k+3))
		}
		list.add(Pair(k+2,k+3))
		list.add(Pair(k+1,k+2))
		list.add(Pair(k,k+1))
		list.add(Pair(k+1,k+3))
		list.add(Pair(k,k+2))
	}


}


inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
}

class FastScanner() {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`: BufferedInputStream? = null

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

	init {
		`in` = BufferedInputStream(System.`in`, BS)
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
	//does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
fun crash(){throw Exception("Bad programme")} // because assertion does not work



fun main() {
	val n = getint()

	if( n== 1){
		put("YES")
		done()
		return
	}
	val r = n % 4
	if(r == 2 || r == 3){
		put("NO")
		done()
	}else{
		val base = if(r == 0) answer.A4 else answer.A5
		while(base.n < n){
			base.add4()
		}
		put("YES")
		for(a in base.list){
			put(a.first + 1 )
			put(a.second+1)
		}
		done()
	}
//	println(answer.A4.validate())
//	val ansnow = answer.A4
//	ansnow.add4()
//	println(ansnow.validate())
//	answer.getFor(4)
//	println(answer.A4.validate())
//	println(answer.A5.validate())
//	val want = permutation(intArrayOf(3,0,1,2))
//	val swaps = listOf(Pair(0,1),Pair(0,2),Pair(1,2),Pair(1,3),Pair(2,3))
//	for(ts in permutation.standard(5)){
//		var tryThis = want
//		for(i in 0 until 5){
//			val s = swaps[ts.p[i]]
//			val (a,b) = s
//			tryThis = tryThis.swapAt(a,b)
//		}
//		if(tryThis == permutation.identity(4)){
//			println("success")
//			for(i in 0 until 5){
//				println(swaps[ts.p[i]])
//			}
//			break
//		}
//
//	}

    // Write your solution here
}