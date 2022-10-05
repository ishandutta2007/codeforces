import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
}

class lazySegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val arr = LongArray(n * 2)

    val lazy = LongArray(n) // l // lazy : already applied to this node

    private fun updateNode(i:Int,level:Int){
        arr[i] = arr[i shl 1 ] + arr[(i shl 1) + 1] + lazy[i] * ( 1L shl level)
    }
    fun nodeAdd(x:Int,level:Int,inc:Long){
        // apply the update to the node , then store further children updates
        arr[x] += (inc * (1 shl level))
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
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,level ->
            nodeAdd(i,level,inc)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int):Long {
        pushPath(l+n)
        pushPath(r+n)
        var ret = 0L
        segDivision(l,r){i, level ->
            ret += arr[i]
        }
        return ret
    }
    fun queryFunctional(l:Int,r:Int):Long {
        var ret = 0L
        segDivision(l,r){i, _ ->
            ret += arr[i]
        }
        return ret
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
        if (c == NC) c = char
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
            System.err.println("Not accepting inputs!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
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
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
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
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }

const val singleCase = true
const val withBruteForce = false
const val randCount = 100

fun IntArray.leftAbove():IntArray{
    val S = ArrayDeque<Pair<Int,Int>>()
    val ret = IntArray(this.size)
    for(i in this.indices){
        val v = this[i]
        while(S.isNotEmpty()){
            val first = S.last()
            if(v > first.second){
                S.removeLast()
            }else{
                break
            }
        }
        val last = S.lastOrNull()?.first ?: -1
        ret[i] = last
        S.add(Pair(i,v))
    }
    return ret
}

fun IntArray.rightAbove():IntArray{
    val S = ArrayDeque<Pair<Int,Int>>()
    val ret = IntArray(this.size)
    for(i in this.lastIndex downTo 0){
        val v = this[i]
        while(S.isNotEmpty()){
            val first = S.last()
            if(v >= first.second){
                S.removeLast()
            }else{
                break
            }
        }
        val last = S.lastOrNull()?.first ?: -1
        ret[i] = last
        S.add(Pair(i,v))
    }
    return ret
}



fun main(){

    solve.tc{
        share(1)
        share(1)
        share(1)
        share(intArrayOf(-3))
    }

//    solve.tc {
//        share(1)
//        share(100)
//        share(75)
//        share(List(75){ Random.nextInt(0,100)})
//    }
//
//    solve.usetc()
    solve.cases{
        val n = getint()
        val w = getint()
        val ST = lazySegTree(w)

        repeat(n){
            val x = getint()
            val L = getline(x)
            val leftBad = L.leftAbove()
            val rightBad = L.rightAbove()

            val bestSpace = w - x

            for(i in 0 until x){

                var lb = maxOf(if(leftBad[i] != -1) bestSpace + leftBad[i] + 1 else 0,i)
                var rb = minOf(if(rightBad[i] != -1) rightBad[i] - 1 else w-1,w-(x-i))
//
                if(L[i] <= 0){
                    lb = maxOf(lb,bestSpace)
                    rb = minOf(rb,w-bestSpace-1)
                }

//                it dei Pair(lb, rb)
                ST.rangeAdd(lb,rb,L[i].toLong())
            }
        }
        for(i in 0 until w){
            put(ST.rangeQueryLazy(i,i))
        }

    }
    done()
}

/*
very tough transitions ( and probably wrong)
break conditions on stack implementations
still off by 1 on updates
protected variable names: n is very sacred
didn't catch all the fails
- so dangerous: 4, no 5 uncatched bugs from one issue
- n must always be array length
 */