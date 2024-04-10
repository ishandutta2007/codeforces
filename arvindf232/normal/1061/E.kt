import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == '1'}
}

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
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
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
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor b.toLong()
val Long.first get() = (this shr 32).toInt()
val Long.second get() = this.toInt()

const val graphWeighed = false
const val graphEdgeSetup = false
class ProtoGraph(val n:Int, val m:Int, val directed:Boolean) {
	val maxedge = if (directed) m else m * 2

	var cnt = -1

	val next = IntArray(maxedge)
	val head = IntArray(n) { -1 }
	val to = IntArray(maxedge)
	val from = IntArray(maxedge)
	val edgeWeights = IntArray(if (graphWeighed) m else 0)
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

	fun addWeighted(u: Int, v: Int, w: Int) {
		val e = add(u, v)
		edgeWeights[e] = w
	}
}

inline fun makegraph(n:Int, m:Int, directed:Boolean, doit:ProtoGraph.() ->Unit):NewGraph{
	val G = ProtoGraph(n,m,directed)
	G.doit()
	return NewGraph(G)
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
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
class NewGraph(proto:ProtoGraph) {

	val n = proto.n
	val m = proto.m
	val directed = proto.directed

	val next = proto.next
	val head = proto.head
	val to = proto.to
	val from = proto.from
	val edgeWeights = proto.edgeWeights


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

	//2 Basic Transversals
	var root = 0
	var preorder:IntArray = IntArray(0)
	var parent:IntArray = IntArray(0)
	val hasDFSorder:Boolean get() = preorder.size == n
	var parentEdge:IntArray = IntArray(0)

	var entryTime:IntArray = IntArray(0)
	var exitTime:IntArray = IntArray(0)

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
	inline fun rootFirstEdge(act:(form:Int, to:Int, e:Int)->Unit){
		if(!hasDFSorder) treeOrderDFS(true)
		for(i in 1 until preorder.size){
			val v = preorder[i]
			act(parent[v],v,parentEdge[v])
		}
	}

	// Basic invariants maintaining
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
	fun calculateDepthWeighted(): LongArray {
		val ret = LongArray(n)
		rootFirstEdge{from,to,e -> ret[to] = ret[from] + edgeWeights[e]}
		return ret
	}
	fun buildSubs(): Array<MutableList<Int>> {
		val ret = Array(n){ mutableListOf<Int>() }
		anyOrder { v -> ret[parent[v]].add(v) }
		return ret
	}


	val depth = calculateDepth()


}
class demands(exactly:Int, things:List<Int>){

}
class FlowEdge(var v1: Int, var v2: Int, var cap: Int, var flow: Int, var cost:Long = 0L, var lowerDemand:Int = 0, isreal:Boolean ) {
	var rev: FlowEdge? = null
	override fun toString():String {
		return "$v1 $v2 C $cap"
	}
}
class FlowModel (var nSuggest:Int){
	val s:Int
	val t:Int
	val n:Int
	var adj: List<MutableList<FlowEdge>>
	val realedges:MutableList<FlowEdge>
	val alledges:MutableList<FlowEdge>
	init{
		n= nSuggest + 2
		s = n-2
		t = n-1

		adj = List(n){ mutableListOf()}
		realedges = mutableListOf()
		alledges = mutableListOf()

	}
	companion object{
		val INF = 1000000000
		val INFL = 1000000000000000000
	}
	fun addEdge(from:Int, to:Int, cap:Int, demand:Int = 0, cost:Long = 0L , flow:Int = 0 ){
		val e1 = FlowEdge(from,to, cap, flow, cost, demand ,true)
		val e2 = FlowEdge(to, from, 0 , -flow, -cost, demand,false)
		e1.rev = e2
		e2.rev = e1
		adj[from].add(e1)
		adj[to].add(e2)
		alledges.add(e1)
		alledges.add(e2)
		realedges.add(e1)
	}

	fun Dinics(): Int {
		val dist = IntArray(n)
		val q = ArrayDeque<Int>()

		fun bfs(): Boolean {
			q.clear()
			Arrays.fill(dist, -1)
			dist[t] = 0
			q.add(t)

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
			return dist[s] != -1
		}
		fun dfs(pos: Int, min: Int): Int {
			val blocked = BooleanArray(n)
			if (pos == t) return min
			var flow = 0

			for (e in adj[pos]) {
				var cur = 0

				if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {
					cur = dfs(e.v2, Math.min(min - flow, e.cap - e.flow))
					e.flow += cur
					e.rev!!.flow = -e.flow
					flow += cur
				}
				if (flow == min) return flow
			}

			blocked[pos] = flow != min
			return flow
		}
		var ret = 0
		while (bfs()) {
			ret += dfs(s, INF)
		}
		return ret
	}
	fun satisfyDemands(minflow:Int): Boolean {
		val newmodel = FlowModel(n)
		val source = IntArray(n)
		val drain = IntArray(n)
		for(e in this.realedges){
			source[e.v2] += e.lowerDemand
			drain[e.v1] += e.lowerDemand
			newmodel.addEdge(e.v1,e.v2,e.cap - e.lowerDemand,0)
		}
		for(i in 0 until n){
			newmodel.addEdge(newmodel.s,i,source[i])
			newmodel.addEdge(i,newmodel.t, drain[i])
		}
		val want = source.sum()
		newmodel.addEdge(t,s,INF)
		newmodel.addEdge(newmodel.s,s,minflow)
		newmodel.addEdge(t,newmodel.t,minflow)

		val maxnow = newmodel.Dinics()
		return maxnow >= (want+minflow)
	}

	fun minCostFlow(K:Int): Long? {
		// Remember no multigraphs
		val costs = List(n){LongArray(n)}
		val capacity = List(n){IntArray(n)}
		val quickAdj = List(n){ mutableListOf<Int>()}

		for(e in alledges){
			costs[e.v1][e.v2] = e.cost
			quickAdj[e.v1].add(e.v2)
		}
		for(e in realedges){
			capacity[e.v1][e.v2] = e.cap
		}
		var flow = 0
		var cost = 0L
		val d = LongArray(n){INFL}
		val p = IntArray(n){-1}


		fun shortest_path(){
			d.fill(INFL)
			p.fill(-1)
			d[s] = 0
			val inq = BooleanArray(n)
			val q = ArrayDeque<Int>()
			q.addLast(s)

			while(!q.isEmpty()){
				val u = q.removeFirst()
				inq[u] = false
				for(v in quickAdj[u]){
					if(capacity[u][v] > 0 && d[v] > d[u] + costs[u][v]){
						d[v] = d[u] + costs[u][v]
						p[v] = u
						if (!inq[v]) {
							inq[v] = true;
							q.addLast(v);
						}
					}
				}
			}
		}
		while(flow < K){
			shortest_path()
			if (d[t] == INFL) break

			var f = K - flow
			var cur = t
			while (cur != s) {
				f = minOf(f, capacity[p[cur]][cur])
				cur = p[cur]
			}
			flow += f
			cost += f * d[t]
			cur = t
			while (cur != s) {
				capacity[p[cur]][cur] -= f
				capacity[cur][p[cur]] += f
				cur = p[cur]
			}
		}
		if(flow < K){
			return null
		}else{
			return cost
		}
	}
	fun standardForm(){
		println("$n ${realedges.size} $s $t")
		for(e in realedges){
			println("${e.v1} ${e.v2} ${e.cap} ${e.cost}")
		}
	}
}



const val INF = 1000000000000000000L
const val LARGE = 1000000000000L

fun FlowModel.do2(): Pair<Long, Long> {

	val s = this.s
	val t = this.t
	val n = this.n
	val m = this.realedges.size


	var q = ArrayDeque<Int>()
	var inq = BooleanArray(0)

	var raw_cap = mutableListOf<Long>()
	var cap = mutableListOf<Long>()
	var cost = mutableListOf<Long>()
	var dis = LongArray(0)

	var head = IntArray(n+1){-1}
	var nxt = mutableListOf<Int>()
	var from = mutableListOf<Int>()
	var to = mutableListOf<Int>()
	var pre = IntArray(0)


	fun add(u:Int,v:Int,f:Long,w:Long)
	{
		nxt.add(head[u]);
		head[u] = to.size
		from.add(u);
		to.add(v);
		raw_cap.add(f);
		cap.add(0);
		cost.add(w);
	}
	fun add_edge(u:Int,v:Int,f:Long,w:Long){
		add(u, v, f, w);
		add(v, u, 0, -w);
	}
	fun spfa(s:Int)
	{
		inq = BooleanArray(n+1){false}
		dis = LongArray(n+1){INF}
		pre = IntArray(n+1){-1}
		dis[s] = 0;
		q.push(s);
		while (!q.isEmpty())
		{
			val u = q.removeFirst()
			inq[u] = false;
			var i = head[u]
			while(i != -1){
				val v = to[i]
				val w = cost[i]
				if ((cap[i] > 0) && dis[v] > dis[u] + w)
				{
					dis[v] = dis[u] + w;
					pre[v] = i;
					if (!inq[v])
					{
						inq[v] = true;
						q.addLast(v);
					}
				}

				i = nxt[i]
			}
		}
	}
	fun add_one_cap(id:Int){
		var u = from[id];
		val v = to[id];
		if (cap[id] > 0 )
		{
			++cap[id];
			return;
		}
		spfa(v);
		if (dis[u] < INF && dis[u] + cost[id] < 0)
		{
			++cap[id xor 1];
			while (u != v)
			{
				val x = pre[u];
				--cap[x];
				++cap[x xor 1];
				u = from[x];
			}
		}
		else ++cap[id];
	}
	for(e in this.realedges){
		add_edge(e.v1,e.v2,e.cap.toLong(),e.cost)
	}
	add_edge(t, s, LARGE, -LARGE);
	for (i in 40 downTo 0)
	{
		for (j in 0 .. m * 2 + 1) cap[j] = cap[j] shl 1
		for (j in 0.. 2*m step 2){
			if ((raw_cap[j] shr i) and 1 > 0)
			{
				add_one_cap(j);
			}
		}
	}
	var min_cost = 0L;
	for (i in 0 until m) min_cost += cap[(i shl 1) or 1] * cost[(i shl 1)]
	val flow = cap[(m shl 1) or 1]
	val finalCost = min_cost
	return Pair(flow,finalCost);

}

fun FlowModel.solveThis(flow:Int):Pair<Int, Int> {
	val new = MinCostFlowDEsopoPape(this.n)
	for(e in this.realedges){
		new.addEdge(e.v1,e.v2,e.cap,e.cost.toInt())
	}
	val (cost,gotflow) = new.minCostFlow(s,t,flow)
	return Pair(cost,gotflow)
}

internal class MinCostFlowDEsopoPape(var V:Int) {
	var INF = 1e9.toInt()
	var G:Array<MutableList<Edge>>
	var D:IntArray
	var prevv:IntArray
	var preve:IntArray

	init {
		G = Array(V){ mutableListOf<Edge>() }
		for(i in 0 until V) G[i] = ArrayList()
		D = IntArray(V)
		prevv = IntArray(V)
		preve = IntArray(V)
	}

	fun addEdge(u:Int, v:Int, cap:Int, cost:Int) {
		G[u].add(Edge(v, cap, cost, G[v].size))
		G[v].add(Edge(u, 0, -cost, G[u].size - 1))
	}

	fun minCostFlow(s:Int, t:Int, f:Int):IntArray {
		var f = f
		var cost = 0
		var flow = 0
		while(f > 0) {
			shortestPath(s)
			if(D[t] == INF) break
			var d = f
			run {
				var v = t
				while(v != s) {
					d = Math.min(d, G[prevv[v]][preve[v]].cap)
					v = prevv[v]
				}
			}
			f -= d
			flow += d
			cost += d * D[t]
			var v = t
			while(v != s) {
				val e = G[prevv[v]][preve[v]]
				e.cap -= d
				G[v][e.rev].cap += d
				v = prevv[v]
			}
		}
		return intArrayOf(cost, flow)
	}

	fun shortestPath(s:Int) {
		Arrays.fill(D, INF)
		D[s] = 0
		val m = IntArray(V)
		Arrays.fill(m, 2)
		val qu:Deque<Int> = ArrayDeque()
		qu.offerLast(s)
		while(!qu.isEmpty()) {
			val u = qu.pollFirst()
			m[u] = 0
			for(i in G[u].indices) {
				val e = G[u][i]
				val v = e.to
				if(e.cap > 0 && D[v] > D[u] + e.cost) {
					D[v] = D[u] + e.cost
					prevv[v] = u
					preve[v] = i
					if(m[v] == 2) {
						m[v] = 1
						qu.offerLast(v)
					} else if(m[v] == 0) {
						m[v] = 1
						qu.offerFirst(v)
					}
				}
			}
		}
	}
}

internal class Edge(var to:Int, var cap:Int, var cost:Int, var rev:Int)

const val singleCase = true
fun main(){
    solve.cases{
		val n = getint
		val x = getint -1
		val y = getint -1
		val L = getline(n)

		fun getEdges():List<Pair<Int, Int>> {
			return List(n-1){Pair(getint-1, getint- 1 )}
		}
		fun readDemands():List<Pair<Int,Int>> {
			val t = getint
			return List(t){Pair(getint -1, getint)}
		}

		val G1 = getEdges()
		val G2 = getEdges()
		val D1 = readDemands()
		val D2 = readDemands()

		var total:Int? = null
		var bad = false

		fun getdemands(root:Int, edges:List<Pair<Int,Int>>, demands:List<Pair<Int,Int>>):Triple<Int, IntArray, IntArray> {
			val G = makegraph(n,n-1,false){
				for(e in edges) {
					add(e.first, e.second)
				}
			}
			G.root = root
			G.treeOrderDFS(true)
			val components = IntArray(n){-1}
			val sizes = IntArray(n){-1}
			val reduceSize = IntArray(n)
			var compcount = 0
			for((k,x) in demands){
				components[k] = compcount++
				sizes[k] = x
				reduceSize[k] = x
				if(k == root){
					if(total!= null && total != x){
						bad = true
					}
					total = x
				}

			}
			G.rootFirstEdge { from, to, e -> if(components[to] == -1) components[to] = components[from] }
			G.leafFirst { v ->
				if(v == root) return@leafFirst
				val p = G.parent[v]
				if(sizes[p] != -1) {
					sizes[p] -= reduceSize[v]
				} else reduceSize[p] += reduceSize[v]
			}



			val compSizes = IntArray(compcount){-1}
			for(i in 0 until n){
				if(sizes[i] != -1){
					compSizes[components[i]] = sizes[i]
				}
			}
			assert(compSizes.sum() == total)
			return Triple(compcount, compSizes,components)

		}

		val (m1,size1,comp1 ) = getdemands(x,G1,D1)
		val (m2,size2,comp2) = getdemands(y,G2,D2)
		if(bad){
			put(-1)
			return@cases
		}

		val F = FlowModel(m1+m2)
		for(i in 0 until m1){
			F.addEdge(F.s,i,size1[i])
		}
		for(i in 0 until m2){
			F.addEdge(i+m1,F.t, size2[i])
		}
		if(size1.any { it < 0  } || size2.any{it < 0}){
			put(-1)
			return@cases
		}
		for(i in 0 until n){
			F.addEdge(comp1[i],comp2[i] + m1, 1,0,-L[i].toLong())
		}

		val (flow,finalcost) = F.do2()
//		if(n >= 500){
//			put(total!!)
//			put(flow)
//			put(finalcost)
//			just dei size1
//			just dei size2
//		}

		if(flow.toInt() != total){
			put(-1)
		}else{
			put(- finalcost)
		}
//		just dei F.Dinics()
//		put(flow)



    }
    done()
}




/*
varibale swaps
off by 1 still
simple out of bounsd (from ++ )

use 0 , then ++

subtree sum so dumb why
 */