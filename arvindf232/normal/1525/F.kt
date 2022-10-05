// 2022.06.23 at 20:50:52 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
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
class HopcroftKarp constructor(val n1: Int, val n2: Int, maxedges:Int) {
    var edges = 0
    var last: IntArray
    var prev: IntArray
    var head: IntArray
    var matching: IntArray
    var dist: IntArray
    var Q: IntArray
    var used: BooleanArray
    var vis: BooleanArray

    init {
        last = IntArray(n1+2)
        prev = IntArray(maxedges + 5)
        head = IntArray(maxedges + 5)
        matching = IntArray(n2+2)
        dist = IntArray(n1+2)
        Q = IntArray(n1+2)
        used = BooleanArray(n1+2)
        vis = BooleanArray(n1+2)
        Arrays.fill(last, -1)
    }

    fun addEdge(u: Int, v: Int) {
        head[edges] = v
        prev[edges] = last[u]
        last[u] = edges++
//        just dei "$u $v"
    }

    fun bfs() {
        Arrays.fill(dist, -1)
        var sizeQ = 0
        for (u in 0 until n1) {
            if (!used[u]) {
                Q[sizeQ++] = u
                dist[u] = 0
            }
        }
        var i = 0
        while(i < sizeQ){
            val u1 = Q[i]
            var e = last[u1]
            while (e >= 0) {
                val u2 = matching[head[e]]
                if (u2 >= 0 && dist[u2] < 0) {
                    dist[u2] = dist[u1] + 1
                    Q[sizeQ++] = u2
                }
                e = prev[e]
            }
            i ++
        }
    }

    fun dfs(u1: Int): Boolean {
        vis[u1] = true
        var e = last[u1]
        while (e >= 0) {
            val v = head[e]
            val u2 = matching[v]
            if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
                matching[v] = u1
                used[u1] = true
                return true
            }
            e = prev[e]
        }
        return false
    }

    fun maxMatching(): Int {
        Arrays.fill(used, false)
        Arrays.fill(matching, -1)
        var res = 0
        while (true) {
            bfs()
            Arrays.fill(vis, false)
            var f = 0
            for (u in 0 until n1) {
                if (!used[u] && dfs(u)) {
                    f++
                }
            }
            if (f == 0) {
                return res
            }
            res += f
        }
    }
}
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val k =getint
        val edges = mutableListOf<Pair<Int,Int>>()

        repeat(m){
            val a = getint - 1
             val b = getint - 1
            edges.add(Pair(a,b))
        }
        fun cantake(cin:BooleanArray, cout:BooleanArray):Int{
            val box = HopcroftKarp(n,n,m)
            for((a,b) in edges){
                if(cout[a] && cin[b]){
                    box.addEdge(a,b)
                }
            }
            val max = box.maxMatching()
            val ret = n - max
            return ret

        }

        var start = cantake(BooleanArray(n){true}, BooleanArray(n){true})
        start = minOf(start, k+1)
//        just dei cantake(BooleanArray(n), BooleanArray(n))


        var strategies = mutableListOf<Int>()
        val canout = BooleanArray(n){true}
        val canin = BooleanArray(n){true}
        first@for(v in start +1..k+1){
            for(attempt in 0 until n){
                for(isin in 0 until 2){
                    if(isin == 1){
                        if(!canin[attempt]){
                            continue
                        }
                        canin[attempt] = false
                    }else{
                        if(!canout[attempt]){
                            continue
                        }
                        canout[attempt] = false
                    }
                    if(cantake(canin, canout) >= v){
                        strategies.add(if(isin == 1) -(attempt + 1) else (attempt +1))
                        continue@first
                    }else{
                        if(isin == 1){
                            canin[attempt] = true
                        }else{
                            canout[attempt] = true
                        }
                    }
                }
            }
        }
        val requests = mutableListOf<Pair<Int,Int>>()
        repeat(k){
            val x = getint
            val y = getint
            requests.add(Pair(x,y))
        }
        val DP = Array(k+1){LongArray(k+2){nhuge} }
        val how = Array(k+1){IntArray(k+2){-1} }
        DP[0][start] = 0L
        for(phase in 0 until k){
            val (x,y) = requests[phase]
            for(left in 1..k+1){
                for(right in maxOf(left,phase + 2)..k+1){
                    val time = right - left
                    val bonus =  maxOf(0,x - time.toLong() * y )
                    if(DP[phase][left] + bonus > DP[phase+1][right]){
                        DP[phase+ 1][right ] = DP[phase][left] + bonus
                        how[phase+1][right] = time
                    }
                }
            }
        }
        var now = k+1
        val ret = IntArray(k)
        for(p in k downTo 1){
            if(now == start) break
            val right = now
            val left = right - how[p][right]
            val extra = right - left
            now = left

            ret[p-1] = extra
        }
        val realret = mint
        for(i in 0 until k){
            repeat(ret[i]){
                realret.add(strategies.removeFirst())
            }
            realret.add(0)
        }
        put(realret.size)
        put(realret.conca())




    }
    done()
}




/*
50 0 1
867058 408127

 */