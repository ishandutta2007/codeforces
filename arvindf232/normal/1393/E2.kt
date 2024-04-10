// 2022.06.04 at 19:31:56 HKT
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
class sameIndexCompare(val a:String, val b:String){
    val n = maxOf(a.size, b.size)
    val compare = IntArray(n){
        if(it !in a.indices) return@IntArray -b[it].compareTo('#')
        if(it !in b.indices) return@IntArray a[it].compareTo('#')
        a[it].compareTo(b[it])
    }

    //    val abrute = a.padEnd(n,'#')
//    val bbrute = b.padEnd(n,'#')
    val nextuseful = IntArray(n){
        if(compare[it] != 0) it else Int.MAX_VALUE
    }
    init{
        for(i in n-2 downTo 0){
            nextuseful[i] = minOf(nextuseful[i], nextuseful[i+1])
            if(compare[i] == 0) compare[i] = compare[i+1]
        }
    }
    fun query(l:Int, r:Int):Int{
//        assert(l in 0 until n)
//        assert(r in 0 until n)
//        val ll = maxOf(0,l)
//        val rr = minOf(n-1,r)
        val ll = l
        val rr = r
        if(ll > rr) return 0
        val useful = nextuseful[ll]
        if(useful > rr) return 0
        return compare[ll]
    }
//    fun querybrute(l:Int, r:Int):Int{
//        return abrute.slice(l..r).compareTo(bbrute.slice(l..r))
//    }
}
inline fun mergeComparator(a:IntArray, b:IntArray, cc:(l:Int, r:Int)->Int, cb:(right:Boolean,value:Int)->Unit){
    //left before right
    var i = 0
    var j = 0
    while (i < a.size && j < b.size)  if (cc(a[i],b[j]) <= 0) cb(false,a[i++]) else cb(true,b[j++])
    while (i < a.size) cb(false,a[i++])
    while (j < b.size) cb(true,b[j++])
}

fun debug(){}
const val singleCase = true
fun main(){
//    repeat(100){
//        val str = List(70){listOf('a', 'b').random()}.conca()
//        val str2 = List(100){listOf('a', 'b').random()}.conca()
//        val n = maxOf(str.size , str2.size)
//        val cc = sameIndexCompare(str,str2)
//        for(i in 0 until n) {
//            for(j in i until n){
//                val a = cc.query(i,j)
//                val bx =  cc.querybrute(i,j)
//                val b = if(bx >= 1) 1 else if(bx <= -1 ) -1 else 0
//                assert(a == b)
//            }
//        }
//    }

//    val s = getstr
//    just dei s
    solve.cases{
        val n = getint
        val all = List(n){ "$getstr#" }
        var DP = IntArray(all[0].size){1}
        fun order(s:String):IntArray{
            val ret = IntArray(s.size)
            var l = 0
            var r = ret.lastIndex
            val nextdifferent = CharArray(s.size)
            for(i in s.lastIndex downTo 0){
                if(i == s.lastIndex) continue
                if(s[i] != s[i+1]){
                    nextdifferent[i] = s[i+1]
                }else{
                    nextdifferent[i] = nextdifferent[i+1]
                }
            }
            for(i in 0 until s.size){
                if(nextdifferent[i] > s[i]) {
                    ret[r] = i
                    r --
                }else{
                    ret[l] = i
                    l ++
                }
            }
//            for(c in ret){
//                just dei s.removeRange(c..c)
//            }
            return ret
        }

//        val s = order("facade")
        val orders = Array(n){order(all[it])}

        for(i in 0 until n-1){
            val A = all[i]
            val B = all[i+1]

            val leftminus1 = sameIndexCompare(A.drop(1), B)
            val equal = sameIndexCompare(A,B)
            val rightminus1 = sameIndexCompare(A, B.drop(1))
            fun compare(left:Int, right:Int):Int{
                val r1 = equal.query(0,minOf(left,right) - 1)
                if(r1 != 0) return r1
                val r2 = if(left <= right) leftminus1.query( minOf(left,right), right - 1) else rightminus1.query(minOf(left, right), left -1)
                if(r2 != 0 )return r2
                val r3 = equal.query(maxOf(left,right) + 1, maxOf(A.lastIndex, B.lastIndex))
                if(r3 != 0) return r3
                return -1
            }
            var now = 0
            val ret = IntArray(B.size)
            mergeComparator(orders[i], orders[i+1], {l,r ->compare(l,r)}, {right,v ->
//                just dei "$right $v"
                if(right){
                    ret[v] = now
                }else{
                    now = now modPlus DP[v]
                }
            })

            DP = ret
        }
        var now = 0
//        val l = all.last()
//        val actual = IntArray(l.size)
//        for(i in DP.indices){
//            actual[orders.last()[i]] = DP[i]
//        }
//        for(i in 0 until all.last().size ){
//            if(i == l.lastIndex || l[i] != l[i+1]){
//                now = now modPlus actual[i]
//            }
//        }
        for(a in DP){
            now = now modPlus a
        }
        put(now)





    }
    done()
}

/*
1
aaaaa

12
aaaaaaaaa
bbbbbbbbb
ccccccccc
ddddddddd
eeeeeeeee
fffffffff
ggggggggg
hhhhhhhhh
iiiiiiiii
jjjjjjjjj
xxxxxxxxx
zzzzzzzzz


2
aa
ab

2
ba
aab

2
aba
aa

 */