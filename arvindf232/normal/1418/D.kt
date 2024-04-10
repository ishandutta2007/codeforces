/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 *
 *  = range - smallest differences
 *
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


fun <K : Any> TreeMap<K,Int>.add1(key:K){
    this[key] = this.getOrDefault(key,0) + 1
}
fun <K : Any> TreeMap<K,Int>.remove1(key:K){
    this[key] = this.getOrDefault(key,0) - 1
    if(this[key]!! == 0){
        this.remove(key)
    }
}

fun main() {
    val n = getInt()
    val q = getInt()
    val arr = getLine(n)

    val things = TreeMap<Int,Int>()
    val differences = TreeMap<Int,Int>()
    for(a in arr){
        things[a] = things.getOrDefault(a,0) +  1
    }
    val items = arr.sorted().windowed(2).map{ it[1] - it[0]}
    for(a in items){
        differences[a] = differences.getOrDefault(a,0) + 1
    }

    fun printA(){
        if(things.isEmpty() || differences.isEmpty()){
            put(0)
        }else{
            val max = things.lastEntry().key
            val min = things.firstEntry().key
            val maxInterval = differences.lastEntry().key
            put((max-min) - (maxInterval))
        }

    }
    printA()
    repeat(q){
        val type = getInt()
        val x = getInt()

        if(type == 1){
            things[x] = things.getOrDefault(x,0) + 1

            if(things[x]!! == 1){
                val upper = things.ceilingKey(x + 1)
                val lower = things.floorKey(x - 1)


                if(upper == null && lower == null){

                }else if(upper == null){
                    val new = x - lower
                    differences[new] = differences.getOrDefault(new,0) + 1
                }else if(lower == null){
                    val new = upper - x
                    differences[new] = differences.getOrDefault(new,0) + 1
                }else{
                    differences.add1(upper - x)
                    differences.add1(x - lower)
                    differences.remove1(upper - lower)
                }
            }
        }else{
            things.remove1(x)
            if(things[x] == null){
                val upper = things.ceilingKey(x + 1)
                val lower = things.floorKey(x - 1)
                if(upper == null && lower == null){

                }else if(upper == null){
                    differences.remove1(x - lower)
                }else if (lower == null){
                    differences.remove1(upper - x)
                }else{
                    differences.remove1(x - lower)
                    differences.remove1(upper - x)
                    differences.add1(upper - lower)
                }
            }
        }
        printA()
    }
    done()
    // Write your solution here
}