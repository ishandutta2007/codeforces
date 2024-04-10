
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.ln
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

class bitset (val all:LongArray){
	constructor():this(LongArray(110)){
	}
	companion object{
		const val n = 7005
		const val wordSize = 64
		const val wordMask = 63
		const val wordSizeShift = 6
		const val allfalse = 0L
		const val alltrue = (0L).inv()
		val allmask = LongArray(wordSize){1L shl it}
		val invertAllMask = LongArray(wordSize){(1L shl it).inv()}
	}
	val size:Int get() = all.sumOf { it.countOneBits() }
	fun Long.element(a:Int):Boolean{
		return (this and (1L shl a)!= 0L)
	}
	operator fun get(i:Int):Boolean{
		return all[i shr wordSizeShift].element(i and wordMask)
	}
	operator fun set(i:Int,v:Boolean){
		val j = i shr wordSizeShift
		if(v){
			all[j] = all[j] or (1L shl (i and wordMask))
		}else{
			all[j] = all[j] and (1L shl (i and wordMask)).inv()
		}
	}
	infix fun and(other:bitset):bitset{
		return (bitset(LongArray(this.all.size){all[it] and other.all[it]}))
	}
	infix fun or(other:bitset):bitset{
		return (bitset(LongArray(this.all.size){all[it] or other.all[it]}))
	}
	infix fun xor(other:bitset):bitset{
		return (bitset(LongArray(this.all.size){all[it] xor other.all[it]}))
	}
	fun copy():bitset{
		return bitset(all.copyOf())
	}

	override fun toString(): String {
		return (0 until n).map { if(this[it]) '1' else '0' }.joinToString("")
	}


	fun andAssign(other:bitset){
		for(i in all.indices){
			this.all[i] = this.all[i] and other.all[i]
		}
	}
	fun orAssign(other:bitset){
		for(i in all.indices){
			this.all[i] = this.all[i] or other.all[i]
		}
	}
	fun xorAssign(other:bitset){
		for(i in all.indices){
			this.all[i] = this.all[i] xor other.all[i]
		}
	}





}


object sieve{

    const val sieveMx = 7005
    val primeOf = IntArray(sieveMx + 1)
    var primeCounter = 0
    val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
    val primes = IntArray(primeUpperBound)
    var sieveCalculated = false
    val nextPrime = IntArray(sieveMx+1)
    val nextPrimePower = IntArray(sieveMx+1)
    val afterPrimePowerDivison = IntArray(sieveMx+1)
    var mobius = IntArray(0)

    var factors:List<MutableList<Int>> = mutableListOf()

    fun calculateSieveFast(){
        if(sieveCalculated){
            return
        }
        sieveCalculated = true
        for(i in 2..sieveMx){
            if(primeOf[i] == 0 ){
                primeOf[i] = i
                primes[primeCounter] = i
                primeCounter += 1
            }
            for(j in 0 until primeCounter){
                val p = primes[j]
                val pd = p * i
                if(p <= i && pd <= sieveMx){
                    primeOf[pd] = p
                }else{
                    break
                }
            }
        }
    }
    fun preparePrimePower(){
        nextPrime[1] = -1
        nextPrimePower[1] = -1
        afterPrimePowerDivison[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            val new = i / p
            nextPrime[i] = p
            if(nextPrime[new] == p){
                nextPrimePower[i] = nextPrimePower[new]
                afterPrimePowerDivison[i] = afterPrimePowerDivison[new]
            }else{
                afterPrimePowerDivison[i] = new
            }
            nextPrimePower[i] += 1
        }
    }
    fun prepareFactors(){
        // 700ms in 1M
        // shoudl not be used for 1M
        // 200ms codeforces for 200k
        factors = List(sieveMx + 1){ mutableListOf()}
        factors[1].add(1)

        for(i in 2..sieveMx){
            val p = nextPrime[i]
            val a = nextPrimePower[i]
            val old = afterPrimePowerDivison[i]

            var here = 1
            repeat(a+1){
                for(c in factors[old]){
                    factors[i].add(c * here )
                }
                here *= p
            }
//            factors[1].ad
//            factors[i].addAll(i.factors())
        }
    }
    fun calculateMobius(){
        assert(sieveCalculated)
        mobius = IntArray(sieveMx + 1)
        mobius[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            if(p == primeOf[i/p]){
                mobius[i] = 0
            }else{
                mobius[i] = -1 * mobius[i/p]
            }
        }
    }
}
inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
    var here = this
    while(here > 1){
        act(sieve.nextPrime[here], sieve.nextPrimePower[here])
        here = sieve.afterPrimePowerDivison[here]
    }
}
fun GS(start:Int,ratio:Int,count:Int) = sequence {
    var ret = 1
    for(i in 1
            ..count){
        ret *= ratio
        yield(ret)
    }
}
fun Int.factors():List<Int>{
    val ret = mutableListOf(1)
    this.eachPrimePower { p, e ->
        val s = ret.toList()
        for(pn in GS(p,p,e)){
            ret.addAll(s.map{it * pn})
        }
    }
    return ret
}
fun totient(a:Int):Int{
    var ret = a
    a.eachPrimePower{
            p, _ ->
        ret /= p
        ret *= (p-1)
    }
    return ret
}
fun Int.numOfDivisors():Int{
    var ret = 1
    this.eachPrimePower { _, e -> ret *= (e+1) }
    return ret
}
fun Int.factorLook():List<Int>{
    return sieve.factors[this]
}

fun factorSingleNumber(a:Long): MutableList<Pair<Long, Int>> {
    val ret = mutableListOf<Pair<Long,Int>>()
    var now = a
    for(pi in 0 until sieve.primeCounter){
        val p = sieve.primes[pi]
        var level = 0
        while(now % p == 0L){
            now /= p
            level ++
        }
        if(level > 0){
            ret.add(Pair(p.toLong(),level ))
        }
    }
    if(now > 1){
        ret.add(Pair(now, 1))
    }
    return ret
}
const val max = 7003
const val singleCase = true
fun main(){
	sieve.calculateSieveFast()
	sieve.calculateMobius()
	val emptySet = bitset()
	val downSet = List(max){bitset()}
	val upSet = List(max){bitset()}

	for(i in 1 until max){
		for(j in i until max step i){
			downSet[j][i] = true
			if(sieve.mobius[j/i] != 0)
			upSet[i][j] = true
		}
	}


	var ret = mutableListOf<Char>()
    solve.cases{
		val n = getint
		val q = getint
		val sets = Array(n+1){emptySet.copy()}
		repeat(q){
			val t = getint
			if(t == 1){
				val x = getint
				val v = getint
				sets[x] = downSet[v].copy()
			}else if(t == 2){
				val x = getint
				val y  = getint
				val z = getint
				val new = sets[y] xor sets[z]
				sets[x] = new
			}else if(t == 3){
				val (x,y,z) = getline(3)
				sets[x] = sets[y] and sets[z]
			}else{
				val (x,v) = getline(2)
				val ans = (sets[x] and upSet[v]).size
				ret.add(if(ans %2 == 1)'1' else '0')

//				ans dei sets[x]
			}
		}
		put(ret.joinToString(""))




    }
    done()
}