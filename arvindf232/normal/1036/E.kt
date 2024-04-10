
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import javax.swing.text.Segment
import kotlin.math.abs
import kotlin.math.absoluteValue
import kotlin.math.roundToInt
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

tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a.absoluteValue
    return if (a % b == 0) abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
class Point(val x: Int, val y: Int) : Comparable<Point> {
    companion object{
        const val mode:Int = 0
        //0: Compare by x coordinate then y
        // 1 : half circle , through origin
        //2: By vecotr, (0,1) is the largest, then clockwise sorting
        var origin:Point? = null
        // null: compare by x coordinate
        // any point: compare by 180 degrees cone, undefined at origin
    }
    operator fun component1() = x
    operator fun component2() = y
    override fun compareTo(other: Point):Int {
        if (mode == 0) {
            if(this.x != other.x){
                return this.x.compareTo(other.x)
            }
            return this.y.compareTo(other.y)
        } else if(mode == 1){
            val origin = origin!!
            val x1 =  x - origin.x
            val x2 = other.x - origin.x
            val y1 = y - origin.y
            val y2 = other.y - origin.y
            if(x1 == 0 && y1 == 0){
                return -1
            }else if(x2 == 0 && y2 == 0){
                return 1
            }
            val f1 = (x1 < 0 || (x1 == 0 && y1 < 0))
            val f2 = (x2 < 0 || (x2 == 0 && y2 < 0))
            val ret = (1L * x1 * y2 - 1L * x2 * y1).compareTo(0)
            return if(f1 xor f2) -ret else ret
        }else{
            if(this.sector != other.sector){
                return (this.sector.compareTo(other.sector))
            }
            return (1L * x * other.y - 1L * y * other.x).compareTo(0L)
        }
    }

    override fun toString() = "($x, $y)"
    operator fun plus(other: Point): Point {
        return Point(this.x + other.x, this.y + other.y)
    }

    operator fun minus(other: Point): Point {
        return Point(this.x - other.x, this.y - other.y)
    }
    fun clockwise():Point{
        return Point(this.y, -this.x)
    }
    fun antiClockwise():Point{
        return Point(-this.y,this.x)
    }
    fun reduced():Point{
        val d = gcd(x,y)
        return Point(x/d,y/d)
    }
    infix fun dot(other: Point):Long{
        return (1L * x * other.x + 1L * y * other.y)
    }
    infix fun cross(other:Point):Long{
        return (1L * x * other.y - 1L * other.x * y)
    }
    fun makeCounterClockwise(from:Point, to:Point):Boolean{
        // in this order: this is the center: clock direction goes in from, to
        return (1L * (from.x - this.x) * (to.y - this.y)) > ((from.y - this.y) * (to.x - this.x))
    }
    fun makeClockwiseTurn(from:Point, to:Point):Boolean{
        return !makeCounterClockwise(from,to)
    }
    fun orientation(second:Point, third:Point):Int{
        val ori = (1L * (second.x - this.x) * (third.y - this.y)) - (1L * (second.y - this.y) * (third.x - this.x))
        return if(ori > 0L) 1 else if(ori < 0L) -1 else 0
    }
    fun sortPoints(pts:List<Point>): List<Point> {
        // Make sure they are in the same halfplanes
        // assume leftmost and top to Bottom
        return pts.sortedWith(Comparator { a, b -> if(makeCounterClockwise(a,b)) 1 else -1  })
    }
    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as Point

        if (x != other.x) return false
        if (y != other.y) return false

        return true
    }
    fun linesThrough(pts:List<Point>,act:(List<Point>)->Unit){
        // for each lines through it, output it , n log n
        origin = this
        var now = mutableListOf<Point>()
        val ps = pts.sorted()
        for (i in 1 until ps.size){
            val p = ps[i]
            if(now.isEmpty()){
                now.add(p)
            }else if(now.last().compareTo(p) == 0){
                now.add(p)
            }else{
                act(now)
                now.clear()
                now.add(p)
            }
        }
        if(now.isNotEmpty()){
            act(now)
        }
    }

    override fun hashCode(): Int {
        var result = x
        result = 31 * result + y
        return result
    }


    // 0 for positeve y axis, 1 for rhs, 2 for down , 3 for lhs
    val sector:Int get() =
        if(this.x == 0){
            if(this.y > 0) 0 else 2
        }else{
            if(x > 0) 1 else 3
        }

    val hash:Long get() = makepair(this.x, this.y)


}
data class doublePoint(val x:Double,val y:Double){

}
fun Point.asDouble() = doublePoint(this.x.toDouble(),this.y.toDouble())

