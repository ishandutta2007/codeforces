// 2022.06.13 at 14:18:47 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.util.*
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
class bitPackerQuery(maxpack:Int, wantmax:Int, val available:IntArray){
    val DP = List(maxpack + 1){ bitset(wantmax + 1 )}
    init{
        DP[0][0] = true
        for(a in available){
            for(left in maxpack-1 downTo 0){
                DP[left + 1].orAssignShifted(DP[left],a)
            }
        }
    }
    fun able(count:Int, sum:Int):Boolean{
        return DP[count][sum]
    }
    fun getPackIndex(count:Int, sum:Int):List<Int>?{
        var endat = -1
        if(DP[count][sum]){
            endat = sum
        }
        if(endat == -1) return null
        val ret = mutableListOf<Int>()
        var remCount = count
        var remSize = endat
        for((i,v) in available.withIndex().reversed()){
            if(remSize - v < 0) continue
            if(DP[remCount-1][remSize - v]){
                remCount --
                remSize -= v
                ret.add(i)
                if(remCount == 0) break
            }
        }
        kotlin.assert(ret.sumOf { available[it] } == endat && ret.size == count)
        return ret
    }
    fun getPack(count:Int,sum:Int):List<Int>?{
        val ret = getPackIndex(count,sum) ?: return null
        return ret.map { available[it] }
    }
}
class bitpacker(wantmax:Int, val available:IntArray){
    val DP = List(available.size + 1){ bitset(wantmax + 1 )}
    init{
        DP[0][0] = true
        for((i,a) in available.withIndex()){
            DP[i+1].orAssignShifted(DP[i], 0)
            DP[i + 1].orAssignShifted(DP[i],a)
        }
    }
    fun able(sum:Int):Boolean{
        return DP.last()[sum]
    }
    fun getPackIndex(sum:Int):List<Int>?{
        if(!able(sum)) return null
        val ret = mutableListOf<Int>()
        var remSize = sum
        for((i,v) in available.withIndex().reversed()){
            if(remSize - v < 0) continue
            if(DP[i][remSize - v]){
                remSize -= v
                ret.add(i)
            }
        }
        kotlin.assert(ret.sumOf { available[it] } == sum)
        return ret
    }
    fun getPack(sum:Int):List<Int>?{
        val ret = getPackIndex(sum) ?: return null
        return ret.map { available[it] }
    }
}
class multiset(val st:TreeMap<Int, Int> = TreeMap()):MutableMap<Int,Int> by st {
    fun addall(a:IntArray){
        for(v in a) addone(v)
    }
    fun addall(a:List<Int>){
        for(V in a) addone(V)
    }
    fun addone(v:Int){
        st[v] = st.getOrDefault(v,0) + 1
    }
    fun removeone(v:Int):Boolean{
        val new = st.getOrDefault(v,0) - 1
        if(new == -1) return false
        if(new > 0) st[v] = new else st.remove(v)
        return true
    }
    fun pollLast():Int {
        val a = st.lastKey()
        removeone(a)
        return a
    }
    fun pollFirst():Int{
        val a = st.firstKey()
        removeone(a)
        return a
    }
    fun makelist():List<Int>{
        val ret = mutableListOf<Int>()
        for((k,v) in st){
            repeat(v){
                ret.add(k)
            }
        }
        return ret
    }
}
fun debug(){}
const val singleCase = false
fun main(){
    solve.cases{

        val a = getint
        val A = getline(a)
        val b = getint
        val B = getline(b)

        if(a != b){
            put("No")
            return@cases
        }
        val asum = A.sum()
        val bsum = B.sum()
        if(asum and 1 == 1 || bsum and 1 == 1){
            put("No")
            return@cases
        }
        val box1 = bitpacker(asum/2, A)
        val box2 = bitpacker(bsum/2, B)

        val astuff = multiset()
        val bstuff = multiset()
        for(at in A){
            astuff.addone(at)
        }
        for(bt in B){
            bstuff.addone(bt)
        }

            if(box1.able(asum/2) && box2.able(bsum/2)){
                val A1 = box1.getPack(asum/2)!!.toMutableList()
                val B1 = box2.getPack(bsum/2)!!.toMutableList()
                for(at in A1){
                    astuff.removeone(at)
                }
                for(bt in B1){
                    bstuff.removeone(bt)
                }
                val A2 = astuff.makelist().toMutableList()
                val B2 = bstuff.makelist().toMutableList()
                while(A1.size < B1.size){
                    A1.add( - A2.removeLast())
                }
                while(B1.size < A1.size){
                    B1.add( - B2.removeLast())
                }
                A1.sortDescending()
                B1.sort()
                A2.sortDescending()
                B2.sort()

                var ret = mutableListOf<Pair<Int,Int>>()
                var x =0
                var y = 0
//                ret.add(Pair(x,y))
                for(i in A1.indices){
                    y += A1[i]
                    ret.add(Pair(x,y))
                    x += B1[i]
                    ret.add(Pair(x,y))
                }
                for(i in A2.indices){
                    y -= A2[i]
                    ret.add(Pair(x,y))
                    x -= B2[i]
                    ret.add(Pair(x,y))
                }
                put("Yes")
                for((a,b) in ret){
                    put("$b $a")
                }
                return@cases

            }
        put("No")




    }
    done()
}

/*
need equal size both ways?
 */