// 2022.07.03 at 19:03:59 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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
class DisjointUnionSets(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    var components:Int = n

    val successfulUnions:Int get() = n - components

    fun find(x: Int): Int {
        if (parent[x] != x) {
            parent[x] = find(parent[x])
        }
        return parent[x]
    }

    fun union(x: Int, y: Int):Boolean {
        var xRoot = find(x)
        var yRoot = find(y)
        if (xRoot == yRoot){
            return false
        }
        components--
        if(size[xRoot] < size[yRoot]){
            xRoot = yRoot.also { yRoot = xRoot }
        }
        parent[yRoot] = xRoot
        size[xRoot] += size[yRoot]
        return true
    }
    fun getsize(a:Int):Int{
        return size[find(a)]
    }

    var modified = mutableListOf<Int>()
    inline fun eachComponent(act:(Int)->Unit){
        for(i in 0 until n){
            if(parent[i] == i){
                act(i)
            }
        }
    }

    fun printAll(){
        val comps = Array(n){ mutableListOf<Int>()}
        for(i in 0 until n){
            comps[find(i)].add(i)
        }
        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
    }
}
class DSU_unroll(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}

    var ver = -1
    val p_i = IntArray(n)
    val p_v = IntArray(n)
    val s_i = IntArray(n)
    val s_v = IntArray(n)

    fun find(x: Int): Int {
        // no path compression
        if (parent[x] != x) {
            return find(parent[x])
        }
        return parent[x]
    }

    fun set(i:Int, p:Int, j:Int, s:Int){
        ver ++
        p_i[ver] = i
        p_v[ver] = parent[i]
        s_i[ver] = j
        s_v[ver] = size[j]

        parent[i] = p
        size[j] = s
    }
    fun unrollTo(v:Int){
        while(ver > v){
            parent[p_i[ver]] = p_v[ver]
            size[s_i[ver]] = s_v[ver]
            ver --
        }
    }

    fun union(x: Int, y: Int) {
        val xRoot = find(x)
        val yRoot = find(y)
        if (xRoot == yRoot) return
        if(size[xRoot] < size[yRoot]){
            set(xRoot,yRoot,yRoot,size[xRoot] + size[yRoot])
        }else{
            set(yRoot,xRoot,xRoot,size[xRoot] + size[yRoot])
        }
    }
    fun getsize(a:Int):Int{
        return size[find(a)]
    }

    fun getVersionNumber(): Int {
        return ver
    }


    inline fun eachComponent(act:(Int)->Unit){
        for(i in 0 until n){
            if(parent[i] == i){
                act(i)
            }
        }
    }

    fun printAll(){
        val comps = Array(n){ mutableListOf<Int>()}
        for(i in 0 until n){
            comps[find(i)].add(i)
        }
        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
    }
}
class item(val one:Int, val two:Int, val c1:Int, val c2:Int, val d1:Int,val d2:Int){

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

class minCountTree (nSuggest  :Int){
    //Items lenght must be a power of 2
    companion object{
        const val huge = 4000000000000000000L
    }

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val min = LongArray(n * 2){huge}
    val mincount = IntArray(n * 2){1}

    val lazy = LongArray(n){0L} // l // lazy : already applied to this node

    constructor(withArray:LongArray):this(withArray.size){
        for(i in withArray.indices){
            min[i+n] = withArray[i]
        }
        updateAll()
    }
    private fun updateNode(i:Int,level:Int){
        val left = min[i shl 1]
        val right = min[(i shl 1) + 1]

        min[i] = minOf(left,right) + lazy[i]
        if(left == right){
            mincount[i] = mincount[i shl 1] + mincount[(i shl 1) + 1 ]
        }else if(left < right){
            mincount[i] = mincount[i shl 1]
        }else{
            mincount[i] = mincount[(i shl 1) + 1]
        }
    }
    fun nodeAdd(x:Int,level:Int,inc:Long){
        // apply the update to the node , then store further children updates
        min[x] += (inc)
        if(x < n){
            lazy[x] += inc
        }
    }

