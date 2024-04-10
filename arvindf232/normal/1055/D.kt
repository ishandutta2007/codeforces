
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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


fun search(text: String, pattern: String):IntArray{
    val concat = "$pattern$$text"
    val l = concat.length
    val Z = IntArray(l)

    getZarr(concat, Z)

    return Z.copyOfRange(pattern.length + 1 , Z.size)
}

fun calculateZarray(str:String): IntArray {
    val ret = IntArray(str.length)

    getZarr(str,ret)
    return ret
}
// Fills Z array for given string str[]
private fun getZarr(str: String, Z: IntArray) {
    val n = str.length

    var L = 0
    var R = 0
    for (i in 1 until n) {

        if (i > R) {
            R = i
            L = R

            while (R < n && str[R - L] == str[R]) R++
            Z[i] = R - L
            R--
        } else {

            val k = i - L

            if (Z[k] < R - i + 1) Z[i] = Z[k] else {


                // else start from R and check manually
                L = i
                while (R < n && str[R - L] == str[R]) R++
                Z[i] = R - L
                R--
            }
        }
    }
}
fun String.contains(other:String): Int? {
    val search = "$other#$this"
    val A = calculateZarray(search)
    return ((other.length + 1 until search.length).firstOrNull { A[it] >= other.length })?.minus(other.length + 1)
}

const val singleCase = true
fun main(){
    val chars = (0 until 26).map{('a'.toInt() + it ).toChar()}
    solve.tc {
        val a = List(3000){chars.random() }.conca()
        val b = a.replaceRange(1500..1500,"b")
        share(3000)
            repeat(3000){
                share(a)
            }
            repeat(3000){
                share(b)
            }
    }
//    solve.usetc()
    solve.cases{
        val all = mutableListOf<String>()

        val from = mutableListOf<String>()
        val to = mutableListOf<String>()
        val cannotchange = mutableListOf<String>()

        val readn = getint
        repeat(2 * readn){
            all.add(getstr)
        }
        repeat(readn){
            val start = all[it]
            val end = all[it+readn]
            if(start == end){
                cannotchange.add(start)
            }else{
                from.add(start)
                to.add(end)
            }
        }
        val n = from.size
        val firstDif = IntArray(n)
        val lastDif = IntArray(n)

        var startString:String? = null
        var endString:String? = null
        for(i in 0 until n) {
            val from = from[i]
            val to = to[i]
            val a = from.indices.first { from[it] != to[it] }
            val b = from.indices.last { from[it] != to[it] }
            val needA = from.slice(a..b)
            val needB = to.slice(a..b)

            firstDif[i] = a
            lastDif[i] = b

            if(startString != null && (startString != needA || endString!! != needB)) {
                put("NO")
                return@cases
            }
            if(startString == null) {
                startString = needA
                endString = needB
            }
        }
        fun agree(i:Int,right:Boolean):Boolean {
            var schar:Char? = null
            var echar:Char? = null
            for(s in 0 until n){
                val newi = if(right){
                    lastDif[s] + i
                }else
                    firstDif[s] + i
                if(newi !in from[s].indices){
                    return false
                }
                val sc = from[s][newi]
                val ec = to[s][newi]
                if(schar != null && (sc != schar || ec != echar!!)){
                    return false
                }
                if(schar == null){
                    schar = sc
                    echar = ec
                }
            }
            return true
        }
        var lefteat = 0
        var righteat = 0
        while(agree(lefteat - 1,false)){
            lefteat--
        }
        while(agree(righteat +1, true)){
            righteat ++
        }
        val sp = firstDif[0] + lefteat
        val ep = lastDif[0] + righteat
        val retS = from[0].slice(sp..ep)
        val retT = to[0].slice(sp..ep)


        if((0 until n).any { from[it].contains(retS) != firstDif[it] + lefteat}){
            put("NO")
            return@cases
        }
        if(cannotchange.any { it.contains(retS) != null  }){
            put("NO")
            return@cases
        }
        put("YES")
        put(retS)
        put(retT)

    }
    done()
}




/*
 bad boolean relations < mostly legacy spaghettis>
 legacy spaghetti

 think about + or - overall
 */