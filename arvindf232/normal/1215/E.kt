import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.math.absoluteValue
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
}

object IO{
	private const val BS = 1 shl 16
	private const val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC

	var warningActive = true
	var fakein = StringBuilder()

	private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
	val OUT: PrintWriter = PrintWriter(System.out)

	private val char: Char
		get() {
			while (bId == size) {
				size = IN.read(buf) // no need for checked exceptions
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
		while (c in '0'..'9') {
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
		while (c in '0'..'9') {
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
		ret.append(c)
		while (true){
			c = char
			if(isWhitespace(c)){ break}
			ret.append(c)
		}
		return ret.toString()
	}
	fun isWhitespace(c:Char):Boolean{
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
	fun rerouteInput(){
		if(warningActive){
			System.err.println("Not accepting inputs!")
			warningActive = false
		}
		IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
	}

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
	if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
	else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
	else if(aa is List<*>){IO.fakein.append(aa.toString())}
	else{IO.fakein.append(aa.toString())}
	IO.fakein.append("\n")
}

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
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
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
enum class solveMode {
	real, rand, tc
}
object solve{
	var mode:solveMode = solveMode.real
	var tcNum:Int = 0
	var rand:()->Unit = {}
	var TC:MutableMap<Int,()->Unit> = mutableMapOf()
	var answersChecked = 0
	inline fun cases(a:solve.()->Unit){
		val t = if(mode == solveMode.real){1} else if(mode == solveMode.tc){1 } else randCount
		repeat(t){
			if(mode == solveMode.tc){
				TC[tcNum]?.let { it() }
				IO.rerouteInput()
			}else if(mode == solveMode.rand){
				rand()
				IO.rerouteInput()
			}
			currentAnswer = null
			currentBruteAnswer = null
			a()
		}
		if(withBruteForce){
			put("Checked ${answersChecked}")
		}
	}
	inline fun singleCase(a:solve.()->Unit){
		val t = if(mode != solveMode.rand){1} else randCount
		repeat(t) { a() }
	}
	fun rand(a:()->Unit){
		this.rand = a
	}
	fun tc(id:Int = 0,a:()->Unit){
		TC[id] = a
	}
	inline fun brute(a:()->Unit){
		if(withBruteForce){
			a()
		}
	}
	fun usetc(a:Int = 0 ){
		this.tcNum = a
		this.mode = solveMode.tc
	}
	fun userand(){
		this.mode = solveMode.rand
	}


	var currentAnswer:String? = null
	var currentBruteAnswer:String? = null
	fun answer(a:Any){
		currentAnswer = a.toString()
		if(currentBruteAnswer != null){
			checkAnswer()
		}
	}
	fun put2(a:Any){answer(a);put(a) }

	fun bruteAnswer(a:Any){
		currentBruteAnswer = a.toString()
		if(currentAnswer != null){
			checkAnswer()
		}
	}
	fun checkAnswer(){
		if(currentAnswer != currentBruteAnswer){
			throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
		}
		answersChecked ++
	}
}
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }


const val withBruteForce = false
const val randCount = 100


data class items(val a:List<Int>){
//	val Lsum = a.runningFold()
	fun goto(here:Int):Long{
		return 0L
//		val ret = a.size * here -

	}
	fun BFgohere(here:Int):Long{
		var ret = 0L
		for(i in 0 until a.size){

			val new = ((here + i) - a[i]).absoluteValue
			ret += new
		}
		return ret
	}
}
const val k = 20
const val HighestBit = k
inline fun Int.eachBits(act:(Int)->Unit){
	for(i in HighestBit downTo 0){
		if(this and (1 shl i) != 0){
			act(1 shl i)
		}
	}
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
	for(i in HighestBit downTo 0){
		if(this and (1 shl i) != 0){
			act(i)
		}
	}
}
inline fun Int.submask(act:(Int)->Unit){
	var here = this
	while (here > 0) {
		act(here)
		here = (here - 1) and this
	}
	act(here)
}
fun main(){
	solve.cases{
		val n = getint()
		val L = getline(n).map{it - 1 }


		val inversions = List(k){LongArray(k)}
		val count = LongArray(k)
		for(c in L){
			for(i in 0 until k){
				inversions[c][i] += count[i]
			}
			count[c] ++
		}
		val DP = LongArray(1 shl k){Long.MAX_VALUE}
		DP[0] = 0L

		for(mask in 0 until ( 1 shl k )){
			for(j in 0 until k){
				if(mask and (1 shl j) != 0) continue
				var cost = 0L
				mask.eachBitIndex {k ->
					cost += (count[j] * 1L * count[k] - inversions[k][j])
				}
				val new = DP[mask] + cost
				val node = mask or (1 shl j)
				DP[node] = minOf(DP[node],new)
			}
		}
		put(DP[(1 shl k) - 1 ])


//		val accums = List(k){ mutableListOf<Int>()}
//		for(i in 0 until n){
//			val here = L[i]
//			accums[here].add(i)
//		}
//		val sacs = accums.map{items(it)}
//		val counts = accums.map { it.size }
//
//		val sizeCount = IntArray(1 shl k )
//		for(i in 0 until (1 shl k)){
//			for(j in 0 until k) {
//				if(i and (1 shl j) != 0) {
//					sizeCount[i] += counts[j]
//				}
//			}
//		}
//
//		val DP = LongArray(1 shl k){Long.MAX_VALUE}
//		DP[0] = 0
//		for(mask in 0 until (1 shl k)){
//			for(j in 0 until k){
//				if(mask and (1 shl j ) == 0){
//					val newCost = sacs[j].BFgohere(sizeCount[mask])
//					DP[mask or (1 shl j )] = minOf(DP[mask or (1 shl j )],DP[mask] + newCost)
//				}
//			}
//		}
//		put(DP[(1 shl k) - 1 ]/2)
	}
	done()

}

/*

debug mistake
	never hardcode 20

forgetting min updates , and setting things to 0 first

is divided by 2 because of logic and (remembering the facts)


huge logic error
	number of inversions, not movements

vaiable swap at i and c

 */