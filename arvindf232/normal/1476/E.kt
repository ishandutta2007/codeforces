/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools


 k = 4 !!!


 essenitlaly demanind first match > all later match
 iff no directed cycle

 every thing matches at most 16 patterns
    - 16 degenerate

 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

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


val a = 27
val a1 = a
val a2 = a * a
val a3 = a2 * a
// _ is 28

val A = intArrayOf(1,a1,a2,a3)
val p2 = intArrayOf(1,2,4,8,16)

fun hash(pt:String):Int{
    var ret = 0
    for((i,c) in pt.withIndex()){
        val x = (c.toInt() - 'a'.toInt())
        val s = when{
            x >= 0 && x <= 25 -> x
            else -> 26
        }
        ret += s * A[i]
    }
    return ret
}

fun adj(pt:String):IntArray{
    val ret = IntArray(p2[pt.length])
    ret[0] = 26
    ret[1] = pt[0].toInt() - 'a'.toInt()
    for(i in 0 until pt.length - 1){
        val mt = p2[i+1]
        val c = pt[i+1].toInt() - 'a'.toInt()
        for(j in 0 until p2[i+1]){
            ret[j+mt] = ret[j] + c * A[i+1]
            ret[j] += A[i+1] * 26
        }
    }
    return ret


}

fun main() {
//    println(hash("_b"))
//    println(adj("ab").joinToString(" "))
    val n = getInt()
    val m = getInt()
    val k = getInt()

    val exist = IntArray(a2*a2)
    val indeg = IntArray(a2*a2)

    val indices = IntArray(a2*a2)

    val AM = MutableList(a2 * a2){ mutableListOf<Int>() }

    val pat = mutableListOf<String>()
    repeat(n){
        val st = getString()
        pat.add(st)

        val h = hash(st)
        exist[h] = 1
        indices[h] = it + 1
    }

    repeat(m){
        val str = getString()
        val k = getInt()

        val Ns = adj(str)
        val p = hash(pat[k-1])

        if(exist[p] == 0){
            put("NO")
            done()
            return
        }
        AM[p].addAll(Ns.toList())
        var used = false
        for(i in Ns) {
            if(i == p){
                used = true
                continue
            }else{
                indeg[i] += 1
            }
        }
        if(!used){
            put("NO")
            done()
            return
        }
    }
    val firstUsable = (0 until a2*a2).filter { (exist[it] == 1) && indeg[it] == 0 }
    if(firstUsable.isEmpty()){
        put("NO")
        done()
        return
    }
    /*

    5 3 4
_bcd
_b_d
__b_
aaaa
ab__

abcd 4
abba 2
dbcd 5
     */
    val stack = LinkedList<Int>()
    stack.addAll(firstUsable)

    var current = 0
    val result = IntArray(a2*a2)
//    result[firstUsable] = 1

    val ret = IntArray(n)

    while(stack.isNotEmpty()){
        val a = stack.remove()
        val Ns = AM[a]
        ret[current] = indices[a]
        current += 1
        result[a] = current
        for(n in Ns){
            indeg[n] -= 1
            if(indeg[n] == 0 && exist[n] == 1){
                stack.add(n)
            }
        }
    }
    if(current < n){
        put("NO")
        done()
        return
    }
    put("YES")
    put(ret.joinToString(" "))

    done()
    // Write your solution here
}