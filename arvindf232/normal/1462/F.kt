// type your solution here


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
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
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

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
fun getstr():String{ return IO.nextString() }

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
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
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
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
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


fun List<Int>.sortedDistinctInt():List<Int>{
    val ret = ArrayList<Int>(this.size)
    for(a in this.sorted()){
        if(ret.size == 0 || ret.last() != a){
            ret.add(a)
        }
    }
    return ret
}

class coordinateCompression(things:List<Int>) {
    val forward:List<Int>
    val reverse:MutableMap<Int,Int> = HashMap(things.size / 3 * 4 + 5)

    init{
        forward = things.sortedDistinctInt()
        for((i,v) in forward.withIndex()){
            reverse[v] = i
        }
    }
}
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
}

class inter(var x:Int, var y:Int):Comparable<inter>{
	override fun compareTo(other:inter):Int {
		if(this.x != other.x )return x.compareTo(other.x)
		return y.compareTo(other.y)
	}
	var intersects = 0

}
inline fun<T> batchProcess(a:List<T>, by:(T)->Int, batch:(List<T>)->Unit){
	var last:Int? = null
	val all = mutableListOf<T>()
	for(c in a){
		val next = by(c)
		if(last == null || next != last){
			if(all.isNotEmpty()){
				batch(all)
			}
			all.clear()
		}
		last = next
		all.add(c)
	}
	if(all.isNotEmpty()){
		batch(all)
	}
	all.clear()
}


class tempIntervalSum(val n:Int){
	val things = IntArray(n + 1)

	fun add(l:Int,r:Int,inc:Int){
		val ll = if(l < 0 ) 0 else l
		val rr = if(r > n-1) n else r + 1
		things[ll] += inc
		things[rr] -= inc
		things[ll] = things[ll].adjust()
		things[rr] = things[rr].adjust()
	}
	fun compile():IntArray{
		val ret = IntArray(n)
		var here = 0
		for(i in 0 until n){
			here += things[i]
			here = here.adjust()
			ret[i] = here
		}
		return ret
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
const val singleCase = false
fun main(){
    solve.cases{
		val n = getint()
		 val all = MutableList(n){inter(getint(), getint())}
		val coods = mint
		for(a in all){
			coods.add(a.x)
			coods.add(a.y)
		}
		val cc = coordinateCompression(coods)
		for(a in all){
			a.x = cc.reverse[a.x]!!
			a.y = cc.reverse[a.y]!!
		}
		val max = 2 * n
		all.sortBy { it.x }

		fun toleft(right:Boolean){
			val st = simpleSegTree(max)
			if(right) all.reverse()
			batchProcess(all,{it.x}){ samex ->
				for(c in samex){
					if(!right)
						st.addValue(c.y,1)
					else
						st.addValue(c.x,1)
				}
				for(c in samex){
					if(!right)
						c.intersects += st.query(c.x,st.n - 1)
					else
						c.intersects += st.query(0,c.y)
				}
			}
		}
		toleft(false)
		toleft(true)

		val total = mutableMapOf<Int,Int>()
		for(a in all)total.addone(a.x)
		for(a in all)a.intersects -= total[a.x]!!

//
//		val tis = tempIntervalSum(max)
//		for(a in all){
//			tis.add(a.x, a.y,1)
//		}
//		val total = tis.compile()
		var best = 0
//		just dei total
		for( a in all){

			val here = a.intersects
//			"${a.x} ${a.y}" dei here
			best = maxOf(best, here)
		}
		put(n-best)
    }
    done()
}


/*
who knows equal case is so annoying
 */