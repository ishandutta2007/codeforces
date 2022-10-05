// 2022-04-17, Sun, 15:35
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

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

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
        if(withBruteForce){
            println("Brute force is active")
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
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
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



object hasher {
	const val m = 1000000007
	val base1 = 37
	val base2 = 43
	const val max = 1000001
	val ppower1 = IntArray(max+1)
	val ppower2= IntArray(max+1)
	val invp1 = IntArray(max+1)
	val invp2 = IntArray(max+1)

	infix fun Int.localM(other:Int):Int{
		return ((this.toLong() * other) %m).toInt()
	}
	private infix fun Int.localPlus(other:Int):Int{
		val ret = (this + other)
		if(ret >= m) return ret - m else return ret
	}
	private infix fun Int.localMinus(other:Int):Int{
		val ret = this - other
		if(ret < 0) return ret + m else return ret
	}

	init {
		ppower1[0] = 1
		ppower2[0] = 1
		for(i in 1..ppower1.lastIndex){
			ppower1[i] = ppower1[i-1] localM base1
			ppower2[i] = ppower2[i-1] localM base2
		}
		invp1[max] = intPow(ppower1[max],m-2,m)
		invp2[max] = intPow(ppower2[max],m-2,m)
		for(i in max - 1 downTo 0){
			invp1[i] = invp1[i+1] localM base1
			invp2[i] = invp2[i+1] localM base2
		}
	}
	fun Char.code(): Int {
		return this.toInt() - '0'.toInt() + 1
	}
	fun hash(a:String):Long{
		var ret1 = 0L
		var ret2 = 0L
		for(i in 0 until a.length){
			ret1 += (1L * ppower1[i] * a[i].code()) % m
			ret2 += (1L * ppower2[i] * a[i].code()) % m
			if(ret1 >= m) ret1 -= m
			if(ret2 >= m) ret2 -= m
		}
		return (ret1 shl 32) + ret2
	}
	fun prefixHash(a:String):LongArray{
		val ret = LongArray(a.length + 1 )
		var ret1 = 0L
		var ret2 = 0L
		for(i in 0 until a.length){
			ret1 += (1L * ppower1[i] * a[i].code()) % m
			ret2 += (1L * ppower2[i] * a[i].code()) % m
			if(ret1 >= m) ret1 -= m
			if(ret2 >= m) ret2 -= m
			ret[i+1] = (ret1 shl 32) + ret2
		}
		return ret
	}
	fun combineHash(a:Long, b:Long, alength:Int): Long {
		val a1 = (a shr 32).toInt()
		val a2 = a.toInt()
		val b1 = (b shr 32).toInt()
		val b2 = b.toInt()
		val ret1 = (a1 + (1L * b1 * ppower1[alength])) % m
		val ret2 = (a2 + (1L * b2 * ppower2[alength])) % m
		return (ret1 shl 32) + ret2
	}
	fun leftAppend(h:Long, len:Int, c:Char):Long{
		val a1 = h.first
		val a2 = h.second
		val code = c.code()
		return makepair((a1 localM base1) localPlus code,  (a2 localM base2) localPlus code)
	}
	fun rightAppend(h:Long, len:Int, c:Char):Long{
		val a1 = h.first
		val a2 = h.second
		val code = c.code()
		return makepair((code localM ppower1[len]) localPlus a1,  (code localM ppower2[len]) localPlus a2)
	}
	fun removeLeft(h:Long, len:Int, c:Char):Long{
		val a1 = h.first
		val a2 = h.second
		val code = c.code()
		return makepair(((a1 localMinus code) localM invp1[1]),  ((a2 localMinus code) localM invp2[1]))
	}
	fun removeRight(h:Long, len:Int, c:Char):Long{
		val a1 = h.first
		val a2 = h.second
		val code = c.code()
		return makepair(a1 localMinus (code localM ppower1[len-1]),  a2 localMinus (code localM ppower2[len-1]))
	}
	class hashQuery(val str:String){
		val arr:LongArray
		init{
			arr = prefixHash(str)
		}
		fun query(l:Int, r:Int):Long{
			val hh = arr[r+1]
			val h1 = hh.first
			val h2 = hh.second
			val ww = arr[l]
			val w1 = ww.first
			val w2 = ww.second

			var a1 = (h1 - w1)
			var a2 = (h2 -w2)
			if(a1 < 0) a1 += m
			if(a2 < 0) a2 += m
			a1 = a1 localM invp1[l]
			a2 = a2 localM invp2[l]
			return makepair(a1,a2)
		}
	}

}


private typealias ei = Int
private typealias earr = IntArray
//NOT batle tested
class fastDeque(val l:Int, val r:Int) {
    val total = r - l + 1
    val st = earr(total)
    var startpointer = 0 - l
    var endpointer = startpointer - 1
    val size: Int get() = endpointer - startpointer + 1

    fun isEmpty(): Boolean {
        return endpointer < startpointer
    }
    fun isNotEmpty():Boolean{
        return endpointer >= startpointer
    }
    fun first():ei{
        assert(isNotEmpty())
        return st[startpointer]
    }
    fun last():ei{
        assert(isNotEmpty())
        return st[endpointer]
    }
    fun addFirst(v:ei ){
        startpointer --
        st[startpointer]= v
    }
    fun addLast(v:ei){
        endpointer ++
        st[endpointer] = v
    }
    fun removeFirst(): Int {
        assert(isNotEmpty())
        val ret = st[startpointer]
        startpointer ++
        return ret
    }
    fun removeLast(): Int {
        assert(isNotEmpty())
        val ret = st[endpointer]
        endpointer --
        return ret
    }
    fun toArray():earr{
        return st.sliceArray(startpointer..endpointer)
    }
    fun toList():List<ei>{
        return st.slice(startpointer..endpointer)
    }

    inline fun forEach(act:(v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(st[i])
        }
    }
    inline fun withIndex(act:(i:Int,v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(i-startpointer,st[i])
        }
    }
	fun reset(){
		startpointer = -l
		endpointer = startpointer -1
	}
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}

fun debug(){}
const val withBruteForce = false
const val singleCase = false
fun main(){
//	TIME{
//		hasher.hash("")
//	}
//	solve.tc(){
//		share("""
//			11 10
//			11111111110
//		""".trimIndent())
//	}
//	solve.usetc()

	val allvalues = IntArray( 1 shl 20)
	val found = fastEmptyList(1 shl 20)
    solve.cases{
		val n = getint
		val k = getint
		val str = getstr

		val neg = CharArray(n){if(str[it] == '1') '0' else '1'}.joinToString("")
		val L = BooleanArray(n){str[it] == '0'}

		val cut = minOf(k, 20)
		val rest = k- cut

		val zerosCount = IntArray(n)
		for(i in 0 until n){
			val last = zerosCount.getOrNull(i - 1 ) ?: 0
			if(neg[i] == '0'){
				zerosCount[i] = last + 1
			}else{
				zerosCount[i] = 0
			}
		}

		fun clean(){
			found.forEach { v ->
				allvalues[v] --
			}
			found.reset()
		}
		for(i in 0..n){
			val r = i + cut
			if(r !in 0 .. n) continue
			val zcount = if(i == 0) 0 else zerosCount[i-1]
			if(zcount >= rest){
				var v = 0
				for(extra in 0 until cut){
					if(L[i + extra]){
						v += ( 1 shl (cut - 1 - extra))
					}
				}
				found.addLast(v)
				allvalues[v] ++
			}
		}
		for(final in 0 until ( 1 shl cut)){
			if(allvalues[final] > 0) continue
			val retstring = List(cut){if(final.has(cut - 1 -it)) '1' else '0'}.conca()
			val before  = List(rest){'0'}.conca()
			put("YES")
			put(before + retstring)
			clean()
			return@cases
		}
		put("NO")
		clean()
		return@cases



//		val HQ = hasher.hashQuery(neg)
//		val allhash = mutableSetOf<Long>()
//		for(l in 0 until n){
//			val r = l + k - 1
//			if(r >= n) {
//				continue
//			}
//			allhash.add(HQ.query(l,r))
//		}
//		val cut = minOf(k ,20 )
//		val rest = k - cut
//		val resthash = hasher.hash(List(rest){'0'}.conca())
//		for(m in 0 until (1 shl cut)) {
//			val st1 = CharArray(cut){if(m.has(cut - 1 -it))'1' else '0'}.conca
//			val hash1 = hasher.hash(st1)
//			val totalhash = hasher.combineHash(resthash, hash1,rest)
//			if(allhash.contains(totalhash)){
//				continue
//			}else{
//				val fullstring = List(rest){'0'}.conca() + st1
//				put("YES")
//				put(fullstring)
//				return@cases
//			}
//		}
//		put("NO")



    }
    done()
}
/*
10 3
0101110001

10 10
1111111111
 */