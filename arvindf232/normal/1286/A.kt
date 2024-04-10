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
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
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
    inline fun cases(a:solve.()->Unit){
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
            a()
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
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
val Char.code :Int get() = this.toInt() -  'a'.toInt()



const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val n = getint()
         val L = getline(n)
        val all = IntArray(n+1)
        for(a in L){
            if(a == 0 ) continue
            all[a] ++
        }
        val types = IntArray(2)
        for(i in 1..n){
            if(all[i] == 1) continue
            types[i %2 ] ++
        }
        var ret = 0
        val profits = Array(2){ mutableListOf<Pair<Int,Int>>() }
        for(i in 0 until n-1){
            if(L[i] != 0 && L[i+1] != 0){
                if(L[i] %2 != L[i+1] % 2){
                    ret ++
                }
            }
        }
        for(start0 in 0 until n){
            val last = if(start0 == 0) -1 else L[start0 -1]
            if(L[start0] == 0 && last != 0){
                val end = (start0 + 1 until n).firstOrNull { L[it] != 0 }
                val start = if(start0 == 0) null else start0 - 1
//                just dei Pair(start,end)
                if(start == null && end == null){
                    if(n == 1){
                        put(0)
                    }else{
                        put(1)
                    }

                    return@cases
                }else if(start != null && end != null){
                    if(L[start] % 2 != L[end] % 2){
                        ret ++
                    }else{
                        val need = end - start - 1
                        if(need > 0){
                            profits[L[start] %2].add(Pair(need,2))
                        }
                    }
                }else{
                    if(end != null){
                        profits[L[end] % 2].add(Pair(end,1))
                    }else{
                        profits[L[start!!] %2].add(Pair(n- 1-start,1))
                    }
                }
            }
        }
        for(i in 0 until 2){
            ret += profits[i].sumOf { it.second }
        }
        var last = Array(types[0] + 1){IntArray(types[1]+1){nlarge}}
        last[0][0] =0
        for(i in 0 until 2){
            for(need in profits[i]){
//                val new = Array(types[0] + 1){IntArray(types[1]+1){nlarge} }
                for(a in types[0] downTo 0){
                    for(b in types[1] downTo 0 ){
                        val newa = a + if(i == 0) need.first else 0
                        val newb = b + if(i == 1) need.first else 0
                        if(newa > types[0] || newb > types[1]) continue
//                        new[a][b] = maxOf(new[a][b], last[a][b])
                        last[newa][newb] = maxOf(last[newa][newb], last[a][b] + need.second )
                    }
                }
            }
        }
        val final = last.maxOfOrNull { it.maxOrNull()!! }!!
        ret -= final
        put(ret)
    }
    done()
}
const val singleCase = true
/*
no reversible
forgot to return DP
so stupid

forgot initial contributions

8
0 0 1 0 0 2 0 0

case of 1 !!!

1 and 2 processing!!!



DUMBIGN

second time I forget the second transitions !!!! in the board knapsack


100
0 15 61 36 45 40 76 56 86 60 42 0 19 11 0 94 0 0 65 32 35 27 54 18 72 4 99 30 95 10 9 81 79 0 0 13 2 66 0 62 77 58 100 50 87 17 41 6 70 78 82 0 89 0 96 0 0 0 51 33 68 55 21 1 24 91 7 0 69 8 0 85 0 0 0 71 28 49 84 48 20 5 14 63 59 73 0 57 52 3 46 31 34 97 0 67 80 23 53 25
Output
 */