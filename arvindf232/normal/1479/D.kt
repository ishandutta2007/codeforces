// 2022.06.20 at 14:23:20 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.absoluteValue
import kotlin.random.Random
import kotlin.system.measureTimeMillis

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

private fun leastSignificantBit(n:Int):Int{
    return (n and (-n))
}


class xorbit (nsuggest:Int){
    val n = nsuggest + 1
    val all = LongArray(n + 1 + (n shr 9))
    
    fun poke(n:Int):Int{
        return n + ( n shr 10)
    }

    fun add(i:Int, inc:Long){
        if(i < 0 || i >= n) return
        var i = i + 1
        while(i <= n){
            all[poke(i)] = all[poke(i)] xor inc
            i += leastSignificantBit(i)
        }
    }
    fun printTree(){
        val ret = mutableListOf<Long>()
        for(i in 0 until n ){
            ret.add(rangeQuery(i,i))
        }
        println(ret.joinToString(" "))
    }
    fun query(i:Int):Long{
        var ret = 0L
        var i  = i + 1
        while(i >0){
            ret = ret xor all[poke(i)]
            i -= leastSignificantBit(i)
        }
        return ret
    }
    fun rangeQuery(a:Int,b:Int): Long {
        return query(b) xor query(a-1)
    }
}
const val graphWeighed = false
class Graph(val n:Int, val m:Int, val directed:Boolean) {
    val maxedge = if (directed) m else m * 2

    var cnt = -1

    val edgecount:Int get() = cnt + 1

    val next = IntArray(maxedge)
    val head = IntArray(n) { -1 }
    val to = IntArray(maxedge)
    val from = IntArray(maxedge)
    val weights = IntArray(if (graphWeighed) m else 0)
    private fun primitive_add(u: Int, v: Int): Int {
        next[++cnt] = head[u]
        head[u] = cnt
        to[cnt] = v
        from[cnt] = u
        return cnt
    }

    fun add(u: Int, v: Int): Int {
        val e = primitive_add(u, v)
        if (!directed) {
            primitive_add(v, u)
        }
        return if (directed) e else e shr 1
    }

    fun addWeighted(u: Int, v: Int, w: Int):Int{
        val e = add(u, v)
        weights[e] = w
        return e
    }

    //Basic Transversals
    inline fun NS(a:Int, act:(Int)->Unit){
        var i= head[a]
        while(i != -1){
            act(to[i])
            i = next[i]
        }
    }
    inline fun NS_E(a:Int, act:(e:Int,v:Int)->Unit){
        var i= head[a]
        while(i != -1){
            act(i,to[i])
            i = next[i]
        }
    }

    // twice for undirected
    inline fun everyEdge(act:(a:Int, b:Int)->Unit){
        for(e in 0 until edgecount){
            act(from[e], to[e])
        }
    }

    //2 Basic Transversals
    var root = 0
    var preorder:IntArray = IntArray(0)
    var parent:IntArray = IntArray(0)
    val hasDFSorder:Boolean get() = preorder.size == n
    var parentEdge:IntArray = IntArray(0)

    var entryTime:IntArray = IntArray(0)
    var exitTime:IntArray = IntArray(0)

    //stores the order
    fun treeOrderDFS(withEdges:Boolean = false){
        parent = IntArray(n){-1}
        var pt = -1
        preorder = IntArray(n){-1}
        if(withEdges) parentEdge = IntArray(n){-1}

        val Q = fastDeque(0,n)
        parent[root] = root
        Q.addLast(root)
        while(Q.isNotEmpty()){
            val a = Q.removeLast()
            val p = parent[a]
            preorder[++pt] = a
            NS_E(a){e,v ->
                if(v == p) return@NS_E
                if(withEdges) parentEdge[v] = if(directed) e else (e shr 1)
                parent[v] = a
                Q.addLast(v)
            }
        }
    }
    fun combine(a:Long,b:Long):Long{
        return maxOf(a,b)
    }


    val L = 31 - n.countLeadingZeroBits()

