// 2022-05-28, Sat, 17:46
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.Comparator
import kotlin.collections.ArrayList
import kotlin.math.absoluteValue
import kotlin.system.measureTimeMillis
import kotlin.math.sqrt

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
object Reader{
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
            put("Custom test enabled")
            println("Custom test enabled")
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
fun put(aa:Any){ Reader.OUT.println(aa)}
fun done(){ Reader.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){Reader.fakein.append(aa.toString())}
    else{Reader.fakein.append(aa.toString())}
    Reader.fakein.append("\n")
}

val getintfast:Int get() = Reader.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
var dmark = -1
infix fun Any.dei(a:Any){
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
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
val just = " "
fun crash(){
    throw Exception("Bad programme")}
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Not usual primes!")
        }
        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                Reader.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                Reader.rerouteInput()
            }
            onecase()
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
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}


class Point(val x: Int, val y: Int) : Comparable<Point> {
    val dist = sqrt(x.toDouble() * x.toDouble() + y.toDouble() * y.toDouble())
    companion object{
        const val mode:Int = 0
        //0: Compare by x coordinate then y
        // 1 : half circle , through origin
        //2: By vecotr, (0,1) is the largest, then clockwise sorting
        //3: By vector, full circle , from the given point
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
        }else if(mode ==2){
            if(this.sector != other.sector){
                return (this.sector.compareTo(other.sector))
            }
            return (1L * x * other.y - 1L * y * other.x).compareTo(0L)
        }else{
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
            if(f1 != f2){
                return if(f1){
                    -1
                }else{
                    1
                }
            }
            val ret = (1L * x1 * y2 - 1L * x2 * y1).compareTo(0)
            return ret
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
        val d = gcd(x,y).absoluteValue
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
        return (1L * (from.x - this.x) * (to.y - this.y)) > (1L * (from.y - this.y) * (to.x - this.x))
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
        result = (37 * result + y)
        return result
    }


    // 0 for positeve y axis, 1 for rhs, 2 for down , 3 for lhs
    val sector:Int get() =
        if(this.x == 0){
            if(this.y > 0) 0 else 2
        }else{
            if(x > 0) 1 else 3
        }


}
//class OrientedPoint(x:Int, y:Int): Point(x,y) {
//    fun at(){
//        val c = this + this
//    }
//
//}

//}
//class orientation(x:Int, y:Int):Comparable<orientation>{
//    companion object{
//        var center:
//    }
//    val x:Int
//    val y:Int
//     init{
//         if(x < 0){
//             this.x = -x
//             this.y = -y
//         }else if(x > 0){
//             this.x = x
//             this.y = y
//         }else{
//             this.x = 0
//             this.y = y.absoluteValue
//         }
//     }
//    override fun compareTo(other: orientation): Int {
//        // smallest: 12 oclock, then 1 oclock then.... 6 oclock
//        return (1L * x * other.y - 1L * other.x * y).compareTo(0)
//    }
//
//    override fun toString(): String {
//        return "o($x,$y)"
//    }
//    // must have  >= 0
//
//}

tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val k = getint
        val all = MutableList(n){Point(getint, getint )}
        all.remove(Point(0,0))
        val groups = HashMap<Point,MutableList<Point>>(n)
        for(p in all){
            val np = p.reduced()
            if(groups[np] == null){
                groups[np] = ArrayList(1)
            }
            groups[np]!!.add(p)
        }
        for(g in groups.values){
            g.sortBy { it.dist }
        }
        fun solve():Double {
//            val have = k - if(withcentral) 1 else 0
            val options = mutableListOf<Double>()
            for(g in groups.values){
                val s = g.size
                var l = 0
                var r = s-1
                val block = mutableListOf<Double>()
                var topcount = 0
                var topsum = 0.0
                var bottomcount = 0
                var bottomsum = 0.0
                repeat(s){ took->
                    val top = (took < k / 2)
                    val new:Int

                    if(top){
                        new = r
                        r--
                    }else{
                        new = l
                        l++
                    }
                    val here = g[new].dist * (k-1 - 2 * topcount) - bottomsum * 2
                    block.add(here)
                    if(top){
                        topcount ++
                        topsum += g[new].dist
                    }else{
                        bottomcount ++
                        bottomsum += g[new].dist
                    }
                }
                assert(block.sortedDescending() == block)
//                just dei block
                options.addAll(block)
            }
            options.sortDescending()
            return maxOf(options.take(k-1).sum(), options.take(k).sum())
        }
        put(solve())




    }
    done()
}




/*
almost 35 minutes
just implementation


14 10
0 19
0 -17
0 17
0 15
-13 0
6 0
0 13
19 0
-19 0
0 0
-17 0
-6 0
0 -15
0 -13


5 4
0 0
0 2
0 4
0 7
0 9

 */