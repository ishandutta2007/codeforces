
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100


fun debug(){}
const val withBruteForce = false
const val singleCase = true

val Int.c3:Int get() = (this) * (this - 1 ) *(this -2)/ 6

fun IntArray.counts():Pair<Int,Int>{
    val one = this.sumOf{it.c3}
    var two = 0
    for(i in 0 until this.size - 2){
        two += (this[i] * this[i+1] * this[i+2])
    }
    return Pair(one,two)
}

fun figureOut(n:Int, arr:IntArray,v1:Int, v2:Int):IntArray? {
    //size n-1
    val ret = IntArray(n)
    ret[0] = v1
    ret[1] = v2
    //before all queries
    for(i in 0 until n-2){
        val last2 = ret.getOrElse(i-2){0}
        val last1 = ret.getOrElse(i-1){0}
        val next = ret[i+1] + 1
        val now = arr[i] - last2 * last1 - last1 * next
        if(next == 0) return null
        var new = (now/next)
        if(i+2 != n-1) new --
        ret[i+2] = new
        if(new < 0) return null
    }
    return ret
}


val fake = false
var base = intArrayOf(0,7,0,0,1,0,0,6,1)
//val start = base.copyOf()
fun query(i:Int):Pair<Int,Int>{
    println("+ ${i+1}")
    System.out.flush()
    if(fake){
        base[i]++
        return base.counts()
    }else{
        val a = getint
        val b = getint
        return Pair(a,b)
    }



}
fun answer(a:IntArray){
    put("! ${a.conca}")
}
fun hash(arr:IntArray):Pair<IntArray,IntArray>{
    val arr = arr.copyOf()
    val n = arr.size
    var pt = 0
    val r1 = IntArray(n+1)
    val r2 = IntArray(n+1)

    val (a,b) = arr.counts()
    r1[pt] = a
    r2[pt] = b
    val all = listOf(0) + (n-2 downTo 0).toList()
    for(s in all){
        pt++
        arr[s]++
        val (a,b) = arr.counts()
        r1[pt] = a
        r2[pt] = b
    }
    return Pair(r1,r2)
}


fun main(){
    val c3lookup = mutableMapOf<Int,Int>()
    for(i in 2..200){
        val value = ((i).c3 - (i-1).c3)
        c3lookup[value] =i
    }
    var i = 0
    solve.rand {
        i++
            base = IntArray(4){if(i and (1 shl it) != 0) 1 else 0}
    }
//    solve.userand()
    solve.cases{
//        just dei base
//        val n = base.size
        val n = if(fake) base.size else getint
        val answer = IntArray(n-1)

        val start1:Int
        val start2:Int

        if(fake){
            val a = base.counts()
            start1 = a.first
            start2 = a.second
        }else{
            start1 = getint
            start2 = getint
        }

//        val (start1,start2) = base.counts()
        var lasttriple = start1
        var last = start2

        val H1 = IntArray(n+1)
        val H2 = IntArray(n+1)
        H1[0] = start1
        H2[0] = start2
        var pt = 0

        pt ++
        val (a,b) = query(0)
        H1[pt] = a
        H2[pt] = b


        var root_1:Int? = null
        var root_2:Int? = null

        for(i in n-2 downTo 0){
            val (a,b) = query(i)
            pt ++
            H1[pt] = a
            H2[pt] = b
            answer[i] = b - last
            last = b

            if(i == 0){
                val dif = a - lasttriple
//                if(dif >= 1){
                    val res = c3lookup[dif]!! -1
                    root_1 = res
//                }
            }
            if(i == 1){
                val dif = a - lasttriple
                if(dif >= 1){
                    val res = c3lookup[dif]!! -1
                    root_2 = res
                }
            }
            lasttriple = a
        }
//        val (a,b) = query(0)
//        pt++
//        H1[pt] = a
//        H2[pt] = b
//        val root_1 = c3lookup[a-lasttriple]!! -2

        root_1!!
        if(root_2 != null){
            figureOut(n,answer,root_1,root_2)?.let{
                it[0]--
                answer(it)
                return@cases
            }
        }else{
            for(root in 0..1){
                val trythis = figureOut(n,answer,root_1,root)
                if(trythis == null) continue
                trythis[0] --

                val hashed = hash(trythis)
                if(hashed.first.contentEquals(H1) && hashed.second.contentEquals(H2) ){
                    answer(trythis)
                    return@cases
                }
            }
            crash()
        }






    }
    done()
}