// 2022.09.02 at 16:01:08 BST
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.system.measureTimeMillis

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
infix fun Int.modMinus(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this modM (b.inverse()) }
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
// 3. convenience conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
}
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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
fun debug(){}


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
    fun getcut():BooleanArray{
        val incut = BooleanArray(n)
        fun dfs(v:Int){
            incut[v] = true
            for(e in adj[v]){
                if(e.flow < e.cap && incut[e.v2]  == false){
                    dfs(e.v2)
                }
            }
        }
        dfs(s)
        return incut
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
    fun removeFirst(): ei {
        assert(isNotEmpty())
        val ret = st[startpointer]
        startpointer ++
        return ret
    }
    fun removeLast(): ei {
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
    operator fun get(v:Int): ei {
        return st[startpointer + v]
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
class fastmint (var array:IntArray){
    val size:Int get() = pt + 1
    var pt = array.lastIndex
    //iterate with 0..pt
    val lastIndex:Int get() = pt
    init{
        if(array.size < 5){
            array = array.copyOf(5)
        }
    }
    constructor(initialCapacity:Int = 10):this(IntArray(initialCapacity)){
        pt = -1
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
            array = array.copyOf(array.size * 3 / 2  )
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
    fun reduceMemory(){
        array = array.copyOf(size)
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
    val demand = fastmint()

    fun newvar():Int{
        head.add(-1)
        n ++
        return n - 1
    }
    fun newseries(n:Int):IntArray{
        return IntArray(n){newvar()}
    }

    private fun add_path(from:Int, target:Int, capacity:Int, cost:Int, demand:Int):Int{
        next.add(head[from])
        to.add(target)
        this.capacity.add(capacity)
        this.cost.add(cost)
        this.demand.add(demand)
        head[from] = next.lastIndex
        return next.lastIndex
    }
    fun add(from: Int, to: Int, capacity: Int, cost: Int, demand:Int = 0): Int {
        val e = add_path(from,to,capacity,cost,demand)
        add_path(to,from,0,-cost,-demand)
        return e
    }
    var dist:IntArray = IntArray(0)
    var pre:IntArray = IntArray(0)
    var incf:IntArray = IntArray(0)
    var vis:BooleanArray = BooleanArray(0)

    var maxflow = 0L
    var mincost = 0L

    private inline fun NS_edge(v:Int, act:(e:Int, to:Int)->Unit){
        var e = head[v]
        while(e != -1){
            act(e,to[e])
            e = next[e]
        }
    }
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
    fun mincost_spfa(needpositive:Boolean): Boolean {
        dist = IntArray(n){plarge}
        vis = BooleanArray(n)

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
        if(needpositive && dist[t] >= 0) return false
        return incf[t] > 0
    }
    fun mincost_update(){
        maxflow += incf[t]
        var u = t
        while(u != s){
            capacity[pre[u]] -= incf[t]
            capacity[pre[u] xor 1] += incf[t]
            mincost += incf[t].toLong() * cost[pre[u]]
            u = to[pre[u] xor 1]
        }
    }
    fun mincostflow(){
        Q = fastDeque(0,n * to.size)
        pre = IntArray(n)
        incf = IntArray(n)
        while(mincost_spfa(false)){
            mincost_update()
        }
    }


    var a:IntArray = IntArray(0)
    var p:IntArray = IntArray(0)
    fun ford(){
        a = IntArray(n)
        p = IntArray(n)
        Q = fastDeque(0,n)
        while(true){
            a.fill(0)
            Q.reset()
            Q.addLast(s)
            a[s] = plarge
            while(Q.isNotEmpty()){
                val x = Q.removeFirst()
                NS_edge(x){
                        e,to ->
                    if(a[to] == 0 && capacity[e] > 0){
                        p[to] = e
                        a[to] = minOf(a[x], capacity[e])
                        Q.addLast(to)
                    }

                }
                if(a[t] != 0){

                    break
                }
            }
            if(a[t] == 0) break
            var now = t
            while(now != s){
                val e = p[now]
                capacity[e] -= a[t]
                capacity[e xor 1] += a[t]
                now = to[e xor 1]
            }
            maxflow += a[t]
        }
    }


    var blocked:BooleanArray = BooleanArray(0)

    fun dinic_bfs():Boolean{
        Q.reset()
        Arrays.fill(dist, -1)
        dist[t] = 0
        Q.addLast(t)
        while (!Q.isEmpty()) {
            val node = Q.removeFirst()
            if (node == s) return true
            NS_edge(node){e,to->
                if (capacity[e xor 1] > 0 && dist[to] == -1) {
                    dist[to] = dist[node] + 1
                    Q.addLast(to)
                }
            }
        }
        return dist[s] != -1
    }
    fun dfs(pos: Int, min: Int): Int {
        if (pos == t) return min
        var flow = 0

        NS_edge(pos){e, to->
            var cur = 0
            if (!blocked[to] && dist[to] == dist[pos] - 1 && capacity[e] > 0) {
                cur = dfs(to, Math.min(min - flow, capacity[e]))
                capacity[e] -= cur
                capacity[e xor 1] += cur
                flow += cur
            }
            if (flow == min) return flow
        }
        blocked[pos] = flow != min
        return flow
    }
    fun dinic(){
        clear()
        blocked = BooleanArray(n)
        dist = IntArray(n)
        Q = fastDeque(0,n)
        while(dinic_bfs()){
            blocked.fill(false)
            maxflow += dfs(s, plarge)
        }
    }
    fun dinic_demand():Boolean{
        val new = flowModelLinked()
        val relative = new.newseries(n)
        val indsum = IntArray(n)
        val outdsum = IntArray(n)

        for(e in 0 until capacity.lastIndex step 2){
            val to = this.to[e]
            val from = this.to[e xor 1]
            val demand = demand[e]
            val cap = capacity[e]
            val actual = cap - demand
            indsum[to] += demand
            outdsum[from] += demand
            new.add(relative[from], relative[to],actual,0)
        }

        new.add(relative[t],relative[s], plarge,0)
        for(i in 0 until n){
            new.add(new.s,relative[i],indsum[i],0)
            new.add(relative[i],new.t,outdsum[i],0)
        }
        var want = 0L
        for(c in indsum){
            want += c
        }
//        new.outputmodel()
        new.dinic()
        if(want != new.maxflow){
            return false
        }
        for(e in 0 until capacity.lastIndex step 2){
            val gotflow = new.flowof(e) + demand[e]
            capacity[e] -= gotflow
            capacity[e xor 1] += gotflow
        }
        return true
    }
    fun clear(){
        for(e in 0 until to.lastIndex step 2){
            val total = capacity[e] + capacity[e xor 1]
            capacity[e] = total
            capacity[e xor 1] = 0
        }
        maxflow = 0
        mincost = 0L
    }

    fun flowof(e:Int): Int {
        return capacity[e xor 1]
    }
    fun outputmodel(){
        for(v in 0 until n){
            NS_edge(v){
                    e,to->
                if(e and 1 == 1) return@NS_edge
                val cap = capacity[e]
                println("$v $to $cap")
            }
        }
    }
}

const val singleCase = true
fun main(){


//    just dei F.maxflow

    solve.cases{
        val n = getint
        val m = getint

        val useful = getline(n)
        val want = getline(n)

        val A = IntArray(m)
        val B = IntArray(m)

        for(i in 0 until m){
            A[i] = getint - 1
            B[i] = getint - 1
        }

        val degree = IntArray(n)
        for(i in 0 until m){
            degree[A[i]] ++
            degree[B[i]] ++
        }
        for(i in 0 until n){
            if(useful[i] == 1 && (degree[i] - want[i]) %2 != 0){
                put("NO")
                return@cases
            }
        }

        val box = flowModelLinked()
        val start = box.newseries(m)
        val end = box.newseries(n)
        val ret = IntArray(m)
        for(i in 0 until m){
            box.add(box.s,start[i],1,0,1)
            ret[i] = box.add(start[i],end[A[i]], 1,0)
            box.add(start[i],end[B[i]], 1,0)
        }
        for(i in 0 until n){
            if(useful[i] == 1){
                val tar = (want[i] + degree[i]) / 2
                box.add(end[i],box.t,tar,0,tar)
            }else{
                box.add(end[i],box.t,10000,0,0)
            }
        }

        val ans = box.dinic_demand()
        if(!ans){
            put("NO")
            return@cases
        }
        put("YES")
        for(i in 0 until m){
            val left = box.flowof(ret[i])
            if(left > 0){
                put("${B[i]+1} ${A[i]+1}")
            }else{
                put("${A[i]+1} ${B[i]+1}")
            }
        }








    }
    done()
}



/*
5 1
1 1 1 1 1
1 -1 0 0 0
1 2
 */