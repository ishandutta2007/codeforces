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
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
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
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()

const val singleCase = true
const val withBruteForce = false
const val randCount = 100
data class event(val modx:Int, val mody:Int, val values:Long,val rboard:Boolean)
fun main(){
    solve.cases{
        val n = getint()
        val m = getint()
        val k = getint()

        val rightboard = Array(n){LongArray(m)}
        val downboard = Array(n){LongArray(m)}
        val baseboard = Array(n){LongArray(m)}
        val DP = Array(2){Array(n){LongArray(m){1000000000000000000} }}
        //0 : last move is x , 1: last move is y
        val events = Array(n){Array(m){ mutableListOf<event>()} }

        repeat(k){
            val x = getint()
            val y = getint()
            val d = getint()
            val t = getint()
            val e = getint().toLong()

            val a1 = (x+y >= t) && (x + y -t) % 4 == 0
            val a2 = (x+y >= t) &&  (x +y -t ) % 4 == 1
            val a3 = (x+y+d  >= t) && (x+d +y -t) % 4 == 2
            val a4 = (x+y+d  >= t) && (x+d+y -t)%4 == 3

//            e dei "$a1 $a2 $a3 $a4"

            if(a1){
                baseboard[x][y] += e
                if(a3){
                    rightboard[x+d][y] -= e
                    events[x][y].add(event(x+d,y,e,true))
                }
                if(a4){
                    downboard[x][y+d] -= e
                    events[x][y].add(event(x,y+d,e,false))
                }
            }
            if(a2){
                baseboard[x+d][y-d] += e
                if(a3){
                    downboard[x+d][y] -= e
                    events[x+d][y-d].add(event(x+d,y,e,false))
                }
            }
            if(a3) baseboard[x+d][y] += e
            if(a4) baseboard[x][y+d] += e
        }

        DP[0][0][0] = 0L
        DP[1][0][0] = 0L

        for(d in 0  until n+m-1){
            for(x in 0 until n){
                val y = d - x
                if(y >= m || y < 0) continue

                var cost = 0L
                val herey = DP[1][x][y]
                val herex = DP[0][x][y]
                for(xmove in 1 until n){
                    if(x + xmove >= n) break
                    cost += baseboard[x + xmove][y]
                    cost += rightboard[x + xmove][y]
                    val new = herey + cost
                    DP[0][x+xmove][y ] = minOf( DP[0][x+xmove][y ],new)
                }

                cost = 0L
                for(ymove in 1 until m){
                    if(y + ymove >= m) break
                    cost += baseboard[x][y+ymove]
                    cost += downboard[x][y+ymove]
                    val new = herex + cost
                    DP[1][x][y+ymove] = minOf(DP[1][x][y+ymove],new)
                }
                for(e in events[x][y]){
                    if(e.rboard){
                        rightboard[e.modx][e.mody] += e.values
                    }else{
                        downboard[e.modx][e.mody] += e.values
                    }
                }

            }
        }
        put(minOf(DP[0].last().last(), DP[1].last().last()))
    }
    done()
}

/*
do not, ever , exchange x and y indieces

a single right board flip
incorrect register

 */