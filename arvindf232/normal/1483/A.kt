/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

claim :
 	iff there is no lone m/2 times

 choose all the ones first

 if lonely done


 if the max lonely occurs enough time, done
 if max lonely does not occur enough times,
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
fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
	get() = this.joinToString("")

infix fun Int.divCeil(b:Int):Int{
	//Positives numbers only!
	if(this == 0) {
		return 0
	}
	return (this-1)/b + 1
}
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
fun main() {
	cases case@{
		val n = getint()
		val m = getint()
		val arr = List(m){
			val c = getint()
			getline(c).map{it - 1}
		}
		ask3(n, arr, m)
	}
//	val things = setOf<Int>(0,1,2).subsets().filter { it != emptySet<Int>() }.toList()
//	repeat(100){
//		val n = 3
//		val m = 5
//		val arr = List(m){
//			things.random().toList()
//		}
//		ask(n,arr,m)
//	}

	done()
    // Write your solution here
}

fun IntArray.countAll(a:List<Int>){
	for(b in a){
		this[b] += 1
	}
}
private fun ask3(n:Int,arr:List<List<Int>>,m:Int) {
	val lone = IntArray(n)
	val s = arr.mapNotNull {  if(it.size ==1 )it[0] else null }
	lone.countAll(s)
	if(lone.any{it > m divCeil 2}){
		put("NO")
		return
	}
	val occurence = IntArray(n)
	for(a in arr){
		occurence.countAll(a)
	}
	val has = occurence.indexOfFirst { it >= m.divCeil(2) }
	val ret = IntArray(m){-1}
	if(has != -1){
		var taken = 0
		for((day,a) in arr.withIndex()){
			for(c in a){
				if(taken >= m divCeil 2){
					break
				}
				if(c == has && a.size ==1){
					ret[day] = has
					taken += 1
				}
			}
		}
		for((day,a) in arr.withIndex()){
			if(ret[day] >= 0){
				continue
			}
			for(c in a){
				if(taken >= m divCeil 2){
					break
				}
				if(c == has){
					ret[day] = has
					taken += 1
				}
			}
		}
	}
	for((day,a) in arr.withIndex()){
		if(ret[day] >= 0){
			continue

		}else{
			ret[day] = a.first{it != has}
		}
	}
	put("YES")
	put(ret.map{it + 1}.joinToString(" "))
}

private fun ask(n:Int, arr:List<List<Int>>, m:Int) {
	val loneOccurence = IntArray(n)
	val loneInverse = List(n) { mutableListOf<Int>() }
	val occurences = IntArray(n)
	for((i, a) in arr.withIndex()) {
		if(a.size == 1) {
			loneOccurence[a[0]] += 1
			loneInverse[a[0]].add(i)
		}
		for(c in a) {
			occurences[c] += 1
		}
	}
	if(loneOccurence.any { it > m divCeil 2 }) {
		put("NO")
		return
	}
	val x = (0 until n).firstOrNull { occurences[it] >= m divCeil 2 }
	var ret = IntArray(m) { -1 }
	if(x != null) {
		var taken = 0
		for(c in loneInverse[x]) {
			ret[c] = x
			taken += 1
		}
		outer@ for((i, a) in arr.withIndex()) {
			if(ret[i] >= 0) {
				continue
			}
			if(taken >= m divCeil 2) {
				break@outer
			}
			for(c in a) {
				if(c == x) {
					ret[i] = x
					taken += 1
					if(taken >= m divCeil 2) {
						break@outer
					}
				}
			}
		}
		for((i, a) in arr.withIndex()) {
			if(ret[i] >= 0) {
				continue
			}
			val nonx = a.first { it != x }
			ret[i] = nonx
		}
	} else {
		for((i, a) in arr.withIndex()) {
			ret[i] = a[0]
		}
	}
//	fun validate(){
//		val counts = IntArray(n)
//		for(a in ret){
//			counts[a] += 1
//		}
//		assert(counts.all{it <= m divCeil 2})
//		assert(ret.withIndex().all{(i,v) -> arr[i].contains(v)})
//	}
//	validate()
	put("YES")
	put(ret.map { it + 1 }.joinToString(" "))
}