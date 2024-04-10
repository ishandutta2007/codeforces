// 2022.06.30 at 21:44:58 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.system.measureTimeMillis

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
object Reader{
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
            put("Custom test enabled")
            println("Custom test enabled")
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
fun put(aa:Any){ Reader.OUT.println(aa)}
fun done(){ Reader.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){Reader.fakein.append(aa.toString())}
    else{Reader.fakein.append(aa.toString())}
    Reader.fakein.append("\n")
}

val getintfast:Int get() = Reader.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
var dmark = -1
infix fun Any.dei(a:Any){
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
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
val just = " "
fun crash(){
    throw Exception("Bad programme")}
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Not usual primes!")
        }
        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                Reader.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                Reader.rerouteInput()
            }
            onecase()
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
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}
fun debug(){}
const val singleCase = true

fun IntArray.leftAbove(inverted:Boolean):IntArray{
	//stirct
	val S = ArrayDeque<Pair<Int,Int>>()
	val ret = IntArray(this.size)
	for(i in this.indices){
		val v = this[i]
		while(S.isNotEmpty()){
			val first = S.last()
			if(inverted){
				if(v <= first.second){S.removeLast()} else break
			}else{
				if(v >= first.second){S.removeLast()} else break
			}
		}
		val last = S.lastOrNull()?.first ?: -1
		ret[i] = last
		S.add(Pair(i,v))
	}
	return ret
}
class simpleMaxTree (nSuggest  :Int){
	//Items lenght must be a power of 2

	val void = Int.MIN_VALUE

	val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
	val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
	val arr = IntArray(n * 2 + 1 ){void}
	val arrSize = n * 2 + 1

	constructor(withArray:IntArray):this(withArray.size){
		for(i in withArray.indices){
			arr[i+n] = withArray[i]
		}

		updateAll()
	}

	private fun updateNode(i:Int){
		arr[i] = maxOf(arr[i shl 1] , arr[(i shl 1) + 1])
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
		var ret = void
		segDivision(l,r){i, _ ->
			ret = maxOf(ret,arr[i])
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
}
inline fun simpleMaxTree.segDivisonOrdered(l:Int, r:Int, act:(index:Int)->Unit){
	var left = l + n
	var right = r + n + 1
	var level = 0
	while(left < right){
		if(left and 1 != 0){
			act(left)
			left += 1
		}
		left = left shr 1
		right = right shr 1
		level ++
	}
	right = r + n + 1
	for(lev in level - 1 downTo 0){
		if((right shr lev) and 1 == 1){
			act((right shr lev) - 1 )
		}
	}
}
fun simpleMaxTree.intervalFirstAtleast(i:Int, v:Int):Pair<Int,Int>?{
	if(arr[i] < v){
		return null
	}
	var now = i
	while(now < n){
		if(arr[(now shl 1)] >= v){
			now = now shl 1
		}else{
			now = (now shl 1) + 1
		}
	}
	return Pair(now - n, arr[now])
}

fun simpleMaxTree.fullFirstAtleast(l:Int, r:Int, vatleast:Int):Pair<Int,Int>?{
	this.segDivisonOrdered(l,r){
			i ->
		val ret = intervalFirstAtleast(i,vatleast)
		if(ret != null){
			return ret
		}
	}
	return null
}
fun solve(L:IntArray, qs:List<subquery>, inverted:Boolean){
	val n = L.size
	val all = L.withIndex().sortedWith(compareBy<IndexedValue<Int>> {if(inverted) it.value else -it.value}.thenBy { -it.index })
	val before = L.leftAbove(inverted)

	val st = simpleMaxTree(IntArray(n){-1} )
	val queries = Array(n){ mutableListOf<subquery>() }
	for(q in qs){
		queries[q.l1].add(q)
	}

	for((i,v) in all){
		val previous = before[i]
		st.setValue(i,previous)
		for(q in queries[i]){
			val best = st.fullFirstAtleast(q.l2,n-1,q.l1 + 1)
			q.ans = best
		}
	}
}

typealias rmqType = Int
typealias rmqArrayType = IntArray

class rmq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = false
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
    }
}


class rmaxq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = true
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
    }
}

class subquery(val l1:Int, val l2:Int){
	var ans:Pair<Int,Int>? = null
}

inline fun BinarySearchFirstTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l
    var R = r+1
    while(L < R){
        val m = (L + R) shr 1
        if(m == r+1 || isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(L == r+1) null else L
}
inline fun BinarySearchLastTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l-1
    var R = r
    while(L < R){
        val m = ((L + R) shr 1) + 1
        if(m == l-1 || isTrue(m)){
            L = m
        }else{
            R = m - 1
        }
    }
    return if(L == l-1) null else L
}


