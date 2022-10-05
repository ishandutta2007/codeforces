import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
const val huge = 2_727_000_000_000_000_000L // used for seg tree things
val Char.code :Int get() = this.toInt() -  'a'.toInt()
infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}

infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}
infix fun Int.modM(b:Int):Int{
    return ((this * 1L * b) % p).toInt()
}
infix fun Int.modPlus(b:Int):Int{
    val ans = this + b
    return if(ans >= pI) ans - pI else ans
}
infix fun Int.modMinus(b:Int):Int{
    val ans = this - b
    return if(ans < 0) ans + pI else ans
}
infix fun Int.modDivide(b:Int):Int{
    return this modM (b.inverse())
}
fun Int.additiveInverse():Int{
    return if(this == 0) 0 else pI - this
}


fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0){
            X = ((1L * X * X) % m).toInt()
            E /= 2
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
fun Int.inverse():Int{
    return intPow(this,pI-2,pI)
}
//make this int instead
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
                store[i] = store[i-1] modM i
                invStore[i] = invStore[i-1] modM (i.inverse())
            }
        }
        fun choose(n:Int,r:Int):Int{
            if(r < 0 || r > n) return 0
            val a = store[n]
            val b = invStore[n-r]
            val c = invStore[r]
            return (a modM b) modM c
        }

        fun bigChoose(n:Int,r:Int):Int{
            var ret = 1
            for(i in 0 until r){
                ret = ret modM (n - i)
            }
            ret = ret modM (invStore[r])
            return ret
        }

    }
}

class interval_incomparable(val keepsmaller:Boolean){
    val t = TreeMap<Int,Int>()

    fun containSome(a:Int,b:Int):Int?{
        val right = t.ceilingEntry(a)
        if(right != null && right.value <= b){
            return right.key
        }
        return null
    }
    fun containedBySome(a:Int,b:Int):Int?{
        // return the key, if it is included by some
        val left = t.floorEntry(a)
        if(left != null && left.value >= b){
            return left.key
        }
        return null
    }
    fun firstFullIntreval(l:Int):Int?{
        // return an r , such that there is some [a,b] contained in [l,r]
        val right = t.ceilingEntry(l)
        if(right != null){
            return right.value
        }
        return null
    }
    fun add(a:Int, b:Int){
        if(keepsmaller){
            if(containSome(a,b) != null){
                return
            }
            while(true){
                val del = containedBySome(a,b) ?: break
                t.remove(del)
            }
            t[a] = b
        }else{
            if(containedBySome(a,b) != null){
                return
            }
            while(true){
                val del = containSome(a,b) ?: break
                t.remove(del)
            }
            t[a] = b
        }
    }
}

