// 2022.06.25 at 16:08:51 HKT
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
fun debug(){}
const val singleCase = true

class DisjointUnionSets(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    var components:Int = n
    val edges = IntArray(n){0}

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
            edges[xRoot] ++
            return false
        }
        components--
        if(size[xRoot] < size[yRoot]){
            xRoot = yRoot.also { yRoot = xRoot }

        }
        parent[yRoot] = xRoot
        size[xRoot] += size[yRoot]
        edges[xRoot] += edges[yRoot]
        edges[xRoot]++
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


infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
//infix fun Int.modPlus(b:Int):Int{
//    val ans = this + b
//    return if(ans >= pI) ans - pI else ans
//}
infix fun Int.modMinus(b:Int):Int{
    val ans = this - b
    return if(ans < 0) ans + pI else ans
}
infix fun Int.modDivide(b:Int):Int{
    return this modM (b.inverse())
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}

fun intPowEXP(x:Int,e:Long,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0L){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
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
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
fun Int.inverse():Int{
    return intPow(this,pI-2,pI)
}
fun min_rem(m:Int, r:Int, c:Int):Int {
    if(c < 1){
        return Int.MIN_VALUE
    }else if(r == 0){
        return 0
    }else{
        val step = m % r
        val mx = ((1L * c * r) /m ).toInt()
        val t = max_rem(r,step,mx)
        return r- t
    }
}
fun max_rem(m:Int, r:Int, c:Int):Int {
    if(r == 0|| c <= m/r){
        return r * c
    }else{
        val step =  m % r
        val mx = ((1L * (c+1) * r )/m).toInt()
        val t = min_rem(r,step,mx)
        return  m - t
    }
}
fun Int.reconstruct():String{
    val num = min_rem(pI,this, 10000)
    val denom = (this modDivide num).inverse()
    return "$num / $denom"
}

//make this int instead
class FACT{
    companion object {
        var store = IntArray(0)
        var invStore = IntArray(0)

        var slowStore:IntArray = IntArray(0)

        fun preCal(upto:Int){
            store = IntArray(upto+1)
            invStore = IntArray(upto + 1 )
            store[0] = 1
            invStore[0] = 1

            for(i in 1..upto) {
                store[i] = store[i-1] modM i
                invStore[i] = invStore[i-1] modM (i.inverse())
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM (n - i)
            }
            ret = ret modM (invStore[r])
            return ret
        }

    }
}

class FFT {
    companion object{
//        val fftmod = 7340033
//        val root = 5
//        val root_1 = 4404020
//        val root_pw = 1 shl 20

        private const val maxPower = 20 // 262144
        private const val n = 1 shl maxPower
        public const val fftmod = 998244353
        private const val root = 15311432
        private const val root_1 = 469870224
        private const val root_level = 23
        private const val root_pw = 1 shl root_level


        private inline fun normalize(int: Int) = (int shr Int.SIZE_BITS - 1 and fftmod) + int
        infix fun Int.modm(other:Int) = (this.toLong() * other % fftmod).toInt()
        infix fun Int.modplus(other: Int) = normalize(this + other - fftmod) // overflow-safe even if MOD >= 2^30
        infix fun Int.modminus(other: Int) = normalize(this - other)

        val quickpower = Array(maxPower+1){p ->
            val base = intPow(root, 1 shl (root_level - p), fftmod)
            (0 until (1 shl p)).runningFold(1){a,b -> a modm base}.toIntArray()
        }


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
            val level = this.n.countTrailingZeroBits()
            val st = this.n / n
            for(i in 0 until n) {
                val j = rev[i * st]
                if(i < j) a[i] = a[j].also { a[j] = a[i] }
            }

            var len = 2
            var ang = 1 shl (level -1)
            if(invert) ang = -ang
            val pt = quickpower[level]
            while(len <= n){

                var i = 0
                val h = len shr 1
                while(i < n){
                    var k = 0
                    for(j in i until i+h){
                        val u = a[j]
                        val w = pt[k]
                        val v = a[j+h] modm w
                        a[j] = u modplus v
                        a[j+h] = u modminus v
                        k = k + ang and (1 shl level) - 1
                    }
                    i += len
                }
                len = len shl 1
                ang = ang shr 1
            }
            if(invert){
                val n_1 = pow(n.toLong(),(fftmod-2).toLong(),fftmod.toLong())
                for((i,x) in a.withIndex()){
                    a[i] = (x.toLong() * n_1 % fftmod).toInt()
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
                a[i] = (a[i].toLong() * b[i] % fftmod).toInt()
            }
            fft(a,true)
            return a.copyOf(expectedSize)
        }
    }
}
fun IntArray.invertAsPowerseries():IntArray{
    if(this.size <= 1){
        return intArrayOf(this[0].inverse())
    }
    val Aminus = IntArray(this.size){if(it and 1 ==0) this[it] else (this[it]).additiveInverse()}
    val originT = FFT.fullconvolution(this,Aminus)
    val T = IntArray((this.size+1) / 2){originT[it shl 1 ]}
    val got = T.invertAsPowerseries()
    val bettergot = IntArray(this.size){if(it and 1 == 0) got[it shr 1] else 0 }
    val ans =  FFT.fullconvolution(Aminus,bettergot).copyOf(this.size)
    return ans
}
fun main(){
//    just dei (998134075).additiveInverse()
    //112078
//    val first = intArrayOf(1,998134075).copyOf(300001)
//    just dei first.invertAsPowerseries()
//    val random = IntArray(300){Random.nextInt(1..100000)}
//    just dei random.invertAsPowerseries()
    solve.tc {
        share(5)
        share(300000)
        share(300000)
        repeat(5){
            share(60000)
            share(List(60000){Random.nextInt(1..300000)}.conca())
        }
    }
//    solve.usetc()
    solve.cases{
        val n = getint
        val m = getint
        val k = getint
        val next = IntArray(k){-1}
        val dsu = DisjointUnionSets(k)

        val indegree = IntArray(k)
        val outdegree = IntArray(k)
        val edges = mutableSetOf<Pair<Int,Int>>()
        repeat(n){
            val len = getint
            val L = getline(len)
            for(i in L.indices){
                L[i] --
            }
            for(i in 0 until L.lastIndex){
                val from = L[i]
                val to = L[i+1]
//                dsu.union(from,to)
                edges.add(Pair(from,to))
//                outdegree[to] ++
//                indegree[from] ++
            }
        }
        for((from,to)in edges){
            dsu.union(from,to)
            outdegree[to] ++
            indegree[from] ++
        }

        val bad = BooleanArray(k)
        for(i in 0 until k){
            if(indegree[i] > 1 || outdegree[i] > 1){
                bad[dsu.find(i)] = true
            }
        }
        val all = mint

        dsu.eachComponent { r ->
            if(!bad[r] && dsu.edges[r] == dsu.size[r]-1){
                all.add(dsu.size[r])
            }

        }
//        if(m == 300000){
//            just dei all
//        }
//        just dei all
        val beforeinvert = IntArray(m+1)
        beforeinvert[0] = 1
        for(v in all){
            if(v in beforeinvert.indices){
                beforeinvert[v] = beforeinvert[v] modMinus 1
            }
        }

//        just dei beforeinvert
        val final = beforeinvert.invertAsPowerseries()
//        just dei final
//
//        if(m == 300000){
//            just dei beforeinvert.size
//            just dei final.size
//
//            just dei beforeinvert.slice(0..10)
//            just dei final.slice(0..10)
//
//
//        }

        put(final.last())
    }
    done()
}
/*
2 30 3
2 1 2
1 3


1 6 6
6 1 2 1 2 1

1 5 5
5 1 2 3 1 3
1 42000 1337
2 13 31

3 100 4
3 1 2 3
3 2 3 4
2 4 1
 */