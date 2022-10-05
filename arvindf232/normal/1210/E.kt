// 2022-05-11, Wed, 18:37
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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
fun debug(){}
const val singleCase = true

data class permutation(val p:IntArray){
    val n:Int get() = p.size
    companion object{
        fun identity(n:Int): permutation {
            return permutation((0 until n).toList().toIntArray())
        }
        fun all(n:Int): MutableList<permutation> {
            val ret = mutableListOf<permutation>()
            val A = IntArray(n){it}
            val c = IntArray(n)

            ret.add(permutation(A.copyOf()))

            var i = 0
            while(i < n){
                if(c[i] < i){
                    if(i %2 == 0){
                        A[0] = A[i].also { A[i] = A[0] }
                    }else{
                        A[c[i]] = A[i].also { A[i] = A[c[i]] }
                    }
                    ret.add(permutation(A.copyOf()))
                    c[i] += 1
                    i = 0
                }else{
                    c[i] = 0
                    i += 1
                }
            }
            return ret
        }
        fun kthpermutation(n:Int, k:Long):permutation{
            val all = (0 until n).toMutableList()
            val FACT = LongArray(n)
            FACT[0] =1L
            for(i in 1 until FACT.size) {
                FACT[i] = i * FACT[i-1]
            }
            val ret = mutableListOf<Int>()
            var indexnow = k
            for(l in n-1 downTo 0){
                val v = (indexnow / FACT[l] ).toInt()
                indexnow %= FACT[l]
                ret.add(all[v])
                all.removeAt(v)
            }
            return permutation(ret.toIntArray())
        }
    }
    // 0 based
    fun inverse():permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[i]] = i
        }
        return permutation(ret)
    }
    operator fun get(i:Int):Int{
        return p[i]
    }
    infix fun compose(other:permutation):permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[other.p[i]]] = i
        }
        return permutation(ret)
    }
    fun swapDistances():Int{
        var ret = 0
        cyclesOfPermutations { ret += it.size - 1  }
        return ret
    }
    fun shiftRightBy(a:Int):permutation{
        val ret = IntArray(p.size)
        var here = a - 1
        for(i in 0 until p.size){
            here += 1
            if(here >= p.size){
                here -= p.size
            }
            ret[here] = p[i]
        }
        return permutation(ret)
    }
    fun swapAt(a:Int,b:Int):permutation{
        val new = p.copyOf()
        new[a] = new[b].also{new[b] = new[a]}
        return permutation(new)
    }
    inline fun cyclesOfPermutations(doit:(List<Int>)->Unit){
        val arr = this.p
        val n = arr.size
        val done = BooleanArray(n)
        var haveDone = 0
        var pointer = 0
        while(haveDone < n){
            while(done[pointer]){
                pointer++
            }
            haveDone += 1
            val x = pointer
            val todo = mutableListOf(x)
            var cur = x
            done[x] = true
            while(true){
                val next = arr[cur]
                if(done[next]){
                    break
                }
                done[next] = true
                todo.add(next)
                haveDone += 1
                cur = next
            }
            doit(todo)
        }
    }

    fun subpermutation(mask:Int):permutation{
        val things = mutableListOf<Int>()
        for(i in 0 until p.size){
            if(mask and 1 shl i != 0){
                things.add(i)
            }
        }
        val firstThings = things.withIndex().sortedBy { it.value }
        return (permutation(firstThings.map{it.index}.toIntArray()).inverse())
    }
    fun uniqueCode():Int{
        var use = 0
        var i = 0
        var r = 0
        for(x in this.p){
            r = r * ( ++ i ) + (use and (-(1 shl x))).countOneBits()
            use = use or (1 shl x)
        }
        return r
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as permutation

        if (!p.contentEquals(other.p)) return false
        return true
    }

    override fun hashCode(): Int {
        return p.contentHashCode()
    }

    override fun toString(): String {
        return p.joinToString(" ")
    }
    fun print(){
        println(this.toString())
    }
}

var S = 0
var mulP = Array(0){IntArray(0)}
var inv = IntArray(0)

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
    fun reset(){
        startpointer = -l
        endpointer = startpointer -1
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}
class subgroup(val all:BooleanArray){
    val size = all.count { it }
    companion object{
        fun min():subgroup{
            val new = BooleanArray(S){it == 0 }
            return subgroup(new)
        }
    }
    fun adding(p:Int):subgroup {
        val explored = BooleanArray(S)
        val Q = fastEmptyList(S)
        val ret = BooleanArray(S)
        for(i in 0 until S){
            if(all[i] || i == p) {
                Q.addLast(i)
                explored[i] = true
            }
        }
        while(Q.isNotEmpty()){
            val v = Q.removeLast()
            ret[v] = true
            for(s in 0 until S) {
                if(!explored[s]) continue
                val c = mulP[v][s]
                if(explored[c] == false) {
                    explored[c] = true
                    Q.addLast(c)
                }
            }
        }
        return subgroup(ret)
    }

    override fun equals(other:Any?):Boolean {
        if(this === other) return true
        if(javaClass != other?.javaClass) return false

        other as subgroup

        if(!all.contentEquals(other.all)) return false

        return true
    }

