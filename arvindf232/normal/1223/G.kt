
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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


typealias sparseType = Long
typealias sparseArrayType = LongArray

class sparseTable(val arr: sparseArrayType){
    val n = arr.size
    val store = mutableListOf<sparseArrayType>()
    init{
        preprocess()
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
                val new = sparseArrayType(size)
                for(i in 0 until size){
                    new[i] = combine(old[i],old[i+olds])
                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun combine(a:sparseType, b:sparseType):sparseType{
        return dmaxcombine(a,b)
    }
    val empty = 0L

    fun query(l:Int,r:Int):sparseType{
        var r = minOf(r,arr.lastIndex)
        if(l > r) return empty

        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return combine(ret1,ret2)
    }
}
fun dmaxcombine(a:Long, b:Long):Long {
    var a = a
    var b = b
    if(a.first < b.first){
        a=b.also { b = a  }
    }
    if(a.second > b.first){
        return a
    }else{
        return makepair(a.first,b.first)
    }
}

class rsq(val arr:List<Int>) {
    val ps = LongArray(arr.size + 1)
    init{
        for(i in 0 until arr.size){
            ps[i+1] = ps[i] + arr[i]
        }
    }
    fun sumQuery(l:Int,r:Int):Long{
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] - ps[ll]
    }
}
class rsqArr(val arr:IntArray) {
    val ps = LongArray(arr.size + 1)
    init{
        for(i in 0 until arr.size){
            ps[i+1] = ps[i] + arr[i]
        }
    }
    fun sumQuery(l:Int,r:Int):Long{
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] - ps[ll]
    }
}
fun IntArray.torsq(): rsqArr {
    return rsqArr(this)
}
fun List<Int>.torsq():rsq{
    return rsq(this)
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
//infix fun Int.modPlus(b:Int):Int{
//    val ans = this + b
//    return if(ans >= pI) ans - pI else ans
//}
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
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
fun intPowEXP(x:Int,e:Long,m:Int):Int{
    var X = x
    var E =e
    var Y = 1
    while(E > 0){
        if(E % 2 == 0L){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
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
fun min_rem(m:Int, r:Int, c:Int):Int {
    if(c < 1){
        return Int.MIN_VALUE
    }else if(r == 0){
        return 0
    }else{
        val step = m % r
        val mx = ((1L * c * r) /m ).toInt()
        val t = max_rem(r,step,mx)
        return r- t
    }
}
fun max_rem(m:Int, r:Int, c:Int):Int {
    if(r == 0|| c <= m/r){
        return r * c
    }else{
        val step =  m % r
        val mx = ((1L * (c+1) * r )/m).toInt()
        val t = min_rem(r,step,mx)
        return  m - t
    }
}
fun Int.reconstruct():String{
    val num = min_rem(pI,this, 10000)
    val denom = (this modDivide num).inverse()
    return "$num / $denom"
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
fun dmod(a:Long, y:Int):Long{
    return makepair(a.first % y, a.second % y )
}

fun upmod(x:Int,y:Int):Int{
    val v = x % y
    return if(v == 0) y else v
}
typealias dsparseType = Long
typealias dsparseArrayType = LongArray
class disjointSparseTable (val oldA:dsparseArrayType){
    val empty = 0L
    fun combine(l:dsparseType, r:dsparseType):dsparseType{
        return dmaxcombine(l,r)
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
        var y = minOf(y, oldA.lastIndex)
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
const val max = 500005
const val singleCase = true

/*
5
2 3 4 5 10
 */
fun main(){
    solve.rand{
        share(5)
        repeat(5){
            share(Random.nextInt(2..10))
        }

    }
    solve.tc {
        share("""
            5
            2 3 4 5 10 
        """.trimIndent())
    }
//    solve.usetc()
//    solve.userand()
    solve.cases{
        val n = getint
        val L = getline(n)


        fun brute():Long {
            val max = 10
            var ans = 0L

            for(x in 2..max){
                for(y in 2..max){
                    for(lefttake in 0 until n){
                        for(righttake in 0 until n){
                            val Lnow = L.copyOf()
                            Lnow[lefttake] -= x
                            Lnow[righttake] -= x
                            if(Lnow[lefttake] < 0 || Lnow[righttake] < 0){
                                continue
                            }
                            var has = 0
                            for(a in Lnow){
                                has += a / y
                            }
                            if(has >= x){
                                ans = maxOf(ans, 1L * x* y )
                                continue
                            }
                        }
                    }
                }
            }
            return ans

        }

        val counts = IntArray(max)
        for(a in L){
            counts[a] ++
        }
        val countsQ = counts.torsq()
        val dmaxTable = LongArray(max)
        var largest = 0L
        for(i in 0 until max){
            val v = counts[i]
            if(v == 1){
                dmaxTable[i] = makepair(i,0)
            }else if(v >= 2 ){
                dmaxTable[i] = makepair(i,i)
            }
            largest = dmaxcombine(dmaxTable[i], largest)
//            if(i < 100)
//                i dei Pair(largest.first, largest.second)
        }
        val st = disjointSparseTable(dmaxTable)
        var ret = 0L

        fun update(x:Int, y:Int){
            if(x >= 2)
                 ret = maxOf(ret, 1L * x * y )

//            if(x >= 2 && y >= 2)
//            just dei "$x $y "
        }
        fun ask(atleast:Int,l:Int, r:Int):Long{
            val ll = maxOf(atleast, l)
            return st.query(ll,r)
        }
        fun bestMod(testx:Int, y :Int):Long{
            var canget = 0L
            for(ys in 0..max step y){
                canget = dmaxcombine(canget, dmod(ask(testx ,ys,ys+y - 1),y))
            }
            return canget
        }
        fun batchBestMod(xx:IntArray, y:Int):LongArray {
            var canget = 0L
            val next = (max/y) * y
            val ret = LongArray(xx.size)
            for(ys in next downTo 0 step y){
                for((i,v) in xx.withIndex()){
                    if(v in ys until ys + y){
                        ret[i] = dmaxcombine(canget, dmod(ask(v ,ys,ys+y - 1),y))
                    }
                }
                canget = dmaxcombine(canget, dmod(st.query(ys,ys+y-1),y))
            }
            return ret
        }
        val cache = mutableMapOf<Int,Long>()
        fun doThis(same:Boolean,largest:Long ,total:Long,x:Int,y:Int):Int{
            if(same){
                if(largest.first < 2 * x) return 0
                val best = cache[2* x]!!
                val need = if(best.first >= (2 * x) % y) ((2 * x)/ y) else ((2 *x) divCeil y)
                return minOf(x.toLong(),total - need ).toInt()
            }else{
                if(largest.second < x ) return 0
                val best = cache[x]!!
                val less = x / y
                val more = x divCeil y
                var totalneed = 0
                if(best.first >= upmod(x,y)){
                    totalneed += less
                }else{
                    totalneed += more
                }
                if(best.second >= upmod(x,y)){
                    totalneed += less
                }else{
                    totalneed += more
                }
                return minOf(x.toLong(),total - totalneed).toInt()
            }
        }


        for(y in 2..max){
            var tcount = 0L
            var mul = 1
            for(ys in y..max step y){
                tcount += mul * countsQ.sumQuery(ys, ys+y - 1 )
                mul ++
            }
            cache.clear()
            val rX = BinarySearchLastTrue(1,max){ x->
                x +  2 * (x divCeil y) <= tcount
            }?: 0

//            if(tcount > 0)
//                y dei "$tcount , $rX"

            val willask = intArrayOf(rX,rX+1,rX +2, 2 * rX, 2 * (rX+1), 2 * (rX+2))
            val all = batchBestMod(willask,y)
            for(i in 0 until 6){
                cache[willask[i]] = all[i]
            }
            if(2 * rX > largest.first){
                update(minOf(rX, largest.first / 2 ), y)
            }else {

                update(doThis(true, largest, tcount, rX + 2, y), y)
                update(doThis(true, largest, tcount, rX + 1, y), y)
                update(doThis(true, largest, tcount, rX, y), y)
            }
            if(rX > largest.second) {
                update(minOf(rX, largest.second), y)
            }else{
                update(doThis(false,largest,tcount,rX +2,y), y)
                update(doThis(false,largest,tcount,rX +1,y), y)
                update(doThis(false,largest,tcount,rX,y), y)
            }
//            just dei calls
        }
//        val bt = brute()
//
//        ret dei bt
//        assert(ret == bt)
        put(ret)
    }
    done()
}

/*

learnt: Sieve > sqrt, almost always

2
11 12

9
3 4 3 5 3 3 10 6 4

 */