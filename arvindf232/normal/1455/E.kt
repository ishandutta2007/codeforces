// 2022-04-16, Sat, 18:42
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.absoluteValue

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

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
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
        if(withBruteForce){
            println("Brute force is active")
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
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
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

fun debug(){}
const val withBruteForce = false
const val singleCase = false
fun main(){
    val all4 = permutation.all(4)
    solve.cases{
        val X = LongArray(4)
        val Y = LongArray(4)
        repeat(4){
            X[it] = getlong
            Y[it] = getlong
        }
        val ds = mutableSetOf<Long>()
        for(x in X){
            for(x2 in X){
                ds.add((x2-x).absoluteValue)
            }
        }
        for(y in Y){
            for(y2 in Y){
                ds.add((y2-y).absoluteValue)
            }
        }
        val alld = ds.toLongArray()
        var XI:LongArray = X
        var YI:LongArray = Y
        var ret = phuge
        fun check(x:Long, y:Long, d:Long){
            var ans = 0L
            ans += (XI[0] - x).absoluteValue + (XI[1] - x).absoluteValue
            ans += (XI[2] - x -d).absoluteValue + (XI[3] - x - d).absoluteValue
            ans += (YI[0] - y).absoluteValue + (YI[2] - y).absoluteValue
            ans += (YI[1] - y -d).absoluteValue + (YI[3] - y - d).absoluteValue
            ret = minOf(ans,ret)
        }

        for(p  in all4){
            XI = LongArray(4){X[p[it]]}
            YI = LongArray(4){Y[p[it]]}
            for(x in X){
                for(y in Y){
                    for(otherx in X){
                        check(x, y , otherx - x)
                    }
                    for(othery in Y){
                        check(x,y, othery - y)
                    }
//                    for(d in alld){
//                        check(x,y,d)
//                        check(x-d,y,d)
//                        check(x-d,y-d,d)
//                        check(x,y-d,d)
//                    }
                }
            }
        }
        put(ret)




    }
    done()
}



/*
1 6
2 2
2 5
4 1

 */