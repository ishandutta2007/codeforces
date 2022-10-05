
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

    fun Dinics():Long {
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
        fun dfs(pos: Int, min: Long): Long {
            val blocked = BooleanArray(n)
            if (pos == t) return min
            var flow = 0L

            for (e in adj[pos]) {
                var cur = 0

                if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {
                    cur = dfs(e.v2, Math.min(min - flow, (e.cap - e.flow).toLong())).toInt()
                    e.flow += cur
                    e.rev!!.flow = -e.flow
                    flow += cur
                }
                if (flow == min) return flow
            }

            blocked[pos] = flow != min
            return flow
        }
        var ret = 0L
        while (bfs()) {
            ret += dfs(s, INFL)
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

const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint

        val F = FlowModel(n+m)

        val L = getline(n)
        for(i in 0 until n){
            F.addEdge(i+m,F.t,L[i])
        }
        var vsum  = 0L
        var wsum = 0L

        for(a in L){
            vsum += a
        }

        repeat(m){
            val x = getint - 1
            val y = getint - 1
            val w = getint
            wsum += w
            F.addEdge(F.s, it, w)
            F.addEdge(it, x+m, plarge)
            F.addEdge(it, y+m , plarge)
        }
//        just dei F.Dinics()
        val f = wsum -  F.Dinics()

        put(f)




    }
    done()
}