    override fun hashCode():Int {
        return all.contentHashCode()
    }
}
typealias dsparseType = Int
typealias dsparseArrayType = IntArray
class disjointSparseTable (val oldA:dsparseArrayType){
    val empty = 0
    fun combine(l:dsparseType, r:dsparseType):dsparseType{
        return mulG[l][r]
    }
    var size = oldA.size
    var maxlevel = 31 - size.countLeadingZeroBits()
    init{
        if((1 shl maxlevel) != size){
            size = 1 shl (++ maxlevel)
        }
    }
    val A:dsparseArrayType
    init{
        A = dsparseArrayType(size){oldA.getOrElse(it){empty}}
    }

    val table = Array(maxlevel + 1){dsparseArrayType(size)}
    fun build(level:Int,l:Int,r:Int){
        val m = (l + r) shr 1

        table[level][m] = A[m]
        for(i in m-1 downTo l){
            table[level][i] = combine(table[level][i+1],A[i])
        }
        if(m+1 < r){
            table[level][m+1] = A[m+1]
            for(i in m+2 until r){
                table[level][i] = combine(table[level][i-1],A[i])
            }
        }
        if(l + 1 != r){
            build(level+1,l,m)
            build(level+1,m,r)
        }
    }
    init{
        build(0,0,size)
    }

    fun query(x:Int, y:Int):dsparseType{
        var y = minOf(y, oldA.lastIndex) // slightly dangeorus if empty is not met
        if(x > y) return empty
        if(x == y) return A[x]
        val k2 = 31 - (x xor y).countLeadingZeroBits()
        val level = maxlevel - 1 - k2
        var ans = table[level][x]
        if(y and ((1 shl k2) - 1) != 0){
            ans = combine(ans,table[level][y])
        }
        return ans
    }
}


inline fun BinarySearchFirstTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
        val m = (L + R) shr 1
        if(isTrue(m)){
            R = m
        }else{
            L = m + 1
        }
    }
    return if(isTrue(L)){
        L
    }else{
        if(L == r){
            null
        }else{
            L + 1
        }
    }
}

inline fun BinarySearchLastTrue(l:Int,r:Int,isTrue:(Int)->Boolean):Int?{
    //inclusive
    var L = l
    var R = r
    while(L<R){
       val m = ((L + R) shr 1) + 1
        if(isTrue(m)){ L = m }else{ R = m - 1 }
    }
    return if(isTrue(L)){ L }else{ null }
}

var mulG = Array(0){IntArray(0)}
fun main(){
    solve.cases{
        val n= getint
        val k = getint
        val allp = permutation.all(k)
        val pid = mutableMapOf<permutation,Int>()
        for((i, p) in allp.withIndex()) {
            pid[p] = i
        }
        S = allp.size
        mulP = Array(S){IntArray(S)}
        for(i in 0 until S){
            for(j in 0 until S){
                val n1 = allp[i]
                val n2 = allp[j]
                val new = pid[n1.compose(n2)]!!
                mulP[i][j] = new
            }
        }
        inv = IntArray(S){
            val p = allp[it]
            val inv = pid[p.inverse()]!!
            inv
        }

        val explored = mutableSetOf<subgroup>()
        val Q = ArrayDeque<subgroup>()
        Q.addLast(subgroup.min())
        explored.add(subgroup.min())
        while(Q.isNotEmpty()){
            val g = Q.removeLast()
            for(s in 0 until S){
                val new = g.adding(s)
                if(new !in explored) {
                    explored.add(new)
                    Q.add(new)
                }
            }
        }
        val allgroups = explored.toList()
        val groupRev = mutableMapOf<subgroup, Int>()
        for((i, v) in allgroups.withIndex()) {
            groupRev[v] = i
        }
        val G = allgroups.size
         mulG = Array(G){IntArray(G)}
        for(i in 0 until G){
            for(j in 0 until G){
                var bestsize =  S + 1
                var best  = -1
                for(k in 0 until G){
                    if((0 until S).all { allgroups[k].all[it] || (!allgroups[i].all[it] && !allgroups[j].all[it]) }){
                        val s = allgroups[k].all.count { it }
                        if(s < bestsize){
                            bestsize = s
                            best = k
                        }
                    }
                }
                mulG[i][j] = best
            }
        }

        val cyclicGenerator = IntArray(S){
            groupRev[subgroup.min().adding(it)]!!
        }

        val mainarr = IntArray(n)
        repeat(n){
            val arr = getline(k)
            for(i in 0 until k){
                arr[i] --
            }
            val p = permutation(arr)
            val id = pid[p]!!
            mainarr[it] = cyclicGenerator[id]
        }
        val groupsize = IntArray(allgroups.size){allgroups[it].size}
        val tb = disjointSparseTable(mainarr)
        fun query(l:Int, r:Int):Int {
            return groupsize[tb.query(l,r)]
        }
        var ret = 0L
        for(left in 0 until n){
            var r = left
            while(r <= n-1){
                val want = query(left,r)
//                assert(S % want == 0)
                val to = BinarySearchLastTrue(r,n-1){query(left,it) == want}!!
                ret += (to - r +1) * want
                r = to + 1
            }
        }
        put(ret)



    }
    done()
}