    var quickParents:Array<IntArray> = arrayOf()
    var depth:IntArray = intArrayOf()
    var tin:IntArray = intArrayOf()
    var tout:IntArray = intArrayOf()
    val empty = Long.MIN_VALUE
    var quickPaths:Array<LongArray> = arrayOf()
    fun preparepaths(lift:LongArray){
        quickPaths = (0..L).scan(lift){P,i -> LongArray(n){combine(P[it], P[quickParents[i][it]])}}.toTypedArray()
    }
    fun prepareLifting(lift:LongArray = longArrayOf()){
        quickParents = (0..L).scan(parent){P,i -> IntArray(n){P[P[it]]} }.toTypedArray()
        depth = calculateDepth()
        tin = intime()
        tout = outtime()
        if(lift.isNotEmpty()){
            preparepaths(lift)
        }
    }
    fun calParent(now:Int,l:Int):Int{
        var now = now
        for(i in quickParents.size -1  downTo 0){
            if(l and (1 shl i) != 0){
                now = quickParents[i][now]
            }
        }
        return now
    }
    fun isancestor(v:Int,of:Int):Boolean{
        return tin[v] <= tin[of] && tout[v] >= tout[of]
    }
    fun LCA(u:Int,v:Int):Int{
        if (isancestor(u, v))
            return u;
        if (isancestor(v, u))
            return v;
        var u = u
        for (i in L downTo 0) {
            val next = quickParents[i][u]
            if(!isancestor(next,v)){
                u = next
            }
        }
        return parent[u]
    }
    fun dist(a:Int, b:Int): Int {
        val c = LCA(a,b)
        return (depth[c] - depth[a]).absoluteValue +  (depth[c] - depth[b]).absoluteValue
    }


    fun liftWeights():LongArray{
        return LongArray(n){if(parentEdge[it] == -1) empty else weights[parentEdge[it]].toLong()}
    }

    fun calculateRootedPath(v:Int,e:Int): Long {
        var ret = empty
        var now = v
        for(i in quickParents.size -1  downTo 0){
            if(e and (1 shl i) != 0){
                ret = combine(ret,quickPaths[i][now])
                now = quickParents[i][now]
            }
        }
        return ret
    }
    fun calculatePath(u:Int, v:Int):Long{
        val lca = LCA(u,v)
        val left = calculateRootedPath(u,depth[u] - depth[lca])
        val right = calculateRootedPath(v,depth[v] - depth[lca])
        return combine(left, right)
    }
    //One off, does not store order
    inline fun anyOrderExplore(root:Int?,newroot:(r:Int) ->Unit, act:(form:Int, to:Int, root:Int, e:Int, spanning:Boolean)->Unit) {
        // null -> Exhaust
        parent = IntArray(n){-1}
        val explored = BooleanArray(n)
        val Q = fastDeque(0,n)
        for(i in 0 until n){
            if(explored[i] || (root != null && root != i) ) continue
            newroot(i)
            Q.addLast(i)
            parent[i] = i
            while(Q.isNotEmpty()){
                val a = Q.removeLast()
                NS_E(a) { e,v ->
                    if (v == parent[v]) return@NS_E
                    val newedge = !explored[v]
                    if (newedge) {
                        parent[v] = a
                        Q.addLast(v)
                        explored[v] = true
                    }
                    act(a, v, i, e,newedge)
                }
            }
            if(root != null) break
        }
    }
    fun EulerDoubleOrder(): Pair<IntArray, IntArray> {
        var pointer = 0
        val euler = IntArray(2 * n - 1)
        val entry = IntArray(n)
        fun dfs(v:Int, p:Int) {
            euler[++pointer] = v
            entry[v] = pointer
            NS(v){ w->
                if(w == p) return@NS
                dfs(w,p)
                euler[++pointer] = v
            }
        }
        dfs(root,-1)
        return Pair(euler, entry)
    }
    inline fun BFS(distRoot:Int, reached:(Int, Int)->Unit = {_,_ ->}): IntArray {
        val toDo = fastDeque(0,n)
        val explored = IntArray(n+1){-1} // also store parents
        toDo.addLast(distRoot)
        explored[distRoot] = -2
        val dist = IntArray(n){-1}
        dist[distRoot] = 0

        while(toDo.size > 0){
            val x = toDo.removeFirst()
            reached(x,explored[x])
            NS(x){ a->
                if(explored[a] == -1){
                    explored[a] = x
                    dist[a] = dist[x] + 1
                    toDo.addLast(a)
                }
            }
        }
        return dist
    }
    inline fun trueOrderDFS(root:Int?,newroot:(r:Int) ->Unit, preexplore:(v:Int) ->Unit, postExplore:(v:Int)->Unit ){
        val Q = fastDeque(0,n)
        val explored = BooleanArray(n){false}
        val headHere = head.copyOf()
        for(i in 0 until n) {
            if (explored[i] || (root != null && root != i)) continue
            newroot(i)
            explored[i] = true
            Q.addLast(i)
            while(Q.isNotEmpty()){
                val v = Q.last()
                val e = headHere[v]
                if(e == head[v]){
                    preexplore(v)
                }
                if(e == -1){
                    postExplore(v)
                    Q.removeLast()
                    continue
                }
                headHere[v] = next[e]
                val t = to[e]
                if(!explored[t]){
                    explored[t] = true
                    Q.addLast(t)
                }
            }
        }

    }


