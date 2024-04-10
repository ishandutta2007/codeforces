/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 k is upto 10


 k = 0
 	binary search for log 10^ 18 = 60
 k = 1
 	- must be random algortihism at its heart


 COncept:
  	trapped area
 	- does not happen easily


 Simple case :
 	assuming you catch it on a interval of k

 a b c d

Strategy :
 	Blockade + bounds + random search


  blockade

 - receding blockade

- known areas + just guess

- can thin into some area of 120 wide after 60 moves

 k=1  case

Clarity :
 	Not inside : decay inwards
 	Inside: Decay outwards


 	-> /2  + k

 after 60 moves:
  	get into case of ~20

 	60 70 80 90 100 110 120
 		70 80 90 100

 120 times each

 */

import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.random.Random

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

fun main() {
	val n = getlong()
	val k = getint()
	var askCount =0 

	fun ask(l:Long,r:Long):Boolean{
		askCount += 1 
		if(askCount > 4500){
			IntArray(1000000000)
		}
		println("$l $r")
		System.out.flush()
		val a = getstr()
		if(a == "Bad"){
			System.exit(0)
		}else if(a == "Yes" && l == r) {
			System.exit(0)
		}else{
			return a == "Yes"
		}
		return false
	}
	var lowerBound = 1L
	var upperBound = n
	//inclusive

	fun relaxBound(){
		lowerBound = maxOf(1L,lowerBound - k)
		upperBound = minOf(n,upperBound + k)
	}
	val thereshold = 120
	while(true){
		if(upperBound - lowerBound + 1 > thereshold){
			val m = (upperBound + lowerBound) /2
			val result = ask(lowerBound,m)

			if(result){
				upperBound = m
			}else{
				lowerBound = m + 1
			}
		}else{
			val guess = Random.nextLong(lowerBound,upperBound + 1)
			val x = ask(guess,guess)
		}
		relaxBound()
	}

    // Write your solution here
}