    private fun pushNode(i:Int, level:Int){ // must be interior node

        val left = (i shl 1)
        val inc = lazy[i]

        nodeAdd(left,level-1,inc)
        nodeAdd(left+1, level-1, inc)
        lazy[i] = 0

    }

    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        var level = 0
        while(here > 1){
            here = here shr 1
            level ++
            updateNode(here,level)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i,i.calculateLevel)
        }
    }
    private fun pushPath(i:Int){
        // i must be in [n,2n)
        for(s in levels downTo 1){
            pushNode(i shr s,s)
        }
    }
    val lastIndex = n-1


    fun primitiveIndex(a:Int) = a + n
    inline fun segmentOrder(act:(here:Int, left:Int,right:Int)->Unit ){
        //iterate over all segments bottom up, probably to rebuild tree
        for(i in (n-1) downTo 1){
            act(i, (i shl 1 ), (i shl 1) + 1)
        }
    }
    inline fun primitiveOrder(act:(here:Int,primitiveIndex:Int)->Unit){
        //iterate over all the leaf nodes
        for(i in 0 until n){
            act(i+n,i)
        }
    }


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

    fun rangeAdd(l:Int,r:Int,inc:Long){
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,level ->
            nodeAdd(i,level,inc)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int):Pair<Long,Int> {
        pushPath(l+n)
        pushPath(r+n)
        var ret = Long.MAX_VALUE
        var count = 0
        segDivision(l,r){i, level ->
            if(min[i] < ret){
                count = 0
                ret = min[i]
            }
            if(min[i] == ret){
                count += mincount[i]
            }
        }
        return Pair(ret,count)
    }

    val Int.leftNode:Int get(){
        // assert(this <= n )
        return this shl 1
    }
    val Int.rightNode:Int get(){
        // assert(this <= n)
        return (this shl 1) + 1
    }
    val Int.endpoints:Pair<Int,Int> get(){
        val offSet = this - this.takeHighestOneBit()
        val widthLevel = levels - (31 - this.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }
    val Int.calculateLevel:Int get(){
        val base = 31 - this.countLeadingZeroBits()
        return levels - base
    }
    fun lazyPrint(){
        val ret = LongArray(n)
        for(i in 0 until n){
            ret[i] = rangeQueryLazy(i,i).first
        }
        println(ret.joinToString(" "))
    }
}
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val arr = Array(n){CharArray(m)}
        val id = IntArray(n * m)
        val parity = IntArray(n *m)
        val other = IntArray(n * m)

        repeat(n){i ->
            val str = getstr
            for(j in 0 until m){
                arr[i][j] = str [j ]
            }
        }
        fun code(x:Int, y:Int):Int?{
            if(x !in 0 until n) return null
            if(y !in 0 until m) return null
            return x * m + y
        }

        for(i in 0 until n){
            for(j in 0 until m){
                parity[code(i,j)!!] = (i + j) %2
            }
        }
