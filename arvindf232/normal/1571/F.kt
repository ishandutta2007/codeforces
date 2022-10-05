import java.io.BufferedInputStream
import java.io.PrintWriter
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
		val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
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

const val singleCase = true
const val withBruteForce = false
const val randCount = 100

data class entries(val ID:Int,val len:Int, val sep:Int)


fun packer(a:IntArray, sizeMin:Int,sizeMax:Int):List<Int>?{
	val size = sizeMax
	val DP = List(a.size + 1){BooleanArray(size + 1)}
	var p = 1
	DP[0][0] = true
	for(c in a){
		for(i in 0..size){
			if(DP[p-1][i]) {
				if(i + c <= size){ DP[p][i + c] = true}
				DP[p][i] = true
			}
		}
		p ++
	}
	p = DP.lastIndex - 1
	var unpackedList = mutableListOf<Int>()
	var target = -1
	var currentPack = -1
	for(i in sizeMin..sizeMax){
		if(DP.last()[i]){
			currentPack = i
			target = i
		}
	}
	if(currentPack == -1){
		return null
	}
	for(i in a.lastIndex downTo 0){
		val c = a[i]
		val want = currentPack - c
		if(want < 0) continue
		if(DP[p][want]){
			unpackedList.add(i)
			currentPack = want
		}
		p--
	}
	assert(unpackedList.sumOf { a[it] } == target)
	return unpackedList
}

class data(val n:Int, var m :Int, val items:List<entries>){
	val ret = IntArray(n)
	var bad = false

	init{
		val one = items.filter{it.sep == 1}
		val two = items.filter{it.sep == 2}
		for(a in one){
			val start = m - a.len
			ret[a.ID] = start
			m -= a.len
		}
		val needToPack = m/2
		val len = two.map { it.len }.toIntArray()
		val sum = len.sum()
		val ok = (0..needToPack).filter{
			val remaining = sum - it
			remaining <= (m - needToPack)
		}
		val minOK = ok.minOrNull()
		val twoUsed = BooleanArray(two.size)
		if(minOK == null){bad = true }else{
			val packed = packer(len,minOK,needToPack)
			if(packed == null){bad = true}else{
				var here = 1
				for(i in packed){
					ret[two[i].ID] = here
					here += two[i].len * 2
					twoUsed[i] = true
				}
				here = 0
				for(i in twoUsed.indices){
					if(twoUsed[i]) continue
					ret[two[i].ID] = here
					here += two[i].len * 2
				}
			}
		}
	}

}
fun main(){
//	val a = packer(intArrayOf(3,2,2),3,3)
//	just dei a!!
	solve.cases{
		val n = getint()
		val m = getint()
		val En = mutableListOf<entries>()
		repeat(n){
			val new = entries(it,getint(),getint())
			En.add(new)
		}
		val R = data(n,m,En)
		if(R.bad){
			put("-1")
		}else{
			for(a in R.ret){
				put(a + 1)
			}
		}
	}
	done()
}