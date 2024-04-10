// 2022.06.06 at 15:47:36 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 998244353L
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
    operator fun get(v:Int): Int {
        return st[startpointer + v]
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E /= 2
        }else{
            Y = (X * Y) % m
            E -= 1
        }
    }
    return Y
}
class FFT {
    companion object{
//        val fftmod = 7340033
//        val root = 5
//        val root_1 = 4404020
//        val root_pw = 1 shl 20

        private const val maxPower = 18 // 262144
        private const val n = 1 shl maxPower
        public const val fftmod = 998244353
        private const val root = 15311432
        private const val root_1 = 469870224
        private const val root_pw = 1 shl 23

        private val rev = IntArray(n).also { rev ->
            var bit = 1
            var rbit = n shr 1
            while(bit < n) {
                for(i in 0 until bit) {
                    rev[i or bit] = rbit or rev[i]
                }
                bit = bit shl 1
                rbit = rbit shr 1
            }
        }

        fun calculateRoot(){
            println("root :$root")
            //   intPow(3,7 * 17,fftmod)
            println("root_1 : $root_1")
            //       intPow(root,fftmod -2,fftmod)
        }

        fun fft(a:IntArray,invert:Boolean){
            val n = a.size
            kotlin.assert(n <= this.n)

            if(n <= 1) return
            val st = this.n / n
            for(i in 0 until n) {
                val j = rev[i * st]
                if(i < j) a[i] = a[j].also { a[j] = a[i] }
            }

            var len = 2
            while(len <= n){
                var wlen = if(invert) root_1 else root
                var i = len
                while(i < root_pw){
                    wlen = (1L * wlen * wlen % fftmod).toInt()
                    i = i shl 1
                }
                i = 0
                while(i < n){
                    var w = 1
                    for(j in 0 until len/2){
                        val u = a[i+j]
                        val v = (1L * a[i+j+len/2] * w % fftmod).toInt()
                        a[i+j] = if(u+v < fftmod) u + v else u + v - fftmod
                        a[i+j+len/2] = if(u-v >= 0) u-v else u-v+fftmod
                        w = (1L * w * wlen % fftmod).toInt()
                    }
                    i += len
                }
                len = len shl 1
            }
            if(invert){
                val n_1 = pow(n.toLong(),(fftmod-2).toLong(),fftmod.toLong())
                for((i,x) in a.withIndex()){
                    a[i] = (1L * x * n_1 % fftmod).toInt()
                }
            }
        }
        fun fullconvolution(at:IntArray,bt:IntArray):IntArray{
            return fullconvolutionOpt(at,bt,at.size,bt.size)
        }

        fun fullconvolutionOpt(at:IntArray,bt:IntArray,sizeA:Int,sizeB:Int):IntArray{
            // 1 shl 18 done in 77 ms
            val maxSize = (sizeA + sizeB).takeHighestOneBit() * 2
            val a = at.copyOf(maxSize)
            val b = bt.copyOf(maxSize)
            val expectedSize = at.size + bt.size - 1
            fft(a,false)
            fft(b,false)
            for(i in a.indices){
                a[i] = (1L * a[i] * b[i] % fftmod).toInt()
            }
            fft(a,true)
            return a.copyOf(expectedSize)
        }
    }
}
class DisjointUnionSets(val n: Int) {
    companion object{
        val tri = IntArray(1503){(it * (it-1))/2 }
    }
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    val edges:IntArray = IntArray(n){0}
    var components:Int = n

    val successfulUnions:Int get() = n - components

    val DP = Array(n){IntArray(2){it } }
    val where = Array(n){ mutableListOf(it) }
    val updated = fastDeque(0,n)


    fun find(x: Int): Int {
        if (parent[x] != x) {
            parent[x] = find(parent[x])
        }
        return parent[x]
    }

    fun eat(x:Int){
        val r = find(x)
        val s = size[r]
        val e = edges[r]
        if(tri[s] == e){
            var now = IntArray(1){1}
            val process = where[r]
            if(process.size == 1) return
            for(p in process){
                val dp = DP[p]
//                val new = IntArray(now.size + dp.size -1)
//                for(l in now.indices) {
//                    for(r in dp.indices) {
//                        new[l+r] = new[l+r] modPlus (now[l] modM dp[r])
//                    }
//                }
                now = FFT.fullconvolution(now,dp)
            }
            assert(now.size == s + 1)
            now[1] = now[1] modPlus 1
            DP[r] = now
            where[r].clear()
            where[r].add(r)
        }
    }
    fun clean(){
        updated.forEach { v ->
            eat(v)
        }
        updated.reset()
    }

    fun union(x: Int, y: Int):Boolean {
        var xRoot = find(x)
        var yRoot = find(y)
        if (xRoot == yRoot){
            edges[xRoot] ++
            updated.addLast(xRoot)
            return false
        }
        components--
        if(size[xRoot] < size[yRoot]){
            xRoot = yRoot.also { yRoot = xRoot }
        }
        parent[yRoot] = xRoot
        size[xRoot] += size[yRoot]
        edges[xRoot] += edges[yRoot] + 1
        where[xRoot].addAll(where[yRoot])
        updated.addLast(xRoot)
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
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val arr = Array(n){getline(n)}
        val dsu = DisjointUnionSets(n)
        val all = mutableListOf<Triple<Int,Int,Int>>()
        for(i in 0 until n){
            for(j in (i + 1) until n) {
                val v = arr[i][j]
                all.add(Triple(i,j,v))
            }
        }
        all.sortBy { it.third }
        var l = 0
        while(l < all.size){
            val r = (l..all.size).first { it == all.size || all[it].third != all[l].third} - 1
            for(c in l..r){
                val (i,j,_) = all[c]
                dsu.union(i,j)
            }
            dsu.clean()
            l = r + 1
        }
        val final = dsu.DP[dsu.find(0)]
        put(final.slice(1..n).conca())




    }
    done()
}

//1408G
//just find number of atoms
/*
so many bugs in a simple tree dP convolutions

wrong indices, wrong strating conditions ,wrong everything

 */