import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.collections.ArrayDeque
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


// convert all to 0 based


class Graph(val n:Int, val directed:Boolean){
    val E = Array<MutableList<Int>>(n) { mutableListOf() }
    val indices = 0 until n
//    val invE = Array<MutableList<Int>>(n) { mutableListOf() }

    fun add(a:Int,b:Int){
        E[a].add(b)
//        invE[b].add(a)
        if(!directed){
            E[b].add(a)
//            invE[a].add(b)
        }
    }
    inline fun NS(from:Int,act:(Int)->Unit){
        for(v in E[from]){
            act(v)
        }
    }
    inline fun everyEdge(act:(Int,Int)->Unit){
        for((i,v) in E.withIndex()){
            for(to in v){
                act(i,to)
            }
        }
    }

    inline fun BFS(reached:(Int,Int)->Unit){
        val root = 0
        val toDo = ArrayDeque<Int>()
        val explored = IntArray(n+1){-1} // also store parents
        toDo.add(root)
        explored[root] = -2

        while(toDo.size > 0){
            val x = toDo.removeFirst()
            reached(x,explored[x])
            NS(x){ a->
                if(explored[a] == -1){
                    explored[a] = x
                    toDo.addLast(a)
                }
            }
        }
    }
    val basic_active = true
    val basic_setup = if(basic_active) n else 0

    val parent = IntArray(basic_setup)
//    val depth = IntArray(basic_setup)
    val sizes = IntArray(basic_setup)
    val subs = List(basic_setup){mutableListOf<Int>()}
    fun setup(root:Int){
        if(!basic_active){
            println("Did not set basic setup ")
        }
        DFS_long(root,{ v ->
            sizes[v]++
            if(v != root) sizes[parent[v]] += sizes[v]
        }){
                from,to ->
            parent[to] = from
//            depth[to] = depth[from] + 1
            subs[from].add(to)
        }
    }
    inline fun DFS(root:Int,dfsOrder:(Int)->Unit){
        DFS_long(root,dfsOrder,{_,_->})
    }
    inline fun DFS_long(root:Int,dfsOrder:(Int)->Unit,long:(parent:Int,here:Int)->Unit){
        //Long: (from,to) i.e. (parent, child)
        var pointer = 0
        val toDo = IntArray(n+1)

        val explored = BooleanArray(n+1)
        val secondTime = BooleanArray(n+1)
        toDo[0] = root
        explored[root] = true

        while(pointer >= 0){
            val x = toDo[pointer]
            if(secondTime[x]){
                dfsOrder(x)
                pointer--
                continue
            }
            //move here for top down order
            secondTime[x] = true
            NS(x){ a->
                if(!explored[a]){
                    explored[a] = true
                    pointer++
                    long(x,a)
                    toDo[pointer] = a
                }
            }
        }
    }
    inline fun DFS_Long_Exhaust(dfsOrder:(Int)->Unit,newroot:(Int)->Unit = {},long:(p:Int,into:Int,root:Int)->Unit = {_,_,_ ->}){
        //Long: (from,to) i.e. (parent, child)
        var pointer:Int
        val toDo = IntArray(n)

        val explored = BooleanArray(n)
        val secondTime = BooleanArray(n)

        var exploredCount = 0
        var exploredPointer = 0

        while(exploredCount < n){
            while(explored[exploredPointer]){
                exploredPointer ++
            }
            val root = exploredPointer
            newroot(root)
            explored[root] = true
            exploredCount ++
            toDo[0] = root
            pointer = 0
            while(pointer >= 0){
                val x = toDo[pointer]
                if(secondTime[x]){
                    dfsOrder(x)
                    pointer--
                    continue
                }
                //move here for top down order
                secondTime[x] = true
                NS(x){ a->
                    if(!explored[a]){
                        explored[a] = true
                        exploredCount ++
                        pointer++
                        long(x,a,root)
                        toDo[pointer] = a
                    }
                }
            }
        }
    }


}
class PointL(val x: Long, val y: Long) : Comparable<PointL> {

    override fun compareTo(other: PointL) = this.x.compareTo(other.x)

    override fun toString() = "($x, $y)"
    operator fun plus(other: PointL): PointL {
        return PointL(this.x + other.x, this.y + other.y)
    }

    operator fun minus(other: PointL): PointL {
        return PointL(this.x - other.x, this.y - other.y)
    }
    fun clockwise():PointL{
        return PointL(this.y, -this.x)
    }
    fun antiClockwise():PointL{
        return PointL(-this.y,this.x)
    }
    //    fun reduced():PointL{
//        val d = gcd(x,y)
//        return PointL(x/d,y/d)
//    }
    infix fun dot(other: PointL):Long{
        return (x * other.x + y * other.y)
    }
    infix fun cross(other:PointL):Long{
        return (x * other.y - other.x * y)
    }
}
inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
        val m = ((L + R) shr 1) + 1
        if(isTrue(m)){ L = m }else{ R = m - 1 }
    }
    return if(isTrue(L)){ L }else{ null }
}

internal class CHT_full() {
    companion object{
        const val type:Int = -1
        var query:Boolean = false
    }
    var hull:TreeSet<Line> = TreeSet()

    fun add(m: Long, b: Long) {
        add(Line(m, b))
    }

