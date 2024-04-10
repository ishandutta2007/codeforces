// 2022.07.21 at 18:45:49 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.absoluteValue
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 998244353L
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
    private const val BS = 1 shl 6
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
    fun flush(){
        OUT.flush()
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
/*
no full strenght needed
 */


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

class path(var start:Int, var end:Int,var st:ArrayDeque<Int> = ArrayDeque() ){
    var reversed = false
    var redsum = 0
    var totalsum = 0

    init{
        for(i in st.indices){
            val v = st[i]
            val s= intPow(2,v,pI)
            if(i and 1 == 1){
                redsum = redsum modPlus s
            }
            totalsum = totalsum modPlus s
        }
    }
    fun contribute(){
        RStotal = RStotal modPlus redsum
    }
    fun decontribute(){
        RStotal = RStotal modMinus redsum
    }

    inline fun each(invert:Boolean,act:(Int)->Unit){
        if(!(reversed xor invert)){
            for(v in st){
                act(v)
            }
        }else{
            for(v in st.reversed()){
                act(v)
            }
        }
    }
    fun addLast(v:Int){
        if(reversed){
            st.addFirst(v)
        }else{
            st.addLast(v)
        }
    }
    fun addFirst(v:Int){
        if(reversed){
            st.addLast(v)
        }else{
            st.addFirst(v)
        }
    }

    fun reverse(){
        start = end.also { end = start }
        this.decontribute()
        if(this.st.size and 1 == 0){
            redsum = totalsum modMinus redsum
        }
        this.contribute()
        reversed = !reversed
    }
    fun merge(other:path) {
        assert(this.end == other.start)
        this.decontribute()
        other.decontribute()
        this.end = other.end
        this.totalsum = this.totalsum modPlus  other.totalsum
        if(this.st.size and 1 == 1){
            other.redsum = other.totalsum modMinus other.redsum
        }
        this.redsum = this.redsum modPlus other.redsum
        this.contribute()
        if(this.st.size >= other.st.size) {
            other.each(false) { v ->
                this.addLast(v)
            }
        } else {
            this.each(true) { v ->
                other.addFirst(v)
            }
            this.reversed = other.reversed
            this.st = other.st
        }
    }
    fun useasstart(v:Int){
        if(start != v){
            this.reverse()
        }
    }
}
var RStotal = 0

var from = mint
var to = mint

fun what(v:Int):Pair<Int,Int>{
    return Pair(from[v], to[v])
}
fun debug(){}
const val singleCase = true
fun main(){

    solve.cases{
        val (n_1,n_2,m) = readLine()!!.split(" ").map { it.toInt() }
//        val n_1 = getint
//        val n_2 = getint
//        val m = getint


        fun left(a:Int):Int{
            return a
        }
        fun right(a:Int):Int{
            return a + n_1
        }
        val all = MutableList<path?>(n_1 +n_2){null}
        val cleanpath = mutableListOf<path>()

//        val from = mint
//        val to = mint

        fun path.print(){
            just dei st.map{"<${from[it-1]} ${to[it-1]}>"}
        }

        var lastedge = 0
        fun print(){
            val ret = IntArray(lastedge+1)
            val used = BooleanArray(lastedge + 1)
            for(c in cleanpath){
//                c.print()
                for((i,v) in c.st.withIndex()){
                    ret[v] = i and 1
                    if(c.reversed){
                        ret[v] = 1 - ret[v]
                    }
                    used[v] = true
                }
            }
            for(x in all){
                if(x != null){
//                    x.print()
                    if(x.reversed){
                        for(i in x.st.lastIndex downTo 0){
                            ret[x.st[i]] = (x.st.lastIndex - i) and 1
                        }
                    }else{
                        for(i in 0 until x.st.size){
                            ret[x.st[i]] = i and 1
                        }
                    }
                    for(a in x.st){
                        used[a] = true
                    }
                }
            }
            val full =ret.indices.filter{ret[it] == 1}
            put(full.size)
            put(full.conca())

            val degree = IntArray(n_1 + n_2)
            val total = IntArray(n_1 +n_2)
            for(i in 1..lastedge){
                val a = from[i-1]
                val b= to[i-1]
                if(ret[i]==1){
                    degree[a] ++
                    degree[b] ++
                }
                total[a] ++
                total[b] ++
            }


//            just dei used
            for(i in 0 until n_1 + n_2){
                val x = degree[i]
                val y  =total[i] - degree[i]
                assert((x-y).absoluteValue <= 1 )

            }

        }

        fun add(a:Int,b:Int){
            lastedge ++
            from.add(a)
            to.add(b)
            val newpath = path(a,b,ArrayDeque(listOf(lastedge)))
            newpath.contribute()

//            newpath.print()
            if(all[b] != null){
                val other = all[b]!!

//                other.print()
                all[other.start] = null
                all[other.end] = null
                other.useasstart(b)
                newpath.merge(other)
            }
//            newpath.print()
            if(all[a] != null){
                val other = all[a]!!
//                other.print()
                all[other.start] = null
                all[other.end] = null
                other.useasstart(a)
                newpath.reverse()
                newpath.merge(other)
            }
//            newpath.print()
            assert(all[newpath.start] == null)
            assert(all[newpath.end] == null)
            if(newpath.start == newpath.end){
                cleanpath.add(newpath)
            }else{
                all[newpath.start] = newpath
                all[newpath.end] = newpath
            }
//            print()

        }


        repeat(m){
            var (a,b) = readLine()!!.split(" ").map { it.toInt() }
            add(a - 1, right(b - 1))
//            print()
        }
        val q = readLine()!!.toInt()
        repeat(q){
            val L = readLine()!!.split(" ").map { it.toInt() }
            val t = L[0]
            if(t == 1) {
                add(left(L[1] - 1), right(L[2] - 1))
                put(RStotal)
            }else{
                print()
            }
            Reader.flush()
        }
    }
    done()
}
/*
2 3 3
1 1
1 2
1 3
6
2
1 2 1
2
1 2 2
2
1 2 3
2

20 20 20
8 3
2 11
2 2
9 11
5 10
6 10
17 8
6 19
19 18
10 1
17 18
20 18
17 20
2 6
20 16
10 11
8 15
12 17
20 11
4 8
20
1 3 3
2
1 4 17
2
1 10 20
2
1 16 15
2
1 14 19
2
1 16 10
2
1 17 19
2
1 6 16
2
1 15 19
2
1 19 11
2


 */