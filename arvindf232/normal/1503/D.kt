// 2022-04-30, Sat, 15:46
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
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
class simpleMaxTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val void = Int.MIN_VALUE

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = IntArray(n * 2 + 1 ){void}
    val arrSize = n * 2 + 1

    constructor(withArray:IntArray):this(withArray.size){
        for(i in withArray.indices){
            arr[i+n] = withArray[i]
        }

        updateAll()
    }

    private fun updateNode(i:Int){
        arr[i] = maxOf(arr[i shl 1] , arr[(i shl 1) + 1])
    }
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun setValue(i:Int,value:Int){
        arr[n+i] = value
        updatePath(n+i)
    }
    fun addValue(i:Int, inc:Int){
        arr[n+i] += inc
        updatePath(n+i)
    }

    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex


    fun primitiveIndex(a:Int) = a + n
    inline fun segmentOrder(act:(here:Int, left:Int,right:Int)->Unit ){
        //iterate over all segments bottom up, probably to rebuild tree
        for(i in (n-1) downTo 1){
            act(i, (i shl 1 ), (i shl 1) + 1)
        }
    }
    inline fun primitiveOrder(act:(here:Int,primitiveIndex:Int)->Unit){
        //iterate over all the leaf nodes
        for(i in 0 until n){
            act(i+n,i)
        }
    }


    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
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

    fun queryFunctional(l:Int,r:Int):Int{
        var ret = void
        segDivision(l,r){i, _ ->
            ret = maxOf(ret,arr[i])
        }
        return ret
    }
    fun indexOf(req:Int):Int{
        // -1 if not enough
        val req = req + 1
        if(req > arr[1]){
            throw IndexOutOfBoundsException()
        }else if(req <= 0 ){
            return -1
        }
        var i = 1
        var rightPoint = -1
        var cur = 0
        for(l in 1..levels){
            i = i shl 1
            if(cur + arr[i] < req){
                rightPoint += 1 shl (levels - l)
                cur += arr[i]
                i += 1
            }
        }
        return rightPoint +1
    }
    val Int.leftNode:Int get(){
        // assert(this <= n )
        return this shl 1
    }
    val Int.rightNode:Int get(){
        // assert(this <= n)
        return (this shl 1) + 1
    }
    val Int.endpoints:Pair<Int,Int> get(){
        val offSet = this - this.takeHighestOneBit()
        val widthLevel = levels - (31 - this.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }
}
typealias CSTkeytype = Int
class CST(val key:CSTkeytype,var value:Int = empty){
    // see https://codeforces.com/blog/entry/83170
    var left:CST? = null
    var right:CST? = null


    var vstore:Int = empty


    fun calculateV(){
        vstore = combine(value, combine(left?.vstore ?: empty, right?.vstore ?: empty))
    }

    fun query(lo:CSTkeytype, hi:CSTkeytype, L:CSTkeytype = min , R:CSTkeytype = max):Int{
        if(hi < L || R < lo) return empty
        if(lo <= L && R <= hi) return vstore
        val M = (L+R) shr 1
        var ans = empty
        if(left != null) ans = combine(ans,left!!.query(lo,hi,L,M))
        if(right != null) ans = combine(ans,right!!.query(lo,hi,M+1, R))
        if(key in lo..hi) ans = combine(ans,value)
        return ans
        //        var base = combine(left?.query(lo,hi,L,M) ?: empty, right?.query(lo,hi,M+1, R) ?: empty)
    }

    companion object{
        const val empty = plarge
        //pay attention , is long!
        const val min:CSTkeytype = 0
        const val max:CSTkeytype = 1 shl 18
        fun insert(root:CST?, i:CSTkeytype, v:Int):CST?{
            return merge(root,CST(i,v) ,min,max)
        }
        fun combine(a: Int, b: Int): Int {
            return minOf(a,b)
        }

        fun merge(T1:CST? , T2:CST?, l:CSTkeytype, r:CSTkeytype):CST?{
            if(T1 == null) return T2
            if(T2 == null) return T1
            val m = (l + r) shr 1
            var T1:CST  = T1
            var T2:CST = T2
            if(T1.key > T2.key){
                T1 = T2.also { T2 = T1 }
            }
            T1.left = merge(T1.left, T2.left, l,m)
            T1.right = merge(T1.right, T2.right, m+1, r)
            T2.left = null
            T2.right = null
            T2.calculateV()

            if(T1.key != T2.key){
                if(T2.key > m){
                    T1.right = merge(T1.right, T2, m+1,r)
                }else{
                    T1.left = merge(T1.left,T2,l,m)
                }
            }else{
                T1.value = combine(T1.value,T2.value)
            }
            T1.calculateV()
            return T1
        }
    }
    fun printall():TreeMap<Int, Int> {
        val ret = TreeMap<Int,Int>()
        ret[key] = value
        if(left != null) ret.putAll(left!!.printall())
        if(right != null) ret.putAll(right!!.printall())
        return ret
    }
}
class CSThandler(){
    var root:CST? = null
    fun query(l:CSTkeytype, r:CSTkeytype): Int {
        return root?.query(l,r) ?: CST.empty
    }
    fun add(i:CSTkeytype ,v:Int){
        root = CST.insert(root, i, v)
    }
    fun print(){
        if(root == null){
            println("Empty CST")
            return
        }
        println()
        for((i,v) in root!!.printall()){
            println("$i : $v")
        }
    }
}

fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val A = Array(n){IntArray(2){getint - 1 } }
        val alternate = IntArray(n)
        val flipped = BooleanArray(n)
        for(c in A) {
            val mini = minOf(c[0],c[1])
            if(mini >= n){
                put(-1)
                return@cases
            }
            val other = if(c[0] == mini) c[1] else c[0]
            alternate[mini] = other
            flipped[mini] = c[0] != mini
        }
        // must use potentials, no way around
        var st0 = CSThandler()
        var st1 = CSThandler()
        var last = n
        var p0 = 0
        var p1 = 0
        st0.add(n,0)
        st1.add(n,0)
        for((i,a) in alternate.withIndex()){
            val a = a - n
            val best1 = st0.query(a,n) + p0
            val best0 = st1.query(a,n) + p1

            if(a > last){
                st0 = CSThandler()
                st1 = CSThandler()
            }
            st0.add(last,best0 - p0)
            st1.add(last,best1 - p1)
            p0 += flipped[i].chi
            p1 += (!flipped[i]).chi
            last = a

//            println("st0")
//            st0.print()
//            println("st1")
//            st1.print()
        }
        val c1 = st0.query(0,n+1) + p0
        val c2 = st1.query(0,n+1) + p1
        val ans = minOf(c1,c2)
        if(ans <= n){
            put(ans)
        }else{
            put(-1)
        }
//        put(minOf(c1,c2))











    }
    done()
}
/*
coded the wrong thing....
 */