    fun add(a: Line) {
        val LR = arrayOf(hull.lower(a), hull.ceiling(a))
        for (i in 0..1) if (LR[i] != null && LR[i].m == a.m) {
            if (type == 1 && LR[i].b >= a.b) return
            if (type == -1 && LR[i].b <= a.b) return
            remove(LR[i])
        }
        hull.add(a)
        var L = hull.lower(a)
        var R = hull.higher(a)
        if (L != null && R != null && a.inter(R) <= R.left) {
            hull.remove(a)
            return
        }
        var LL = if (L != null) hull.lower(L) else null
        var RR = if (R != null) hull.higher(R) else null
        if (L != null) a.left = a.inter(L)
        if (R != null) R.left = a.inter(R)
        while (LL != null && L.left >= a.inter(LL)) {
            remove(L)
            a.left = a.inter(LL.also { L = it })
            LL = hull.lower(L)
        }
        while (RR != null && R.inter(RR) <= a.inter(RR)) {
            remove(R)
            RR.left = a.inter(RR.also { R = it })
            RR = hull.higher(R)
        }
    }

    fun query(x: Long):Long? {
        val temp = Line(0, 0, 0)
        temp.left = x.toDouble()
        query = true
        val ans = hull.floor(temp)?.eval(x)
        query = false
        return ans
    }

    fun addAll(other:CHT_full){
        for(l in other.hull){
            add(l)
        }
    }

    private fun remove(x: Line) {
        hull.remove(x)
    }

    fun size(): Int {
        return hull.size
    }


}
internal class Line:Comparable<Line> {
    var m: Long
    var b: Long
    var left = Long.MIN_VALUE.toDouble()

    constructor(mm: Long, x: Long, y: Long) {
        m = mm
        b = -m * x + y
    }

    constructor(mm: Long, bb: Long) {
        m = mm
        b = bb
    }

    fun eval(x: Long): Long {
        return m * x + b
    }

    fun inter(x: Line): Double {
        return (x.b - b).toDouble() / (m - x.m).toDouble()
    }

    override fun compareTo(other: Line): Int {
        if(!CHT_full.query){
            return CHT_full.type * this.m.compareTo(other.m)
        }
        if(this.left == other.left){
            return this.m.compareTo(other.m)
        }
        return this.left.compareTo(other.left)

    }
}

class weak_convexhull_trick {
    val hull = mutableListOf<PointL>()
    val vecs = mutableListOf<PointL>()

    /*
    can add lines of form of y = kx + b
    ask (x) : return minimum of kx + b , where (k,b) are taken over the added lines
    lines must be added in order of increasing k

    Literal porting from cp-algorithm
     */

    fun addLine(k:Long, b:Long){
        //added monotone increasing in k
        val np = PointL(k,b)
        while(vecs.isNotEmpty() && vecs.last().dot(np - hull.last()) < 0){
            hull.removeLast()
            vecs.removeLast()
        }
        if(hull.isNotEmpty()){
            vecs.add((np - hull.last()).antiClockwise())
        }
        hull.add(np)
    }
    fun ask(a:Long): Long {
        val q = PointL(a,1)
        val ret = if(vecs.isEmpty()) -1 else {BinarySearchLastTrue(0,vecs.lastIndex){
            vecs[it].cross(q) > 0
        } ?: -1}
        return q.dot(hull[ret + 1 ])
    }

}

const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.tc {
        val n = 500000
        share("$n")
        for(i in 2..n){
            share("$i $n")
        }
    }
//    solve.usetc()
    solve.cases{
        val n = getint()
        val G = Graph(n,false)
        repeat(n-1){
            G.add(getint() - 1, getint() - 1)
        }
        if(n == 2){
            put(2)
            return@cases
        }
        val root = (0 until n).first{G.E[it].size > 1}
        G.setup(root)
        val DP = LongArray(n)
        var allmin = Long.MAX_VALUE
        G.DFS(root) { v->
            if(G.subs[v].size == 0){
                DP[v] = 1
                return@DFS
            }
            val sh = G.sizes[v]
            var dp_ret = Long.MAX_VALUE
            for(s in G.subs[v]){
                val new = (sh - G.sizes[s]).toLong()
                val newcost = DP[s] + (new) * (new)
                dp_ret = minOf(dp_ret, newcost)
            }
            DP[v] = dp_ret
            val subs = G.subs[v].sortedBy { G.sizes[it] }
            val X = (n).toLong()
            val k = subs.size
            val S = LongArray(k){G.sizes[subs[it]].toLong()}
            val C = LongArray(k){(S[it] - 2 * X) * S[it] + DP[subs[it]]}
            val M = LongArray(k){2 * S[it].toLong()}

            val CHT = CHT_full()

            for(i in 0 until k){
                if(i != 0){
                    val get = CHT.query(S[i])!!
                    val ans = X * X + get + C[i]
                    allmin = minOf(allmin, ans)
                }
                CHT.add(M[i],C[i])
//                CHT.addLine(M[i],C[i])
//                just dei "${M[i]} ${C[i]}"
            }
            val x = 0
        }
        put((n).toLong() * (n-1) - (allmin - n)/2)

    }
    done()
}
const val singleCase = true