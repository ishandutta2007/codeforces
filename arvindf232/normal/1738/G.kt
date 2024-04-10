// 2022.09.27 at 12:50:58 BST
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
infix fun Int.modMinus(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this modM (b.inverse()) }
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
// 3. convenience conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 10000
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
}
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun eat(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>()}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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

fun Array<BooleanArray>.flip():Array<BooleanArray> {

    val n = this.size
    return Array(n){i ->BooleanArray(n){j -> this[n-1-i][n-1-j]} }
}
fun Array<IntArray>.flip():Array<IntArray> {

    val n = this.size
    return Array(n){i ->IntArray(n){j -> this[n-1-i][n-1-j]} }
}

const val singleCase = false
fun main(){
    solve.rand {
        share(5)
        share(Random.nextInt(1..5))
        repeat(5){
            share(List(5){if(Random.nextBoolean()) '1' else '0'}.conca())
        }
    }
//    solve.userand()
    solve.cases{
        val n = getint
        val k = getint

        val board = Array(n){BooleanArray(n)}
        for(i in 0 until n){
            val str = getstr
            for(j in 0 until n){
                board[i][j] = str[j] == '1'
            }
        }

        val flow = k-1
        if(flow == 0){
            if(board.any { it.any { !it } }){
                put("NO")
                return@cases
            }else{
                repeat(n){
                    put(List(n){'0'}.conca())
                }
                return@cases
            }
        }
        fun analyze(board:Array<BooleanArray>):Triple<Array<IntArray>, Array<IntArray>, Array<IntArray>> {
            val DP = Array(n){IntArray(n){-1} }
            val prefixmax = Array(n){IntArray(n){-1} }
            val minrank = Array(n){IntArray(n)}
            for(i in 0 until n){
                for(j in 0 until n){
                    val anti = i - j

                    if(board[i][j]){
                        var new = 0
                        if(i > 0)
                            new = maxOf(new, prefixmax[i-1][j])

                        if(j > 0)
                            new = maxOf(new, prefixmax[i][j-1])

                        prefixmax[i][j] = new

                        continue
                    }
                    if(anti in n-flow+1..n-1){
                        continue
                    }
                    if(- anti in n-flow+1..n-1){
                        continue
                    }
                    var max = 0
                    if(i > 0 && j > 0){
                        max = maxOf(max,prefixmax[i-1][j-1])
                    }
                    DP[i][j] = max +1
                    var new = max+1
                    if(i >0){
                        if(prefixmax[i-1][j] > new){
                            IntArray(1000000000)
                        }
                        new = maxOf(new, prefixmax[i-1][j])
                    }
                    if(j > 0){
                        if(prefixmax[i][j-1] > new){
                            IntArray(1000000000)
                        }
                        new= maxOf(new, prefixmax[i][j-1])
                    }
                    prefixmax[i][j] = new
                }
            }

            for(i in 0 until n){
                for(j in 0 until n){
                    var now = maxOf(DP[i][j],0)
                    if(i > 0 && j > 0){
                        now = maxOf(now, prefixmax[i-1][j-1] + 1 )
                    }
                    minrank[i][j] = now
                }
            }
            return Triple(DP,prefixmax,minrank)
        }

        val (dp1,p1,r1) = analyze(board)

        val t2 = analyze(board.flip())
        val (dp2,p2,r2) = Triple(t2.first.flip(), t2.second.flip(), t2.third.flip())
        for(i in 0 until n){
            for(j in 0 until n){
                r2[i][j] = (flow + 1) - r2[i][j]
            }
        }
        if(dp1.any{it.any { it > flow }}){
            put("NO")
            return@cases
        }
        if(dp2.any { it.any{it > flow} }){
            put("NO")
            return@cases
        }

        val ret = Array(n){BooleanArray(n)}
        for(i in 0 until n){
            for(j in 0 until n){
                val anti = i - j

                if(anti >= n-flow || anti < -(n-flow)){
                    ret[i][j] =true
                }
            }
        }
        for(f in 0 until flow){
            var x = n-flow+f
            var y = f
            val r = f + 1

            val tarx = f
            val tary = n- flow + f
            while(x != tarx || y != tary){
                if(x > tarx && r in r1[x-1][y]..r2[x-1][y]){
                    x --
                    assert(!ret[x][y])
                    ret[x][y] = true
                    continue
                }
                if(y < tary && r in r1[x][y+1]..r2[x][y+1]){
                    y++
                    assert(!ret[x][y])
                    ret[x][y] = true
                    continue
                }
            }

        }

//        val bins = Array(flow){ mutableListOf<Pair<Int,Int>>() }
//

//        for(v in bins){
//            v.sortByDescending { it.first - it.second }
//        }
//        val z = 0
//
//
//        for(v in bins){
//            var (x,y) = v.first()
//            ret[x][y] = true
//            for((nx,ny) in v){
//                while(x != nx || y != ny){
//                    if(x > nx && !ret[x-1][y]){
//                        x --
//                        ret[x][y] = true
//                    }
//                    if(y < ny && !ret[x][y+1]){
//                        y++
//                        ret[x][y] = true
//                    }
//                }
//            }
//        }
//
////        just dei ret
        put("YES")
        for(c in ret){
            put(List(c.size){if(c[it]) '1' else '0'}.conca())
        }


        val x = 0








    }
    done()
}
/*
1
4 3
1110
0101
1010
0111


4
2 2
10
01
4 3
1110
0101
1010
0111
5 5
01111
10111
11011
11101
11110
5 2
10000
01111
01111
01111
01111

1
4 4
0111
1111
1111
1110

1
5
5
10000
01111
00100
01111
10000

 */