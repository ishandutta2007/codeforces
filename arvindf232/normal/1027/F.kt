
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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
class FastCoordinateCompression(things:IntArray){
    val forward:IntArray
    var reverse:MutableMap<Int,Int> = HashMap(things.size / 3 * 4 + 5)
    var n:Int
    init{
        //destroys the compression
        things.radixsort()
        var pointer = -1
        val newarr = IntArray(things.size)
        var last = -1
        for((i,v) in things.withIndex()){
            if(i == 0 || v != last){
                pointer ++
                newarr[pointer] = v
                last = v
            }
        }
        n = pointer + 1
        forward = newarr
        for(i in 0 until n){
            val v = newarr[i]
            reverse[v] = i
        }
    }
    fun delete(){

    }
}

class edge(val oldx:Int, val oldy:Int){
    var x:Int  =-1
    var y:Int  = -1
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
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
private const val radixLogL = 10
private const val radixBaseL = 1 shl radixLogL
private const val radixMaskL = radixBaseL - 1

fun countSortL(arr: LongArray, n: Int, expB: Int) {
    val output = LongArray(n)
    val count = IntArray(radixBaseL)
    for(i in 0 until n) {
        count[(arr[i] shr expB).toInt() and radixMaskL]++
    }
    for(i in 1 until radixBaseL){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        output[count[(arr[i] shr expB).toInt() and radixMaskL] - 1] = arr[i]
        count[(arr[i] shr expB).toInt() and radixMaskL]--
    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
}
fun LongArray.radixsort(){
    val n = this.size
    var b = 0
    repeat(7){
        countSortL(this, n, b)
        b += radixLogL
    }
}
const val intmask = (1L shl 32) - 1
inline fun hyperspeedCC(things:IntArray,cb:(i:Int,v:Int)->Unit): Pair<IntArray, Int> {
    val n = things.size
    val arr = LongArray(n){(things[it].toLong() shl 32) xor it.toLong()}
    arr.radixsort()
    var lastvalue = Int.MIN_VALUE
    var pointer = -1
    val ret = IntArray(n)
    for(i in 0 until n){
        val here = arr[i]
        val ov = (here shr 32).toInt()
        val oi = here.toInt()
        if(pointer == -1 || ov != lastvalue){
            pointer++
            ret[pointer] = ov
            lastvalue = ov
        }
        cb(oi,pointer)
    }
    return Pair(ret,pointer + 1)
}
class Graph_Fast(val n:Int, val maxm:Int, val directed:Boolean){
    val edges = LongArray(if(directed) maxm else 2 * maxm)
    var edgepointer = -1
    var start = IntArray(0)
    var end = IntArray(0)

    fun add(a:Int, b:Int){
        edgepointer ++
        edges[edgepointer] = (a.toLong() shl 32) xor b.toLong()
        if(!directed){
            edgepointer ++
            edges[edgepointer] = (b.toLong() shl 32) xor a.toLong()
        }
    }
    fun compile(){
//        assert(maxm >= 10000)
        edges.radixsort()
        var leftpointer = 0
        var rightpointer = -1
        start = IntArray(n)
        end = IntArray(n)

        for(v in 0 until n){
            while(rightpointer < edgepointer && (edges[rightpointer+1] shr 32).toInt() == v ){
                rightpointer ++
            }
            start[v] = leftpointer
            end[v] = rightpointer
            leftpointer = rightpointer + 1
        }
    }

    inline fun NS(v:Int,act:(Int)->Unit){
        for(i in start[v]..end[v]){
            act(edges[i].toInt())
        }
    }
}
const val singleCase = true
fun main(){
//    val a = LongArray(2000000){Random.nextLong(1000000000000000)}
//    TIME{
//
//        a.radixsort()
//    }
    solve.tc{
        share("1000000")
        repeat(2000000){
            share(Random.nextInt(1000000000))
        }
    }
//    solve.usetc()
    solve.cases{

		val readn = getint
        val all = List(readn){edge(getint, getint )}

        val allcoords = IntArray(readn * 2)
        for(i in 0 until readn){
            allcoords[i * 2] = all[i].oldx
            allcoords[i* 2 + 1] = all[i].oldy
        }
        val (CC,n) = hyperspeedCC(allcoords){
            i,v ->
            val ii = i / 2
            if(i and 1 == 0){
                all[ii].x = v
            }else{
                all[ii].y = v
            }
        }


//        val CC = coordinateCompression(allcoods)v
//        return@cases
//        for( e in all){
//            e.x = CC.reverse[e.oldx]!!
//            e.y = CC.reverse[e.oldy]!!
//        }

        val G = Graph_Fast(n,all.size,false)
//        val E = List(n){ mutableListOf<Int>() }

        for(e in all){
            G.add(e.x,e.y)
//            E[e.x].add(e.y)
//            E[e.y].add(e.x)
        }
        G.compile()

        val Q = fastDeque(0,n)
        val used = BooleanArray(n)
        var ret = -1
        for(i in 0 until n){
            if(used[i]) continue
            var vertex = 0
            var edges = 0
            var secondlargest = -1
            var largest = -1
            used[i] = true
            Q.addLast(i)
            while(Q.isNotEmpty()){
                val a = Q.removeFirst()
//                just dei a
                vertex ++
                if( a > largest){
                    secondlargest = largest
                    largest = a
                }else if(a > secondlargest){
                    secondlargest = a
                }
                G.NS(a){b ->
                    edges ++
                    if(!used[b]){
                        used[b] = true
                        Q.addLast(b)
                    }
                }
            }

//            just dei "$edges $vertex"
            val ee = edges / 2
            if(ee == vertex - 1){
                ret = maxOf(ret,secondlargest)
            }else if(ee == vertex){
                ret = maxOf(ret,largest)
            }else{
                put(-1)
                return@cases
            }
        }
        put(CC[ret])
    }
    done()
}


/*
3
1 5
1 7
5 7
 */