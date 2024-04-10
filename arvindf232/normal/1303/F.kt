// 2022-05-20, Fri, 21:29
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

    fun union(x: Int, y: Int):Boolean {
        val xRoot = find(x)
        val yRoot = find(y)
        if (xRoot == yRoot) return false
        if(size[xRoot] < size[yRoot]){
            set(xRoot,yRoot,yRoot,size[xRoot] + size[yRoot])
        }else{
            set(yRoot,xRoot,xRoot,size[xRoot] + size[yRoot])
        }
        return true
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
class tempIntervalSum(val n:Int){
    val things = IntArray(n + 1)

    fun add(l:Int,r:Int,inc:Int){
        val ll = if(l < 0 ) 0 else l
        val rr = if(r > n-1) n else r + 1
        if(ll > rr) return
        things[ll] += inc
        things[rr] -= inc
        things[ll] = things[ll].adjust()
        things[rr] = things[rr].adjust()
    }
    fun compile():IntArray{
        val ret = IntArray(n)
        var here = 0
        for(i in 0 until n){
            here += things[i]
            here = here.adjust()
            ret[i] = here
        }
        return ret
    }
}

fun debug(){}
class event(val x:Int, val y:Int, val t:Int, val add:Boolean){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val q = getint

        val dsu = DSU_unroll(n * m)
        fun code(i:Int, j:Int):Int{
            return i * m + j
        }
        val maxcolour = maxOf(1000,(2_000_000.0 / n /m).toInt()) + 5
        val queryBins = Array(maxcolour){ mutableListOf<event>() }
        val board = Array(n){IntArray(m)}
        fun process(e:event,v:Int){
            queryBins[v].add(e)
        }
        for(i in 0 until n){
            for(j in 0 until m){
                queryBins[0].add(event(i,j,0,true))
            }
        }

        repeat(q){oldt ->
            val t = oldt + 1
            val x = getint - 1
            val y = getint - 1
            val v = getint
            if(board[x][y] != v){
                process(event(x,y,t,false),board[x][y])
                board[x][y] = v
                process(event(x,y,t,true),v)
            }
//            just dei board

        }

        for(i in 0 until n){
            for(j in 0 until m){
                queryBins[board[i][j]].add(event(i,j,q+1,false))
            }
        }
        var last = 0
        val templates = IntArray(n * m)
        fun clearstore(){
            last ++
        }
        fun enable(i:Int, j:Int){
            templates[code(i,j)] = last
        }
        fun same(i:Int, j:Int):Boolean {
            if(i in 0 until n && j in 0 until m){
                return templates[code(i,j)] == last
            }
            return false
        }

        val st = tempIntervalSum(q+2)
//        just dei "WRONG"
        var version = dsu.getVersionNumber()
        for(c in 0 until maxcolour){
            if(queryBins[c].isEmpty()) continue
            val cut = queryBins[c].first { !it.add }.t -1
//            val st = tempIntervalSum(q+2)
            var points = 0
            var unions = 0
            var compnow = 0
            clearstore()
            for(q in queryBins[c]){
                if(!q.add) break
                val x = q.x
                val y = q.y
                points ++
                val here = code(x,y)
                enable(x,y)
                if(same(x-1,y)){
                    unions += dsu.union(here, code(x-1,y)).chi
                }
                if(same(x+1,y)){
                    unions += dsu.union(here, code(x+1,y)).chi
                }
                if(same(x,y+1)){
                    unions += dsu.union(here, code(x,y+1)).chi
                }
                if(same(x,y-1)){
                    unions += dsu.union(here, code(x,y-1)).chi
                }
                val newcomp = points - unions

//                c dei "$points $unions"
                st.add(q.t,cut,newcomp - compnow)
                compnow = newcomp
            }
//            c dei st.compile()
            dsu.unrollTo(version)
            clearstore()
            points = 0
            unions = 0
            compnow = 0
            for(q in queryBins[c].asReversed()){
                if(q.add) break
                val x = q.x
                val y = q.y
                points ++
                enable(x,y)
                val here = code(x,y)
                if(same(x-1,y)){
                    unions += dsu.union(here, code(x-1,y)).chi
                }
                if(same(x+1,y)){
                    unions += dsu.union(here, code(x+1,y)).chi
                }
                if(same(x,y+1)){
                    unions += dsu.union(here, code(x,y+1)).chi
                }
                if(same(x,y-1)){
                    unions += dsu.union(here, code(x,y-1)).chi
                }
                val newcomp = points - unions
                st.add(cut+1 , q.t - 1 ,newcomp - compnow)
                compnow = newcomp
            }
            dsu.unrollTo(version)
//            c dei st.compile()
        }
        val cc = st.compile()
        for(i in 1..q){
            put(cc[i])
        }




    }
    done()
}
/*
faces are crazy hard to detect
crazxy hard

12 minutes down the drain
not that bad
 */