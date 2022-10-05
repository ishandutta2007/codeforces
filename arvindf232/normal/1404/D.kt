// 2022.06.05 at 20:16:08 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

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
const val hasunroll = false
class DisjointUnionSets_Parity(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}
    var changeParity = BooleanArray(n)
    var components:Int = n

    val successfulUnions:Int get() = n - components

    fun find(x: Int): Pair<Int,Boolean> {
        if (parent[x] != x) {
            val result = find(parent[x])
            return Pair(result.first, changeParity[x] xor result.second)
        }
        return Pair(x,false )
        // base is 0 - false
    }

    fun union(x: Int, y: Int,dif:Boolean):Boolean {
//        printAll()
//        just dei "$x $y $dif"
        // return inconsistent
        val xRoot = find(x)
        val yRoot = find(y)

        if (xRoot.first == yRoot.first){
            val now = xRoot.second xor yRoot.second
            if(now != dif){
                return false
            }
            return true
        }
        components--
        val xx = xRoot.first
        val yy = yRoot.first
        val overdif = dif xor xRoot.second xor yRoot.second
        if(size[xx] < size[yy]){
//            parent[xx] = yy
//            size[yy] += size[xx]
//            changeParity[xx] = overdif
            set(xx,yy,xx,yy,size[xx] + size[yy], overdif)
        }else{
            set(yy,xx,yy,xx,size[xx] + size[yy], overdif)
//            parent[yy] = xx
//            size[xx] += size[yy]
//            changeParity[yy] = overdif
        }
        return true
    }

    var v = -1
    val memorystack = if(hasunroll) n else 0
    val vs1 = IntArray(memorystack)
    val vs2 = IntArray(memorystack)
    val vs3 = IntArray(memorystack)
    val oldparent = IntArray(memorystack)
    val oldsize = IntArray(memorystack)
    val oldparity = BooleanArray(memorystack)

    fun set(v1:Int, v2:Int, v3:Int, newparent:Int, newsize:Int, newparity:Boolean){
//        v++
//        vs1[v] = v1
//        vs2[v] = v2
//        vs3[v] = v3
//        oldparent[v] = parent[v1]
//        oldsize[v] = size[v2]
//        oldparity[v] = changeParity[v3]

        parent[v1] = newparent
        size[v2] = newsize
        changeParity[v3] = newparity
    }
    fun getversion(): Int {
        return v
    }
    fun setToversion(ver:Int){
        while(v > ver){
            parent[vs1[v]] = oldparent[v]
            size[vs2[v]] = oldsize[v]
            changeParity[vs3[v]] = oldparity[v]
            v --
        }
    }
//    fun getsize(a:Int):Int{
//        return size[find(a)]
//    }

    fun printAll(){
        println((0 until n).joinToString { find(it).toString() })
    }

//    fun printAll(){
//        val comps = Array(n){ mutableListOf<Int>()}
//        for(i in 0 until n){
//            comps[find(i)].add(i)
//        }
//        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
//    }
}
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        if(n %2 == 0){
            println("First")
            val doit = mint
            for(i in 1.. n){
                doit.add(i)
            }
            for(i in 1.. n){
                doit.add(i)
            }
            println(doit.conca())
            System.out.flush()
        }else{
            println("Second")
            System.out.flush()
            val dsu = DisjointUnionSets_Parity(2 * n)
            val L = IntArray(2 * n + 1){if(it ==0) nlarge else getint }
            L[0] = L[2 *n]

            val other = IntArray(n+1)
            for(i in 0 until n) {
                dsu.union(i, i+n, true)
            }
            for((i,a) in L.withIndex()){
                if(i == 2 * n )continue
                if(other[a] == 0){
                    other[a] = i
                }else{
                    val ot = other[a]
                    dsu.union(i,ot,true)
                }
            }
            val attempt1 = BooleanArray(2 * n){dsu.find(it).second}
            var got = 0L
            for(i in 0 until 2 *n){
                if(attempt1[i]){
                    got += i
                }
            }
            if((got % (2 * n) != 0L )){
                assert((got % (2 * n) == n.toLong()))
                val firstroot = (0 until 2*n).first { dsu.parent[it] == it && dsu.size[it] % 4 == 2 }
                for(i in 0 until 2 * n){
                    if(dsu.find(i).first == firstroot){
                        attempt1[i] = !attempt1[i]
                    }
                }
            }
            val ret = mint
            for(i in 0 until 2 * n){
                if(attempt1[i]){
                    ret.add(if(i == 0) 2 * n else i)
                }
            }
            println(ret.conca())
            System.out.flush()
        }




    }
    done()
}



/*
015
024
135
123
345


0 1, 2 3


way way more than enough bruh

15 23 04

04
15

01
45

2
13
04


5

1 2 2 1 3 5 4 5 4 3

 */