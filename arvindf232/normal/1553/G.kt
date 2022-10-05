/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.ln
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
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


data class query(val a:Int,val b:Int){
	var ans:Int = -1

}
const val sieveMx = 1000005
val primeOf = IntArray(sieveMx + 1)
var primeCounter = 0
val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
val primes = IntArray(primeUpperBound)
var sieveCalculated = false

fun calculateSieveFast(){
	if(sieveCalculated){
		return
	}
	sieveCalculated = true
	for(i in 2..sieveMx){
		if(primeOf[i] == 0 ){
			primeOf[i] = i
			primes[primeCounter] = i
			primeCounter += 1
		}
		for(j in 0 until primeCounter){
			val p = primes[j]
			val pd = p * i
			if(p <= i && pd <= sieveMx){
				primeOf[pd] = p
			}else{
				break
			}
		}
	}
}
inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
	var p = 1
	var count = 0
	var a = this
	while(a > 1){
		val next = primeOf[a]
		a /= next
		if(next == p){
			count += 1
		}else{
			if(count != 0){
				act(p,count)
			}
			p = next
			count = 1
		}
	}
	if(p != 1){
		act(p,count)
	}

}
class DisjointUnionSets(n: Int) {
	var rank: IntArray
	var parent: IntArray
	var n: Int
	var counts:Int = 0

	fun makeSet() {
		for (i in 0 until n) {
			parent[i] = i
		}
	}

	fun find(x: Int): Int {
		if (parent[x] != x) {
			parent[x] = find(parent[x])
		}
		didModify(x)
		return parent[x]
	}

	fun union(x: Int, y: Int) {
		didModify(x)
		didModify(y)
		val xRoot = find(x)
		val yRoot = find(y)
		if (xRoot == yRoot) return
		counts += 1
		if (rank[xRoot] < rank[yRoot])
			parent[xRoot] = yRoot else if (rank[yRoot] < rank[xRoot])
			parent[yRoot] = xRoot else
		{
			parent[yRoot] = xRoot
			rank[xRoot] = rank[xRoot] + 1
		}
	}

	var modified = mutableListOf<Int>()
	fun didModify(a:Int){
//        modified.add(a)
	}
	fun resetAll(){
		for(a in modified){
			parent[a] = a
		}
		counts = 0
		modified = mutableListOf()
	}
	fun printClasses(){

	}

	init {
		rank = IntArray(n)
		parent = IntArray(n)
		this.n = n
		makeSet()
	}
}
fun main() {
	calculateSieveFast()
	val n = getint()
	val q = getint()
	val arr = getline(n)
	val queries = mutableListOf<query>()
	repeat(q){
		queries.add(query(getint() - 1 , getint() - 1 ))
	}
	val primeIndex = IntArray(1000005)
	for((i,p) in primes.withIndex()){
		if(i > primeCounter){
			break
		}
		primeIndex[p] = i
	}


	val DSU = DisjointUnionSets(primeCounter)

	for(l in arr){
		var last:Int = -1
		l.eachPrimePower { p, a ->
			if(last != -1){
				DSU.union(primeIndex[p],primeIndex[last])
			}
			last = p
		}
	}

	val classes = (0 until primeCounter).map{DSU.find(primeIndex[primes[it]])}.toSet().toList()
	val classCount = classes.size
	val classEncode = IntArray(1000005)
	for((i,v) in classes.withIndex()){
		classEncode[v] = i
	}
	val connects = List<MutableSet<Int>>(classCount){ mutableSetOf()}

	for(l in arr){
		val allConnects = mutableSetOf<Int>()
		l.eachPrimePower{p,a -> allConnects.add(p)}
		(l+1).eachPrimePower{p,a -> allConnects.add(p)}
		val things = allConnects.map{classEncode[DSU.find(primeIndex[it])]}.toSet().toList()
		for(i in things.indices){
			for(j in 0..i){
				connects[things[i]].add(things[j])
				connects[things[j]].add(things[i])
			}
		}
	}

	for(q in queries){
		val i1 = primeIndex[primeOf[arr[q.a]]]
		val i2 = primeIndex[primeOf[arr[q.b]]]
		val f1 = DSU.find(i1)
		val f2 = DSU.find(i2)
		if(f1 == f2){
			q.ans = 0
		}else{
			val c1 = classEncode[f1]
			val c2 = classEncode[f2]
			if(connects[c1].contains(c2)){
				q.ans = 1
			}else{
				q.ans = 2
			}
		}
	}
	for(q in queries){
		put(q.ans)
	}
	done()



    // Write your solution here
}