class interval(val a:Int, val b:Int, val type:Boolean){

}
class lazySegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val arr = IntArray(n * 2)

    val lazy = IntArray(n) // lazy : already applied to this node

    constructor(withArray:IntArray):this(withArray.size){
        for(i in withArray.indices){
            arr[i+n] = withArray[i]
        }

        updateAll()
    }

    private fun updateNode(i:Int,level:Int){
        arr[i] = arr[i shl 1 ] modPlus arr[(i shl 1) + 1] modPlus (lazy[i] modM ( 1 shl level))
    }
    fun nodeAdd(x:Int,level:Int,inc:Int){
        // apply the update to the node , then store further children updates
        arr[x] = arr[x] modPlus inc * (1 shl level)
        if(x < n){
            lazy[x] = lazy[x] modPlus inc
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

    fun rangeAdd(l:Int,r:Int,inc:Int){
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivision(l,r){i,level ->
            nodeAdd(i,level,inc)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int): Int {
        pushPath(l+n)
        pushPath(r+n)
        var ret = 0
        segDivision(l,r){i, level ->
            ret = ret modPlus arr[i]
//            ret += arr[i]
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
    val Int.calculateLevel:Int get(){
        val base = 31 - this.countLeadingZeroBits()
        return levels - base
    }

    fun lazyPrint(){
        val ret = IntArray(n)
        for(i in 0 until n){
            ret[i] = rangeQueryLazy(i,i)
        }
        println(ret.joinToString(" "))
    }

}
private fun leastSignificantBit(n:Int):Int{
    return (n and (-n))
}

class BIT_modded (nsuggest:Int){
    val n = nsuggest + 1
    val all = IntArray(n + 1 )

    fun add(i:Int, inc:Int){
        if(i < 0 || i >= n) return
        var i = i + 1
        while(i <= n){
            all[i] = all[i] modPlus inc
            i += leastSignificantBit(i)
        }
    }
    fun printTree(){
        val ret = mutableListOf<Int>()
        for(i in 0 until n ){
            ret.add(rangeQuery(i,i))
        }
        println(ret.joinToString(" "))
    }
    private fun query(i:Int):Int{
        var ret = 0
        var i  = i + 1
        while(i >0){
            ret = ret modPlus all[i]
            i -= leastSignificantBit(i)
        }
        return ret
    }
    fun rangeQuery(a:Int,b:Int): Int {
        return query(b) - query(a-1)
    }
}

class BITasrange(nsuggest: Int){
    val under = BIT_modded(nsuggest)
    fun addrange(a:Int, b:Int,inc:Int){
        under.add(a,inc)
        under.add(b+1,inc.additiveInverse())
    }
    fun pointQuery(a:Int): Int {
        return under.rangeQuery(0,a)
    }

}
const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val t = System.currentTimeMillis()
        val k = getint()
        val acount = getint()
        val bcount = getint()
        var allcoords = mutableListOf<Int>()
//        val coords = TreeMap<Int,Int>()
        val allI = mutableListOf<interval>()
        repeat(acount){
            allI.add(interval(getint()-1, getint() - 1,false))
        }
        repeat(bcount){
            allI.add(interval(getint() - 1 , getint() -1 , true))
        }
        for(a in allI) {
            allcoords.add(a.a-1)
            allcoords.add(a.b)

//            coords[a.a - 1] = 0
//            coords[a.b] = 0
        }
        allcoords.add(-1)
        allcoords.add(k-1)
        val forward = allcoords.distinct().sorted()
        val reverse = HashMap<Int,Int>(forward.size / 3 * 4 + 5 )
        for((i,v) in forward.withIndex()){
            reverse[v] = i
        }

//        coords[-1] = 0
//        coords[k-1] = 0
//        val forward = mutableListOf<Int>()
//        var count = -1
//        for(k in coords.entries){
//            count ++
//            forward.add(k.key)
//            coords[k.key] = count
//        }
        //590
        val n = forward.size
        val last0 = BITasrange(n)
        val last1 = BITasrange(n)
        val lastboth = BITasrange(n)
        lastboth.addrange(0,0,1)

        val A1 = interval_incomparable(true)
        val A0 = interval_incomparable(true)
        for(I in allI){
            if(I.type){
                A1.add(reverse[I.a-1]!!+1,reverse[I.b]!!)
            }else{
                A0.add(reverse[I.a-1]!!+1,reverse[I.b]!!)
            }
        }

        //1175
        // 1175 -> 974

//        if(k == 1000000000 ){
//            put(System.currentTimeMillis() - t)
//            return@cases
//        }

        //1777 after 1/3

        for(i in 0 until n - 1){

            val here0 = last0.pointQuery(i)
            val here1 = last1.pointQuery(i)
            val here2 = lastboth.pointQuery(i)
            val l = forward[i+1] - forward[i]
            val baseoption = intPow(2,l,pI) modMinus 2
            lastboth.addrange(i+1,i+1,baseoption modM (here2 modPlus here0 modPlus here1))

            val max0 = (A0.firstFullIntreval(i+1) ?: n)-1
            val max1 = (A1.firstFullIntreval(i+1) ?: n)-1

            last0.addrange(i+1,max0, (here2 modPlus here1))
            last1.addrange(i+1,max1, (here2 modPlus here0))
//            just dei i
//            last0.lazyPrint()
//            last1.lazyPrint()
//            lastboth.lazyPrint()


        }
        val a = last0.pointQuery(n-1)
        val b = last1.pointQuery(n-1)
        val c = lastboth.pointQuery(n-1)
        put(a modPlus b modPlus c)
    }
    done()
}
const val singleCase = true

/*

5 4 1
1 1
2 2
4 4
5 5
1 5

1000000000 2 2
1 3
3 5
2 2
4 500000000
learn clean debug

mistakes:
    intreval tree range: left -1 , right
    use BIT
    additive inverse in BIT 

 */