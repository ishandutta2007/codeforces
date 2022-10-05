// 2022.07.15 at 16:02:40 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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

class shortcut(val x:Int, val y:Int){

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
data class bad(val xn:Int, val yn:Int, val len:Int){

}
class interval_tree_disjoint {
    val st = TreeMap<Int, Int>()

    fun add(l: Int, r: Int) {
        val left = st.floorEntry(l)
        var ll = l
        var rr = r
        if(left != null && left.value >= l - 1){
            st.remove(left.key)
            ll = minOf(ll, left.key)
            rr = maxOf(rr, left.value)
        }
        while(true){
            val right = st.floorEntry(r+1)
            if(right == null || right.key < l- 1){
                break
            }else{
                st.remove(right.key)
                ll = minOf(ll,right.key)
                rr = maxOf(rr, right.value)
            }
        }
        st[ll] = rr
    }
    fun delete(l:Int, r:Int){
        add(l,r)
        val left = st.floorEntry(l)!!
        st.remove(left.key)
        val ll = left.key
        val rr = left.value
        if(ll < l){
            st[ll] = l- 1
        }
        if(rr > r){
            st[r+1] = rr
        }
    }
    fun keeponly(l:Int, r:Int){
        while(true){
            val left = st.floorEntry(l-1) ?: break
            if(left.value >= l){
                st[l] = left.value
            }
            st.remove(left.key)
        }
        while(true){
            val right = st.ceilingEntry(r+1) ?: break
            st.remove(right.key)
        }
        val left = st.floorEntry(r) ?: return
        if(left.value > r){
            st[left.key] = r
        }
    }
    fun contains(pt:Int): Boolean {
        val left = st.floorEntry(pt) ?: return false
        return pt in (left.key .. left.value)
    }
    fun growby1(){
        val stuff = st.toList()
        for((a,b) in stuff){
            add(a-1,b+1)
        }
    }

    fun print(){
        println(st.map { "${it.key} ${it.value}" }.joinToString())
    }

}
class query(val x:Int, val y:Int){}
fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val m = getint
        val n = getint

        val cuts = MutableList(m){shortcut(getint, getint )}
        val Qs = List(n){query(getint ,getint)}
        cuts.add(shortcut(plarge,plarge))

        val xx = mint
        val yy = mint
        for(c in cuts){
            xx.add(c.x)
            yy.add(c.y)
        }


        var xn = -1
        var yn = -1

        val earliestX = TreeMap<Int,Int>()
        val earliestY = TreeMap<Int,Int>()
        for(c in cuts){
            earliestY[c.x] = minOf(earliestY.getOrDefault(c.x, plarge), c.y)
            earliestX[c.y] = minOf(earliestX.getOrDefault(c.y,plarge),c.x)
        }
        val bads = mutableListOf<bad>()
        while(true) {
            val dif = minOf(earliestY.higherKey(xn)?.minus(xn) ?: plarge, earliestX.higherKey(yn)?.minus(yn) ?: plarge)
//            val dif = minOf(if(xlist.isEmpty()) plarge else xlist.first() - xn, if(ylist.isEmpty()) plarge else ylist.first() - yn)
            if(dif == plarge) break
            val next = if(dif == 1) 1 else dif - 1
            xn += next
            yn += next
            var havex = false
            var havey = false
            if(earliestX[yn] != null && earliestX[yn]!! < xn){
                havex = true
            }
            if(earliestY[xn] != null && earliestY[xn]!! < yn){
                havey = true
            }
            if(havex && !havey){
                xn --
            }else if(havey && !havex){
                yn --
            }else if(!havex && !havey){
                bads.add(bad(xn-next+1, yn - next+1, next))
            }else if(havex && havey){
                continue
            }
        }

        for(c in cuts){
            bads.add(bad(c.x, c.y, 1))
        }

//        val badboard = Array(10){BooleanArray(10)}
//        for(b in bads){
//            for(i in 0 until b.len){
//                if(b.xn + i !in 0 until 10 || b.yn + i !in 0 until 10) break
//                badboard[b.xn + i] [b.yn +i] = true
//            }
//        }
//        just dei badboard


        val badbins = mutableMapOf<Int,interval_tree_disjoint>()
        for(b in bads){
            val d = b.yn - b.xn
            if(badbins[d] == null){
                badbins[d] = interval_tree_disjoint()
            }
            badbins[d]!!.add(b.xn, b.xn + b.len - 1)
        }
        for(q in Qs){
            val d = q.y - q.x
            if(badbins[d] == null){
                put("WIN")
                continue
            }else{
                val st = badbins[d]!!
                if(st.contains(q.x)){
                    put("LOSE")
                }else{
                    put("WIN")
                }
                continue
            }
        }


    }
    done()
}



/*
1 0
4 7
 */