inline fun BinarySearchExact(value:Int,l:Int,r:Int,find:(Int)->Int):Int?{
    //find shoudl be increasing
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(value <= find(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(find(L) == value){ L}else{null}
}


class query(val l:Int, val r:Int){
	var ans:IntArray? = null
}
fun IntArray.findnext(left:Boolean,above:Boolean,strict:Boolean):IntArray{
	val S = ArrayDeque<Pair<Int,Int>>()
	val ret = IntArray(this.size)
	val n = this.size
	val base = if(left) -1 else n
	for(suggesti in this.indices){
		val i = if(left) suggesti else n-1-suggesti
		val v = this[i]
		while(S.isNotEmpty()){
			val first = S.last()
			val delete =
				if(v == first.second){
					strict
				}else{ above xor (v < first.second)}
			if(delete){
				S.removeLast()
			}else{
				break
			}
		}
		val last = S.lastOrNull()?.first ?: base
		ret[i] = last
		S.add(Pair(i,v))
	}
	return ret
}

inline fun<T> List<T>.queuesweep(crossinline left:(T)->Int, right:(T) ->Int):MutableList<T>{
	val prepare = this.sortedBy { left(it) }
	val stack = mutableListOf<T>()
	for(c in prepare){
		while(stack.isNotEmpty() && right(c) <= right(stack.last())){
			stack.removeLast()
		}
		if(stack.isEmpty() || left(c) > left(stack.last())){
			stack.add(c)
		}
	}
	return stack
}
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
fun main(){
    solve.cases{
		val n = getint
		val q = getint
		val L = getline(n)


		val leftabove = L.findnext(true,true,true)
		val rightabove = L.findnext(false,true, true)
		val leftbelow = L.findnext(true,false,true)
		val rightbelow = L.findnext(false,false,true)


		val attempt = Array<Pair<subquery, subquery>?> (n){null}
		for(i in 0 until n){
			val fr = rightabove[i]
			val fd = rightbelow[i]
			if(fr !in 0 until n || fd !in 0 until n){
				continue
			}
			attempt[i] = Pair(subquery(i,fd), subquery(i,fr))
		}

		val q1 = mutableListOf<subquery>()
		val q2 = mutableListOf<subquery>()
		for((a,b) in attempt.filterNotNull()){
			q1.add(a)
			q2.add(b)
		}
		solve(L,q1,false)
		solve(L,q2,true)

		val ret = mutableListOf<IntArray>()
		for(i in 0 until n){
			if(attempt[i] == null) continue
			val (a,b) = attempt[i] !!
			if(a.ans == null && b.ans == null) continue
			val left = a.ans?.first ?: plarge
			val right = b.ans?.first ?: plarge
			if(left < right){
				ret.add(intArrayOf(i,a.ans!!.first, a.ans!!.second, rightbelow[i]).sortedArray())
			}else{
				ret.add(intArrayOf(i,b.ans!!.first, b.ans!!.second, rightabove[i]).sortedArray())
			}
		}


		val realret = mutableListOf<IntArray>()
		for(c in ret){
			while(realret.isNotEmpty() && c.last() <= realret.last().last()){
				realret.removeLast()
			}
			realret.add(c)
		}
		val fourhow = TreeMap<Int,IntArray>()
		for(c in realret){
			fourhow[c[0]] = c
		}

		val threeall = mutableListOf<IntArray>()
		val threehow = TreeMap<Int,IntArray>()
		for(i in 0 until n){
			if(leftbelow[i] in 0 until n && rightbelow[i] in 0 until n){
				threeall.add(intArrayOf(leftbelow[i],i, rightbelow[i]))
			}
			if(leftabove[i] in 0 until n  && rightabove[i] in 0 until n){
				threeall.add(intArrayOf(leftabove[i], i, rightabove[i]))
			}
		}
		val TT = threeall.queuesweep({it[0]},{it[2]})
		for(t in TT){
			threehow[t[0]] = t
		}


		val queries = List(q){query(getint - 1 , getint - 1 )}
		for(q in queries){
			val next = fourhow.ceilingEntry(q.l) ?: continue
			if(next.value.last() <= q.r){
				q.ans = next.value
			}
		}
		for(q in queries){
			if(q.ans != null) continue
			val next = threehow.ceilingEntry(q.l) ?: continue
			if(next.value.last() <= q.r){
				q.ans = next.value
			}
		}
		for(q in queries){
			if(q.ans == null) {
				put(0)
			}else{
				put(q.ans!!.size)
				put(q.ans!!.map { it +1 }.conca())
			}
		}







    }
    done()
}
/*
does there exist lenght 4 non montone

2- 4
	1- 3
how to solve

cross and opposite sides

observe containment monontone

earlier of the two



4 0
2 1 4 3

4 1
1 2 2 1
1 4


30 27
698632656 525581861 577504542 296603772 998990943 682881766 954895689 281259836 501177498 256330408 76466544 702835982 616513496 248342985 523962020 40996762 511850624 770240476 118371399 223228156 684298386 413908009 791936146 358337607 806286367 436654632 51668240 860274173 306994125 637771786
13 22
16 28
4 8
3 5
10 16
23 27
25 27
19 24
13 28
11 25
2 5
17 26
11 18
7 19
5 8
2 4
15 27
13 24
8 20
28 30
12 15
26 29
18 27
3 11
7 22
10 23
10 29

 */