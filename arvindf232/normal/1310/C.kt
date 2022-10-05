// 2022-05-21, Sat, 12:23
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
const val phuge = 1_100_000_000_000_000_000L
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
tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
class suffixArray ( str_recommend:String){
    // Remember adding an extra $ or not
    // just cannot use suffix array on n = 1M , asks for death
    companion object{
        const val alphabet = 256


        const val storeTables = true
    }
    val str = str_recommend + "$"
    //str.map{it.toInt()}
    val s = IntArray(str.length){str[it].toInt()}
    val n = s.size
    val p:IntArray //the suffix array
    val pos:IntArray // lookup where the suffix is
    var lcp:IntArray = IntArray(0)


    val ci = mutableListOf<IntArray>()

    init{

        val cnts = IntArray(alphabet)
        val p = IntArray(n) // permutation
        var c = IntArray(n) // classes
        for(i in 0 until n){
            cnts[s[i]]++
        }
        for(i in 1 until alphabet){
            cnts[i] += cnts[i-1]
        }
        for(i in 0 until n){
            p[--cnts[s[i]]] = i
        }
        var classes = 1
        for(i in 1 until n){
            if(s[p[i]] != s[p[i-1]]){
                classes ++
            }
            c[p[i]] = classes - 1
        }
        if(storeTables){
            ci.add(c)
        }

        val pn = IntArray(n)
        val cn = IntArray(n)
        for(h in 0..32){
            if((1 shl h) >= n){
                break
            }
            for(i in 0 until n){
                pn[i] = p[i] - (1 shl h)
                if(pn[i] < 0) pn[i] += n
            }
            val cnt2 = IntArray(classes){0}
            for(a in c){
                cnt2[a]++
            }
            for(i in 1 until classes){
                cnt2[i] += cnt2[i-1]
            }
            for(i in n-1 downTo 0 ){
                val new = --cnt2[c[pn[i]]]
                p[new] = pn[i]
            }
            cn[p[0]] = 0
            classes = 1
            for(i in 1 until n){
//                val cur = Pair(c[p[i]],c[(p[i] + (1 shl h)) % n])
//                val prev = Pair(c[p[i-1]],c[(p[i-1] + (1 shl h)) % n])
//                if(cur != prev){
//                    classes ++
//                }
                if((c[p[i]] != c[p[i-1]]) || (c[(p[i] + (1 shl h)) % n] != c[(p[i-1] + (1 shl h)) % n])){
                    classes ++
                }
                cn[p[i]] = classes - 1
            }

            c = cn.copyOf()
            if(storeTables){
                ci.add(c)
            }

        }
        this.p = p

        pos = IntArray(n)
        for ((i, v) in p.withIndex()) {
            pos[v] = i
        }
    }
    fun directComparison(t:String,l:Int,r:Int,strict:Boolean=true):Boolean{
        val min = minOf(t.length , r- l + 1 )
        val firstD = (0 until min).firstOrNull { t[it] != str[it  + l] }
        if(firstD == null){
            if(strict){
                return (t.length > (r-l+1))
            }else{
                return (t.length >= (r-l+1))
            }
        }else{
            return t[firstD] > str[firstD + l]
        }
    }



    fun findAnyMatch(t:String):Int?{
        val ans = BinarySearchFirstTrue(0,n-1){
            t <= str.substring(p[it] until n)
        } ?: return null
        if(str.substring(p[ans] until n).startsWith(t)){
            return p[ans]
        }else{
            return null
        }
    }
    fun Int.adjust():Int{
        if(this < 0){
            return this + n
        }else if( this >= n){
            return this - n
        }else{
            return this
        }
    }

