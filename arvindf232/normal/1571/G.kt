import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*
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

data class attack(val ID:Int,val da:Int,val bar:Int){
	var dp = 0
}
data class warrior(val ID:Int,val atk:List<attack>)
class linearHull(){
	val tree = TreeMap<Int,Long>()

	fun cleanUP(index:Int){
		var i = index
		var here = tree[index]!!

		while(true){
			val next = tree.ceilingEntry(i + 1)
			if(next == null || next.value > here){
				break
			}else{
				tree.remove(next.key)
			}
		}
	}
	fun cleanDown(index:Int) {
		var i = index
		var here = tree[index]!!

		while(true){
			val next = tree.floorEntry(i - 1)
			if(next == null || next.value < here){
				break
			}else{
				tree.remove(next.key)
			}
		}
	}
	fun add(index:Int, value:Long){
		if(tree[index] != null){
			tree[index] = maxOf(tree[index]!!,value)
		}else{
			tree[index] = value
		}
		cleanUP(index)
		cleanDown(index)
	}
	fun queryDownMax(index:Int):Long {
		return tree.floorEntry(index)?.value ?: 0L
	}
}
val Int.highestBitsIndex:Int
	get(){
		return 31 - this.countLeadingZeroBits()
	}

val Long.highestBitsIndex:Int
	get(){
		return 63 - this.countLeadingZeroBits()
	}

infix fun Int.contains(a:Int):Boolean{
	return (this.inv() and a) == 0
}
class simpleSegTree (nSuggest  :Int){
	//Items lenght must be a power of 2

	val n = (nSuggest - 1).takeHighestOneBit() shl 1
	val levels = n.highestBitsIndex
	val arr = LongArray(n * 2 + 1 )
	val arrSize = n * 2 + 1

	constructor(withArray:LongArray):this(withArray.size){
		for(i in withArray.indices){
			arr[i+n] = withArray[i]
		}

		recalculateAll()
	}

	private fun calculateNode(i:Int){
		arr[i] = maxOf(arr[i shl 1 ], arr[(i shl 1) + 1])
	}
	private fun calculatePath(i:Int){
		// i is the endpoint, typically (n+i)
		var here = i
		while(here > 1){
			here = here shr 1
			calculateNode(here)
		}
	}
	fun recalculateAll(){
		for(i in n-1 downTo 1){
			calculateNode(i)
		}
	}
	fun setValue(i:Int,value:Long){
		arr[n+i] = value
		calculatePath(i)
	}
	fun addValue(i:Int, inc:Long){
		arr[n+i] += inc
		calculatePath(i)
	}

	val firstIndex = n
	val lastIndex = (n shl 1 ) - 1
	val indices = firstIndex..lastIndex


	fun primitiveIndex(a:Int) = a + n
	inline fun segmentOrder(act:(here:Int, left:Int,right:Int)->Unit ){
		for(i in (n-1) downTo 1){
			act(i, (i shl 1 ), (i shl 1) + 1)
		}
	}
	inline fun primitiveOrder(act:(here:Int,primitive:Int)->Unit){
		for(i in 0 until n){
			act(i+n,i)
		}
	}


	fun query(l:Int,r:Int): Long {
		var ret= 0L
		var left = l + n
		var right = r + n+1
		while(left < right){
			if(left and 1 != 0){
				ret = maxOf(ret,arr[left])
//				ret += arr[left]
				left += 1
			}
			if(right and 1 != 0){
				right -= 1
//				ret += arr[right]
				ret = maxOf(ret,arr[right])
			}
			left = left shr 1
			right = right shr 1
		}
		return ret
	}
	inline fun segQuery(l:Int,r:Int,act:(index:Int)->Unit){
		var left = l + n
		var right = r + n + 1
		while(left < right){
			if(left and 1 != 0){

				act(left)
				left += 1
			}
			if(right and 1 != 0){
				right -= 1
				act(right)
			}
			left = left shr 1
			right = right shr 1
		}
	}
//	fun queryFunctional(l:Int,r:Int):Int{
//		var ret = 0
//		segQuery(l,r){
//			ret += arr[it]
//		}
//		return ret
//	}
//	fun walkDown(req:Int):Int{
//		// -1 if not enough
//		if(req > arr[1]){
//			return Int.MAX_VALUE
//		}else if(req <= 0 ){
//			return -1
//		}
//		var i = 1
//		var rightPoint = -1
//		var cur = 0
//		for(l in 1..levels){
//			i = i shl 1
//			if(cur + arr[i] < req){
//				rightPoint += 1 shl (levels - l)
//				cur += arr[i]
//				i += 1
//			}
//		}
//		return rightPoint +1
//	}


	val Int.leftNode:Int get(){
		// assert(this <= n )
		return this shl 1
	}
	val Int.rightNode:Int get(){
		// assert(this <= n)
		return (this shl 1) + 1
	}
	val Int.endpoints:Pair<Int,Int> get(){
		val offSet = this - this.takeHighestOneBit()
		val widthLevel = levels - this.highestBitsIndex
		return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
	}

}

fun main(){
//	just dei L.queryDownMax(7)
	solve.cases{

		val n = getint()
		val m = getint()
		val W = mutableListOf<warrior>()
		var atks = mutableListOf<attack>()
		repeat(n){ID ->
			val k = getint()
			val ats = getline(k)
			val bar = getline(k)
			val alist = (0 until k).map{attack(ID,ats[it],bar[it])}
			val wa = warrior(ID,alist)
			atks.addAll(alist)
			W.add(wa)
		}
		 atks.sortWith(Comparator.comparing<attack?, Int?> {-it.bar}.thenBy {it.ID })
//		val T = simpleSegTree(n+1)
//		T.setValue(0,0)
		val H = linearHull()
		H.add(m,0)
//		val st = simpleSegTree(m + n + 1 )
//		st.setValue(m,0)
		var max = 0L
		for(a in atks){

//		for(w in W){
//			for(a in w.atk.reversed()){
				val vquery = a.bar + a.ID
				if(vquery < m) continue
				val bestAttack = H.queryDownMax(a.bar + a.ID)
//				val bestAttack = T.query(a.bar - a.ID , a.bar + a.ID - m )
				val totalAttack = bestAttack + a.da
				max = maxOf(max,totalAttack)
//				T.setValue(a.bar + a.ID + 1 - m, totalAttack)
				H.add(a.bar + a.ID + 1,totalAttack)

		}
		put(max)
	}
	done()
}