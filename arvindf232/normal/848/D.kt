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
const val pI = p.toInt()
infix fun Long.modM(b:Long):Long{
	return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
	return ((this * 1L * b) % p).toInt()
}

fun Int.adjust():Int{
	if(this >= pI){
		return this  - pI
	}else if (this < 0){
		return this + pI
	}
	return this
}
fun intPow(x:Int,e:Int,m:Int):Int{
	var X = x
	var E =e
	var Y = 1
	while(E > 0){
		if(E % 2 == 0){
			X = ((1L * X * X) % m).toInt()
			E /= 2
		}else{
			Y = ((1L * X * Y) % m).toInt()
			E -= 1
		}
	}
	return Y
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
fun Int.inverse():Int{
	return intPow(this,pI-2,pI)
}
class FACT{
	companion object {
		var store = mutableListOf<Long>()
		var invStore = mutableListOf<Long>()

		var slowStore:IntArray = IntArray(0)

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
		fun precalSlow(a:Int){
			slowStore = IntArray(a+1)
			for(i in 1..a){
				slowStore[i] = i.inverse()
			}
		}


		fun slowChoose(n:Int,r:Int):Int{
			var ret = 1
			for(i in 0 until r){
				ret = ret modM ((n - i).adjust())
			}
			for(i in 1..r){
				ret = ret modM (slowStore[i])
			}
			return ret
		}

	}
}


fun main(){
	val askn = getint()
	 val askm = getint()
	val n = 51
	val m = 51
	FACT.precalSlow(100)

	var singBoard = List(n){IntArray(m)}

	val totalBoard = List(n){IntArray(m)}

	fun addSing(i:Int, jSug:Int, newval:Int){

//		just dei "$i $jSug $newval"
		val j = jSug - 1
		val phrases = (50 / maxOf(i,j))
		val retBoard:List<IntArray> = singBoard.map{it.copyOf()}
		for(p in 1..phrases){
			val needed = FACT.slowChoose(newval + p - 1, p)
			for(x in 0 until n){
				for(y in 0 until m){
					val xx = x + i * p
					val yy =  y + j * p
					if(xx >= n || yy >= m ){
						continue
					}
					retBoard[xx][yy] += needed modM singBoard[x][y]
					retBoard[xx][yy] = retBoard[xx][yy].adjust()
				}
			}
		}
		singBoard = retBoard
	}
	fun calSingBoard(i:Int,j:Int):Int{
		var ret = 0
		for(n1 in 0 until i){
			val n2 = i - 1 - n1
			//for now
			for(m1 in 0 until m){
				for(m2 in 0 until m){
					if(minOf(m1,m2) != j-1){
						continue
					}
					ret += singBoard[n1][m1] modM singBoard[n2][m2]
					ret = ret.adjust()
				}
			}
		}
		return ret
	}
	singBoard[0][1] = 1
	for(x in 1 until n){
		for(y in 2 until m){
			val newSing = calSingBoard(x,y)
			addSing(x,y,newSing)
			totalBoard[x][y] = singBoard[x][y]
		}
	}
	put(totalBoard[askn][askm])
	done()
//		for(i in 0 until n){
//			i dei totalBoard[i]
//		}


}