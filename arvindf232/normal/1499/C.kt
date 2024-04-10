/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

parity is trivial


choose an n

 result is most n = cheapest option
 + 1 piece for all other

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
class rsq(val arr:List<Int>) {
	val ps = arr.runningFold(0L, { a,b->a+b.toLong()} )
	fun sumQuery(l:Int,r:Int):Long{
		val ll = maxOf(l,0)
		val rr = minOf(arr.lastIndex,r) + 1
		return ps[rr] - ps[ll]
	}
}
infix fun String.dei(a:Any){
	//does not stand for anything it is just easy to type
	if(a is List<*>){
		println("$this : ${a.joinToString(" ")}")
	}else if(a is IntArray){
		println("$this : ${a.joinToString(" ")}")
	}else if(a is LongArray){
		println("$this : ${a.joinToString(" ")}")
	}else{
		println("$this : $a")
	}
}
val just = " "

fun main() {
	cases{
		val n = getint()
		val arr = getline(n)
		val b1 = arr.slice(arr.indices step 2)
		val b2 = arr.slice(1 until arr.size step 2 )

//		"b1" dei b1
//		"b2" dei b2

		fun complie(a:List<Int>):List<Long>{
			val rm = rmq(a)
			val rs = rsq(a)


			var ret = mutableListOf<Long>(0)
			for(take in 1..minOf(n,a.size)){
				val price = rs.sumQuery(0,take-1)
				val rm = rm.minQuery(0,take-1).toLong()
				val ans = price + rm * (n - take + 1 - 1)
				ret.add(ans)
			}

//			just dei ret
			return ret
		}

		val c = complie(b1)
		val d = complie(b2)

		var ret = Long.MAX_VALUE
		for(i in 2..n){
			val p1 = c[(i+1)/2]
			val p2 = d[i/2]
			ret = minOf(ret,p1 +p2)
//			"$i" dei (p1+p2)
		}
		put(ret)
	}
	done()
    // Write your solution here
}