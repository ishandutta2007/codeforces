// 2022-03-23, Wed, 16:9
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
const val K = 26


class ACVertex(var len:Int, var ID:Int = -1, var nodeRep:Char = '$'){
    var next = IntArray(K){-1}
    var leaf = -1 // -1 means not a leaf, nonnegative number refers to string index
    var mult = 0
    var link = -1
    var exitLink = -1 // -1 not calculated, -2 not available
    var exitCount = -1
    val go = IntArray(K){-1}
}

class AC(val all:List<String>){
    companion object{
        const val aCode = 'a'.toInt()
        val Char.code:Int get() = this.toInt() - aCode
        val Int.asChar:Char get() = (this + aCode).toChar()
    }
    val nodes = MutableList(1){ACVertex(len= 0 )}
    var strCounts = 0


    init{
        for((i,s) in all.withIndex()){
            addString(s,i)
        }
        compile()
    }
    fun compile(){
        for(i in nodes.indices){
            get_link(i)
        }
    }

    fun addString(str:String,id:Int){
        var v = 0
        for(ch in str){
            val c = ch.code
            if(nodes[v].next[c] == -1){
                nodes[v].next[c] = nodes.size
                nodes.add(ACVertex(nodes[v].len + 1, v,ch))
            }
            v = nodes[v].next[c]
        }
        nodes[v].leaf = id
        nodes[v].mult ++
        strCounts ++
    }
    fun get_link(v:Int): Int {
        if(nodes[v].link == -1){
            if(v == 0|| nodes[v].ID == 0){
                nodes[v].link = 0
            }else{
                nodes[v].link = go(get_link(nodes[v].ID),nodes[v].nodeRep)
            }
        }
        return nodes[v].link
    }
    fun go(v:Int,ch:Char): Int {
        val c = ch.code
        if(nodes[v].go[c] == -1){
            if (nodes[v].next[c] != -1)
                nodes[v].go[c] = nodes[v].next[c];
            else
                nodes[v].go[c] = if(v == 0){ 0}else go(get_link(v), ch)
        }
        return nodes[v].go[c];
    }

    fun exit_link(v:Int):Int{
        if(nodes[v].exitLink != -1){
            return nodes[v].exitLink
        }else{
            val ret:Int
            if(v == 0 || nodes[v].ID == 0){
                ret = -2
            }else if(nodes[v].link == -1){
                ret = -2
            }else if(nodes[v].leaf >= 0) {
                ret = v
            }else{
                ret = exit_link(nodes[v].link)
            }
            nodes[v].exitLink = ret
            return ret
        }
    }

    fun exit_count(v:Int):Int{
        if(nodes[v].exitCount != -1){
            return nodes[v].exitCount
        }else{
            var ret:Int
            if(v == 0 || nodes[v].ID == 0){
                ret = 0
            }else if(nodes[v].link == -1){
                ret = 0
            }else{
                ret = exit_count(nodes[v].link)
            }
            if(nodes[v].leaf >= 0){
                ret += nodes[v].mult
            }
            nodes[v].exitCount = ret
            return ret
        }
    }

    var exitnodes = mutableListOf<MutableList<Int>?>()
    fun exit_nodes(v:Int):List<Int>{
        //obviously, n^2
        if(exitnodes.isEmpty()){
            exitnodes = MutableList(nodes.size){ null  }
        }
        if(exitnodes[v] != null ){
            return exitnodes[v]!!
        }else{
            var ret:MutableList<Int>
            if(v == 0 || nodes[v].ID == 0){
                ret = mutableListOf()
            }else if(nodes[v].link == -1){
                ret = mutableListOf()
            }else{
                ret = exit_nodes(nodes[v].link).toMutableList()
            }
            if(nodes[v].leaf >= 0){
                ret.add(nodes[v].leaf)
            }
            exitnodes[v] = ret
            return ret
        }
    }
    fun exitDP(occur:IntArray):IntArray{
        val ret = IntArray(strCounts)
        val statecounts = occur.copyOf()
        for(v in (0..nodes.lastIndex).sortedByDescending { nodes[it].len }){
            if(v == 0 || nodes[v].ID == 0 || nodes[v].link == -1){

            }else{
                statecounts[nodes[v].link] += statecounts[v]
            }
            if(nodes[v].leaf >= 0){
                ret[nodes[v].leaf] += statecounts[v]
            }
        }
        return ret
    }

    fun countMatches(a:String): List<Int> {
//        var ret = 0
        var v = 0
        val ret = mutableListOf<Int>()
        for(c in a){
            while(nodes[v].next[c.code] == -1){
                if(v != 0){
                    v = nodes[v].link
                }else{
                    break
                }
            }
//            just dei v
            if(nodes[v].next[c.code] != -1){
                v = nodes[v].next[c.code]
                ret.add(exit_count(v))
            }else{
                ret.add(0)
            }
        }
        return ret
    }

    inline fun runAndStated(a:String,act:(state:Int)->Unit){
        var v = 0
        for(c in a){
            while(nodes[v].next[c.code] == -1){
                if(v != 0){
                    v = nodes[v].link
                }else{
                    break
                }
            }
            if(nodes[v].next[c.code] != -1){
                v = nodes[v].next[c.code]
            }
            act(v)
        }
    }
}


fun debug(){}
const val withBruteForce = false
const val singleCase = true
fun main(){
    solve.cases{
        val t = getstr
        val n = getint
        val strings = mutableListOf<String>()
        repeat(n){
            strings.add(getstr)
        }

        val forward = AC(strings)
        val backwards = AC(strings.map{it.reversed()})

        val first = forward.countMatches(t)
        val reversed = backwards.countMatches(t.reversed()).reversed()

        var ret = 0L
        for(i in 0 until first.size - 1){
            ret += first[i].toLong() * reversed[i+1]
        }

        put(ret)





    }
    done()
}