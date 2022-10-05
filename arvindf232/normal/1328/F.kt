
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.math.absoluteValue
import kotlin.random.Random
import kotlin.random.Random.Default.nextInt
import kotlin.random.nextInt
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
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
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == '1'}
}

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
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }

        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
const val withBruteForce = false
const val randCount = 100
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
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
            onecase()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
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
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor b.toLong()
val Long.first get() = (this shr 32).toInt()
val Long.second get() = this.toInt()



private const val radixLog = 11
private const val radixBase = 1 shl radixLog
private const val radixMask = radixBase - 1
fun countSort(arr: IntArray, n: Int, expB: Int) {
    val output = IntArray(n)
    val count = IntArray(radixBase)
    for(i in 0 until n) {
        count[(arr[i] shr expB) and radixMask]++
    }
    for(i in 1 until radixBase){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        output[count[(arr[i] shr expB) and radixMask] - 1] = arr[i]
        count[(arr[i] shr expB) and radixMask]--
    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
}
fun IntArray.radixsort() {
    //Positives only!
    val n = this.size
    var b = 0
    repeat(3){
        countSort(this, n, b)
        b += radixLog
    }
}
fun <K> MutableMap<K,Int>.addone(key:K){
    this[key] = this.getOrDefault(key,0) + 1
}
fun <K> MutableMap<K,Int>.subone(key:K){
    val pe = this[key]
    if(pe == 0 || pe == null){
        throw Exception("Removing what is already empty ")
    }else{
        this[key] = pe - 1
        if( pe == 1){
            this.remove(key)
        }
    }
}
class rsq(val arr:List<Int>) {
    val ps = LongArray(arr.size + 1)
    init{
        for(i in 0 until arr.size){
            ps[i+1] = ps[i] + arr[i]
        }
    }
    fun sumQuery(l:Int,r:Int):Long{
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] - ps[ll]
    }
}
class rsqArr(val arr:IntArray) {
    val ps = LongArray(arr.size + 1)
    init{
        for(i in 0 until arr.size){
            ps[i+1] = ps[i] + arr[i]
        }
    }
    fun sumQuery(l:Int,r:Int):Long{
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] - ps[ll]
    }
}
fun IntArray.torsq(): rsqArr {
    return rsqArr(this)
}
fun List<Int>.torsq():rsq{
    return rsq(this)
}
const val singleCase = true
fun main(){
    solve.tc{
        share("200000")
        share("777")
        share(List(200000){Random.nextInt(1000000000)}.conca())
    }
    solve.rand {
        share(6)
        share(Random.nextInt(1..6))
        share(List(6){Random.nextInt(1..10)})
    }
//    solve.userand()
//    solve.usetc()
    solve.cases{
		val n = getint
		val k = getint
		val L = getline(n)

		L.radixsort()

		val counts = mutableMapOf<Int,Int>()
		for(a in L){
			counts.addone(a)
		}
		if(counts.values.any{it >= k}){
			put(0)
			return@cases
		}
		fun handed(left:Boolean):Long {
			val pivot = if(left) L[k-1] else L[L.size - k]
            val alreadyhas = counts[pivot]!!
			var costs = 0L
			if(left){
				for(i in 0 until k){
                    val v = (L[i] - pivot).absoluteValue
                    costs += if(v > 0) v - 1 else 0
				}
			}else{
				for(i in L.size- k until n){
                    val v = (L[i] - pivot).absoluteValue
                    costs += if(v > 0) v - 1 else 0
                }
			}
            costs += (k - alreadyhas)
			return costs
		}
		var ret = Long.MAX_VALUE

		ret = minOf(ret,handed(false), handed(true))
		val sq = L.torsq()

		var leftpointer = 0
		while(leftpointer < n){
            val here = L[leftpointer]
            var rightpointer = leftpointer
            while(rightpointer + 1 < n && L[rightpointer +1] == here){
                rightpointer ++
            }

//			val rightpointer = (leftpointer until n).last{L[it] == L[leftpointer]}

//            leftpointer dei rightpointer

			val len = (rightpointer - leftpointer +1)
			val cost1 = (k - len)


			val leftcost = (leftpointer) *1L * (here - 1) - sq.sumQuery(0,leftpointer - 1)
			val rightcost = sq.sumQuery(rightpointer + 1, n-1) - (n-rightpointer -1 ) * 1L * (here+1)

            val T = leftcost +rightcost + cost1
//            just dei T
			ret = minOf(ret,T)
			leftpointer = rightpointer + 1
		}


        fun another():Long {
            val array = L.toMutableList()
            array.sort()
            var amtSame = 1
            for (j in 1 until n) {
                if (array[j] == array[j - 1]) {
                    amtSame++
                    if (amtSame == k) {
//                        println(0)
                        return 0L
                    }
                } else {
                    amtSame = 1
                }
            }
            var answer1 = 0L
            for (j in k until n) {
                if (array[j] == array[k - 1]) {
                    answer1--
                }
            }
            for (j in 0 until k) {
                answer1 += (array[k - 1] - array[j]).toLong()
            }
            var answer2 = 0L
            for (j in n - k - 1 downTo 0) {
                if (array[j] == array[n - k]) {
                    answer2--
                }
            }
            for (j in n - 1 downTo n - k) {
                answer2 += (array[j] - array[n - k]).toLong()
            }
            var curr = 0L
            for (j in 0 until n) {
                curr += (array[j] - array[0]).toLong()
            }
            var answer3 = curr
            for (j in 1 until n) {
                curr += (array[j] - array[j - 1]).toLong() * (j - (n - j)).toLong()
                answer3 = minOf(answer3, curr)
            }
            answer3 -= (n - k).toLong()
            return(minOf(answer3, minOf(answer1, answer2)))
        }
//        asser t(ret == another())

//        just dei another()

		put(ret)

//		fun process(fromabove:Boolean):Long {
//			val all = TreeMap<Int,Int>()
//			var cost = 0L
//			for(a in L){
//				all[a] = all.getOrDefault(a,0) + 1
//			}
//			while(true){
//				val next = if(fromabove){
//					all.lastEntry()
//				}else{
//					all.firstEntry()
//				}
//				all.remove(next.key)
//				val thenext = if(fromabove){
//					all.lastEntry()
//				}else{
//					all.firstEntry()
//				}
//				if(next.value + thenext.value >= k){
//					val move1 = 1L * ((next.key - thenext.key).absoluteValue -1) * next.value
//					val move2 = 1L * (k - thenext.value)
//					cost += move1
//					cost += move2
//					return cost
//				}else{
//					val costs = 1L * ((next.key - thenext.key).absoluteValue) * next.value
//					cost += costs
//					val newv = next.value + thenext.value
//					all[thenext.key] = newv
//					continue
//				}
//			}
//		}
//
//		put(minOf(process(false),process(true)))




    }
    done()
}
/*

BAD
greedy got punihsed yet again
see a fully working solutino first

 */


/*
has
 */
/*
6 3
2 4 8 8 9 9
 */

// 2 4 8 8 9 9
// nee d 3

// 1.. 20