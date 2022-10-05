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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
const val huge = 2_727_000_000_000_000_000L // used for seg tree things
val Char.code :Int get() = this.toInt() -  'a'.toInt()


const val withBruteForce = false
const val randCount = 100
fun main(){
    val a = mutableListOf<Int>(1,2,3,4,5,6,7,8,9)
//    fun nextOf(a:List<Int>,cap:Int){
//        val new = a.toMutableList()
//        for((i,v))
//    }


    solve.cases{
        // count (mod 11)
        // starting index ( first number)

//        val store = Array(11){ MutableList(11){Pair(0,0)} }
        val phraseStore = IntArray(121)
        for(s in 0 until 11){
            for(c in 0 until 11){
                val nexts = (s + c) % 11
                var nextc = 0
                for(cp in 0 until c){
                    nextc += (s + cp) % 11
                }
                nextc = nextc % 11
                phraseStore[s * 11 + c] = nexts * 11 + nextc
            }
        }
        val transitions = Array(121){Array(10){IntArray(11)} }
        for(cp in 0 until 121){
            val s = cp / 11
            val c = cp % 11
            for(d in 0 until 10){
                for(oldm in 0 until 11){

                    var newpos = (s +c) % 11
                    for(i in 0 until (11 + oldm - s) % 11){
                        newpos += (s + i) % 11
                    }
                    newpos += d
                    newpos %= 11
                    transitions[cp][d][oldm] = if(d < oldm % 11) newpos else -1
                }
            }
        }

        fun accepts(d:Int, oldm:Int, cp:Int):Int{
            return transitions[cp][d][oldm]
        }
//        fun good(a:Int){
//            val c = a.toString()
//            if(c[0] == '0'){
//                return false
//            }
//            if(!good(a-1))
//        }
        val S = intArrayOf(20,111,10)
        val nextS = intArrayOf(1,2,1)
        val str = getstr()
        val n = str.length
        val A = IntArray(n){str[it].toInt() - '0'.toInt()}

        val DP = Array(n){Array(3){IntArray(11) }}
        //accepted until digit i,

        for(i in n-1 downTo 0){
            val d = A[i]
            for(c in 0 until 3){
                val cp = S[c]
                for(oldmo in 0 until 11){
                    val newm = accepts(d,oldmo,cp) //1 5 20
                    val  got = if(newm == -1){
                        0
                    }else if(i != n-1){
                        DP[i+1][nextS[c]][newm] + 1
                    }else{
                        1
                    }
                    DP[i][c][oldmo] = got
                }
            }
        }

        var ret = 0L
        for(i in 0 until n){
            if(A[i] == 0){
                continue
            }
            if(i == n-1){
                ret ++
                continue
            }
            ret += (DP[i+1][0][A[i]] + 1)
        }
        put(ret)


//        var startState = 1 * 11 + 9
//        repeat(1000){
//            startState = phraseStore[startState]
//            just dei startState
//            just dei "${startState / 11} ${startState % 11}"
//        }
        //1010203040506070809

        /*
        1 2 3 4 5 6 7 8 9 10
        20 21 30 31 32 40
         */
    }
    done()
}
const val singleCase = true
/*
a simple -1 placement flip
problem: base or relative
it shoudl be consistent base
base or relative ... consistent
 */