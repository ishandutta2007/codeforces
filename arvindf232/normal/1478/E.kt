/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
really long string

 greedy ?

 if repeat, forced to change into one of them

 multiple inspection are consistent

 constructiv method available


 not inspected: is free for whatever
 inspected: is exactly of the right number


 need to keep track of almost exact the string

 simple case :
    must see all 0s or all 1s

 backwards


 */
import java.util.*
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

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
            if(isWhitespace(c)){ break}
            ret.appendCodePoint(c.toInt());

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
fun getLong():Long{ return reading.jin.nextLong() }
fun getLine(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getLineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getString():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}



val n0 = Long.MIN_VALUE
internal class segTreeAss(
    private val size: Int
) {
    //indices are 0 until size
    // out of boundary access are perfectly fine
    // if anyone reads this up in codeforces,
    // I have kept all 4 operations for your conveniences
    val sum: LongArray = LongArray(4 * size)
    //    val max: LongArray = LongArray(4 * size)
//    val min: LongArray = LongArray(4 * size)
    val lazy: LongArray = LongArray(4 * size){n0}
    fun update(l: Int, r: Int, inc: Int) {
        update(1, 0, size - 1, l, r, inc)
    }

    private fun pushDown(index: Int, l: Int, r: Int) {
//        min[index] += lazy[index]
//        max[index] += lazy[index];
        if(lazy[index] != n0){
            sum[index] = lazy[index] * (r-l+1);
            if (l != r) {
                lazy[2 * index] = lazy[index]
                lazy[2 * index + 1] = lazy[index]
            }
        }
//        sum[index] += lazy[index] * (r-l+1);

        lazy[index] = n0
    }

    private fun pullUp(index: Int, l: Int, r: Int) {
        val m = (l + r) / 2
//        min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
//        max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
        sum[index] = evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r);
    }

    //    private fun evaluateMin(index: Int, l: Int, r: Int): Long {
//        return min[index] + lazy[index]
//    }
//    private fun evaluateMax(index: Int, l: Int, r: Int): Long {
//        return max[index] + lazy[index]
//    }
    private fun evaluateSum(index: Int, l: Int, r: Int): Long {
        if(lazy[index] == n0){
            return sum[index]
        }else{
            return lazy[index] * (r-l+1)
        }

    }

    private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Int) {
//        println("${l} ${r} ${index} set to ${inc}")
        if (r < left || l > right) return
        if (l >= left && r <= right) {
            lazy[index] =  inc.toLong()
//            println("Set here")
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
//    fun maxQuery(l: Int, r: Int): Long {
//        return maxQuery(1, 0, size - 1, l, r)
//    }
    fun sumQuery(l: Int, r: Int): Long {
        return sumQuery(1, 0, size - 1, l, r)
    }

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
//    private fun maxQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
//        if (r < left || l > right) return Long.MIN_VALUE
//        if (l >= left && r <= right) {
//            return evaluateMax(index, l, r)
//        }
//        pushDown(index, l, r)
//        val m = (l + r) / 2
//        var ret = Long.MIN_VALUE
//        ret = Math.max(ret, maxQuery(2 * index, l, m, left, right))
//        ret = Math.max(ret, maxQuery(2 * index + 1, m + 1, r, left, right))
//        pullUp(index, l, r)
//        return ret
//    }
    private fun sumQuery(index: Int, l: Int, r: Int, left: Int, right: Int): Long {
        if (r < left || l > right) return 0L
        if (l >= left && r <= right) {
//            println("Evaluated prim ${l} ${r} ${evaluateSum(index, l, r)}")
            return evaluateSum(index, l, r)
        }
        pushDown(index, l, r)
        val m = (l + r) / 2
        var ret = 0L
        ret += sumQuery(2 * index, l, m, left, right)
        ret += sumQuery(2 * index + 1, m + 1, r, left, right)
        pullUp(index, l, r)
//        println("Evaluated ${l} ${r} ${ret}")
        return ret
    }
    fun printTree(){
        val ret = mutableListOf<Long>()
        for(i in 0 until size){
            ret.add(sumQuery(i,i))
        }
        println(ret.joinToString(" "))
    }
}


fun main() {
//    val arr = listOf<Long>(1L,0L,1L,0L)
//
//    val x = segTreeAss(arr.size)
//    x.printTree()
//
//    x.update(2,3,1)
//    x.printTree()

//    println(n0)

    cases case@{
        val n = getInt()
        val q = getInt()

        val s = getString()
        val t = getString()

        val arr = t.map{if(it == '1')1 else 0}.toIntArray()
        val st = segTreeAss(n)

        for(i in arr.indices){
//            println("START ${i} ${arr[i]}")
            st.update(i,i,arr[i])
        }

        val lQ = IntArray(q)
        val rQ = IntArray(q)

        repeat(q){
            lQ[q-1-it] = getInt()
            rQ[q-1-it] = getInt()
        }
        fun printTree(){
            println((0 until n).map{st.sumQuery(it,it)}.joinToString(" "))
        }
        repeat(q){
            val l = lQ[it]
            val r = rQ[it]

            val sum = st.sumQuery(l-1,r-1)
            val size = r-l+1
            if(size % 2 == 0){
                if(sum == (size/2).toLong()){
                    put("NO")
                    return@case
                }
            }
            val setTo = if(sum * 2 > size) 1 else 0
            st.update(l-1,r-1,setTo)
//            printTree()
        }

        for((i,c) in s.withIndex()){
            val now = st.sumQuery(i,i)
            val cc = if(c == '1') 1L else 0L
            if(now == cc){
                continue
            }else{
                put("NO")
                return@case
            }
        }
        put("YES")
    }
    done()

//    val ar = intArrayOf(0,0,1,1,1,0,0)
//    val s = SegmentTree(ar)
//    s.update(1,3,3)
//    println(s.rsq(3,5))
////    for(i in 0..6){
//////        println(s.rMinQ(i,i))
//////    }
//    // Write your solution here
}