class segment (val a:Point, val b:Point){
    fun containsPoint(c:Point):Boolean{
        return a.orientation(b,c) == 0 && containsPoint_rect(c)
    }

    fun containsPoint_rect(c:Point):Boolean{
        if (c.x <= Math.max(a.x, b.x) && c.x >= Math.min(a.x, b.x) &&
            c.y <= Math.max(a.y, b.y) && c.y >= Math.min(a.y, b.y))
            return true;

        return false;
    }
    fun intersect(other:segment): Boolean {
        val c = other.a
        val d = other.b

        val o1 = a.orientation(b,c)
        val o2 = a.orientation(b,d)
        val o3 = c.orientation(d,a)
        val o4 = c.orientation(d,b)

        if(o1 != o2 && o3 != o4) return true
        if(o1 == 0 && this.containsPoint_rect(c)) return true
        if( o2 == 0 && this.containsPoint_rect(d)) return true
        if(o3 == 0 && other.containsPoint_rect(a)) return true
        if(o4 == 0 && other.containsPoint_rect(b)) return true
        return false
    }

    fun intersectionPoint(other:segment): doublePoint? {
        if(!intersect(other)){
            return null
        }
        val p1 = this.a.asDouble()
        val q1 = this.b.asDouble()
        val p2 = other.a.asDouble()
        val q2 = other.b.asDouble()

        return if (p1.x === q1.x) {
            val m: Double = (q2.y - p2.y) * 1.0 / (q2.x - p2.x)
            val c: Double = q2.y - q2.x * m
            return doublePoint(p1.x, m * p1.x + c)
        } else if (p2.x === q2.x) {
            val m: Double = (q1.y - p1.y) * 1.0 / (q1.x - p1.x)
            val c: Double = q1.y - q1.x * m
            return doublePoint(p2.x, m * p2.x + c)
        } else {
            val m1: Double = (q1.y - p1.y) * 1.0 / (q1.x - p1.x)
            val c1: Double = q1.y - q1.x * m1
            val m2: Double = (q2.y - p2.y) * 1.0 / (q2.x - p2.x)
            val c2: Double = q2.y - q2.x * m2
            val finx = (c2 - c1) * 1.0 / (m1 - m2)
            val finy = finx * m1 + c1
            return doublePoint(finx, finy)
        }

    }
    fun intersectInteger(other:segment):Point?{
        val trythis = intersectionPoint(other) ?: return null
        val p = Point(trythis.x.roundToInt(), trythis.y.roundToInt())
        return if(containsPoint(p) && other.containsPoint(p)) p else null
    }
    fun integerPoints():Int{
        if(this.a == this.b){
            return 1
        }else {
            return gcd((this.a.x - this.b.x).absoluteValue, (this.a.y - this.b.y).absoluteValue) + 1
        }
    }
}
const val singleCase = true
fun main(){
    solve.cases{
		val n = getint
        val all = List(n){
            segment(Point(getint, getint),Point(getint,getint))
        }

        var ret = 0L
        for(s in all){
            ret += s.integerPoints()
        }

        val IP = mutableMapOf<Long,MutableSet<Int>>()
        for(i in all.indices){
            for(j in i+1 until all.size){
                val s1 = all[i]
                val s2 = all[j]
                val p = s1.intersectInteger(s2)
                if(p == null) continue
                if(IP[p.hash] == null) IP[p.hash] = mutableSetOf()
                IP[p.hash]!!.add(i)
                IP[p.hash]!!.add(j)
                ret --
            }
        }
        val extra = IntArray(1003){v ->
            if(v <= 2) 0
            else (v - (v * (v-1))/2 - 1)
        }
        for((i,v) in IP){
            ret -= extra[v.size]
        }
        put(ret)
    }
    done()
}




/*
2
454379 373644 -454379 -373644
-665078 -385892 665078 385892

 */