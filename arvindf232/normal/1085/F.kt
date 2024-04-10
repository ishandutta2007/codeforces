
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
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

class simpleSegTree (nSuggest  :Int){
	//Items lenght must be a power of 2

	val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
	val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
	val arr = IntArray(n * 2 + 1 )
	val arrSize = n * 2 + 1

	constructor(withArray:IntArray):this(withArray.size){
		for(i in withArray.indices){
			arr[i+n] = withArray[i]
		}

		updateAll()
	}

	private fun updateNode(i:Int){
		arr[i] = arr[i shl 1 ] + arr[(i shl 1) + 1]
	}
	private fun updatePath(i:Int){
		// i is the endpoint, typically (n+i)
		// bottom up, recalculate
		var here = i
		while(here > 1){
			here = here shr 1
			updateNode(here)
		}
	}
	fun updateAll(){
		for(i in n-1 downTo 1){
			updateNode(i)
		}
	}
	fun setValue(i:Int,value:Int){
		arr[n+i] = value
		updatePath(n+i)
	}
	fun addValue(i:Int, inc:Int){
		arr[n+i] += inc
		updatePath(n+i)
	}

	val firstIndex = n
	val lastIndex = (n shl 1 ) - 1
	val indices = firstIndex..lastIndex


	fun primitiveIndex(a:Int) = a + n
	inline fun segmentOrder(act:(here:Int, left:Int,right:Int)->Unit ){
		//iterate over all segments bottom up, probably to rebuild tree
		for(i in (n-1) downTo 1){
			act(i, (i shl 1 ), (i shl 1) + 1)
		}
	}
	inline fun primitiveOrder(act:(here:Int,primitiveIndex:Int)->Unit){
		//iterate over all the leaf nodes
		for(i in 0 until n){
			act(i+n,i)
		}
	}


	fun query(l:Int,r:Int): Int {
		var ret:Int = 0
		var left = l + n
		var right = r + n+1
		while(left < right){
			if(left and 1 != 0){
				ret += arr[left]
				left += 1
			}
			if(right and 1 != 0){
				right -= 1
				ret += arr[right]
			}
			left = left shr 1
			right = right shr 1
		}
		return ret
	}
	inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
		var left = l + n
		var right = r + n + 1
		var level = 0
		while(left < right){
			if(left and 1 != 0){

				act(left,level)
				left += 1
			}
			if(right and 1 != 0){
				right -= 1
				act(right,level)
			}
			left = left shr 1
			right = right shr 1
			level ++
		}
	}

	fun queryFunctional(l:Int,r:Int):Int{
		var ret = 0
		segDivision(l,r){i, _ ->
			ret += arr[i]
		}
		return ret
	}
	fun indexOf(req:Int):Int{
		// -1 if not enough
		val req = req + 1
		if(req > arr[1]){
			throw IndexOutOfBoundsException()
		}else if(req <= 0 ){
			return -1
		}
		var i = 1
		var rightPoint = -1
		var cur = 0
		for(l in 1..levels){
			i = i shl 1
			if(cur + arr[i] < req){
				rightPoint += 1 shl (levels - l)
				cur += arr[i]
				i += 1
			}
		}
		return rightPoint +1
	}


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
		val widthLevel = levels - (31 - this.countLeadingZeroBits())
		return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
	}


	//like set
	fun contains(a:Int): Boolean {
		return arr[a+n] == 1
	}
	fun add(a:Int){
		if(!contains(a)){
			addValue(a,1)
		}
	}
	fun remove(a:Int){
		if(contains(a)){
			addValue(a,-1)
		}
	}
	fun numberInRange(l:Int, r:Int):Int{
		return query(l,r)
	}
	val size:Int get() = this.arr[1]
	operator fun get(a:Int):Int{
		return indexOf(a)
	}
	fun first():Int{
		return get(0)
	}
	fun last():Int{
		return get(size - 1)
	}
	fun safeFirst():Int{
		return if(size == 0)  n+1 else first()
	}
	fun safeLast():Int{
		return if(size == 0)  - 1 else last()
	}
}

fun code(a:Char):Int{
	return when(a){
		'R' -> 0
		'P' -> 1
		'S' -> 2
		else -> 727
	}
}

fun Int.next():Int{
	return (this + 1 ) % 3
}
fun Int.last():Int{
	return when(this){
		1 -> 0
		2 -> 1
		0 -> 2
		else -> -1
	}
}
val except:Array<IntArray> = arrayOf(intArrayOf(1,2), intArrayOf(0,2), intArrayOf(0,1))
const val singleCase = true
fun main(){
    solve.cases{
		val n = getint
		val q = getint
		val str = getstr

		val types = Array(3){simpleSegTree(n)}
		val now = IntArray(n)

		for((i,v) in str.withIndex()){
			val c = code(v)
			types[c].add(i)
			now[i] = c
		}
		fun calculate(){
			val startColour = now[0]
			val (a,b) = except[startColour]
			if(except[startColour].all { types[it].size == 0 }){
				put(n)
				return
			}
			var ret =0
			val realstart = minOf(types[a].safeFirst(), types[b].safeFirst())

			val endColour = now[n-1]
			val (a2,b2) = except[endColour]
			val realend = maxOf(types[a2].safeLast(), types[b2].safeLast())
			if(types[startColour.last()].size != 0 )
				ret += realstart

			if(types[endColour.last()].size != 0 )
				ret += (n - 1 - realend)

			for(i in 0 until 3){
				val first = types[i].safeFirst()
				val last = types[i].safeLast()
				val next = (i+1) % 3
				ret += types[next].numberInRange(maxOf(first,realstart), minOf(last,realend))
			}
			put(ret)
		}
		calculate()
		repeat(q){
			val i = getint -1
			val c = code(getstr[0])
			val was = now[i]
			types[was].remove(i)
			types[c].add(i)
			now[i] = c
			calculate()
		}




    }
    done()
}