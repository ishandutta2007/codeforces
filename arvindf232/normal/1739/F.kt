// 2022.09.29 at 16:12:35 BST
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.mm(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.mp(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
infix fun Int.ms(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this mm (b.inverse()) }
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
const val just = " "
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


const val K = 13

//class ACVertex(var len:Int, var ID:Int = -1, var nodeRep:Char = '$'){
//    var next = IntArray(K){-1}
//    var leaf = -1 // -1 means not a leaf, nonnegative number refers to string index
//    var mult = 0
//    var link = -1
//    var exitLink = -1 // -1 not calculated, -2 not available
//    var exitCount = -1
//    val go = IntArray(K){-1}
//}

class AC(val max:Int){
    companion object{
        const val aCode = 'a'.toInt()
        val Char.code:Int get() = this.toInt() - aCode
        val Int.asChar:Char get() = (this + aCode).toChar()
        val allchars = (0 until 13).map{(it + 'a'.toInt()).toChar()}
    }
    //    val nodes = MutableList(1){ACVertex(len= 0 )}
//    val strcount = all.size

//    val max:Int


//    init{
//        max = all.sumOf { it.length } + 1
//    }
    var nodesize = 1
    val parent = IntArray(max){-1}
    val chars = CharArray(max){'#'}
    val next = Array(max){IntArray(K){-1} } // Next vertex in sense of trie
    val leaf = IntArray(max){-1} //store ID of string
    val multi = IntArray(max){0} // number of uses
    val link = IntArray(max){-1} // next prefix that can survive
    val exitcounts = IntArray(max){-1} //value of this state
    val go = Array(max){IntArray(K){-1} }

    //stored


    init{
//        for((i,s) in all.withIndex()){
//            addString(s,i)
//        }
//        compile()
    }
    fun compile(){
        for(i in 0 until nodesize){
            get_link(i)
        }
        for(i in 0 until nodesize){
            for(c in allchars){
                go_compute(i,c)
            }
        }
        for(i in 0 until nodesize){
            exit_count_compute(i)
        }
    }

    fun addString(str:String, cost:Int){
        var v = 0
        for(ch in str){
            val c = ch.code
            if(next[v][c] == -1){
                next[v][c] = nodesize
                parent[nodesize] = v
                chars[nodesize] = ch
                nodesize ++
            }
            v = next[v][c]
        }
        leaf[v] = 1
        multi[v] += cost
    }
    fun get_link(v:Int): Int {
        if(link[v] == -1){
            if(v == 0|| parent[v] == 0){
                link[v] = 0
            }else{
                link[v] = go_compute(get_link(parent[v]),chars[v])
            }
        }
        return link[v]
    }
    fun go_compute(v:Int,ch:Char): Int {
        val c = ch.code
        if(go[v][c] == -1){
            if (next[v][c] != -1)
                go[v][c] = next[v][c]
            else
                go[v][c] = if(v == 0) 0 else go_compute(get_link(v),ch)
        }
        return go[v][c]
    }

    fun exit_count_compute(v:Int):Int{
        if(exitcounts[v] == -1){
            var ret:Int
            if(v == 0 || parent[v] == 0){
                ret = 0
            }else if(link[v] == -1){
                ret = 0
            }else{
                ret = exit_count_compute(link[v])
            }
            if(leaf[v] >= 0){
                ret += multi[v]
            }
            exitcounts[v] = ret
        }
        return exitcounts[v]
    }

//    var exitnodes = mutableListOf<MutableList<Int>?>()
//    fun exit_nodes(v:Int):List<Int>{
//        //obviously, n^2
//        if(exitnodes.isEmpty()){
//            exitnodes = MutableList(nodes.size){ null  }
//        }
//        if(exitnodes[v] != null ){
//            return exitnodes[v]!!
//        }else{
//            var ret:MutableList<Int>
//            if(v == 0 || nodes[v].ID == 0){
//                ret = mutableListOf()
//            }else if(nodes[v].link == -1){
//                ret = mutableListOf()
//            }else{
//                ret = exit_nodes(nodes[v].link).toMutableList()
//            }
//            if(nodes[v].leaf >= 0){
//                ret.add(nodes[v].leaf)
//            }
//            exitnodes[v] = ret
//            return ret
//        }
//    }

    fun countMatches(a:String): Int {
        var ret = 0
        var v = 0
        for(c in a){
            v = go[v][c.code]
            ret += exitcounts[v]
        }
        return ret
    }

    inline fun runAndStated(a:String,act:(state:Int)->Unit){
        var v = 0
        for(c in a){
            v = go[v][c.code]
            act(v)
        }
    }
    fun endstate(s:String): Int {
        var v = 0
        for(c in s){
            v = go[v][c.code]
        }
        return v
    }
}


const val singleCase = true
fun main(){
    solve.cases{
        val n = getint

        val give = mutableListOf<Pair<Int,String>>()

        repeat(n){
            val c = getint
            val str = getstr

            val have = BooleanArray(12)
            val desired = ArrayDeque<Char>()
            desired.add(str[0])
            have[str[0].code] = true
            var pt = 0
            for(i in 1 until str.size){
                val x = str[i]
                if(have[x.code]){
                    if(pt > 0 && desired[pt - 1] == x){
                        pt --
                    }else if(pt < desired.lastIndex && desired[pt+1] == x){
                        pt ++
                    }else{
                        return@repeat
                    }
                }else{
                    if(pt != 0 && pt != desired.lastIndex){
                        return@repeat
                    }
                    if(pt == desired.lastIndex){
                        desired.addLast(x)
                        pt ++
                    }else{
                        desired.addFirst(x)
                    }
                    have[x.code] = true
                }
            }
            give.add(Pair(c,desired.conca()))
        }

        val box = AC(4005)

        for((c,s) in give){
            box.addString(s,c)
            if(s.size > 1){
                box.addString(s.reversed(),c)
            }
        }
        box.compile()

        val V = box.nodesize
        val dp = Array(1 shl 12){IntArray(V){nlarge} }
        val hows = Array(1 shl 12){IntArray(V){-1} }
        val howm = Array(1 shl 12){IntArray(V){-1} }
        dp[0][0] = 0
        for(m in 0 until (1 shl 12)){
            for(new in 0 until 12){
                if(m.has(new)) continue
                for(s in 0 until V){
                    val nm = m xor ( 1 shl new)

                    val ns = box.go[s][new]

                    val nc = dp[m][s] + box.exitcounts[ns]
                    if(nc > dp[nm][ns]){
                        dp[nm][ns] = nc
                        hows[nm][ns] = s
                        howm[nm][ns] = m
                    }
                }
            }
        }

        var nowstate = -1
        var nowcost = nlarge
        var nowmask = (1 shl 12) - 1

        for(i in 0 until V){
            if(dp[nowmask][i] > nowcost){
                nowcost = dp[nowmask][i]
                nowstate = i
            }
        }
        val ret = mutableListOf<Char>()
        while(nowmask != 0){
            val nm = howm[nowmask][nowstate]
            val ns = hows[nowmask][nowstate]

            val new =( nowmask - nm ).countTrailingZeroBits()

            ret.add('a' + new)
            nowmask = nm
            nowstate = ns
        }
        put(ret.conca())


//        just dei give




    }
    done()
}