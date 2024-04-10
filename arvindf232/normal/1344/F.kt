// 2022.07.02 at 15:30:51 HKT
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
class matrixP(val n:Int, val m:Int) {
    companion object{
        //        const val modded = false
        const val p = 2
        private inline fun normalize(int: Int) = (int shr Int.SIZE_BITS - 1 and p) + int
        infix fun Int.modm(other:Int) = (this.toLong() * other % p).toInt()
        infix fun Int.modplus(other: Int) = normalize(this + other - p) // overflow-safe even if MOD >= 2^30
        infix fun Int.modminus(other: Int) = normalize(this - other)

        fun localMul(a:Int,b:Int):Int{
            return a modm b
        }
        fun Int.localAdjust():Int{
            return if(this > p) this - p else if(this <0) this + p else this
        }
        fun localDivide(a:Int,d:Int):Int{
            return localMul(a, intPow(d, p -2, p))
        }

        fun identity(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            return ret
        }
        fun standardTriangle(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            for(i in 1 until n){
                ret.A[i-1][i] = 1
            }
            return ret
        }
        fun columnvector(a:IntArray):matrixP{
            val new = matrixP(a.size,1)
            for(i in a.indices){
                new[i][0] = a[i]
            }
            return new
        }
        fun fromcolumns(a:Array<IntArray>):matrixP{
            val new = matrixP(a[0].size, a.size)
            for(i in a.indices){
                for(j in a[0].indices){
                    new[j][i] = a[i][j]
                }
            }
            return new
        }
    }
    val A = Array(n){IntArray(m)}

    infix operator fun times(other: matrixP): matrixP {
        assert(m == other.n)
        val ret = matrixP(n,other.m)
        for(i in 0 until n){
            for(k in 0 until m){
                for(j in 0 until other.m){
                    ret.A[i][j] = ret.A[i][j] modplus ( A[i][k] modm other.A[k][j])
                }
            }
        }
        return ret
    }
    fun print(){
        for(i in 0 until n){
            println(A[i].joinToString(" "))
        }
        println()
    }
    operator fun get(i:Int):IntArray{
        return A[i]
    }

