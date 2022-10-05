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

//fun calculateSur(max:Int, hasbitposition:Int){
//
//}
//fun calculateUnder(max:Int, hasbitposition:Int):Int {
//    var ret = 0
//    for(i in 0 until max){
//        if((max and (1 shl hasbitposition)) != 0){
//            ret ++
//        }
//    }
//    return ret
//}
fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}
fun fullVector(fromSur:Boolean,toSur:Boolean,atmost:Int,d:Int,hasbitposition:Int):Int {
    if(toSur){
        if(!fromSur){
            return 0
        }else if(d > atmost){
            return 0
        }else{
            return if(hasbitposition == 4){1 } else d.hasElement(hasbitposition).chi
        }
    }else{
        val effectiveD = if(fromSur) d else 16
        val max = minOf(atmost, effectiveD - 1 )
        var ret = 0
        for(i in 0..max){
            if(hasbitposition == 4 || i.hasElement(hasbitposition)){
                ret ++
            }
        }
        return ret
    }
}

fun solve(atmost:Int, upperbound:IntArray, hasbitposition:Int):Long{
    var DP = LongArray(2)
    DP[1] = 1
    val badbin = hasbitposition shr 2
    if(badbin > upperbound.lastIndex){
        return 0L
    }
    for(b in upperbound.indices){
        val up = upperbound[b]
        val bi = upperbound.lastIndex - b
        val hasbit = if(bi != badbin) 4 else (hasbitposition % 4)
        val newDP = LongArray(2)
        for(left in 0 until 2) {
            for(right in 0 until 2) {
                newDP[right] += DP[left] * storage[left][right][atmost][up][hasbit]
            }
        }
        DP = newDP
    }
    return DP.sum()
}
fun fullsolve(upperbound:IntArray):Long {
    var total = 0L
    for(i in 0 until 16){
        val first = solve(i, upperbound, i)
        val added = first - (if(i > 0) solve(i-1,upperbound,i) else 0)
        total += added
    }
    return total
}
fun String.tohex():IntArray {
    val ret = IntArray(this.length)
    for(i in 0 until this.length){
        val c = this[i]
        if(c.isDigit()){
            ret[i] = c.toInt() - '0'.toInt()
        }else if(c.isLetter()){
            ret[i] = c.toInt() - 'a'.toInt() + 10
        }
    }
    return ret
}
fun IntArray.decr():IntArray? {
    val a = indexOfLast { it != 0 }
    if(a == -1){
        return null
    }else{
        for(i in a+1 .. this.lastIndex){
            this[i] = 15
        }
        this[a] --
        return this
    }
}
fun brute(max:IntArray):Long{
    var now = IntArray(max.size)

    var ret = 0L
    var final = false
    while(true){
        if(now.contentEquals(max)){
            final = true
        }
//        just dei now
        val needbit = now.maxOrNull()!!
        if(now.getOrNull(max.lastIndex - (needbit/4))?.hasElement(needbit % 4) == true){
            ret ++
        }
        for(i in max.size - 1 downTo 0){
            if(now[i] == 15){
                now[i] = 0
            }else{
                now[i] ++
                break
            }
        }
        if(final){
            break
        }
    }
    return ret
}

val storage = Array(2){Array(2){Array(16){Array(16){IntArray(5)} } } }
fun main(){
    for(b1 in 0 until 2){
        for(b2 in 0 until 2){
            for(a in 0 until 16){
                for(x in 0 until 16){
                    for(z in 0 until 5){
                        storage[b1][b2][a][x][z] = fullVector(b1==1,b2==1,a,x,z)
                    }
                }
            }
        }
    }
    solve(2, intArrayOf(15),2)
//    solve.tc {
//        """0 15
//
//        """.trimIndent()
//    }
//    solve.usetc()

    solve.cases{
        val LS = getstr()
        val RS = getstr()
        val L = LS.tohex().decr()
        val R = RS.tohex()
//        "brute" dei brute(R)
        var ans = fullsolve(R)
        if(L != null){
            ans -= fullsolve(L)
        }
//        "try" dei fullsolve(R)
        put(ans)
    }
    done()
}
const val singleCase = false
/*
reversed ind
inversion fof by 1 ( reversed is lastindex - , not size - )
bin vs hasbitposition
decremennt error 
1
0 15
 */