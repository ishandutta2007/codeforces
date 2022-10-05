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


class Point(val x: Int, val y: Int, val id:Int = 0 ) : Comparable<Point> {
    companion object{
        var origin:Point? = null
        // null: compare by x coordinate
        // any point: compare by 180 degrees cone, undefined at origin
    }
    override fun compareTo(other: Point):Int {
        val origin = origin
        if (origin == null) {
            return this.x.compareTo(other.x)
        } else {
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
//    fun reduced():Point{
//        val d = gcd(x,y)
//        return Point(x/d,y/d)
//    }
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
        val ori = (1L * (second.x - this.x) * (third.y - this.y)) - ((second.y - this.y) * (third.x - this.x))
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
}
class matrixReal(val n:Int, val m:Int) {
    companion object{
        fun identity(n:Int): matrixReal {
            val ret = matrixReal(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1.0
            }
            return ret
        }
        fun standardTriangle(n:Int): matrixReal {
            val ret = matrixReal(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1.0
            }
            for(i in 1 until n){
                ret.A[i-1][i] = 1.0
            }
            return ret
        }
    }
    val A = Array(n){DoubleArray(m)}

    infix operator fun times(other: matrixReal): matrixReal {
        kotlin.assert(m == other.n)
        val ret = matrixReal(n,other.m)
        for(i in 0 until n){
            for(k in 0 until m){
                for(j in 0 until other.m){
                    ret.A[i][j] += A[i][k] * other.A[k][j]
                }
            }
        }
        return ret
    }
    fun print(){
        for(i in 0 until n){
            println(A[i].joinToString(" "))
        }
        println()
    }
    operator fun get(i:Int):DoubleArray{
        return A[i]
    }
}
typealias genericMatrix = matrixReal
class quickPower(val m: genericMatrix){
    companion object{
        const val final = 15
    }
    val allm = mutableListOf<genericMatrix>(m)
    init{
        kotlin.assert(m.n == m.m)
        for(i in 1..final){
            allm.add(allm.last().times(allm.last()))
        }
    }
    fun getMatrix(e:Int): genericMatrix {
        var ret = genericMatrix.identity(m.n)
        for(i in 0 until final){
            if(e and (1 shl i) != 0){
                ret = ret * allm[i]
            }
        }
        return ret
    }
    fun matrixVector(e:Int, other: genericMatrix): genericMatrix {
        kotlin.assert(m.m == other.n)
        var ret = other
        for(i in 0 until final){
            if(e and ( 1 shl i)!= 0){
                ret = allm[i] * ret
            }
        }
        return ret
    }
    fun rowVectorMatrix(e:Int, left:genericMatrix):genericMatrix{
        kotlin.assert(m.n == left.m)
        var ret = left
        for(i in 0 until final){
            if(e and ( 1 shl i)!= 0){
                ret = ret * allm[i]
            }
        }
        return ret
    }
}

const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val n = getint()
        val pts = mutableListOf<Point>()
        repeat(n){
            pts.add(Point(getint(), getint(),it))
        }
        val linesthrough = IntArray(n)
        for(p in pts){
            p.linesThrough(pts){
                linesthrough[p.id] ++
            }
        }
        val M = matrixReal(n,n)
        for(p in pts){
            p.linesThrough(pts){
                val each = 1.0 / (linesthrough[p.id].toDouble()) / (1 + it.size.toDouble())
                for(c in it){
                    M[c.id][p.id] += each
                }
                M[p.id][p.id] += each
            }
        }
        val power = quickPower(M)
        val q = getint()
        val listOfVectors = mutableSetOf<List<Int>>()
        for(p in pts){
            p.linesThrough(pts){
                val s = (listOf(p.id) + it.map{it.id}).sorted()
                listOfVectors.add(s)
//                val ret = matrixReal(n,1)
//                val div = 1.0 / (it.size +1).toDouble()
//                for(a in it){
//                    ret[a.id][0] = div
//                }
//                ret[p.id][0] = div
//                listOfVectors.add(ret)
            }
        }
        repeat(q){
            val t = getint() - 1
            val m = getint() - 1
            val ask = matrixReal(1,n)
            ask[0][t] = 1.0
            val MT = power.rowVectorMatrix(m,ask)

            var max = 0.0
            for(it in listOfVectors){
//            put(listOfVectors.maxOf { (MT * it )[0][0]})
//            for(p in pts){
//                p.linesThrough(pts){

//                    val div = (it.size + 1).toDouble()
//                    val total = (MT[0][p.id] + it.sumOf{MT[0][it.id]}).toDouble() / div
                    max = maxOf(it.sumOf{MT[0][it]} / (it.size.toDouble()), max)
                }
//            }
            put(max)
//            put(max)
        }
    }
    done()
}
const val singleCase = true

/*
extra temp field, remember to just give default
wrong condition: >=1 , wrong
wrong stupid calculation at the end
5
0 0
1 3
2 2
3 1
4 4
1
3 2
 */