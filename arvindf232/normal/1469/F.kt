// 2022-03-28, Mon, 22:01
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

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

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
        if(withBruteForce){
            println("Brute force is active")
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
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)


private const val radixLog = 11
private const val radixBase = 1 shl radixLog
private const val radixMask = radixBase - 1
fun countSort(arr: IntArray, n: Int, expB: Int) {
    val output = IntArray(n)
    val count = IntArray(radixBase)
    for(i in 0 until n) {
        count[(arr[i] shr expB) and radixMask]++
    }
    for(i in 1 until radixBase){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        output[count[(arr[i] shr expB) and radixMask] - 1] = arr[i]
        count[(arr[i] shr expB) and radixMask]--
    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
}
fun IntArray.radixsort() {
    //Positives only!
    val n = this.size
    var b = 0
    repeat(3){
        countSort(this, n, b)
        b += radixLog
    }
}

class tempIntervalSum(val n:Int){
    val things = IntArray(n + 1)

    fun add(l:Int,r:Int,inc:Int){
        val ll = if(l < 0 ) 0 else l
        val rr = if(r > n-1) n else r + 1
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
class lazySegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val arr = LongArray(n * 2)

    val lazy = LongArray(n) // lazy : already applied to this node


    // can assume parents are free of lazy. But cannot assume children are free
    private fun updateNode(i:Int,level:Int){
        arr[i] = arr[i shl 1 ] + arr[(i shl 1) + 1] + lazy[i] * ( 1 shl level)
    }
    fun nodeAdd(x:Int,level:Int,inc:Long){
        // apply the update to the node , then store further children updates
        arr[x] += inc * (1 shl level)
        if(x < n){
            lazy[x] += inc
        }
    }

    private fun pushNode(i:Int, level:Int){ // must be interior node
        val left = (i shl 1)
        val inc = lazy[i]

//        i dei level

        nodeAdd(left,level-1,inc)
        nodeAdd(left+1, level-1, inc)
        lazy[i] = 0
    }

    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        var level = 0
        while(here > 1){
            here = here shr 1
            level ++
            updateNode(here,level)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i,i.calculateLevel)
        }
    }
    private fun pushPath(i:Int){
        // i must be in [n,2n)
        for(s in levels downTo 1){
            pushNode(i shr s,s)
        }
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

    fun rangeAdd(l:Int,r:Int,inc:Long){
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,level ->
            nodeAdd(i,level,inc)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int): Long {
        pushPath(l+n)
        pushPath(r+n)
        var ret = 0L
        segDivision(l,r){i, level ->
            ret += arr[i]
        }
        return ret
    }
    fun walkDown(req:Int):Int{
        // -1 if not enough
        if(req > arr[1]){
            return Int.MAX_VALUE
        }else if(req <= 0 ){
            return -1
        }
        var i = 1
        var rightPoint = -1
        var cur = 0L
        for(l in 1..levels){
            pushNode(i,levels - l + 1)
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
    val Int.calculateLevel:Int get(){
        val base = 31 - this.countLeadingZeroBits()
        return levels - base
    }


}

fun debug(){}
const val withBruteForce = false
const val singleCase = true
fun main(){

//    for(i in 0..103){
//        val st = lazySegTree(300)
//        st.rangeAdd(101,200,1)
//        i dei st.walkDown(i)
//    }


    solve.cases{
        val n = getint
        val k = getint
        val L = getline(n)
        L.radixsort()
        L.reverse()

        val whites = lazySegTree(3 * 200000 + 5)
        whites.rangeAdd(0,0,1)
        var bestpos = Int.MAX_VALUE

        for(c in L){
            val first = whites.walkDown(1)
//            just dei first
            if(first == Int.MAX_VALUE){
                break
            }
            val c1 = (c-1) / 2
            val c2 =  c - 1 - c1
            whites.rangeAdd(first,first,-1)
            whites.rangeAdd(first+2,first+2 + c1 - 1, 1)
            whites.rangeAdd(first+2,first+2 + c2 - 1 ,1 )

            bestpos = minOf(bestpos, whites.walkDown(k))

//            c dei bestpos
        }
        if(bestpos == Int.MAX_VALUE){
            put(-1)
        }else{
            put(bestpos)
        }

//        val chains = List(2*n+5){mint }
//        chains[0].add(1)
//        var left = 0
//        for(c in L){
//            while(chains[left].isEmpty()){
//                left ++
//                if(left !in chains.indices){
//                    put(-1)
//                    return@cases
//                }
//            }
//            val v = chains[left].removeLast()
//            if( v > 1) chains[left+1].add(v-1)
//            val c1 = (c-1) / 2
//            val c2 =  c - 1 - c1
//            chains[left + 2].add(c1)
//            chains[left + 2].add(c2)
//        }
//        val S = tempIntervalSum(2 * n + 5)
//        for((i,c) in chains.withIndex()){
//            for(v in c){
//                S.add(i,i+v-1,1)
//            }
//        }
//        val ss = S.compile()
//        var remaining = k
//        for(i in ss.indices){
//            remaining -= ss[i]
//            if(remaining <= 0){
//                put(i)
//                return@cases
//            }
//        }
//        put(-1)
        




    }
    done()
}



/*
inaccuarcy: did not read problem statements
forgot simple operations

 */