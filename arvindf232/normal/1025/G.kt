import kotlin.math.roundToInt

/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
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

const val N = 6

fun Double.round(decimals: Int): Double {
	var multiplier = 1.0
	repeat(decimals) { multiplier *= 10 }
	return (this * multiplier).roundToInt().toDouble() / multiplier
}

val cache = mutableMapOf<state,Map<state,Double>>()

data class state(val things:IntArray){
	override fun equals(other:Any?):Boolean {
		if(this === other) return true
		if(javaClass != other?.javaClass) return false

		other as state

		if(!things.contentEquals(other.things)) return false

		return true
	}

	override fun hashCode():Int {
		return things.contentHashCode()
	}

	val sums:Int get() =   things.withIndex().sumBy { it.index * it.value }
	val actives:Int get() =  things.sum()
	val terminal:Boolean get() =  actives == 1


	init{
		assert(sums == N)
	}

	fun stateIf(a:Int,b:Int):state?{
		if(things[a] <1 || things[b] <1 ){
			return null
		}
		if( a== b && things[a] <2){
			return null
		}
		val newThings = things.copyOf()
		newThings[a] -= 1
		newThings[b] -= 1
		newThings[a+1] += 1
		newThings[1] += (b-1)
		return state(newThings)
	}

	fun NS():Map<state,Double>{
		if(terminal){
			return mapOf()
		}
		if(cache[this] != null){
			return cache[this]!!
		}
		val actives = actives.toDouble()
		val ret = mutableMapOf<state,Double>()
		val total = actives * (actives - 1)
		for(i in things.indices){
			for(j in things.indices){
				val newState = stateIf(i,j) ?: continue
				val probab =
					if(i == j){
						val c = things[i]
						(c * (c-1.0) /total )
					}else{
						(things[i].toDouble()) * (things[j].toDouble())/total
					}

				ret[newState ] = probab
			}
		}

		cache[this] = ret
		return ret
	}
}


fun recursiveCheck() {
	var allStates = mutableMapOf<state,Double>()



	val initial = IntArray(N+1)
	initial[1] = N
	val iState = state(initial)

	val explored = mutableSetOf<state>(iState)

	fun explore(s:state){
		for(t in s.NS().keys){
			if(explored.contains(t)){
				continue
			}
			explored.add(t)
			explore(t)
		}
	}
	explore(iState)
	for(s in explored){
		if(s.terminal){
			allStates[s] = 0.0
		}else{
			allStates[s] = 1.00
		}
	}

	fun newValue(s:state):Double{
		if(s.terminal){
			return 0.0
		}
		var ret:Double = 1.0
		for((t,v) in s.NS().entries){
			ret += v * allStates[t]!!
		}
		return ret
	}

	repeat(5000){
		val newMap = mutableMapOf<state,Double>()
		for(s in explored){
			val v = newValue(s)
			newMap[s] = v
		}
		allStates = newMap
	}
	for((k,v) in allStates.entries){
		println(k.things.joinToString(" ") + "   " + "${v.round(2)}")
	}


	// Write your solution here
}




infix fun Int.divCeil(b:Int):Int{
	//Positives numbers only!
	if(this == 0) {
		return 0
	}
	return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
	//Positives numbers only!
	if(this == 0L) {
		return 0
	}
	return (this-1)/b + 1
}
const val p = 1000000007L
infix fun Long.modM(b:Long):Long{
	return (this * b) % p
}
fun intPow(x:Int,e:Int,m:Int):Int{
	return pow(x.toLong(),e.toLong(),m.toLong()).toInt()
}

fun pow(x:Long,e:Long,m:Long):Long{
	var X = x
	var E =e
	var Y = 1L
	while(E > 0){
		if(E % 2 == 0L){
			X = (X * X) % m
			E /= 2
		}else{
			Y = (X * Y) % m
			E -= 1
		}
	}
	return Y
}
fun Long.inverse():Long{
	return pow(this,p-2,p)
}
class FACT{
	companion object {
		var store = mutableListOf<Long>()
		var invStore = mutableListOf<Long>()

		fun preCal(upto:Int){
			store = mutableListOf()
			invStore = mutableListOf()
			store.add(1)
			invStore.add(1)
			var previous = 1L

			for(i in 1..upto) {
				previous = previous modM i.toLong()
				store.add(previous)
				invStore.add(previous.inverse())
			}
		}
		operator fun get(n:Int):Long{
			return store[n]
		}
		operator fun get(n:Long):Long{
			return store[n.toInt()]
		}

		fun choose(n:Int,r:Int):Long{
			val a = FACT[n]
			val b = invStore[n-r]
			val c = invStore[r]
			return (a modM b) modM c
		}

	}
}


const val max = 5000
fun main(){

	val n = getint()
	val items = getline(n)
	val sizes = IntArray(n)

	for((i,a) in items.withIndex()){
		if(a == -1){
			sizes[i] += 1
		}else{
			sizes[i] = 0
			sizes[a-1] += 1
		}
	}
	val collect = IntArray(n+1)
	for(i in sizes){
		collect[i] += 1
	}
	val costValues = IntArray(max)
	for(i in 2 until max){
		val pre = costValues[i-1]
		costValues[i] = ((2 * pre + 1) % p).toInt()
	}
	var ret:Long = costValues[n].toLong()
	for((i,v) in collect.withIndex()){
		val reducing = (v.toLong() modM costValues[i].toLong())
		ret = (ret - reducing) % p
		if(ret < 0){
			ret += p
		}
	}
	val x = 0 
	put(ret)
	done()

}