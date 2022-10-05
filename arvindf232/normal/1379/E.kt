// 2022.06.02 at 14:25:15 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.random.nextInt
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
fun Int.isPerfectPower():Boolean{
    return this == (1 shl this.countTrailingZeroBits())
}

class cont(val n:Int, val ret:IntArray = IntArray(n){-1}, val imbalance:Int){
    companion object{

        val cache = mutableMapOf<Pair<Int,Int>,cont>()
        val unit = cont(1, intArrayOf(-1), 0)
        fun merge(first:cont, second:cont):cont{
            val newimbalance = first.imbalance + second.imbalance + if(first.n >= second.n * 2 || second.n >= first.n *  2) 1 else 0
            val newn = first.n + second.n + 1
            val new = IntArray(newn){-1}
            for(i in first.ret.indices){
                if(first.ret[i] == -1){
                    new[i+1] = 0
                }else{
                    new[i+1] = first.ret[i] + 1
                }
            }
            val shift = first.n + 1
            for(i in second.ret.indices){
                if(second.ret[i] == -1 ){
                    new[i + shift] = 0
                }else{
                    new[i + shift] = second.ret[i] + shift
                }
            }
            val final =  cont(newn, new, newimbalance)
            final.confirmImbalance()
            cache[Pair(newn,newimbalance)] = final
            return final
        }

        val max = 50
        val DP = Array(max+1){BooleanArray(max+1)}
        init{


            //max size, want amount

            val found = Array(max+1){Array<cont?>(max+1){null} }
            DP[1][0] = true
            found[1][0] = cont.unit

            for(next in 2..max){
                for(first in 1..next-2){
                    val second = next - 1 - first
                    for(firstwant in 0..first){
                        for(secondwant in 0..second){
                            if(!DP[first][firstwant] || !DP[second][secondwant]) continue
                            val here = firstwant + secondwant + if(first >= second * 2 || second >= first * 2) 1 else 0
                            DP[next][here] = true
                            if(found[next][here] == null){
                                found[next][here] = cont.merge(found[first][firstwant]!!,found[second][secondwant]!!)
                            }

                        }
                    }
                }
            }
            for(a in 0..max){
                for(b in 0..max){
                    if(found[a][b] != null){
                        cache[Pair(a,b)] = found[a][b]!!
                    }
                }
            }

        }
        fun read(a:Int, b:Int):cont?{
            return cache[Pair(a,b)]
        }
        fun getBinaryTree(n:Int):cont{
            val newimbalance = if((n+1).isPerfectPower()) 0 else 1
            val want = cont(n,IntArray(n){
                if(it == 0) -1 else ((it -1)/2)
            }, newimbalance)
            want.confirmImbalance()
            return want


//            assert((n+1).isPerfectPower())
//            val test1 = read(n,0)
//            if(test1 != null){
//                return test1
//            }
//            val half = getBinaryTree(n/2)
//            return merge(half,half)
        }
        fun getSecond(n:Int):cont{
            assert((n-1).isPerfectPower())
            val test1 = read(n,2)
            if(test1 != null) return test1
            val first = getSecond((n/2) + 1)
            val other = getBinaryTree((n/2) - 1 )
            return merge(first, other)
        }

    }
    fun extendBy(x:Int):cont{
        val newn = n + x * 2
        val new = IntArray(newn){-1}
        for(i in 1..x * 2){
            new[i] = ((i-1)/2) * 2
        }
        for(i in ret.indices){
            if(i == 0) continue
            new[i + x * 2] = ret[i] + x * 2
        }
        val got =  cont(newn,new,imbalance + x)
        got.confirmImbalance()
        return got
    }

    fun confirmImbalance(){
        return
        val children = IntArray(n)
        for(i in 0 until n){
            if(ret[i] != -1)
            children[ret[i]] ++
        }
        assert(children.all { it == 0 || it == 2 })
        val sizes = IntArray(n){1}
        for(i in n-1 downTo 0){
            if(ret[i] != -1){
                sizes[ret[i]] += sizes[i]
            }
        }
        var total = 0
        for(i in n-1 downTo 0){
            if(ret[i] != -1){
                val other = sizes[ret[i]] -1 - sizes[i]
                if(other >= sizes[i] * 2){
                    total ++
                }
            }
        }
        assert(total == imbalance)
    }

    fun print(){
        "$n $imbalance" dei ret
    }
    fun output(){
        put(ret.map{it+1}.conca())
    }

}

fun debug(){}
const val singleCase = true
fun main(){
    solve.rand {
        share(Random.nextInt(1..100))
        share(Random.nextInt(1..100))
    }
//    solve.userand()
    solve.cases{
        val n = getint
        val k = getint
        if(n <= cont.max && k <= cont.max){
            if(cont.DP[n][k] == false){
                put("NO")
                return@cases
            }else{
                put("YES")
                cont.read(n,k)!!.output()
                return@cases
            }
        }else{
            if(n and 1 == 0 || k > (n-3) /2 || (k == 1 && (n+1).isPerfectPower()) || (k==0 && !(n+1).isPerfectPower())){
                put("NO")
                return@cases
            }
        }

        var nn = n
        var kk = k
        var moved = 0
        var start:cont? = null
        while(true){
            if(cont.read(nn,kk) != null){
                start = cont.read(nn,kk)
                break
            }else if(kk == 2 && (nn-1).isPerfectPower()){
                start = cont.getSecond(nn)
                break
            }else if(kk == 1){
                start = cont.getBinaryTree(nn)
                break
            }else if(kk == 0 && (nn+1).isPerfectPower()){
                start = cont.getBinaryTree(nn)
                break 
            }
            nn -= 2
            kk --
            moved ++
        }
        start!!.confirmImbalance()
        if(moved > 0){
            start = start!!.extendBy(moved)
        }
        put("YES")
        start!!.confirmImbalance()
        start!!.output()
//        val n = ge
    //       tint
//        val k = getint
//        fun NO(){
//            put("NO")
//        }
//        if(n %2 == 0){
//            NO()
//            return@cases
//        }

//        val canget = if(n <= 2 ) 0 else (n/2) - 1
//        if(k !in 0..canget){
//            put("NO")
//            return@cases
//        }
//        if(n == 1){
//            put("YES")
//            put(0)
//            return@cases
//        }
//        val need = (k+1) * 2
//        assert(need <= n)
//        val ret = IntArray(n+1)
//        var seed = 1
//        ret[seed] = 0
//        repeat(n- need){
//            ret[seed+1] = seed
//            seed ++
//        }
//        repeat(k){
//            ret[seed+1] = seed
//            ret[seed+2] = seed
//            seed += 2
//        }
//        ret[seed+1] = seed
//        put("YES")
//        put(ret.slice(1..n).conca())



//        val n = getint
//        val k = getint
//
//
//        found[17][2]!!.print()
//        found[17][2]!!.confirmImbalance()
//        for(i in DP.indices){
//            i dei DP[i]
//        }
//        val guess =
//        just dei DP
//        just dei IntArray(max){if(it <= 2) 0 else (it/2) - 1 }




    }
    done()
}

//1379E