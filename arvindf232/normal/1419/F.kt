// 2022.06.07 at 23:43:24 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import kotlin.math.absoluteValue

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


fun List<Int>.sortedDistinctInt():List<Int>{
    val ret = ArrayList<Int>(this.size)
    for(a in this.sorted()){
        if(ret.size == 0 || ret.last() != a){
            ret.add(a)
        }
    }
    return ret
}

class coordinateCompression(things:List<Int>) {
    val forward:List<Int>
    val reverse:MutableMap<Int,Int> = HashMap(things.size / 3 * 4 + 5)

    init{
        forward = things.sortedDistinctInt()
        for((i,v) in forward.withIndex()){
            reverse[v] = i
        }
    }
}

inline fun BinarySearchFirstTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l
    var R = r+1
    while(L < R){
        val m = ((L.toLong() + R) shr 1).toInt()
        if(m == r+1 || isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(L == r+1) null else L
}
inline fun BinarySearchLastTrue(l:Int, r:Int, isTrue:(Int)->Boolean):Int?{
    var L = l-1
    var R = r
    while(L < R){
        val m = ((L + R) shr 1) + 1
        if(m == l-1 || isTrue(m)){
            L = m
        }else{
            R = m - 1
        }
    }
    return if(L == l-1) null else L
}


inline fun BinarySearchExact(value:Int,l:Int,r:Int,find:(Int)->Int):Int?{
    //find shoudl be increasing
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(value <= find(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(find(L) == value){ L}else{null}
}


fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val arr = mutableListOf<Pair<Int,Int>>()
        repeat(n){
            val x = getint
             val y = getint
            arr.add(Pair(x,y))
        }
        val xi = mint
        val yi = mint
        for((x,y) in arr){
            xi.add(x)
            yi.add(y)
        }
        val cx = coordinateCompression(xi)
        val cy = coordinateCompression(yi)
        val board = Array(n){BooleanArray(n)}
        val who = Array(n){IntArray(n){-1} }

        for(i in arr.indices){
            val (a,b) = arr[i]
            val aa = cx.reverse[a]!!
            val bb = cy.reverse[b]!!
            board[aa][bb] = true
            who[aa][bb] = i
        }

        fun attempt(t:Int):Boolean{
            val dsu = DSU_unroll(n+1)
            for(i in 0 until n){
                for(j in i+1 until n){
                    val (a,b) = arr[i]
                    val (c,d) = arr[j]
                    if((a == c && (b - d).absoluteValue <= t) || (b == d && (a - c).absoluteValue <= t)){
                        dsu.union(i,j)
                    }
                }
            }
            val downnext =  Array(n){ x ->IntArray(n){ y -> if(board[x][y]) x else plarge} }
            val rightnext =  Array(n){ x ->IntArray(n){ y -> if(board[x][y]) y else plarge} }
            val topnext =  Array(n){ x ->IntArray(n){ y -> if(board[x][y]) x else nlarge} }
            val leftnext =  Array(n){ x ->IntArray(n){ y -> if(board[x][y]) y else nlarge} }
            for(i in 0 until n) {
                for(j in 0 until n){
                    if(i+1 in 0 until n){
                        topnext[i+1][j] = maxOf(topnext[i+1][j],topnext[i][j])
                    }
                    if(j+1 in 0 until n){
                        leftnext[i][j+1] = maxOf(leftnext[i][j+1],leftnext[i][j])
                    }
                }
            }
            for(i in n-1 downTo 0){
                for(j in n-1 downTo 0){
                    if(i-1 in 0 until n){
                        downnext[i-1][j] = minOf(downnext[i-1][j],downnext[i][j])
                    }
                    if(j - 1 in 0 until n) {
                        rightnext[i][j-1] = minOf(rightnext[i][j-1], rightnext[i][j])
                    }
                }
            }
            val root = n

            val v = dsu.getVersionNumber()
            for(i in 0 until cx.forward.size){
                for(j in 0 until cy.forward.size) {
                    val x1 = downnext[i][j]
                    val x2 = topnext[i][j]
                    val y1 = rightnext[i][j]
                    val y2 = leftnext[i][j]

                    if(x1 in 0 until n && (cx.forward[x1] - cx.forward[i]).absoluteValue <= t ){
                        dsu.union(who[x1][j], root)
                    }
                    if(x2 in 0 until n && (cx.forward[x2] - cx.forward[i]).absoluteValue <= t){
                        dsu.union(who[x2][j], root)
                    }
                    if(y1 in 0 until n && (cy.forward[y1] - cy.forward[j]).absoluteValue <= t ){
                        dsu.union(who[i][y1],root)
                    }
                    if(y2 in 0 until n && (cy.forward[y2] - cy.forward[j]).absoluteValue <= t ){
                        dsu.union(who[i][y2],root)
                    }


                    if(dsu.getsize(0) == n+1){
                        return true
                    }
                    dsu.unrollTo(v)
                }
            }
            for(i in 0 until cx.forward.size) {
                for(j in 0 until cy.forward.size) {
                    if(!board[i][j]) continue
                    if(i in 0 until n-1){
                        val rn = downnext[i+1][j]
                        if(rn in 0 until n && (cx.forward[rn] - cx.forward[i]) <= 2*t){
                            dsu.union(who[i][j], root)
                            dsu.union(who[rn][j],root)
                            if(dsu.getsize(0) == n+1){
                                return true
                            }
                        }
                        dsu.unrollTo(v)
                    }
                    if(j in 0 until n-1){
                        val dn = rightnext[i][j+1]
                        if(dn in 0 until n && (cy.forward[dn] - cy.forward[j]) <= 2*t){
                            dsu.union(who[i][j], root)
                            dsu.union(who[i][dn],root)
                            if(dsu.getsize(0) == n+1){
                                return true
                            }
                        }
                        dsu.unrollTo(v)
                    }

                }
            }
            return false
        }
//        attempt(53)
        val ans = BinarySearchFirstTrue(0,(2.1e9).toInt()){
            attempt(it)
        } ?: -1
        put(ans)




    }
    done()
}
/*

60 minutes bruh


2
0 0
100 0
 */