// 2022.07.29 at 19:18:03 HKT
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
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
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

val Int.c2:Long get() = ((this.toLong()) * (this + 1) )/2
class interval_tree_disjoint {
    val st = TreeMap<Int, Int>()

    var sum = 0L


    fun add(l: Int, r: Int) {
        val left = st.floorEntry(l)
        var ll = l
        var rr = r
        if(left != null && left.value >= l - 1){
            st.remove(left.key)
            val len = left.value - left.key + 1
            sum -= len.c2
            ll = minOf(ll, left.key)
            rr = maxOf(rr, left.value)
        }
        while(true){
            val right = st.floorEntry(r+1)
            if(right == null || right.key < l- 1){
                break
            }else{
                st.remove(right.key)
                sum -= (right.value - right.key + 1).c2
                ll = minOf(ll,right.key)
                rr = maxOf(rr, right.value)
            }
        }
        st[ll] = rr
        sum += (rr - ll + 1).c2
    }
    fun delete(l:Int, r:Int){
        add(l,r)
        val left = st.floorEntry(l)!!
        st.remove(left.key)
        sum -= (left.value - left.key + 1).c2

        val ll = left.key
        val rr = left.value
        if(ll < l){
            st[ll] = l- 1
            sum += (l-1-ll + 1).c2
        }
        if(rr > r){
            st[r+1] = rr
            sum += (rr - (r+1) + 1).c2
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
fun debug(){}
const val singleCase = true
fun main(){


//    val S = interval_tree_disjoint()
//    for(i in 1..3){
//        S.add(i,i)
//    }
//    just dei S.sum
//
//    S.delete(2,2)
//    just dei S.sum

    solve.cases{

        val n = getint
        val m = getint
        val q = getint

        var total = 0L

        // i -j
        val st = Array(10000){interval_tree_disjoint()}

        fun alter(x:Int, y:Int, adding:Boolean){
            total -= st[5000 + x - y].sum
            total -= st[5000 + x - y + 1 ].sum
            if(adding){
                st[5000 + x - y].add(x+y,x+y)
                st[5000 + x - y+1].add(x+y,x+y)
            }else{
                st[5000 + x - y].delete(x+y,x+y)
                st[5000 + x - y+1].delete(x+y,x+y)
            }
            total += st[5000 + x - y].sum
            total += st[5000 + x - y + 1 ].sum
        }

        val rm = IntArray(10000){plarge }
        val rmax = IntArray(10000){nlarge}
        for(i in 0 until n){
            for(j in 0 until m){
                val d = 5000 + i - j
                rm[d] = minOf(rm[d], i + j )
                rmax[d] = maxOf(rm[d], i+j)
                rm[d+1] = minOf(rm[d+1], i + j )
                rmax[d+1] = maxOf(rm[d+1], i+j)
            }
        }

        for(d in 0 until 10000){
            val l = rm[d]
            val r = rmax[d]
            if(l > r) continue
            st[d].add(l,r)
            total += st[d].sum
        }
//        just dei total

        var activecells = n * m

        val now = Array(n){BooleanArray(m){true} }
        repeat(q){
            val i = getint - 1
            val j = getint - 1
            val adding = !now[i][j]
            now[i][j] = !now[i][j]

            alter(i,j,adding)
            if(adding){
                activecells ++
            }else{
                activecells --
            }
            put(total - activecells)


        }
        val z = 0





    }
    done()
}