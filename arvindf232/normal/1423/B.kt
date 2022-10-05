
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.random.Random
import kotlin.random.nextInt
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

class DinicEdge(var v1: Int, var v2: Int, var cap: Int, var flow: Int) {
    var rev: DinicEdge? = null
}

class Dinic(var n: Int) {
    // Queue for the top level BFS.
    var q:ArrayDeque<Int>

    // Stores the graph.
    var adj: Array<MutableList<DinicEdge>>

    // s = source, t = sink
    var s: Int
    var t: Int

    // For BFS.
    var blocked: BooleanArray
    var dist: IntArray

    // Just adds an edge and ALSO adds it going backwards.
    fun add(v1: Int, v2: Int, cap: Int, flow: Int) {
        val e = DinicEdge(v1, v2, cap, flow)
        val rev = DinicEdge(v2, v1, 0, 0)
        adj[v1].add(e.also { rev.rev = it })
        adj[v2].add(rev.also { e.rev = it })
    }

    // Runs other level BFS.
    fun bfs(): Boolean {

        // Set up BFS
        q.clear()
        Arrays.fill(dist, -1)
        dist[t] = 0
        q.add(t)

        // Go backwards from sink looking for source.
        // We just care to mark distances left to the sink.
        while (!q.isEmpty()) {
            val node = q.poll()
            if (node == s) return true
            for (e in adj[node]) {
                if (e.rev!!.cap > e.rev!!.flow && dist[e.v2] == -1) {
                    dist[e.v2] = dist[node] + 1
                    q.add(e.v2)
                }
            }
        }

        // Augmenting paths exist iff we made it back to the source.
        return dist[s] != -1
    }

    // Runs inner DFS in Dinic's, from node pos with a flow of min.
    fun dfs(pos: Int, min: Int): Int {

        // Made it to the sink, we're good, return this as our max flow for the augmenting path.
        if (pos == t) return min
        var flow = 0

        // Try each edge from here.
        for (e in adj[pos]) {
            var cur = 0

            // If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
            // can go this way.
            if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {

                // Recursively run dfs from here - limiting flow based on current and what's left on this edge.
                cur = dfs(e.v2, Math.min(min - flow, e.cap - e.flow))

                // Add the flow through this edge and subtract it from the reverse flow.
                e.flow += cur
                e.rev!!.flow = -e.flow

                // Add to the total flow.
                flow += cur
            }

            // No more can go through, we're good.
            if (flow == min) return flow
        }

        // mark if this node is now blocked.
        blocked[pos] = flow != min

        // This is the flow
        return flow
    }

    fun flow(): Int {
        clear()
        var ret = 0

        // Run a top level BFS.
        while (bfs()) {

            // Reset this.
            Arrays.fill(blocked, false)

            // Run multiple DFS's until there is no flow left to push through.
            ret += dfs(s, oo)
        }
        return ret
    }

    // Just resets flow through all edges to be 0.
    fun clear() {
        for (edges in adj) for (e in edges) e.flow = 0
    }

    companion object {
        const val oo = 1E9.toInt()
    }

    // Constructor.
    init {

        // s is the source, t is the sink, add these as last two nodes.
        s = n++
        t = n++

        // Everything else is empty.
        blocked = BooleanArray(n)
        dist = IntArray(n)
        q = ArrayDeque()
        adj= Array(n) { mutableListOf<DinicEdge>() }
    }
}

inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(isTrue(L)){
        L
    }else{
        if(L == r){
            null
        }else{
            L + 1
        }
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
const val singleCase = true
fun main(){
    solve.tc {
        share(10000)
        share(100000)
        repeat(100000){
            share("${Random.nextInt(10000) + 1} ${ 1 + Random.nextInt(10000)} ${Random.nextInt(100000)}")
        }
    }
//    solve.usetc()
    solve.cases{
        val n = getint()
        val m = getint()
        val edges = mutableListOf<Triple<Int,Int,Int>>()

        repeat(m){
            edges.add(Triple(getint() -1, getint() -1 , getint()) )
        }
        edges.sortBy { it.third }

        val ans = BinarySearchFirstTrue(0,m-1){i ->
            val d = edges[i].third
//            println("attempt $d ")
            val G = HopcroftKarp(n,n,100000)
            for(e in edges){
                if(e.third > d) break
                G.addEdge(e.first, e.second)
            }
//            val G = Dinic(2 * n)
//            for(e in edges){
//                if(e.third > d) break
//                G.add(e.first, e.second + n , 1,0)
//            }
//            for(i in 0 until n){
//                G.add(G.s, i, 1, 0)
//                G.add(i+n, G.t, 1,0)
//            }
            G.maxMatching() == n
        }
        put(if(ans != null) edges[ans].third else -1 )
    }
    done()
}



/*
4 9
1 3 1
4 3 8
2 1 3
4 2 5
3 1 3
2 4 9
1 2 7
1 1 10
1 4 9

 */