//        val dsu = DSU_unroll(n * m)
//
//        fun digest(a:item){
//            if(a.c1 != -1 && a.c2 != -1){
//                dsu.union(a.c1,a.c2)
//            }
//            if(a.d1 != -1 && a.d2 != -1){
//                dsu.union(a.d1,a.d2)
//            }
//        }

        val G = Graph(n*m +1, n*m , true)
        val badroot = n * m
        G.root = badroot

        val all = mutableListOf<item>()
        var cnt = -1
        for(i in 0 until n){
            for(j in 0 until m){
                val c = arr[i][j]
                cnt ++
                if(c == 'U'){
                    val a = code(i,j)!!
                    val b = code(i+1,j)!!
                    val c1 = code(i-1,j) ?: -1
                    val c2 = code(i+1,j) ?: -1
                    val d1 = code(i,j) ?: -1
                    val d2 = code(i+2,j) ?: -1

                    id[a] = cnt
                    id[b] = cnt


                    if(c1 != -1 && c2 != -1){
                        G.add(c1,c2)
                    }else{
                        G.add(badroot,c2)
                    }
                    if(d1 != -1 && d2 != -1){
                        G.add(d2,d1)
                    }else{
                        G.add(badroot,d1)
                    }
                    other[a] = b
                    other[b] =a
                    all.add(item(a,b,c1,c2,d1,d2))
                }else if(c == 'L'){
                    val a = code(i,j)!!
                    val b = code(i,j+1)!!
                    val c1 = code(i,j-1) ?: -1
                    val c2 = code(i,j+1) ?: -1
                    val d1 = code(i,j) ?: -1
                    val d2 = code(i,j+2) ?: -1
                    id[a] = cnt
                    id[b] = cnt
                    if(c1 != -1 && c2 != -1){
                        G.add(c1,c2)
                    }else{
                        G.add(badroot,c2)
                    }
                    if(d1 != -1 && d2 != -1){
                        G.add(d2,d1)
                    }else{
                        G.add(badroot,d1)
                    }
                    other[a] = b
                    other[b] =a
                    all.add(item(a,b,c1,c2,d1,d2))
                }
            }
        }

        val subtree = G.calculateSizes()
//        fun path(i:Int):MutableList<Int> {
//            val ret = mint
//            var now = i
//            ret.add(id[i])
//            while(now != G.root) {
//                now = G.parent[now]
//                if(now != G.root)
//                ret.add(id[now])
//            }
//            return ret
//        }
//
//        fun brutecheck(i:Int, j:Int):Boolean {
//            val p1 = path(i)
//            val p2 = path(j)
//            if(p1.intersect(p2).isNotEmpty()){
////                just dei "$i $j"
//                return true
//            }
//            return false
//        }
        val intime = G.intime()
        val outtime = G.outtime()
        val st = minCountTree(LongArray(n * m  + 1){0})
        var ret = 0L
        for(i in 0 until n*m){
            if(parity[i] == 0){
                st.rangeAdd(intime[i],intime[i],1)
            }
        }
        st.rangeAdd(0 , 0 , 1)
//        st.lazyPrint()
        fun dfs(v:Int){
            if(v != badroot && parity[v] != 0) return
            if(v != badroot){

                val t1 = intime[other[v]]
                val t2 = outtime[other[v]]
                st.rangeAdd(t1,t2,1L)

//                st.lazyPrint()

                if(parity[v] == 0){
                    val (min,count) = st.rangeQueryLazy(0,n*m)
//                    just dei "$min $count"
                    val total = (n * m)/2
                    if(min == 0L){
                        ret += (total - count)
                    }else{
                        ret += total
                    }
                }
            }
            G.NS(v){
                dfs(it)
            }
            if(v != badroot){
                val t1 = intime[other[v]]
                val t2 = outtime[other[v]]
                st.rangeAdd(t1,t2,-1L)
            }
        }
        dfs(badroot)

//       var ret = 0L
//        for(c in all){
//            ret += subtree[c.one].toLong() * subtree[c.two]
//        }
//        for(i in 0 until n * m){
//            for(j in i+ 1 until n * m ){
//                if(parity[i] == parity[j]) continue
//                if(brutecheck(i,j)){
//                    ret ++
//                }
//            }
//        }

//        fun solve(l:Int, r:Int){
//            if(l == r){
//                val new = dsu.getsize(all[l].one).toLong() * dsu.getsize(all[l].two)
//                ret += new
//                just dei new
//                return
//            }
//            val version = dsu.getVersionNumber()
//            val mid = (l + r ) shr 1
//            for(i in l..mid){
//                digest(all[i])
//            }
//            solve(mid+1 , r)
//            dsu.unrollTo(version)
//            for(i in mid+1 ..r){
//                digest(all[i])
//            }
//            solve(l,mid)
//        }
//        solve(0,all.lastIndex)
        put(ret)




    }
    done()
}
/*
- cannot repeat moves
- cannot move two moves

iff linearlly enough - NO

find application of 2 cycles

hard proof
or transformational proofs

 */