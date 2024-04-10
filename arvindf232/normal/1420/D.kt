/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 * classify by the lowest lamp
 *
 * so any point has 1 starting point and
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
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
        while (c >= '0' && c <= '9') {
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
        while (c >= '0' && c <= '9') {
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
        ret.appendCodePoint(c.toInt())
        while (true){
            c = char
            ret.appendCodePoint(c.toInt());
            if(isWhitespace(c)){ break}
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
}
class reading{
    companion object{
        var jin = FastScanner()
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{ return reading.jin.nextInt() }
fun getLong():Int{ return reading.jin.nextInt() }
fun getLine(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getLineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getString():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}
internal class segTree(
    val size: Int
) {
    //indices are 0 until size
    // out of boundary access are perfectly fine
    // if anyone reads this up in codeforces,
    // I have kept all 4 operations for your conveniences
//    val sum: LongArray = LongArray(4 * size)
    val max: LongArray = LongArray(4 * size)
//    val min: LongArray = LongArray(4 * size)
    val lazy: LongArray = LongArray(4 * size)
    fun update(l: Int, r: Int, inc: Int) {
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

    private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Int) {
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
}
infix fun Int.divCeil(b:Int):Int{
    //Positives numbers only!
    if(this == 0) {
        return 0
    }
    return (this-1)/b + 1
}
infix fun Long.divCeil(b:Long):Long{
    //Positives numbers only!
    if(this == 0L) {
        return 0
    }
    return (this-1)/b + 1
}
val p = 998244353L
infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}

fun pow(x:Long,e:Long,m:Long):Long{
    var X = x
    var E =e
    var Y = 1L
    while(E > 0){
        if(E % 2 == 0L){
            X = (X * X) % m
            E = E/2
        }else{
            Y = (X * Y) % m
            E = E-1
        }
    }
    return Y
}
fun Long.inverse():Long{
    return pow(this,p-2,p)
}
class FACT{
    companion object {
        var store = mutableListOf<Long>()
        var invstore = mutableListOf<Long>()

        fun preCal(upto:Int){
            store = mutableListOf()
            invstore = mutableListOf()
            store.add(1)
            invstore.add(1)
            var previous = 1L
            var prev2 = 1L

            for(i in 1..upto) {
                previous = previous modM i.toLong()


                store.add(previous)

                val ii  = i.toLong().inverse()
                prev2 = prev2 modM ii
                invstore.add(prev2)
            }
        }
        operator fun get(n:Int):Long{
            return store[n]
        }
        operator fun get(n:Long):Long{
            return store[n.toInt()]
        }

    }
}
fun hugeCombin(n:Int,r:Int):Long{
    val aa = FACT[n]
    val bb = FACT.invstore[n-r]
    val cc = FACT.invstore[r]
    return (aa modM bb) modM cc
}
fun prefixSum(arr:IntArray):IntArray{
    val ret = IntArray(arr.size)

    var previous = 0
    for((i,a) in arr.withIndex()){
        previous += a
        ret[i] = previous
    }
    return ret
}
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
}
fun main() {
    val n = getInt()
    val k = getInt()

    val aas = mutableListOf<Int>()
    val bbs = mutableListOf<Int>()

    FACT.preCal(n+1)

    repeat(n){
        aas.add(getInt())
        bbs.add(getInt())
    }
//    val allcoords = aas.toMutableSet()
//    allcoords.addAll(bbs)
    val cordSorted = (aas+bbs).sorted()
    val inverseMap = mutableMapOf<Int,Int>()

    for ((i,a) in cordSorted.withIndex()){
        inverseMap[a] = i
    }

    val A = aas.map{inverseMap[it]!!}
    val B = bbs.map{inverseMap[it]!!}

//    val st = segTree(cordSorted.size + 1)

//    val processing = A.zip(B)
    val presum = IntArray(cordSorted.size + 1)
    for (i in A.indices){
        val l = A[i]
        val r = B[i]
        presum[l] += 1
        presum[r+1] -= 1
    }
    val actualCount = prefixSum(presum)
    var ret = 0L

    val done = IntArray(cordSorted.size + 1)
    for (i in A.indices){
        val l = A[i]
        val r = B[i]
        val maxpos = actualCount[l] - done[l]
        if(maxpos >= k){
            ret += hugeCombin((maxpos-1).toInt(),(k-1))
        }
        ret = ret % p

//        st.update(l,r,-1)
        done[l] += 1
//        printTree()
    }
    put(ret)
    done()
    // Write your solution here
    // classify on the earliest possible point
}