/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */
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

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
    val t = getint()
    repeat(t){
        ask()
    }
}
fun just(a:Boolean){
    put(if(a)"YES" else "NO")
}
fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
    get() = this.joinToString("")

fun prefixSumL(arr:List<Long>):MutableList<Long>{
    val ret = mutableListOf<Long>()

    var previous = 0L
    for(a in arr){
        previous += a
        ret.add(previous)
    }
    return ret
}

val p = 1000000007L
infix fun Long.modM(b:Long):Long{
    return (this * b) % p
}

internal class segTree(
    private val size: Int
) {
    //indices are 0 until size
    // out of boundary access are perfectly fine
    // if anyone reads this up in codeforces,
    // I have kept all 4 operations for your conveniences
    val sum: LongArray = LongArray(4 * size)
//    val max: LongArray = LongArray(4 * size)
//    val min: LongArray = LongArray(4 * size)
    val lazy: LongArray = LongArray(4 * size)
    fun update(l: Int, r: Int, inc: Int) {
        update(1, 0, size - 1, l, r, inc)
    }

    private fun pushDown(index: Int, l: Int, r: Int) {
//        min[index] += lazy[index]
//        max[index] += lazy[index];
        sum[index] = (sum[index] + (lazy[index] modM (r-l+1).toLong())) % p
        if (l != r) {
            lazy[2 * index] = (lazy[2 * index]+lazy[index]) %p
            lazy[2 * index + 1] = (lazy[2 * index + 1]+lazy[index])%p
        }
        lazy[index] = 0
    }

    private fun pullUp(index: Int, l: Int, r: Int) {
        val m = (l + r) / 2
//        min[index] = Math.min(evaluateMin(2 * index, l, m), evaluateMin(2 * index + 1, m + 1, r))
//        max[index] = Math.max(evaluateMax(2*index, l, m), evaluateMax(2*index+1, m+1, r));
        sum[index] = (evaluateSum(2*index, l, m) + evaluateSum(2*index+1, m+1, r))%p
    }

//    private fun evaluateMin(index: Int, l: Int, r: Int): Long {
//        return min[index] + lazy[index]
//    }
//    private fun evaluateMax(index: Int, l: Int, r: Int): Long {
//        return max[index] + lazy[index]
//    }
    private fun evaluateSum(index: Int, l: Int, r: Int): Long {
//        println("Evaluate $l $r")
//    println((sum[index] + (lazy[index] modM (r-l+1).toLong())) % p)
        return (sum[index] + (lazy[index] modM (r-l+1).toLong())) % p
    }

    private fun update(index: Int, l: Int, r: Int, left: Int, right: Int, inc: Int) {
        if (r < left || l > right) return
        if (l >= left && r <= right) {
            lazy[index] = (lazy[index] + inc) % p
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
            return evaluateSum(index, l, r)
        }
        pushDown(index, l, r)
        val m = (l + r) / 2
        var ret = 0L
        ret += sumQuery(2 * index, l, m, left, right)
        ret += sumQuery(2 * index + 1, m + 1, r, left, right)
        pullUp(index, l, r)
        return ret % p
    }
    fun printTree(){
        val ret = mutableListOf<Long>()
        for(i in 0 until size){
            ret.add(sumQuery(i,i))
        }
        println(ret.joinToString(" "))
    }
}

//Price:  500ms for 400k operations, with all min,max,update present
fun main() {
//    val tree = segTree(10)
//
//    repeat(100){
//        tree.update((1..10).random(),10,13)
//        println(tree.sumQuery(1,10))
//    }
//    val x  =0

//    tree.update(2,10,1)
//    tree.printTree()

    cases{
        val n = getint()
        val arr = getlineL(n)
        val presum = prefixSumL(arr)

        var red = mutableMapOf<Long,Int>()

        var tree = segTree(n+1)
        tree.update(0,0,1)
//        tree.update(0,n,1)
//        red[0] = 1
//        var ret = 1
        for(i in 0 until n){
            val ps = if(i == 0) 0 else presum[i-1]
            val re = red.getOrDefault(ps,0)
            val s = (tree.sumQuery(i,i) - re).toInt()

//            if(s > p || re > p){
//                val z = IntArray(Int.MAX_VALUE)
//            }

            tree.update(i+1,n,s)
            val ps1 = ps
//            val ps1 = presum[i] - arr[i]
//            println(ps1)

            red[ps1] = ((red.getOrDefault(ps1,0) + s)%p).toInt()
//            tree.printTree()
        }

        val ans = tree.sumQuery(n,n)
        put(if(ans >= 0) ans else ans + p )
    }
    done()
    // Write your solution here
}