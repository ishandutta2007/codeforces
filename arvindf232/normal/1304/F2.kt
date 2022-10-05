import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
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
        if (c == NC) c = char
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
            System.err.println("Not accepting inputs!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
get() = this.joinToString("")
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    var str = ""
    if(this is String){ str = this
    }else if(this is Int){ str = this.toString()
    }else if(this is Long){ str = this.toString()
    }
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            currentAnswer = null
            currentBruteAnswer = null
            a()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
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
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentBruteAnswer != null){
            checkAnswer()
        }
    }
    fun put2(a:Any){answer(a);put(a) }

    fun bruteAnswer(a:Any){
        currentBruteAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun checkAnswer(){
        if(currentAnswer != currentBruteAnswer){
            throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
        }
        answersChecked ++
    }
}
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }

internal class segTree(
    private val size: Int
) {
    //indices are 0 until size
    // out of boundary access are perfectly fine
    // if anyone reads this up in codeforces,
    // I have kept all 4 operations for your conveniences
//    val sum: LongArray = LongArray(4 * size)
    val max: LongArray = LongArray(4 * size)
    //    val min: LongArray = LongArray(4 * size)
    val lazy: LongArray = LongArray(4 * size)
    fun update(l: Int, r: Int, inc: Long) {
        update(1, 0, size - 1, l, r, inc)
    }

    private fun pushDown(index: Int, l: Int, r: Int) {
//        min[index] += lazy[index]
        max[index] += lazy[index];
//        sum[index] += lazy[index] * (r-l+1);
        if (l != r) {
            lazy[2 * index] += lazy[index]
            lazy[2 * index + 1] += lazy[index]
        }
        lazy[index] = 0
    }

    private fun pullUp(index: Int, l: Int, r: Int) {
        val m = (l + r) / 2
//        min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
        max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
//        sum[index] = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r);
    }

    //    private fun evaluateMin(index: Int, l: Int, r: Int): Long {
//        return min[index] + lazy[index]
//    }
    private fun evaluateMax(index: Int, l: Int, r: Int): Long {
        return max[index] + lazy[index]
    }
//    private fun evaluateSum(index: Int, l: Int, r: Int): Long {
//        return sum[index] + lazy[index] * (r-l+1)
//    }

    private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Long) {
        if (r < left || l > right) return
        if (l >= left && r <= right) {
            lazy[index] = lazy[index] + inc
            return
        }
        pushDown(index, l, r)
        val m = (l + r) / 2
        update(2 * index, l, m, left, right, inc)
        update(2 * index + 1, m + 1, r, left, right, inc)
        pullUp(index, l, r)
    }

    //    fun minQuery(l: Int, r: Int): Long {
//        return minQuery(1, 0, size - 1, l, r)
//    }
    fun maxQuery(l: Int, r: Int): Long {
        return maxQuery(1, 0, size - 1, l, r)
    }


//    fun sumQuery(l: Int, r: Int): Long {
//        return sumQuery(1, 0, size - 1, l, r)
//    }

    //    private fun minQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//        if (r < left || l > right) return Long.MAX_VALUE
//        if (l >= left && r <= right) {
//            return evaluateMin(index, l, r)
//        }
//        pushDown(index, l, r)
//        val m = (l + r) / 2
//        var ret = Long.MAX_VALUE
//        ret = Math.min(ret, minQuery(2 * index, l, m, left, right))
//        ret = Math.min(ret, minQuery(2 * index + 1, m + 1, r, left, right))
//        pullUp(index, l, r)
//        return ret
//    }
    private fun maxQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
        if (r < left || l > right) return Long.MIN_VALUE
        if (l >= left && r <= right) {
            return evaluateMax(index, l, r)
        }
        pushDown(index, l, r)
        val m = (l + r) / 2
        var ret = Long.MIN_VALUE
        ret = Math.max(ret, maxQuery(2 * index, l, m, left, right))
        ret = Math.max(ret, maxQuery(2 * index + 1, m + 1, r, left, right))
        pullUp(index, l, r)
        return ret
    }
    //    private fun sumQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//        if (r < left || l > right) return 0L
//        if (l >= left && r <= right) {
//            return evaluateSum(index, l, r)
//        }
//        pushDown(index, l, r)
//        val m = (l + r) / 2
//        var ret = 0L
//        ret += sumQuery(2 * index, l, m, left, right)
//        ret += sumQuery(2 * index + 1, m + 1, r, left, right)
//        pullUp(index, l, r)
//        return ret
//    }
    fun printTree(){
        val ret = mutableListOf<Long>()
        for(i in 0 until size){
            ret.add(maxQuery(i,i))
        }
        println(ret.joinToString(" "))
    }
}
class rsqArr(val arr:IntArray) {
    val ps = arr.runningFold(0L, { a,b->a+b.toLong()} )
    fun sumQuery(l:Int,r:Int):Long{
        val ll = maxOf(l,0)
        val rr = minOf(arr.lastIndex,r) + 1
        return ps[rr] - ps[ll]
    }
}

//Price:  500ms for 400k operations, with all min,max,update present
const val singleCase = true
const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val n = getint()
        val m = getint()
        val k = getint()
        val table = List(n){IntArray(m)}
        repeat(n){ a->
            repeat(m){
                table[a][it] = getint()
            }
        }
        var last = LongArray(m - k + 1){0}
        val fr = rsqArr(table[0])
        val second = if(n > 1) rsqArr(table[1]) else null

        for(i in last.indices){
            var new = fr.sumQuery(i,i+k -1)
            if(second != null ){
                new += second.sumQuery(i,i+k-1)
            }
            last[i] = new
        }

//        just dei last

        for(p in 1 until n){
            val ret = LongArray(m - k + 1)
            val segMax = segTree(m-k+1)
            val row = table[p]
            val rowSum = rsqArr(row)
            val next = if(p < n-1) table[p+1] else IntArray(row.size)
            val nextsum = rsqArr(next)
            for(i in 0 until last.size){
                segMax.update(i,i,last[i] )
            }
            for(reduce in 0 until k){
                segMax.update(0,reduce,- row[reduce].toLong())
            }
            for(i in 0 until m-k+1){
                if(i != 0){
                    segMax.update(i-k,i-1,row[i-1].toLong())
                    segMax.update(i,i+k-1,- row[i+k-1].toLong())
                }
                ret[i] = segMax.maxQuery(0,m) + rowSum.sumQuery(i,i+k-1) + nextsum.sumQuery(i,i+k-1)
            }
            last = ret
//            just dei last
        }
        put(last.maxOrNull()!!)
    }
    done()
}

//16 minutes idea
/*
slow

15 minutes coding, unreliable seg tree

15 minutes debug
getting destroyed byt the seg tree thing 
 */