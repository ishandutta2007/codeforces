import java.io.BufferedInputStream
import java.io.PrintWriter
import java.lang.Math.abs
import java.util.*
import kotlin.Comparator
import kotlin.math.absoluteValue
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
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
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

data class Point(val row: Int, val column: Int) : Comparable<Point> {

    override fun compareTo(other: Point) = this.row.compareTo(other.row)

    override fun toString() = "($row, $column)"
    operator fun plus(other: Point): Point {
        return Point(this.row + other.row, this.column + other.column)
    }

    operator fun minus(other: Point): Point {
        return Point(this.row - other.row, this.column - other.column)
    }
    fun clockwise():Point{
        return Point(this.column, -this.row)
    }
    fun antiClockwise():Point{
        return Point(-this.column,this.row)
    }
    infix fun dot(other: Point):Long{
        return (1L * row * other.row + 1L * column * other.column)
    }
    infix fun cross(other:Point):Long{
        return (1L * row * other.column - 1L * other.row * column)
    }
    fun makeCounterClockwise(from:Point, to:Point):Boolean{
        return (1L * (from.row - this.row) * (to.column - this.column)) > ((from.column - this.column) * (to.row - this.row))
    }
    fun makeClockwiseTurn(from:Point, to:Point):Boolean{
        return !makeCounterClockwise(from,to)
    }
    fun sortPoints(pts:List<Point>): List<Point> {
        // Make sure they are in the same halfplanes
        // assume leftmost and top to Bottom
        return pts.sortedWith(Comparator { a, b -> if(makeCounterClockwise(a,b)) 1 else -1  })
    }
}




const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.tc{
        share("""
           5 5 10 3
3 1
3 2
3 5
1 5
2 1
2 5
1 2
1 4
3 3
2 4
2 1 5

        """.trimIndent())
    }
    solve.rand {
        share("5 5 4 3")
        repeat(4){
            share(Random.nextInt(1,6))
            share(Random.nextInt(1,6))
        }

        share("1 3 5")
    }
//    solve.userand()
//    solve.usetc()
    solve.cases{
        val n = getint()
        val m = getint()
        val k = getint()
        val q = getint()
        val treasure = List(k){
            Point(getint() - 1,getint() -1 )
        }
        val safe = List(q){getint() - 1 }
        val safeTree = TreeSet<Int>(safe)
        val byColumn = List(n){ mutableListOf<Point>()}
        for(p in treasure){
            byColumn[p.row].add(p)
        }
        byColumn[0].add(Point(0,0))
        val useY  = byColumn.indices.filter{byColumn[it].isNotEmpty() || it == 0 }
        for(c in useY){
            val col = byColumn[c]
            col.sortBy { it.column }
        }
        val leftMost = IntArray(n)
        val rightMost = IntArray(n)
        val keypoints = List(n){ TreeSet<Int>()}

        fun addNearby(c:Int,p:Point){
            val t = safeTree.ceiling(p.column)
            t?.let{
                keypoints[c].add(it)
            }
            val t2 = safeTree.floor(p.column)
            t2?.let{
                keypoints[c].add(it)
            }
        }

        for(c in useY){
            val col = byColumn[c]
            leftMost[c] = col.first().column
            rightMost[c] = col.last().column
            addNearby(c,col.first())
            addNearby(c,col.last())
        }

        val DP = List(n){ mutableListOf<Long>()}

        for(x in keypoints[0]){
            DP[0].add(((rightMost[0] - 0).absoluteValue + if(useY.size != 1 )(rightMost[0] - x).absoluteValue else 0 ).toLong())
        }
        for(cs in useY.windowed(2)){
            val c0 = cs[0]
            val c1 = cs[1]

            val C0 = keypoints[c0]
            val C1 = keypoints[c1]

            repeat(C1.size){
                DP[c1].add(Long.MAX_VALUE)
            }

            for((i,x) in C0.withIndex()){
                for((j,y) in C1.withIndex()){
                    val base:Long = DP[c0][i] + (c1 - c0)
                    val extraCost1 = abs(rightMost[c1] - x) + abs(leftMost[c1] - rightMost[c1]) + if(c1 != useY.last()) abs(leftMost[c1] - y) else 0
                    val extraCost2 = abs(leftMost[c1] - x) + abs(leftMost[c1] - rightMost[c1]) + if(c1 != useY.last()) abs(rightMost[c1] - y) else 0
                    val total = base+ minOf(extraCost1,extraCost2)
                    DP[c1][j] = minOf(DP[c1][j],total )
                }
            }

        }
        val ans = DP[useY.last()].minOrNull()!!
        if(ans < 0) crash()
        put(DP[useY.last()].minOrNull()!!)
    }
    done()
}

/*

small misatkes:
    all naming: no pural

small mistakes 1:
    not last layer of DP, shoudl be DP[last useful column ]

 Major
     swapping keypoints with actual poitns on the column
    wrong lace to put the answer

Major
    cannot sort things and expects others do not change

Major
     failure to sort the array
     (and forgetting that they should be sorted)

Critical error:
    not every layer are run
        because of windowed 2 and first row special case


 Critical logic error;
    forget about the first row isn't to be deal with in normal case
    - probbaly better to haev no edge cases
    Edge cases reduction

 FIRST ROW ARGG

 somehow the reduction doesn't work
    why



 */