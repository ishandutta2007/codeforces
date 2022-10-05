import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
//import kotlin.collections.ArrayDeque
import kotlin.system.measureTimeMillis
import java.util.*
import java.util.ArrayDeque
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}class FlowEdge(var v1: Int, var v2: Int, var cap: Int, var flow: Int, var cost:Long = 0L, var lowerDemand:Int = 0, isreal:Boolean ) {
    var rev: FlowEdge? = null
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
        val q = java.util.ArrayDeque<Int>()

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
            val q = java.util.ArrayDeque<Int>()
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
            while(i > 0){
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

const val singleCase = true
fun main(){
    solve.cases{
        val n= getint()
         val A = getline(3)
        val B = getline(3)

        fun solve(type:Int):Long? {
            val G = FlowModel(6)
            for(i in 0 until 3){
                G.addEdge(G.s,i,A[i],0,0,0)
                G.addEdge(i+3,G.t,B[i],0,0,0)
            }
            for(i in 0 until 3){
                for(j in 0 until 3){
                    val win = ((i+1) %3 == j)
                    val draw = i == j
                    val lose = i == (j+1) %3
                    val cost = if(win) type else 0
                    G.addEdge(i,j+3,n,0,cost.toLong(),0  )
                }
            }
            return G.minCostFlow(n)
        }
        put(solve(1)!!)
        put(- solve(-1)!!)







    }
    done()
}