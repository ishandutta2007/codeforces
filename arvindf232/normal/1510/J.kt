// 2022.06.22 at 21:39:30 HKT
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
const val randCount = 100000
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
fun debug(){}
const val singleCase = true
infix fun Int.divceil(b:Int):Int{
    return (this/b) + if(this % b > 0) 1 else 0
}
infix fun Long.divceil(b:Long):Long{
    return (this/b) + if(this % b > 0) 1L else 0L
}
infix fun Int.div_neg_floor(b:Int):Int{
    return (this/b) - if(this % b < 0) 1 else 0
}
infix fun Long.div_neg_floor(b:Long):Long{
    return (this/b) - if(this % b < 0) 1L else 0L
}
fun modCount(x:Long, mod:Long, l:Long, r:Long):Long{
    val ans = ((r -x) div_neg_floor mod ) - ((l - x) divceil mod) + 1
    return maxOf(ans,0)
    //coun number of x mod mod in [l..r]
}
fun main(){
    solve.rand{
        share(List(20){if(Random.nextBoolean()) '#' else '_'}.conca())

    }
    solve.tc{
        share("____######")
    }
//    solve.usetc()
//    just dei (-1 and 1 )
//    solve.userand()
    solve.cases{

        val str = getstr
        val n = str.length
        val arr = BooleanArray(n){str[it] == '#'}
        fun check(ret:List<Int>, flex:Int){
            assert(ret.size -1  + ret.sum() + flex == n)
            val actual = BooleanArray(n)
            var now = 0
            for(c in ret){
//                val have = maxOf(0,c - flex)
                for(x in now + flex until now + c ){
                    actual[x] = true
                }
                now += c
                now ++
            }
            assert(arr.contentEquals(actual))
        }

        if(arr.all { !it }){
            put(0)
            return@cases
        }
        val last = arr.indexOfLast { it }
        val lines = mint
        var l = 0
        while(l < n){
            if(!arr[l]){
                l ++
                continue
            }
            val r = (l..n).first{it == n || arr[it] == false } - 1
            lines.add(r - l + 1)
            l = r + 1
        }
        val space1 = arr.indexOf(true)
        val end = n - 1 -last

        val middlespaces = mint
        l = space1
        while(l < n ){
            if(arr[l]){
                l ++
                continue
            }
            val r = (l..n).first{it == n || arr[it]} - 1
            if(r == n -1) break
            middlespaces.add(r - l + 1 )
            l = r + 1
        }


        // 0
        if(arr[0] && arr[n-1] && (0 until n-1).all { arr[it] || arr[it+1]  }){
            put(lines.size)
            put(lines.conca())
            check(lines,0)
            return@cases
        }
        //1
        assert(lines.size == middlespaces.size + 1 )
        if((space1 - 1) and 1 == 0 && end >= 1 && (end - 1 - 1) and 1 == 1 && middlespaces.all { it and 1 == 0 }){
            val ret = mint
            repeat((space1 - 1) divceil 2 ){
                ret.add(1)
            }
            for(i in lines.indices){
                ret.add(lines[i] + 1 )
                if(i in middlespaces.indices){
                    repeat((middlespaces[i]-1)/2){
                        ret.add(1)
                    }
                }
            }
            repeat((end -2) divceil 2 ){
                ret.add(1)
            }
            check(ret,1)
            put(ret.size)
            put(ret.conca())
            return@cases
        }
        val cannot = mutableSetOf<Int>()
        for(v in middlespaces){
            cannot.add(v - 2)
        }
        cannot.add(space1 - 1)
        cannot.add(end - 1 )

        fun middleconstruct(x:Int):MutableList<Int> {
            assert( x != 2)
            var had = x -1
            val ret= mint
            if(had and 1 == 1){
                ret.add(2)
                had -= 3
            }
            repeat(had/2){
                ret.add(1)
            }
            return ret
        }
        val use = (2..n).firstOrNull { it !in cannot  }

        if(use == null){
            put(-1)
            return@cases
        }
        if(use <= space1 && end >= use &&  middlespaces.all { it >= use + 1 }){
            val ret = mint
            ret.addAll(middleconstruct(space1 -1 - use  + 2 ))
            for(i in lines.indices){
                ret.add(lines[i] + use )
                if(i in middlespaces.indices){
                    ret.addAll(middleconstruct(middlespaces[i] - use))
                }
            }
            ret.addAll(middleconstruct(end -use -1  + 2 ))
            check(ret,use)
            put(ret.size)
            put(ret.conca())
            return@cases
        }else{
            put(-1)
            return@cases
        }






    }
    done()
}

/*

__#__#__#__
 */