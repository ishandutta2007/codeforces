// 2022.05.31 at 20:22:50 HKT
import item.Companion.other
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
inline fun lazySegTree.segDivisonOrdered(l:Int, r:Int, act:(index:Int)->Unit){
    var left = l + n
    var right = r + n + 1
    var level = 0
    while(left < right){
        if(left and 1 != 0){
            act(left)
            left += 1
        }
        left = left shr 1
        right = right shr 1
        level ++
    }
    right = r + n + 1
    for(lev in level - 1 downTo 0){
        if((right shr lev) and 1 == 1){
            act((right shr lev) - 1 )
        }
    }
}
fun debug(){}
const val singleCase = true

class lazySegTree (nSuggest  :Int){
    //Items lenght must be a power of 2

    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = 31 - n.countLeadingZeroBits() // (Levels) amount of levels then a layer of leaf
    val arr = Array<item>(n * 2){item.base('<')}
    val lazy = BooleanArray(n) // lazy : already applied to this node

    constructor(withArray:String):this(withArray.size){
        for(i in withArray.indices){
            if(withArray[i] == '>'){
                arr[i+n].invert()
            }
        }
        updateAll()
    }


    // can assume parents are free of lazy. But cannot assume children are free
    private fun updateNode(i:Int,level:Int){
        arr[i].writeMerge(arr[i shl 1 ] ,arr[(i shl 1) + 1])
        if(lazy[i]){
            arr[i].invert()
        }
    }
    fun nodeAdd(x:Int,level:Int){
        // apply the update to the node , then store further children updates
        arr[x].invert()
        if(x < n){
            lazy[x] = !lazy[x]
        }
    }

    private fun pushNode(i:Int, level:Int){ // must be interior node
        val left = (i shl 1)
        if(lazy[i]){
            nodeAdd(left,level-1)
            nodeAdd(left+1, level-1)
            lazy[i] = false
        }
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



    fun rangeFlip(l:Int,r:Int){
        if(r < l) return
        pushPath(l+n)
        pushPath(r+n)
        segDivisonOrdered(l,r){i ->
            nodeAdd(i,0)
        }
        updatePath(l+n)
        updatePath(r+n)
    }
    fun rangeQueryLazy(l:Int,r:Int): Int {
        pushPath(l+n)
        pushPath(r+n)
        var now:item? = null
        segDivisonOrdered(l,r){i ->
            if(now == null){
                now = arr[i]
            }else{
                val new = item.any
                new.writeMerge(now!!,arr[i])
                now = new
            }
        }
        return now!!.main.max
    }
    fun rangeQueryLazydebug(l:Int,r:Int): item {
        pushPath(l+n)
        pushPath(r+n)
        var now:item? = null
        segDivisonOrdered(l,r){i ->
            if(now == null){
                now = arr[i]
            }else{
                val new = item.any
                "adding" dei arr[i]
                new.writeMerge(now!!,arr[i])
                now = new
            }
            just dei now!!
        }
        return now!!
    }
    val Int.calculateLevel:Int get(){
        val base = 31 - this.countLeadingZeroBits()
        return levels - base
    }
}

data class subitem(
    var left:Int,
    var right:Int,
    var through:Boolean,
    var max:Int,
    var leftChar:Char = '<',
    var rightChar:Char = '>'
){
    companion object{
        fun base(c:Char):subitem {
            return subitem(1,1,true,1,c,c)
        }
    }
    fun writemerge(A:subitem, B:subitem){
        val cut = A.rightChar == '<' && B.leftChar == '>'
        this.through = (A.through && B.through && !cut)
        if(cut){
            this.max = maxOf(A.max , B.max)
            this.left = A.left
            this.right = B.right
        }else if(this.through) {
            this.max = A.max + B.max
            this.left = this.max
            this.right = this.max
        }else if(A.through){
            this.max = maxOf(B.max , A.max + B.left)
            this.left = A.max + B.left
            this.right = B.right
        }else if(B.through){
            this.max = maxOf(A.max, A.right + B.max)
            this.left = A.left
            this.right = B.max + A.right
        }else{
            this.max = maxOf(A.max, B.max, A.right + B.left)
            this.left = A.left
            this.right = B.right
        }

        this.leftChar = A.leftChar
        this.rightChar = B.rightChar
    }
}
class item(
    var main:subitem,
    var inv:subitem,
){
    companion object{
        val Char.other:Char get() = if(this == '<') '>' else '<'
        fun base(c:Char):item{
            return item(subitem.base(c), subitem.base(c.other))
        }
        val any = base('>')
    }
    fun writeMerge(A:item, B:item){
        this.main.writemerge(A.main, B.main)
        this.inv.writemerge(A.inv, B.inv)
    }
    fun invert(){
        this.main = this.inv.also { this.inv = this.main }
    }
    fun copy():item {
        return item(this.main.copy(), this.inv.copy())
    }

    override fun toString():String {
        return " ${main.toString()}    ${inv.toString()}"
    }
}
class brute(start:String){
    val n = start.size
    val real = CharArray(n){start[it]}
    fun make(l:Int, r:Int):Int {
        for(i in l..r){
            real[i] = real[i].other
        }
        var ret = 0
        var clast = l
        for(cut in l..r+1){
            if(cut == l || cut == r+1 || (real[cut-1] == '<' && real[cut] == '>')){
                ret = maxOf(ret, cut - clast)
                clast = cut
            }
        }
        return ret
    }
}

fun main(){
    solve.tc {
        val n = 1000
        val q = 10000
        share(n)
        share(q)
        share(List(n){'<'}.conca())
        repeat(q){
            var l = Random.nextInt(n)
            var r = Random.nextInt(n)
            if(l > r){
                l = r.also { r = l  }
            }
            share("${l+1} ${r+1}")
        }
    }
    solve.tc(1){
        share("""
            10
            3
            <<<<<<<<<<
            5 6
            4 9
            4 7
        """.trimIndent())
    }
//    solve.usetc(0)
    solve.cases{
        val n = getint
        val q = getint
        val str = getstr
        val st = lazySegTree(str)
//        val bt = brute(str)
        repeat(q){
            val l = getint - 1
            val r = getint - 1
            st.rangeFlip(l,r)
            val ans1 = st.rangeQueryLazy(l, r)
//            val ans2 = bt.make(l,r)
//            assert(ans1 == ans2)
            put(ans1)
        }
//        st.rangeQueryLazy(3,6)





    }
    done()
}




//1371 F
/*
40 mitnuse 2800
ok la
died to TLE then idk

10
3
<<<<<<<<<<
5 6
4 9
4 7
 */