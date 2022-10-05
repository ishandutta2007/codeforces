// 2022.07.24 at 23:42:49 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

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
fun brute(n:Int):Int {
    var ret = 0
    val got = IntArray(8)
    for(xa in 0..n){
        for(xb in 0..n){
            for(xc in 0..n){
                val a = xb xor xc
                val b = xa xor xc
                val c = xa xor xb
                if(a + b > c && a + c > b && b + c > a){
                    ret ++
//                    var now = 0
//                    if(a < n){
//                        now ++
//                    }
//                    if( b < n ){
//                        now +=2
//                    }
//                    if(c < n){
//                        now +=4
//                    }
////                    got[now] ++
//                    just dei "$a $b $c"
                }
            }
        }
    }
    just dei got
    return ret
}
fun debug(){}
const val singleCase = true
fun main(){
//    for(i in 1..5){
//        i dei brute(i)
//    }
//    brute(3)
//

    solve.cases{
        //state 0: a below
        // state 1: b below
        // state 2: c below
        //state 3:  a = b + c
        //state 4: b = a + c
        //state 5 : c = a+ b

        val n0 = mint
        val n0result = mint
        val n1 = mint
        val n1result = mint

        val trans = Array(2){Array(64){IntArray(64)} }
        for(next in 0 until 2){
            for(now in 0 until (1 shl 6)){
                val abelow = now.has(0)
                val bbelow =now.has(1)
                val cbelow = now.has(2)

                val aeq = now.has(3)
                val beq = now.has(4)
                val ceq = now.has(5)

                for(sa in 0..1){
                    if(sa == 1 && next == 0 && !abelow){
                        continue
                    }

                    val newabelow = abelow || (sa < next)
                    for(sb in 0..1){
                        if(sb == 1 && next == 0 && !bbelow){
                            continue
                        }
                        val newbbelow = bbelow || (sb < next)
                        for(sc in 0..1){
                            if(sc == 1 && next == 0 && !cbelow){
                                continue
                            }
                            val newcbelow = cbelow || (sc < next)

                            val na = sb xor sc
                            val nb = sa xor sc
                            val nc = sa xor sb


                            if(aeq && nb + nc < na){
                                continue
                            }
                            if(beq && na + nc < nb){
                                continue
                            }
                            if(ceq && na + nb < nc){
                                continue
                            }

                            val naeq = aeq && (nb + nc == na)
                            val nbeq = beq && (na + nc == nb)
                            val nceq = ceq && (na + nb == nc)

                            val thing = booleanArrayOf(newabelow,newbbelow,newcbelow, naeq, nbeq,nceq)
                            var new = 0
                            for(i in 0 until 6){
                                if(thing[i]){
                                    new += 1 shl i
                                }
                            }
                            if(next == 0){
                                n0.add(now)
                                n0result.add(new)
                            }else{
                                n1.add(now)
                                n1result.add(new)
                            }
//                            trans[next][now][new] ++
                        }
                    }
                }
            }
        }

        val z0 = n0.toIntArray()
        val z0v = n0result.toIntArray()
        val z1 = n1.toIntArray()
        val z1v = n1result.toIntArray()

        val DP = IntArray(64)
        DP[56] = 1
        val str = getstr
        for(c in str){
            val next = if(c == '1') 1 else 0
            val new = IntArray(64)
            if(next == 1){
                for(i in z1.indices){
                    val from = z1[i]
                    val to = z1v[i]
                    new[to] = new[to] modPlus DP[from]
                }
            }else{
                for(i in z0.indices){
                    val from = z0[i]
                    val to = z0v[i]
                    new[to] = new[to] modPlus DP[from]
                }
            }
//            for(start in 0 until 64){
//                for(end in 0 until 64){
//                    new[end] = new[end] modPlus (trans[next][start][end] modM DP[start])
//                }
//            }
            new.copyInto(DP)
        }
//        just dei DP
        var ret = 0
        for((i,c) in DP.withIndex()){
            if(!i.has(3) && !i.has(4) && !i.has(5)){
//                just dei i
                ret = ret modPlus c
            }
        }
        put(ret)




    }
    done()
}

/*

1
5
 15
 34
 65
 */