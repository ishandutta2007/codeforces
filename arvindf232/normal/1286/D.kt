
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.sign
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
const val p = 998244353L
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


infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}

infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
//infix fun Int.modPlus(b:Int):Int{
//    val ans = this + b
//    return if(ans >= pI) ans - pI else ans
//}
infix fun Int.modMinus(b:Int):Int{
    val ans = this - b
    return if(ans < 0) ans + pI else ans
}
infix fun Int.modDivide(b:Int):Int{
    return this modM (b.inverse())
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}


fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
fun intPowEXP(x:Int,e:Long,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0L){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
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
fun min_rem(m:Int, r:Int, c:Int):Int {
    if(c < 1){
        return Int.MIN_VALUE
    }else if(r == 0){
        return 0
    }else{
        val step = m % r
        val mx = ((1L * c * r) /m ).toInt()
        val t = max_rem(r,step,mx)
        return r- t
    }
}
fun max_rem(m:Int, r:Int, c:Int):Int {
    if(r == 0|| c <= m/r){
        return r * c
    }else{
        val step =  m % r
        val mx = ((1L * (c+1) * r )/m).toInt()
        val t = min_rem(r,step,mx)
        return  m - t
    }
}
fun Int.reconstruct():String{
    val num = min_rem(pI,this, 10000)
    val denom = (this modDivide num).inverse()
    return "$num / $denom"
}

//make this int instead
class FACT{
    companion object {
        var store = IntArray(0)
        var invStore = IntArray(0)

        var slowStore:IntArray = IntArray(0)

        fun preCal(upto:Int){
            store = IntArray(upto+1)
            invStore = IntArray(upto + 1 )
            store[0] = 1
            invStore[0] = 1

            for(i in 1..upto) {
                store[i] = store[i-1] modM i
                invStore[i] = invStore[i-1] modM (i.inverse())
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM (n - i)
            }
            ret = ret modM (invStore[r])
            return ret
        }

    }
}
class fraction(val x:Int, val y:Int):Comparable<fraction>{
    override fun compareTo(other: fraction): Int {
        val left = 1L * this.x * other.y
        val right = 1L * this.y * other.x
        return left.compareTo(right)
    }
    companion object{
        fun checked(x:Int, y:Int):fraction?{
            if(y == 0 ) return null
            if(x == 0) return fraction(0,y)
            if(x.sign != y.sign) return null
            var x = x
            var y = y
            if(x.sign < 0){
                x = -x
                y = -y
            }
            return fraction(x,y)
        }
    }

    override fun toString():String {
        return "$x / $y"
    }
}
class tt(var a:Int, var b:Int, var c:Int ,var d:Int){
    fun invert():tt{
        return tt(d,c,b,a)
    }
    infix fun mutiply(other:tt):tt{
        //as matrix
        val aa = (this.a modM other.a) modPlus (this.b modM other.c)
        val bb = (this.a modM other.b) modPlus (this.b modM other.d)
        val cc = (this.c modM other.a) modPlus (this.d modM other.c)
        val dd = (this.c modM other.b) modPlus (this.d modM other.d)
        return tt(aa,bb,cc,dd)
    }
    infix fun compose(other:tt):tt{
        //as function
        val aa = (other.a modM this.a) modPlus (other.b modM this.c)
        val bb = (other.a modM this.b) modPlus (other.b modM this.d)
        val cc = (other.c modM this.a) modPlus (other.d modM this.c)
        val dd = (other.c modM this.b) modPlus (other.d modM this.d)
        return tt(aa,bb,cc,dd)
    }
    fun writtenBy(other:tt){
        a = other.a
        b = other.b
        c = other.c
        d = other.d
    }
    companion object{
        val identity:tt get() = tt(1,0,0,1)
    }
    fun copy():tt{
        return tt(a,b,c,d)
    }
    operator fun set(i:Int,v:Int){
        if(i == 0){
            a = v
        }else if(i == 1){
            b = v
        }else if(i == 2){
            c = v
        }else{
            d = v
        }
    }

    override fun toString():String {
        return "[${a.reconstruct()} ${b.reconstruct()}] [${c.reconstruct()} ${d.reconstruct()}]"
    }
}
val inv100 = (100).inverse()
class item(val x:Int, val v:Int, val p:Int ){
    val right = p modM inv100
    val left = 1 modMinus right
}
fun buildableSegTree.segDivisionOrdered(l:Int, r:Int, act:(index:Int)->Unit){
    var left = l + n
    var right = r + n + 1
    var level = 0
    val L = mutableListOf<Int>()
    val R = mutableListOf<Int>()
    while(left < right){
        if(left and 1 != 0){

            L.add(left)
            left += 1
        }
        if(right and 1 != 0){
            right -= 1
            R.add(right)
        }
        left = left shr 1
        right = right shr 1
        level ++
    }
    for(i in L){
        act(i)
    }
    for(i in R.asReversed()){
        act(i)
    }
}
class buildableSegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = Array<tt>(n * 2 + 1 ){tt.identity}

    constructor(withArray:List<tt>):this(withArray.size){
        for(i in withArray.indices){
            arr[i+n].writtenBy(withArray[i])
        }
        updateAll()
    }

    private fun updateNode(i:Int){
        arr[i].writtenBy(arr[i shl 1 ] compose arr[(i shl 1) + 1])
    }
    fun queryFunctional(l:Int,r:Int):tt {
        var ret = tt.identity
        segDivisionOrdered(l,r){i ->
            ret = ret compose arr[i]
        }
        return ret
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
    fun getroot():Int{
        val root = arr[1]
        return root.a modPlus root.c
    }

    operator fun get(i:Int):tt{
        return arr[n+i]
    }
    fun updateAtIndex(i:Int){
        updatePath(n+i)
    }
//    fun setValue(i:Int,value:Int){
//        arr[n+i] = value
//        updatePath(n+i)
//    }
    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex


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
/*
0 LL:
1 LR
2 RL
3 RR
 */
const val singleCase = true

fun calculateTime(left:item, right:item,type:Int):fraction?{
    val distance = right.x - left.x
    if(type == 1) return null
    val speed =
        if(type == 2){
            left.v + right.v
        }else if(type == 3){
            left.v - right.v
        }else if(type == 0){
            right.v - left.v
        }else{
            0
        }
    return fraction.checked(distance, speed)
}
data class event(val leftid:Int, val type:Int, val time:fraction){

}
fun buildMask(right:item):tt{
    return tt(right.left,right.left, right.right, right.right)
}
fun buildMaskType(right:item,v:Int):tt{
    if(v == 0){
        return tt(right.left,0,0,0)
    }else if(v == 1){
        return tt(0,0, right.right,0)
    }else if(v == 2){
        return tt(0,right.left,0,0)
    }else if(v == 3){
        return tt(0,0,0,right.right)
    }
    return tt.identity
}
fun main(){
    solve.cases{
        val n = getint
        val all = List(n){item(getint, getint, getint )}
        val events = mutableListOf<event>()
        for(i in 0 until n-1){
            val left = all[i]
            val right = all[i+1]
            for(p in 0..3){
                val trytime = calculateTime(left, right, p)
                if(trytime != null){
                    events.add(event(i,p,trytime))
                }
            }
        }
        events.sortBy { it.time }
        val arr = List(n){
            buildMask(all[it])
        }
        val st = buildableSegTree(arr)
        var total = 0
        for(e in events){
            val old = st[e.leftid+ 1].copy()
            st[e.leftid+ 1].writtenBy(buildMaskType(all[e.leftid + 1],e.type))
            st.updateAtIndex(e.leftid + 1)
            total = total modPlus (st.getroot() modM e.time.x modDivide e.time.y)


//            for(i in 0 until n){
//                just dei st[i]
//            }
//            just dei "$e   ${st.getroot().reconstruct()}"

            st[e.leftid+ 1].writtenBy(old)
            val newtype = if(e.type == 2) 1 else if(e.type == 1 ) 2 else e.type
            st[e.leftid +1][newtype] = 0
            st.updateAtIndex(e.leftid+ 1)
        }
        put(total)
//        put(total.reconstruct())

    }
    done()
}
/*
2
1 2 50
4 1 50

 */