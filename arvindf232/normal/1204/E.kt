import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
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
        if (c == NC) c = char
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
            System.err.println("Not accepting inputs!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
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
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){1} else if(mode == solveMode.tc){1 } else randCount
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

const val p = 998244853L
const val pI = p.toInt()
infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
    return ((this * 1L * b) % p).toInt()
}
infix fun Int.modPlus(b:Int):Int{
    return (this + b).adjust()
}
infix fun Int.modMinus(b:Int):Int{
    return (this - b).adjust()
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}

fun Int.adjust():Int{
    if(this >= pI){
        return this  - pI
    }else if (this < 0){
        return this + pI
    }
    return this
}
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0){
            X = ((1L * X * X) % m).toInt()
            E /= 2
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}

fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E /= 2
        }else{
            Y = (X * Y) % m
            E -= 1
        }
    }
    return Y
}
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
fun Int.inverse():Int{
    return intPow(this,pI-2,pI)
}
class FACT{
    companion object {
        var store = mutableListOf<Int>()
        var invStore = mutableListOf<Int>()

        var slowStore:IntArray = IntArray(0)

        fun preCal(upto:Int){
            store = mutableListOf()
            invStore = mutableListOf()
            store.add(1)
            invStore.add(1)
            var previous = 1

            for(i in 1..upto) {
                previous = previous modM i
                store.add(previous)
                invStore.add(previous.inverse())
            }
        }
        operator fun get(n:Int):Int{
            return store[n]
        }
        operator fun get(n:Long):Int{
            return store[n.toInt()]
        }

        fun choose(n:Int,r:Int):Int{
            val a = FACT[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }
        fun precalSlow(a:Int){
            slowStore = IntArray(a+1)
            for(i in 1..a){
                slowStore[i] = i.inverse()
            }
        }


        fun slowChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM ((n - i).adjust())
            }
            for(i in 1..r){
                ret = ret modM (slowStore[i])
            }
            return ret
        }

    }
}


const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.tc{
        share("2 2")
    }
    solve.rand{
        share(Random.nextInt(1,10))
        share(Random.nextInt(1,10))
    }
//    solve.usetc()
//    solve.userand()
    FACT.preCal(4001)
    solve.cases{
        val n = getint()
        val m = getint()
        val z = 2000

        val DS = List(z+1){IntArray(z+1)}
        DS[0][0] = 1
        for(i in 0..z){
            for(j in 0..z){
                val here = i - j
                if(here > 0 && j < z){
                    DS[i][j+1] += DS[i][j]
                    DS[i][j+1] = DS[i][j+1].adjust()
                }
                if(i < z)
                DS[i+1][j] = (DS[i+1][j] + DS[i][j]).adjust()
            }
        }

        val DZ = List(n+1){IntArray(m+1)}
        DZ[0][0] = 1
        for(i in 0..n){
            for(j in 0..m){
                val here = i - j
                if(here > 1 && j < m){
                    DZ[i][j+1] += DZ[i][j]
                    DZ[i][j+1] = DZ[i][j+1].adjust()
                }
                if(i < n)
                DZ[i+1][j] = (DZ[i+1][j] + DZ[i][j]).adjust()
            }
        }



        var ret = 0
        for(firstMax in 1..n){
            for(conv in 0..minOf(n,m)){
                if(n-conv-firstMax >= 0 ){
                    val firstFactor = DZ[firstMax+conv][conv]
                    val secondFactor = DS[m-conv][n-conv-firstMax]
                    val v = (firstFactor) modM (secondFactor) modM (firstMax)
                    ret += v
                    ret = ret.adjust()

//                    just dei Triple(firstMax,conv,v)
                }
            }
        }
        put2(ret)

        brute {
            val DP = List(n+1){List(m+1){MutableList(n+1){0}} }
            DP[0][0][0] = 1
            for(i in 0..n){
                for(j in 0..m){
                    for(k in 0..n){

//                        just dei Triple(i,j,k)
                        val here = i - j
                        val p1 = here + 1
                        val newstate = maxOf(k, p1)
                        if(i + 1 <= n) {
                            DP[i + 1][j][newstate] += DP[i][j][k]
                            DP[i+1][j][newstate] = DP[i+1][j][newstate].adjust()
                        }


                        if(j + 1 <= m){
                            DP[i][j+1][k] += DP[i][j][k]
                            DP[i][j+1][k] = DP[i][j+1][k].adjust()
                        }

                    }
                }
            }
//            println(DP)
            val ans = DP[n][m].withIndex().sumOf { (i,v) -> i * v  }
            bruteAnswer(ans)
        }
    }
    done()
}

/*

mistake_: vaiable swap on the final state

    maybe don't define new variables that isn't used
    or define transient variable ( such as long names)

    failing the iteration bounds


    still many out of bounds even though I tried to eb clean

    so much cleaner if I get the recursion right
    outdated bounds

    2D indices and swaped buonds
 */