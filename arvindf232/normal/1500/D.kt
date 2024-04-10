// 2022.06.20 at 21:13:48 HKT
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
fun debug(){}
const val singleCase = true
inline fun mergeArrayCB(left:IntArray,right:IntArray, cb:(which:Int,i:Int)->Unit){
    var lp = 0
    var rp = 0
    while(true){
        val lreach = lp != left.size
        val rreach = rp != right.size
        if(!lreach && !rreach) break
        val goleft = (lreach && rreach && left[lp] < right[rp]) || (!rreach)
        if(goleft){
            cb(0,lp)
            lp++
        }else{
            cb(1,rp)
            rp++
        }
    }
}
fun main(){
    solve.cases{
        val n = getint
        val q = getint
        val arr = Array(n){getline(n)}
        val max = Array(n){IntArray(n)}
        val colours = Array(n){Array(n){IntArray(q)}}
        val earliest = Array(n){Array(n){IntArray(q)}}

        val emptycolour = IntArray(0)
        val emptyearliest = IntArray(0)

        fun merge(x:Int, y:Int, rank:Int):Pair<IntArray,IntArray>? {
            if(x < rank || y < rank) return null
            val a = if(x - 1 in 0 until n) colours[x - 1][y] else emptycolour
            val e1 = if(x - 1 in 0 until n) earliest[x - 1][y] else emptyearliest
            val b = if(y - 1 in 0 until n) colours[x][y - 1] else emptycolour
            val e2 = if(y - 1 in 0 until n) earliest[x][y - 1] else emptyearliest

            val retc = IntArray(q){plarge}
            val retearliest = IntArray(q){plarge}
            var ci = -1

            mergeArrayCB(a,b){which , i ->
                val c = if(which == 0) a[i] else b[i]
                val re = if(which == 0) e1[i] else e2[i]
                if(re >= rank || c >= plarge ) return@mergeArrayCB
                if(ci == -1 || c != retc[ci]){
                    ci ++
                    if(ci >= q){
                        return null
                    }
                    retc[ci] = c
                    retearliest[ci] = re +1
                }else{
                    retearliest[ci] = minOf(retearliest[ci],re + 1)
                }
            }
            var found = false
            for(i in 0 until q){
                if(retc[i] == arr[x][y]){
                    retearliest[i] = 0
                    found = true
                }
            }
            if(!found){
                ci ++
                if(ci >= q) return null
                val v = (0 until q).first {retc[it] > arr[x][y] }
                for(i in q-1 downTo v+1){
                    retc[i] = retc[i-1]
                    retearliest[i] = retearliest[i-1]
                }
                retc[v] = arr[x][y]
                retearliest[v] = 0
            }
            found = false
            val c2 = arr[x-rank][y-rank]
            val t2 = rank
            for(i in 0 until q){
                if(retc[i] == c2){
                    retearliest[i] = minOf(retearliest[i],t2)
                    found = true
                }
            }
            if(!found){
                ci ++
                if(ci >= q) return null
                val v = (0 until q).first {retc[it] > c2 }
                for(i in q-1 downTo v+1){
                    retc[i] = retc[i-1]
                    retearliest[i] = retearliest[i-1]
                }
                retc[v] = c2
                retearliest[v] = t2
            }
            for(i in 0 until q){
                if(retc[i] != plarge){
                    val e = retearliest[i]
                    if(e == 0) continue
                    if(arr[x - e + 1][y-e+1] == retc[i]){
                        retearliest[i] = e-1
                    }
                }
            }
            return Pair(retc,retearliest)
        }

        for(i in 0 until n){
            for(j in 0 until n){
                val top = if(i -1 in 0 until n) max[i-1][j] else 0
                val left = if(j-1 in 0 until n) max[i][j-1] else 0
                var attempt = minOf(top,left) +1
                while(true){
                    val p = merge(i,j,attempt)
                    if(p == null){
                        attempt --
                        continue
                    }
                    val (a,b) = p
                    a.copyInto(colours[i][j])
                    b.copyInto(earliest[i][j])
                    max[i][j] = attempt
                    break
                }
            }
        }
//        for(i in 0 until n){
//            for(j in 0 until n){
//                val v = colours[i][j].filter { it != plarge }
//                assert(v.distinct().size == v.size )
//
//                "$i $j " dei colours[i][j]
//                "$i $j " dei earliest[i][j]
//            }
//        }
        val total = IntArray(n)
        for(i in 0 until n){
            for(j in 0 until n){
                total[max[i][j]] ++
            }
        }
        for(i in n-1 downTo 1){
            total[i -1] += total[i]
        }
        put(total.conca)


//        just dei max





    }
    done()
}




/*
3 3
1 1 1
1 1 3
1 3 3


7 10
10 1 2 2 7 11 4
8 8 13 9 7 7 10
5 6 5 10 6 3 6
10 13 5 7 5 3 3
12 1 3 9 12 3 5
1 2 11 9 7 9 2
13 8 13 10 3 11 1

 */