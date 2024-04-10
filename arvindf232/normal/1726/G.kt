// 2022.10.06 at 15:49:24 BST
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

// 1. Modded
const val p = 998244353L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.mm(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.mp(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
infix fun Int.ms(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this mm (b.inverse()) }
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
// 3. convenience conversions
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
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
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun eat(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>()}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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
const val just = " "
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

typealias SI = Int
typealias SA = IntArray

const val sumactive = true
const val minactive = false
const val maxactive = false

const val rangeAdd = false
const val rangeMul = false
const val rangeSet = false



val Int.Companion.zero get() = 0
val Long.Companion.zero get() = 0L
inline fun Int.Companion.convert(v:Int):Int{ return v }
inline fun Long.Companion.convert(v:Int):Long{ return v.toLong()}
const val push = rangeAdd || rangeMul || rangeSet
class ST(nSuggest:Int) {

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val len = n * 2 + 1

    inline val Int.left get() = (this shl 1)
    inline val Int.right get() = (this shl 1) + 1
    inline val Int.level get() = levels + this.countLeadingZeroBits() - 31


    val sum = SA(if(sumactive) len else 0  )
    val min = SA(if(minactive) len else 0 )
    val max = SA(if(maxactive) len else 0 )


    val radd = SA(if(rangeAdd) len else 0 )

    val rset = SA(if(rangeSet) len else 0 )
    val setactive = BooleanArray(if(rangeSet) len else 0)

    //Constructor
    constructor(withArray:SA):this(withArray.size){
        for(i in withArray.indices){
            justSetValue(i,withArray[i])
        }
        updateAll()
    }
    constructor(nSuggest: Int, v:SI):this(nSuggest){
        for(i in 0 until n){
            justSetValue(i,v)
        }
        updateAll()
    }


    //Key functions
    fun justSetValue(i:Int, v:SI){
        if(sumactive){ sum[n+i] = v }
        if(minactive){ min[n+i] = v}
        if(maxactive){ max[n+i] = v}
    }
    fun realget(i:Int):SI{
        //assume pushed
        if(sumactive){return sum[n+i]}
        else if(minactive){return min[n+i]}
        else if(maxactive){return max[n+i]}
        return SI.MIN_VALUE
    }
    private fun updateNode(i:Int){
        if(rangeSet){
            if(setactive[i]){
                if(sumactive) sum[i] = rset[i] * (1 shl i.level)
                if(minactive) min[i] = rset[i]
                if(maxactive) max[i] = rset[i]
                return
            }
        }
        if(sumactive) sum[i] = sum[i.left] + sum[i.right]
        if(minactive) min[i] = minOf(min[i.left], min[i.right])
        if(maxactive) max[i] = maxOf(max[i.left], max[i.right])
        if(rangeAdd){
            if(sumactive) sum[i] += radd[i] * (1 shl i.level)
            if(minactive) min[i] += radd[i]
            if(maxactive) max[i] += radd[i]
        }
    }
    fun push(i:Int){
        if(rangeAdd){
            val v = radd[i]
            nodeadd(i.left,v)
            nodeadd(i.right,v)
            radd[i] = SI.zero
        }
        if(rangeSet){
            if(setactive[i]){
                nodeset(i.left, rset[i])
                nodeset(i.right,rset[i])
                setactive[i] = false
            }
        }
    }


    //Basic updates
    fun set(i:Int,v:SI){
        if(push) pushPath(i+n)
        justSetValue(i,v)
        updatePath(n+i)
    }
    fun add(i:Int, v:SI){
        if(push) pushPath(i+n)
        justSetValue(i,realget(i)+v)
        updatePath(n+i)
    }
    fun consider(i:Int, v:SI){
        if(push) pushPath(i+n)
        val new = if(minactive) minOf(realget(i),v) else maxOf(realget(i),v)
        justSetValue(i,new)
        updatePath(n+i)
    }
    fun nodeset(x:Int, newvalue:SI){
        if(maxactive) max[x] = newvalue
        if(minactive) min[x] = newvalue
        if(sumactive) sum[x] = newvalue * (1 shl x.level)
        if(x < n) {
            rset[x] = newvalue
            setactive[x] = true
            if(rangeAdd){
                radd[x] = 0
            }
        }
    }
    fun nodeadd(x:Int, inc:SI){
        if(maxactive) max[x] += inc
        if(minactive) min[x] += inc
        if(sumactive) sum[x] += inc * (1 shl x.level)
        if(x < n) {
            if(rangeSet){
                if(setactive[x]){
                    rset[x] += inc
                }else{
                    radd[x] += inc
                }
            }else{
                radd[x] += inc
            }
        }
    }


    //Group Updates
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    private fun pushPath(i:Int){
        // i must be in [n,2n)
        for(s in levels downTo 1){
            push(i shr s)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun pushAll(){
        for(i in 1..n-1){
            push(i)
        }
    }


    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                act(left,level)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                act(right,level)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
    }

    fun rangeSet(l:Int, r:Int, new:SI){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(l > r) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,_ ->
            nodeset(i,new)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeAdd(l:Int, r:Int, new:SI){
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(l > r) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,_ ->
            nodeadd(i,new)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun sumQuery(l:Int, r:Int):SI{
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(l > r) return SI.zero
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.convert(0)
        segDivision(l,r){i,_ -> ret += sum[i]}
        return ret
    }
    fun minQuery(l:Int, r:Int):SI{
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(l > r) return SI.MAX_VALUE
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.MAX_VALUE
        segDivision(l,r){i,_ -> ret = minOf(ret,min[i])}
        return ret
    }
    fun maxQuery(l:Int, r:Int):SI{
        val l = maxOf(l,0)
        val r = minOf(r, n-1)
        if(l > r) return SI.MIN_VALUE
        if(push){
            pushPath(l+n)
            pushPath(r+n)
        }
        var ret = SI.MIN_VALUE
        segDivision(l,r){i,_ -> ret = maxOf(ret,max[i])}
        return ret
    }
    fun globalMax():SI{ return max[1]}
    fun globalMin():SI{ return min[1]}
    fun globalSum():SI{ return sum[1]}

    //descends
    fun sumdescent(req:SI, i:Int = 1):Int{
        if(req >= sum[i]) throw IndexOutOfBoundsException()
        if(req < SI.zero) return -1
        var req = req
        var i = i
        while(i < n){
            if(push) push(i)
            i = i shl 1
            if(req >= sum[i]){
                req -= sum[i]
                i ++
            }
        }
        return i - n
    }
    fun maxdescent(i:Int = 1, want:SI?):Int{
        val want = want ?: max[i]  // assume already pushed
        if(max[i] < want) return -1
        var i = i
        while(i  < n){
            if(push) push(i)
            i = i shl 1
            if(max[i] < want){
                i++
            }
        }
        return i - n
    }
    fun mindescent(i:Int = 1, want:SI?):Int{
        val want = want ?: min[i]  // assume already pushed
        if(min[i] > want) return -1
        var i = i
        while(i  < n){
            if(push) push(i)
            i = i shl 1
            if(min[i] > want){
                i++
            }
        }
        return i - n
    }


    fun compile():SA{
        if(push) pushAll()
        return SA(n){realget(it)}
    }
    //debug
    override fun toString(): String {
        return compile().joinToString(" ")
    }
}


class multiset(val st: TreeMap<Int, Int> = TreeMap()):MutableMap<Int,Int> by st {
    fun addall(a:IntArray){
        for(v in a) addone(v)
    }
    fun addall(a:List<Int>){
        for(V in a) addone(V)
    }
    fun addone(v:Int){
        st[v] = st.getOrDefault(v,0) + 1
    }
    fun removeone(v:Int):Boolean{
        val new = st.getOrDefault(v,0) - 1
        if(new == -1) return false
        if(new > 0) st[v] = new else st.remove(v)
        return true
    }
    fun pollLast():Int {
        val a = st.lastKey()
        removeone(a)
        return a
    }
    fun pollFirst():Int{
        val a = st.firstKey()
        removeone(a)
        return a
    }
    fun makelist():List<Int>{
        val ret = mutableListOf<Int>()
        for((k,v) in st){
            repeat(v){
                ret.add(k)
            }
        }
        return ret
    }
}


infix fun Long.modM(b:Long):Long{
    return (this * b) % p
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
                store[i] = store[i-1] mm i
            }
            invStore[upto] = store[upto].inverse()
            for(i in upto-1 downTo 1){
                invStore[i] = invStore[i+1] mm (i+1)
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a mm b) mm c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret mm (n - i)
            }
            ret = ret mm (invStore[r])
            return ret
        }

    }
}
const val singleCase = true
fun main(){
    FACT.preCal(400005)
    solve.cases{
        val n = getint
        val A = getline(n)
        val B = getline(n)

        val st = ST(2 * n + 3)
        for(a in A){
            st.add(a,1)
        }

//        val target = A.maxOrNull()!!
//        val want = mutableListOf<Pair<Int,Int>>() // before

        val up = multiset()
        val down = multiset()
//        var free = 0
        for(i in 0 until n){
            if(B[i] ==1){
                up.addone(A[i])
            }else{
                down.addone(A[i])
            }
        }
//        var res = 0
//        var ret = 1
        val stuff = A.toSet().toList().sorted()

        var atleast = nlarge
        var atmost = plarge
        for(v in stuff){
            val a = up.st.getOrDefault(v,0)
            val b = down.st.getOrDefault(v,0)
            if(b > 0){
                val rn = st.sumQuery(0,v -1 )
                atleast = maxOf(atleast, v)
                atmost = minOf(atmost, rn + v)
            }
            if(a > 1){
                atleast = maxOf(atleast, v)
                atmost = minOf(atmost, v)
            }else if(a == 1){
                val rn = st.sumQuery(0,v) - 1
//                target <= n - 1 + v
//                n- 1 + v -rn <= target
                atleast = maxOf(atleast, n-1+v -rn)
                atmost = minOf(atmost,n-1+v)
            }
        }
        var base = 1
        for(x in down.values){
            base = base mm FACT.store[x]
        }
        var ret = 0
        for(v in atleast..atmost){
            val free = up.getOrDefault(v,0)
            ret = ret mp (base mm FACT.choose(n,free) mm FACT.store[free])
        }
        put(ret)
//
//        for(v in stuff){
////            val v = want.last().first
//            val a = up.st.getOrDefault(v,0)
//            val b = down.st.getOrDefault(v,0)
//
////            v dei "$a $b"
//
//            val S = multiset()
//
//
////            repeat(b){
//            val rn = st.sumQuery(0,v -1 )
//            if(b > 0) {
////                val success = target - v
//                if(target !in v..rn+v) {
//                    put(0)
//                    return@cases
//                }
//            }
//            ret = ret mm FACT.store[b]
//            res += b
////                S.addone(success)
////            }
////            for(v in S.values){
////                ret = ret mm FACT.store[v]
////                res += v
////            }
//
//
//            if(v != target){
//                if(a > 1){
//                    put(0)
//                    return@cases
//                }
//                repeat(a){
//                    val nres = st.sumQuery(0,v) - 1
//                    if(n - 1 + v - target !in 0..nres) {
//                        put(0)
//                        return@cases
//                    }
////                    S.addone(fails)
//                }
//                res += a
//            }else{
//                free += a
//            }
//        }
//        put(ret mm FACT.choose(n,free) mm FACT.store[free])




    }
    done()
}



/*


5
1 2 2 4 4
1 1 1 0 0
 */