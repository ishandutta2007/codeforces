
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
import kotlin.random.Random
import kotlin.random.Random.Default.nextInt
import kotlin.random.nextInt
import kotlin.system.measureTimeMillis

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

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == '1'}
}

val List<Char>.ret:String
get() = this.joinToString("")
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    var str = ""
    if(this is String){ str = this
    }else if(this is Int){ str = this.toString()
    }else if(this is Long){ str = this.toString()
    }
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
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
const val withBruteForce = false
const val randCount = 100
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
            currentAnswer = null
            currentBruteAnswer = null
            onecase()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
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
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentBruteAnswer != null){
            checkAnswer()
        }
    }
    fun put2(a:Any){answer(a);put(a) }

    fun bruteAnswer(a:Any){
        currentBruteAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun checkAnswer(){
        if(currentAnswer != currentBruteAnswer){
            throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
        }
        answersChecked ++
    }
}
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor b.toLong()
val Long.first get() = (this shr 32).toInt()
val Long.second get() = this.toInt()

class lazySegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val cutmin = IntArray(n * 2)
    val cuthere = IntArray(n)
    val fullmax = IntArray(n * 2)
    val leftmax = IntArray(n*2)
    val rightmax = IntArray(n*2)
    var total = IntArray(n*2)
    // unless length 1, the two sides do not join together


    val lazy = IntArray(n) // lazy : already applied to this node

    constructor(withArray:IntArray):this(withArray.size){
        for(i in withArray.indices){
            cutmin[i+n] = withArray[i]
        }

        updateAll()
    }

    fun updateNode(i:Int,level:Int){
        val left = i shl 1
        val right = (i shl 1) + 1

        val leftmincut = lazy[i] + cutmin[left]
        val rightmincut = lazy[i] + cutmin[right]
        cutmin[i] = if(left >= n) cuthere[i] else minOf(leftmincut, rightmincut,cuthere[i])
        fullmax[i] = maxOf(fullmax[left], fullmax[right])
//        leftmax[i] = leftmax[left]
//        rightmax[i] = rightmax[right]

        val hascut = cutmin[i] == cuthere[i]
        val leftactive = if(left >= n) false else cutmin[i] == leftmincut
        val rightactive = if(right >= n) false else cutmin[i] == rightmincut
        if(leftactive){
            leftmax[i] = leftmax[left]
        }else if(hascut){
            leftmax[i] = fullmax[left]
        }else{
            leftmax[i] = maxOf(fullmax[left], leftmax[right])
        }
        if(rightactive){
            rightmax[i] = rightmax[right]
        }else if(hascut){
            rightmax[i] = fullmax[right]
        }else{
            rightmax[i] = maxOf(fullmax[right],rightmax[left])
        }

        if(hascut){
            val leftpiece = if(leftactive) total[left] + rightmax[left] else 0
            val rightpiece = if(rightactive) total[right] + leftmax[right] else 0
            total[i] = leftpiece + rightpiece
        }else{
            val base = (if(leftactive) total[left] else 0) + (if(rightactive) total[right] else 0)
            val extra = if(leftactive && rightactive) maxOf(rightmax[left] , leftmax[right]) else 0
            total[i] = base + extra
        }
    }
    fun nodeAdd(x:Int,level:Int,inc:Int){
        // apply the update to the node , then store further children updates

        if(x < n){
            cuthere[x] += inc
            cutmin[x] += inc
            lazy[x] += inc
        }
    }

    fun pushNode(i:Int, level:Int){ // must be interior node
        val left = (i shl 1)
        val inc = lazy[i]

        nodeAdd(left,level-1,inc)
        nodeAdd(left+1, level-1, inc)
        lazy[i] = 0
    }

    fun updatePath(i:Int){
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
    fun segDivisionOrdered(l:Int, r:Int):List<Int>{
        var left = l + n
        var right = r + n + 1
        var level = 0
        val L = mutableListOf<Int>()
        val R = mutableListOf<Int>()
        while(left < right){
            if(left and 1 != 0){

                L.add(left)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                R.add(right)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
        return L + R.reversed()
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
    fun pointset(p:Int,new:Int){
        leftmax[p+n] = new
        rightmax[p+n] = new
        fullmax[p+n] = new
        updatePath(p + n)
    }
    fun setcut(c:Int,inc:Int){
        val tr = c.countTrailingZeroBits()
        val i = (n+c) shr (1 + tr)
        cuthere[i] += inc
        updateNode(i,0)
    }
    fun rangeAdd(l:Int,r:Int,inc:Int){
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        val od = segDivisionOrdered(l,r)
        for((i,c) in od.withIndex()){
            nodeAdd(c,0,inc)
            if(c < n) updateNode(c,0)
            if(i != od.lastIndex){
                val r = totalRight[c]
                setcut(r+1,inc)

//                just dei "set segment ${r+1} cut "
            }
        }
//        segDivision(l,r){i,level ->
//            nodeAdd(i,level,inc)
//        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun answer():Int{
        pushNode(1,0)
        if(cutmin[1] == 0){
            return leftmax[1] + rightmax[1] + total[1]
        }else{
            return fullmax[1]
        }
    }
    val totalLeft = IntArray(2 * n)
    val totalRight = IntArray(2 * n)
    init{
        for(i in 1 until 2 * n){
            val (l,r) = i.endpoints
            totalLeft[i] = l
            totalRight[i] = r
        }
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

    fun fullupdate(){
        for(i in 6 downTo 1){
            updateNode(i,0)
        }
    }
    fun pushall(){
        for(i in 1..n-1){
            pushNode(i,0)
        }
    }
}

class intervalTree(){
    val T = TreeMap<Int,Long>()
    //first: right second: max

    fun add(a:Int, b:Int,m:Int) {
        var mina = a
        var maxb = b
        var mnow = m
        while(true) {
            val left = T.floorEntry(a) ?: break
            if(left.value.first >= a){
                mina = minOf(mina , left.key)
                maxb = maxOf(maxb, left.value.first)
                mnow = maxOf(mnow,left.value.second)
                T.remove(left.key)
            }else{
                break
            }
        }
        while(true){
            val right = T.ceilingEntry(a) ?: break
            if(right.key <= b){
                maxb = maxOf(maxb,right.value.first)
                mnow = maxOf(mnow,right.value.second)
                T.remove(right.key)
            }else{
                break
            }
        }
        T[mina] = makepair(maxb,mnow)
        //assumes no duplicate pairs
    }
    fun solve():Int {
        var total = 0
        for((l,p) in T){
            val len = p.first - l + 1
            val actual = len - p.second
            total += actual
        }
        return total
    }
}

const val max = 200001
const val singleCase = true
fun main(){
    solve.rand {
        share(8)
        share(0)
        share(List(8){Random.nextInt(1..3)})
    }
//    solve.userand()
    solve.cases{
        val n = getint
        val q = getint
        val things = Array(max){ TreeSet<Int>() }
        val L = getline(n)
        for((i,a) in L.withIndex()){
            things[a].add(i)
        }
        val st = lazySegTree(n)
//        st.rangeAdd(0,0,plarge)
        st.rangeAdd(n-1,st.n -1,plarge)
//        val t = intervalTree()
        for(s in things){
            if(s.isNotEmpty()){
                st.rangeAdd(s.first(),s.last(),1)
                st.pointset(s.first(),s.size)
//                t.add(s.first(),s.last(),s.size)
            }
        }
        fun itsolve():Int {
            val t = intervalTree()
            for(s in things){
                if(s.isNotEmpty()){
                    t.add(s.first(),s.last(),s.size)
                }
            }
            return t.solve()
        }
        val finalanser = n - st.answer()
        assert(finalanser == itsolve())
//        st.pushall()
//        st.fullupdate()

        put(n- st.answer())
    }
    done()
}
/*
updates over cuts are hard
confused over what to push


4 0
1 2 3 2

6 0
1 3 3 3 3 3

8 0
4 2 2 4 2 4 3 3

100 0
6 7 100 8 5 61 5 75 59 65 51 47 83 37 34 54 87 46 4 26 21 87 12 97 86 68 60 11 62 76 14 83 29 31 91 62 57 80 47 75 85 97 62 77 91 86 14 25 48 77 83 65 39 61 78 77 45 46 90 74 100 91 86 98 55 5 84 42 91 69 100 4 74 98 60 37 75 44 41 12 15 34 36 1 99 16 7 87 36 26 79 42 41 84 17 98 72 16 38 55
 */