    fun longestCommonPrefix(i:Int,j:Int):Int{
        var i = i
        var j = j
        var ans = 0
        for(k in ci.size downTo 0){
            if(ci[k][i] == ci[k][j]){
                ans += (1 shl k )
                i += 1 shl k
                j += 1 shl k
            }
        }
        return ans
    }
    var rmqlcp:rmq = rmq(IntArray(1))
    fun calculatelcp(){
        if(lcp.size != 0) return
        val rank = IntArray(n)
        for(i in 0 until n){
            rank[p[i]] = i
        }
        var k = 0
        lcp = IntArray(n-1)
        for(i in 0 until n){
            if(rank[i] == n-1){
                k = 0
                continue
            }
            val j = p[rank[i]+1]
            while(i +k < n && j + k < n && s[i+k] == s[j+k]){k++}
            lcp[rank[i]] = k
            if(k > 0){k --}
        }
        rmqlcp = rmq(lcp)
    }
    fun calculateLCPquick(i:Int,j:Int): rmqType {
        if(i == j) return n-i
        var p1 = pos[i]
        var p2 = pos[j]
        if(p1 > p2){
            p1 = p2.also { p2 = p1  }
        }
        return rmqlcp.query(p1,p2 - 1 )

    }
    fun lexigraphicalCompare(l1:Int, r1:Int, l2:Int, r2:Int):Int{
        val len1 = r1 - l1 + 1
        val len2 = r2 - l2 + 1
        val x = minOf(minOf(len1,len2),calculateLCPquick(l1,l2))
        if(x == len1 || x == len2){
            return len1.compareTo(len2)
        }else{
            return pos[l1].compareTo(pos[l2])
        }
    }
    fun treeEnd(): IntArray {
        calculatelcp()
        val ret = IntArray(n)
        val st = ArrayDeque<Int>()
        for(i in 0 until n){
            st.add(i)
            val downto = lcp.getOrElse(i){0}
            while(st.size > downto){
                val rem = st.removeLast()
                ret[rem] = i
            }
        }
        return ret
    }

    fun print(){
        println(this.p.joinToString(" "))
    }
    fun visualise(){
        for((i,v) in p.withIndex()){
            println(str.slice((v)..str.lastIndex))
            if( i < n-1 && lcp.size != 0){
                println(lcp[i])
            }
        }
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

private operator fun <A:Comparable<A>, B:Comparable<B>> Pair<A, B>.compareTo(other: Pair<A, B>): Int {
    if(this.first < other.first){
        return -1
    }else if (this.first > other.first){
        return 1
    }else if(this.second < other.second){
        return -1
    }else if(this.second > other.second){
        return 1
    }else{
        return 0
    }

}

typealias rmqType = Int
typealias rmqArrayType = IntArray

class rmq(val arr: rmqArrayType){
    val n = arr.size
    val store = mutableListOf<rmqArrayType>()
    init{
        preprocess()
    }
    companion object{
        const val max = false
    }
    private fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = rmqArrayType(size)
                for(i in 0 until size){
                    if(max){
                        new[i] = maxOf(old[i],old[i+olds])
                    }else{
                        new[i] = minOf(old[i],old[i+olds])
                    }

                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun query(l:Int,r:Int):rmqType{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return if(max) maxOf(ret1,ret2) else minOf(ret1,ret2)
    }
}

fun debug(){}
const val singleCase = true
fun main(){
    solve.cases{
        val n = getint
        val m = getint
        val k = getlong
        val str = getstr
        val all = mutableListOf<Pair<Int,Int>>()
        for(i in 0 until n) {
            for(j in i until n) {
                all.add(Pair(i,j))
            }
        }
        val S = suffixArray(str)
        S.calculatelcp()
        all.sortWith({p1,p2 -> S.lexigraphicalCompare(p1.first,p1.second,p2.first, p2.second)})



        fun calculate(idx:Int):Long{
            val (a,b) = all[idx]
            val s = str.slice(a..b)
            val DP = Array(n+1){LongArray(m+1)}
            DP[0][0] = 1
            first@for(p in 0 until n){
                if(p != 0){
                    for(taken in 0..m){
                        DP[p + 1][taken] += DP[p][taken]
                        if(DP[p+1][taken] >= phuge){
                            DP[p+1][taken] = phuge
                        }
                    }
                }

                var startfrom = 0
                for(i in 0 until s.size){
                    if(p + i !in 0 until n){
                        continue@first
                    }
                    if(s[i] != str[p+i]){
                        if(s[i] > str[p+i]){
                            continue@first
                        }else{
                            startfrom = p + i
                            break
                        }
                    }
                    startfrom = p + i
                }

                for(taken in 0 until m){
                    DP[startfrom + 1][taken+1] += DP[p][taken]
                    if(DP[startfrom+1][taken+1] >= phuge){
                        DP[startfrom+1][taken+1] = phuge
                    }
                }

            }
            val have = DP[n][m]
            return have
        }
//        for((i,p) in all.withIndex()){
//            val (a,b) = p
//            calculate(i) dei str.slice(a..b)
//        }

        val ans = BinarySearchLastTrue(0,all.lastIndex){ idx ->
            return@BinarySearchLastTrue calculate(idx) >= k
        }!!




        val (a,b) = all[ans]
        put(str.slice(a..b))


    }
    done()
}


/*
4 2 3
abac

 */