    //standard graph transversal orders
    inline fun leafFirst(act:(Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
        for(i in preorder.lastIndex downTo 0){
            act(preorder[i])
        }
    }
    inline fun rootFirst(act:(Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
        for(a in preorder){
            act(a)
        }
    }
    inline fun anyOrder(act:(Int)->Unit){
        for(i in 0 until n){
            act(i)
        }
    }
    inline fun rootFirstEdge(act:(from:Int, to:Int, e:Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
        for(i in 1 until preorder.size){
            val v = preorder[i]
            act(parent[v],v,parentEdge[v])
        }
    }

    // Basic invariants maintaining
    fun calculateParents():IntArray{
        if(!hasDFSorder) treeOrderDFS()
        return parent
    }
    fun calculateSizes():IntArray{
        val ret = IntArray(n){1}
        leafFirst { v -> if(v != root) ret[parent[v]] += ret[v] }
        return ret
    }
    fun calculateSubtreeSum(weights:IntArray){
        leafFirst { v -> if(v != root) weights[parent[v]] += weights[v] }
    }
    fun calculateDepth(): IntArray {
        val ret = IntArray(n)
        rootFirst { v -> if(v != root) ret[v] = ret[parent[v]] + 1  }
        return ret
    }
    inline fun subs(v:Int, act:(Int)->Unit){
        NS(v){w ->
            if(w != parent[v]) act(w)
        }
    }
    fun calculateDepthWeighted(): LongArray {
        val ret = LongArray(n)
        rootFirstEdge{from,to,e -> ret[to] = ret[from] + weights[e]}
        return ret
    }
    fun outdegree():IntArray{
        val ret = IntArray(n)
        everyEdge { a, b -> ret[a] ++  }
        return ret
    }
    fun indegree():IntArray{
        val ret = IntArray(n)
        everyEdge {a, b -> ret[b] ++}
        return ret
    }
    fun degree():IntArray = outdegree()
    fun reversed():Graph{
        assert(directed)
        val new = Graph(n,m,true)
        everyEdge { a, b -> new.add(b,a) }
        return new
    }
    fun intime():IntArray{
        val tin = IntArray(n)
        if(!hasDFSorder) treeOrderDFS()
        for(i in 0 until n) tin[preorder[i]] = i
        return tin
    }
    fun outtime():IntArray{
        val tout = intime()
        leafFirst { v ->
            val p = parent[v]
            if(p == v) return@leafFirst
            tout[p] = maxOf(tout[p], tout[v])
        }
        return tout
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
class onebin (val max:Int){
    val head = IntArray(max){-1}
    val value = fastmint()
    val next = fastmint()
    fun add(k:Int ,v:Int){
        value.add(v)
        next.add(head[k])
        head[k] = value.lastIndex
    }
    inline fun every(k:Int,act:(Int)->Unit) {
        var now = head[k]
        while(now != -1){
            act(value[now])
            now = next[now]
        }
    }
}

class twobin (val max:Int){
    val head = IntArray(max){-1}
    val value = fastmint()
    val value2 = fastmint()
    val next = fastmint()
    fun add(k:Int ,v:Int,v2:Int){
        value.add(v)
        value2.add(v2)
        next.add(head[k])
        head[k] = value.lastIndex
    }
    inline fun every(k:Int,act:(Int,Int)->Unit) {
        var now = head[k]
        while(now != -1){
            act(value[now],value2[now])
            now = next[now]
        }
    }
}

class typebin<T> (val max:Int){
    val head = IntArray(max){-1}
    val value = mutableListOf<T>()
    val next = fastmint()
    fun add(k:Int ,v:T){
        value.add(v)
        next.add(head[k])
        head[k] = value.lastIndex
    }
    inline fun every(k:Int,act:(T)->Unit) {
        var now = head[k]
        while(now != -1){
            act(value[now])
            now = next[now]
        }
    }
}
class query(val id: Int, var prime:Boolean){

}
class simpleSegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = Array<MutableList<query>>(n * 2 + 1 ){ mutableListOf() }
    val arrSize = n * 2 + 1
    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                act(left,level)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                act(right,level)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
    }
    fun endpoints(v:Int):Pair<Int,Int>{
        val offSet = v - v.takeHighestOneBit()
        val widthLevel = levels - (31 - v.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }
}

fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val q = getint

        val A = getline(n)
        for(i in 0 until n){
            A[i] --
        }

        val G = Graph(n,n-1,false)
        repeat(n-1){
            G.add(getint - 1 , getint - 1 )
        }

        val rand = LongArray(n){ Random.nextLong()}
        val xst = xorbit(n+1)
        val intime = G.intime()
        val outtime = G.outtime()

        G.prepareLifting()


        fun xornow(v:Int):Long{
            return xst.query(intime[v])
        }
        fun contribute(type:Int,v:Int){
            val i = intime[v]
            val j = outtime[v]
            val hash = rand[type]
            xst.add(i,hash)
            xst.add(j+1,hash)
        }
        val st = simpleSegTree(n)
        val bign = st.n
        val bins = onebin(bign)
        val queries = twobin(bign * 2)
        for(i in 0 until n){
            bins.add(A[i],i)
        }
        for(t in 0 until n){
            bins.every(t){v ->
                contribute(t,v)
            }
        }
        fun groupcontribute(l:Int, r:Int){
            for(t in l..r){
                bins.every(t) { v ->
                    contribute(t, v)
                }
            }
        }


        val ret = IntArray(q){-1}
        val lcatype = IntArray(q){-1}
        val X = IntArray(q){-1}
        val Y = IntArray(q){-1}
        val left = IntArray(q){-1}
        val right = IntArray(q){-1}
        repeat(q){
            val x = getint -1
            val y = getint -1
            val l = getint - 1
            val r = getint - 1
            X[it] = x
            Y[it] = y
            left[it] = l
            right[it] = r
            lcatype[it] = A[G.LCA(x,y)]
            st.segDivision(l,r){i, level ->
                queries.add(i,it,1)
//                st.arr[i].add(query(it,true))
            }
        }

        fun answer(i:Int,ll:Int, rr:Int){
            val terminal = (i >= st.n)
            queries.every(i){
                    id,prime ->
                val prime = prime == 1
                if(ret[id] != -1) return@every
                val v1 = xornow(X[id])
                val v2 = xornow(Y[id])
                var now = v1 xor v2
                if(lcatype[id] in ll..rr){
                    now = now xor rand[lcatype[id]]
                }
                val answer = now != 0L

//                just dei "$i ${st.endpoints(i)}  $v1 $v2 $answer"
                if(answer){
                    if(terminal){

                        ret[id] = i - st.n
                    }else{
                        queries.add(i shl 1, id, 0)

                    }
                }else{
                    if(prime){

                    }else if(terminal){
                        ret[id] = i + 1 - st.n
                    }else{
                        queries.add((i +1) shl 1 , id, 0)
                    }
                }
            }
        }

        fun solve(l:Int, r:Int, v:Int){
            val mid = (l +r ) shr 1
            answer(v,l,r)
            if(l == r) return
            groupcontribute(mid + 1 , r)
            solve(l,mid,v shl 1)
            groupcontribute(l,r)
            solve(mid+1,r, (v shl 1) + 1 )
            groupcontribute(l,mid)
        }
        solve(0,st.n-1, 1)
        for(i in 0 until q){

            if(ret[i] == -1){
                put(ret[i])
            }else{
                assert(ret[i] in left[i]..right[i])
                put(ret[i]+1)
            }
        }





    }
    done()
}




/*
6 1
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
1 1 3 3

6 8
1 2 3 4 5 6
1 2
2 3
3 4
4 5
5 6
1 6 1 1
1 6 2 2
1 6 3 3
1 6 4 4
1 6 5 5
1 6 6 6
1 6 1 3
1 6 4 6

 */