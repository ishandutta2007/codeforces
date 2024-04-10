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

fun getInt():Int{ return readLine()!!.toInt() }
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

/*

4
2
3
1
3
1

 */



fun main() {
    // Write your solution here

    val n = getInt()
    val arr = mutableListOf<Int>()

    for(i in 2..n){
        println("XOR ${i} ${1}")
        System.out.flush()
        val ans = getInt()
        arr.add(ans)
    }
//    System.out.flush()
//    val arr = (2..n).map{getInt()}

    val first0 = arr.indexOfFirst { it == 0}
    val has0 = (first0 != -1)
    val items = IntArray(n)


    var hasRepeat = false

    var r1 = -2
    var r2 = -2
    for((i,v) in arr.withIndex()){
        if(items[v] > 0){
            r1 = items[v]
            r2 = i + 2
            hasRepeat = true
            break
        }else{
            items[v] = i + 2
        }
    }
    var knownPos = 0
    var knownValue  = 0
    if( hasRepeat || has0 ){
        var c0:Int =0
        var c1:Int = 0
        if(hasRepeat){
            c0 = r1
            c1 = r2
        }else if(has0){
            c0 = 1
            c1 = first0 + 2
        }
        println("AND ${c0} ${c1}")
        System.out.flush()
        val ans = getInt()

        knownPos = c1
        knownValue = ans
    }else{
        val p1 = 1
        val strongP = items[n-1]

        val ask = if(items[n-1] != 2) 2 else 3

        println("AND ${ask} ${p1}")
        val a = getInt()
        System.out.flush()


        println("AND ${ask} ${strongP}")
        System.out.flush()


        val b = getInt()
        knownValue = a or b
        knownPos = ask
    }

    val ret = IntArray(n)
    ret[0] = arr[knownPos - 2] xor knownValue

    for(i in 2..n){
        ret[i-1] = arr[i - 2] xor ret[0]
    }
    println("! ${ret.joinToString(" ")}")
    System.out.flush()
}