    fun elimination():IntArray?{
//        assert(answer.size == this.n)
        //Always vertical

        val where = IntArray(m){-1}
        var row = 0
        val m = this.m - 1
        for(col in 0 until m){
            for(i in row until n){
                if(A[i][col] != 0){
                    val temp = A[i]
                    A[i] = A[row]
                    A[row] = temp
                    break
                }
            }
            if(A[row][col] == 0) continue
            where[col] = row
            for(i in 0 until n){
                val inv = intPow(A[row][col], p -2, p)
                if(i != row && A[i][col] != 0){
                    val c = localMul(A[i][col],inv)
                    for(j in col..m){
                        A[i][j] -= localMul(A[row][j],c)
                        A[i][j] = A[i][j].localAdjust()
                    }
                }
            }
            row ++
        }
        val ret = IntArray(m){0}
        for(i in 0 until m){
            if(where[i] != -1){
                ret[i] = localDivide(A[where[i]][m],A[where[i]][i])
            }
        }
        for(i in 0 until n){
            var sum = 0
            for(j in 0 until m){
                sum += localMul(ret[j],A[i][j])
                sum = sum.localAdjust()
            }
            if( sum != A[i][m]){
                return null
            }
        }
//        if(where.any { it == -1 }){
//            //infinity
//        }
        return ret
    }
}


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
class bitset (val n:Int ,val all:LongArray){
    constructor(n:Int):this(n,LongArray((n shr wordSizeShift) + 1 )){
    }
    companion object{
        const val wordSize = 64
        const val wordMask = 63
        const val wordSizeShift = 6
        const val allfalse = 0L
        const val alltrue = allfalse.inv()
        val allmask = LongArray(wordSize){1L shl it}
        val invertAllMask = LongArray(wordSize){(1L shl it).inv()}
    }
    val size:Int get() = all.sumOf { it.countOneBits() }
    fun Long.element(a:Int):Boolean{
        return (this and (1L shl a)!= 0L)
    }
    operator fun get(i:Int):Boolean{
        return all[i shr wordSizeShift].element(i and wordMask)
    }
    operator fun set(i:Int,v:Boolean){
        if(v){
            all[i shr wordSizeShift] = all[i shr wordSizeShift] or allmask[i and wordMask]
        }else{
            all[i shr wordSizeShift] = all[i shr wordSizeShift] and invertAllMask[i and wordMask]
        }
    }
    infix fun and(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] and other.all[i]
        }
        return new
    }
    infix fun or(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] or other.all[i]
        }
        return new
    }
    infix fun xor(other:bitset):bitset{
        kotlin.assert(this.n == other.n)
        val new = bitset(n)
        for(i in all.indices){
            new.all[i] = this.all[i] xor other.all[i]
        }
        return new
    }
    fun copy():bitset{
        return bitset(n,all.copyOf())
    }



    fun andAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] and other.all[i]
        }
    }
    fun orAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] or other.all[i]
        }
    }
    fun xorAssign(other:bitset){
        for(i in all.indices){
            this.all[i] = this.all[i] xor other.all[i]
        }
    }
    fun issuperset(other:bitset): Boolean {
        for(i in all.indices){
            if(this.all[i].inv() and other.all[i] != 0L){
                return false
            }
        }
        return true
    }
    fun issubset(other:bitset):Boolean{
        return other.issuperset(this)
    }

    fun orAssignShifted(other:bitset,otherShift:Int){
        //obviously, used in knapsacking, safe to use itself
        kotlin.assert(otherShift >= 0)
        if(otherShift and wordMask == 0){
            val take = otherShift shr wordSizeShift
            for(i in all.lastIndex downTo take){
                all[i] = all[i] or other.all[i - take]
            }
        }else{
            val bins = otherShift shr wordSizeShift
            val extra = otherShift and wordMask
            for(i in all.lastIndex downTo bins){
                var now = all[i]
                now = now or (other.all[i - bins] shl extra)
                if(i != bins) now = now or (other.all[i - bins - 1] ushr (wordSize - extra))
                all[i] = now
            }
        }
    }

    override fun toString(): String {
        return (0 until n).map { if(this[it]) '1' else '0' }.joinToString("")
    }

    fun prefixMask(upto:Int): Long {
        return alltrue ushr (63 - upto)
    }
    fun suffixMask(downto:Int):Long {

        return alltrue shl downto
    }
    fun negate(from:Int, to:Int){
        val a = from shr wordSizeShift
        all[a] = all[a] xor suffixMask(from and wordMask)
        val b = to shr wordSizeShift
        all[b] = all[b] xor prefixMask(to and wordMask)
        if(a== b){
            all[a] = all[a].inv()
        }
        for(i in a+1 until b){
            all[i] = all[i].inv()
        }
    }





}
class solvermod2(val m:Int) {
    val arr = mutableListOf<bitset>()
    fun addrelation(b:BooleanArray,tar:Boolean){
        kotlin.assert(b.size == m)
        val nb = bitset(m+1)
        for(i in b.indices){
            nb[i] = b[i]
        }
        nb[m] = tar
        arr.add(nb)
    }
    fun solve():BooleanArray?{
//        assert(answer.size == this.n)
        //Always vertical
        val n = arr.size
        val where = IntArray(m){-1}
        var row = 0
        for(col in 0 until m){
            if(row >= n ) break
            for(i in row until n){
                if(arr[i][col]){
                    arr[i] = arr[row].also { arr[row] = arr[i] }
                    break
                }
            }
            if(!arr[row][col]) continue
            where[col] = row
            for(i in 0 until n){
                if(i != row && arr[i][col]){
                    arr[i].xorAssign(arr[row])
                }
            }
            row ++
        }
        val ret = BooleanArray(m)
        for(i in 0 until m){
            if(where[i] != -1){
                ret[i] = arr[where[i]][m]
            }
        }
        val retbs = bitset(m+1)
        for(i in 0 until m){
            retbs[i] = ret[i]
        }
        retbs[m] = false
        for(i in 0 until n){
            val expect = arr[i][m]
            val got = (retbs.and(arr[i])).size
            if((got and 1 ==1) != expect){
                return null
            }
        }
//        if(where.any { it == -1 }){
//            //infinity
//        }
        return ret
    }
}
fun debug(){}
const val singleCase = true
fun main(){
//    val box = solvermod2(3)
//    box.addrelation(booleanArrayOf(true,false,false),true)
//    box.addrelation(booleanArrayOf(true,true,false),false)
//    box.addrelation(booleanArrayOf(false,true,false),false)
////    box.addrelation(booleanArrayOf(true,true,true),false)
//    just dei box.solve()!!
    solve.cases{
        val n = getint
        val k = getint
        val empty = matrixP(2,1)
        val ycol = intArrayOf(1, 0)
        val Y = matrixP.columnvector(ycol)
        val bcol = intArrayOf(0, 1)
        val B = matrixP.columnvector(bcol)
        val rcol = intArrayOf(1, 1)
        val R = matrixP.columnvector(rcol)

        val rbswap = matrixP.fromcolumns(arrayOf(ycol,rcol))
        val ryswap = matrixP.fromcolumns(arrayOf(rcol,bcol))
        val ybswap = matrixP.fromcolumns(arrayOf(bcol,ycol))

        val perm = Array(n){matrixP.identity(2)}
        val box = solvermod2(2 * n)
        repeat(k){
            val command = getstr
            val len = getint
            val L = getline(len)
            for(i in 0 until len){
                L[i] --
            }
            if(command == "mix"){
                val colour = getstr
                val rows = Array(2){BooleanArray(2 * n)}
                for(c in L){
                    for(i in 0 until 2){
                        for(j in 0 until 2){
                            rows[i][ 2 * c + j] = perm[c][i][j] == 1
                        }
                    }
                }
                val t1 = colour == "Y" || colour == "R"
                val t2 = colour == "B" || colour == "R"
                box.addrelation(rows[0], t1)
                box.addrelation(rows[1],t2)
            }else{
                val new = when(command){
                    "RB" -> rbswap
                    "RY" -> ryswap
                    "YB" -> ybswap
                    else -> matrixP.identity(0)
                }
                for(i in L){
                    perm[i] = new * perm[i]
                }
            }

        }
        val ans = box.solve()
        if(ans == null){
            put("NO")
        }else{
            val table = arrayOf(
                charArrayOf('.','B'), charArrayOf('Y', 'R'))
            val ret = mutableListOf<Char>()
            for(i in 0 until n){
                val c1 = ans[i * 2].chi
                val c2 = ans[i * 2 + 1].chi
                ret.add(table[c1][c2])
            }
            put("YES")
            put(ret.conca())
        }









    }
    done()
}