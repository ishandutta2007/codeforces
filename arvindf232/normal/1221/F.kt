import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
class longMaxLazy (nSuggest  :Int){
    //Items lenght must be a power of 2
    companion object{
        const val huge = 4000000000000000000L
    }

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val arr = LongArray(n * 2)

    val lazy = LongArray(n){0L} // l // lazy : already applied to this node

    constructor(withArray:LongArray):this(withArray.size){
        for(i in withArray.indices){
            arr[i+n] = withArray[i]
        }
        updateAll()
    }
    private fun updateNode(i:Int,level:Int){
        arr[i] = maxOf(arr[i shl 1 ], arr[(i shl 1) + 1]) + lazy[i]
    }
    fun nodeAdd(x:Int,level:Int,inc:Long){
        // apply the update to the node , then store further children updates
        arr[x] += (inc)
        if(x < n){
            lazy[x] += inc
        }
    }

    private fun pushNode(i:Int, level:Int){ // must be interior node

        val left = (i shl 1)
        val inc = lazy[i]

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
    val lastIndex = n-1


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
                left ++
            }
            if(right and 1 != 0){
                right --
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
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                nodeAdd(left,level,inc)
                left ++
            }
            if(right and 1 != 0){
                right --
                nodeAdd(right,level,inc)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int):Long {
        pushPath(l+n)
        pushPath(r+n)
        var ret = Long.MIN_VALUE
        segDivision(l,r){i, level ->
            ret  = maxOf(ret,arr[i])
        }
        return ret
    }
    fun maxPos():Int{
        // rememrbe must be whole array
        val max = arr[1]
        // -1 if not enough
        var here = 1
        for(i in 1..levels){
            val left = here shl 1
            pushNode(here,i)
            if(arr[(left )] == max){
                here = left
            }else{
                here = left +1
            }
        }
        return here - n
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
    fun lazyPrint(){
        val ret = LongArray(n)
        for(i in 0 until n){
            ret[i] = rangeQueryLazy(i,i)
        }
        println(ret.joinToString(" "))
    }
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
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
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

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

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
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
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
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount

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
            a()
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()

const val singleCase = true
const val withBruteForce = false
const val randCount = 100
class point(val x:Int, val y:Int, val c:Int){
    val left = minOf(x,y)
    val right = maxOf(x,y)
}

fun IntArray.sortedDistinct():IntArray {
    val st = this
    st.radixsort()
    val ret = IntArray(this.size){-1}
    var pointer = -1
    var previous = 0
    for((i,c) in st.withIndex()){
        if(i == 0){
            previous = c
            pointer ++
            ret[pointer] = c
        }else{
            if(previous != c){
                pointer ++
                ret[pointer] = c
                previous = c
            }
        }
    }
    return ret.copyOf(pointer + 1)
}
val huge = 1000000000000000000L
fun main(){
    solve.cases{
        val n = getint()
        val qs = Array(n){
            point(getint(), getint(), getint())
        }
        val allcoordinates = IntArray(2 * n + 1 )
        allcoordinates[0] = 1000000007
        var pointer = 0
        for(i in qs){
            pointer ++
            allcoordinates[pointer] = i.x
            pointer ++
            allcoordinates[pointer] = i.y
        }

        val cor = allcoordinates.sortedDistinct()
        val inv = HashMap<Int,Int>(((cor.size + 4) / 3 * 4 ))
        for((i,v) in cor.withIndex()){
            inv[v] = i
        }
        val s = cor.size
        val allQs = Array(s){ mutableListOf<point>()}
        for(q in qs){
            allQs[inv[q.left]!!].add(q)
        }
        val st = longMaxLazy(cor.size)
        st.rangeAdd(0,st.lastIndex,- huge )


        var ret = Long.MIN_VALUE
        var leftMax = -1
        var rightMax = -1

        for(l in cor.size -1 downTo 0){
            st.rangeAdd(l,l,huge)
            for(p in allQs[l]){
               st.rangeAdd(inv[p.right]!!,s-1,p.c.toLong())
            }

            val maxhere = st.arr[1]
            if(maxhere > ret){
                ret = maxhere
                leftMax = l
                rightMax = st.maxPos()
            }
//            st.lazyPrint()

            if( l > 0){
                st.rangeAdd(l,s-1,-(cor[l] - cor[l-1]).toLong())
            }
        }

        put(ret)

        val xx = cor[leftMax]
        val yy = cor[rightMax]

        put(xx)
        put(xx)
        put(yy)
        put(yy)
    }
    done()
}
/*
forgot about special case of all nothing
cannot use radix sort on negative integers
 */