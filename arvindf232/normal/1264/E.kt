// 2022-05-15, Sun, 17:37
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.system.measureTimeMillis
import kotlin.random.Random
import kotlin.random.nextInt

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
class fastmint (var array:IntArray){
    var pt = -1
    //iterate with 0..pt
    val lastIndex:Int get() = pt
    val size:Int get() = pt + 1
    constructor(initialCapacity:Int = 10):this(IntArray(initialCapacity)){

    }
    inline fun foreach(act:(Int)->Unit){
        for(i in 0..pt){
            act(array[i])
        }
    }
    inline fun withIndex(act:(i:Int, v:Int)->Unit){
        for(i in 0..pt){
            act(i,array[i])
        }
    }
    operator fun get(v:Int):Int{
        return array[v]
    }
    operator fun set(i:Int, v:Int){
        array[i] = v
    }
    fun add(v:Int){
        if(pt + 1 == array.size){
            array = array.copyOf(array.size * 2 )
        }
        pt ++
        array[pt] = v
    }
    fun addLast(v:Int) = add(v)
    fun removeLast():Int{
        pt--
        return array[pt+1]
    }
    fun clear(){
        pt = -1
    }
    override fun hashCode(): Int {
        return array.hashCode()
    }
    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as fastmint

        if (pt != other.pt) return false
        if (!array.contentEquals(other.array)) return false

        return true
    }
}
private typealias ei = Int
private typealias earr = IntArray
//NOT batle tested
class fastDeque(val l:Int, val r:Int) {
    val total = r - l + 1
    val st = earr(total)
    var startpointer = 0 - l
    var endpointer = startpointer - 1
    val size: Int get() = endpointer - startpointer + 1

    fun reset(){
        startpointer = -l
        endpointer = startpointer -1
    }

    fun isEmpty(): Boolean {
        return endpointer < startpointer
    }
    fun isNotEmpty():Boolean{
        return endpointer >= startpointer
    }
    fun first():ei{
        assert(isNotEmpty())
        return st[startpointer]
    }
    fun last():ei{
        assert(isNotEmpty())
        return st[endpointer]
    }
    fun addFirst(v:ei ){
        startpointer --
        st[startpointer]= v
    }
    fun addLast(v:ei){
        endpointer ++
        st[endpointer] = v
    }
    fun removeFirst(): Int {
        assert(isNotEmpty())
        val ret = st[startpointer]
        startpointer ++
        return ret
    }
    fun removeLast(): Int {
        assert(isNotEmpty())
        val ret = st[endpointer]
        endpointer --
        return ret
    }
    fun toArray():earr{
        return st.sliceArray(startpointer..endpointer)
    }
    fun toList():List<ei>{
        return st.slice(startpointer..endpointer)
    }

    inline fun forEach(act:(v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(st[i])
        }
    }
    inline fun withIndex(act:(i:Int,v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(i-startpointer,st[i])
        }
    }
    operator fun get(v:Int): Int {
        return st[startpointer + v]
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
class flowModelLinked {
    val s:Int = 0
    val t:Int = 1
    var n:Int = 2

    val next = fastmint()
    val head = fastmint()

    init{
        head.add(-1)
        head.add(-1)
    }

    val to = fastmint()
    val capacity = fastmint()
    val cost = fastmint()

    fun newvar():Int{
        head.add(-1)
        n ++
        return n - 1
    }
    fun newseries(n:Int):IntArray{
        return IntArray(n){newvar()}
    }

    fun add_path(from:Int, target:Int, capacity:Int, cost:Int){
        next.add(head[from])
        to.add(target)
        this.capacity.add(capacity)
        this.cost.add(cost)
        head[from] = next.lastIndex
    }
    fun add_real_edge(from: Int, to: Int, capacity: Int, cost: Int) {
        add_path(from,to,capacity,cost)
        add_path(to,from,0,-cost)
    }
    var dist:IntArray = IntArray(0)
    var pre:IntArray = IntArray(0)
    var incf:IntArray = IntArray(0)
    var vis:BooleanArray = BooleanArray(0)

    inline fun NSE(v:Int,act:(to:Int, flow:Int)-> Unit){
        var e = head[v]
        while(e != -1){
            if(e and 1 == 0){
                act(to[e],capacity[e or 1])
            }
            e = next[e]
        }
    }
    var Q:fastDeque = fastDeque(0,1)
    fun spfa(): Boolean {
        dist = IntArray(n){plarge}


        val q = Q
        q.reset()
        q.addLast(s)
        dist[s] = 0
        incf[s] = plarge
        incf[t] = 0
        while (q.isNotEmpty()) {
            val u = q.removeFirst()
            vis[u] = false
            var e = head[u]
            while(e != -1){
                val v = to[e]
                val cap = capacity[e]
                val cost = cost[e]
                if(cap == 0 || dist[v] <= dist[u] + cost){
                    e = next[e]
                    continue
                }
                dist[v] = dist[u] + cost
                incf[v] = minOf(cap, incf[u])
                pre[v] = e
                if (!vis[v]) {
                    q.addLast(v)
                    vis[v] = true
                }
            }
        }
        return incf[t] > 0
    }
    var maxflow = 0
    var mincost = 0L

    fun update(){
        maxflow += incf[t]
        var u = t
        while(u != s){
            capacity[pre[u]] -= incf[t]
            capacity[pre[u] xor 1] += incf[t]
            mincost += incf[t].toLong() * cost[pre[u]]
            u = to[pre[u] xor 1]
        }
    }
    fun flow(){
        Q = fastDeque(0,n * to.size)
        pre = IntArray(n)
        incf = IntArray(n)
        vis = BooleanArray(n)
        while(spfa()){
            update()
        }
    }

}

fun debug(){}
const val singleCase = true
fun main(){
    solve.tc {
        share("50 0")
    }
//    solve.usetc()
    solve.cases{
        val n = getint
        val m = getint
        val board = Array(n){BooleanArray(n){true}}

        val f = flowModelLinked()

        val vars = Array(n){IntArray(n){-1}}
        for(i in 0 until n) {
            for(j in i + 1 until n) {
                vars[i][j] = f.newvar()
                f.add_real_edge(f.s,vars[i][j],1,0)
            }
        }
        val results = IntArray(n){f.newvar()}


        for(i in 0 until m) {
            val x = getint - 1
            val y = getint - 1
            board[x][y] = true
            board[y][x] = false
        }

        var edges = 0
        for(i in 0 until n){
            for(j in i + 1 until n) {
                edges ++
                if(board[i][j]) {
                    f.add_real_edge(vars[i][j],results[j],1,0)
                }
                if(board[j][i]) {
                    f.add_real_edge(vars[i][j],results[i], 1,0)
                }
            }
        }
        for(i in 0 until n) {
            for(tier in 0 until n) {
                f.add_real_edge(results[i], f.t, 1,  tier )
            }
        }
        val best = f.flow()
//        just dei f.maxflow
//        just dei f.mincost
//        just dei best

        val ret = Array(n){BooleanArray(n)}
        for(i in 0 until n) {
            for(j in i + 1 until n) {
                val v = vars[i][j]
                f.NSE(v){
                    to,flow ->
                    if(flow != 0){
                        if(to == results[i]){
                            ret[j][i] = true
                        }
                        if(to == results[j]) {
                            ret[i][j] = true
                        }
                    }
                }
            }
        }
        for(i in 0 until n) {
            put(ret[i].map { if(it)'1' else '0' }.joinToString(""))

        }




    }
    done()
}




/*
don't know how large maximum is

find something, anything, DPable

number of equalities

    - elementary transformations

max differing
why died
    why died
    why died

 */