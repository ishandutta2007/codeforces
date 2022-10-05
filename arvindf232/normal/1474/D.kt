/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools


 1 <= 2
 2-1 <= 3
 3-2+1 <= 4
 4-3+2-1 == 5


if 2-3+1  changed by -2* 3 and + 2*2


 1 3 2 6 6

 check last equal

 check postfix minimum


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


fun main() {

    cases case@{
        val n = getInt()
        val arr = getLineL(n)

        val alt = LongArray(n,{0})

        alt[0] = arr[0]

        for( i in 1 until n){
            alt[i] = arr[i] - alt[i-1]
        }
        val postMin = LongArray(n,{0})
        for(i in n-1 downTo 0){
            if(i + 2 <= n - 1){
                postMin[i] = minOf(postMin[i+2],alt[i])
            }else{
                postMin[i] = alt[i]
            }
        }
//        val a = postMin[0] >= 0
//        val b = postMin[1] >= 0
//        val c = arr[n-1] == 0L
//        val d = arr[n-1]
        var firstBad = alt.indexOfFirst { it < 0 }
        if(firstBad == -1){
            firstBad = n + 1
        }

        if(postMin[0] >= 0 && postMin[1] >= 0 && alt[n-1] == 0L ){
            put("YES")
            return@case
        }
        for(swap in 0 until n-1) {
            val a1 = arr[swap]
            val a2 = arr[swap + 1]

            val diff = 2 * a2 - 2 * a1

            val con5 = !(swap > firstBad)
            val condition1 = (alt[swap] - a1 + a2) >= 0
            val condition2 = if (swap + 1 <= n - 1) (postMin[swap + 1] -diff >= 0 ) else true
            val condition3 = if (swap + 2 <= n - 1) (postMin[swap + 2] + diff >= 0) else true
            val mod = ((n - 1 - swap )% 2) * 2 - 1
            val condition4 = (alt[n - 1] - mod * diff) == 0L

            if (condition1 && condition2 && condition3 && condition4 && con5) {
                put("YES")
                return@case
            }
        }
        // just a chaotic logic error 
        // be logically sound
        
        // pattern: assumed it doesn't change 
        
        
// 1 3 1 2 3
// 1 2 -1 3 0
//        val dif = LongArray(n,{0})
//
//        alt[0] = arr[0]
//
//        for(i in 1 until n){
//            alt[i] = arr[i-1] - alt[i-1]
//            dif[i] = arr[i] - alt[i]
//        }
//
//        val postMin = LongArray(n,{0})
//        for(i in n-1 downTo 0){
//            if(i + 2 <= n - 1){
//                postMin[i] = minOf(postMin[i+2],dif[i])
//            }else{
//                postMin[i] = dif[i]
//            }
//        }
//
//        //1 2 1
//        // 2 1 1
//
//        // dif: 0,-1,2
//        for(swap in 0 until n-1) {
//            val a1 = arr[swap]
//            val a2 = arr[swap + 1]
//
//            val diff = 2 * a2 - 2 * a1
//
//
//            val condition1 = (dif[swap + 1] - a1 + a2) > 0
//            val condition2 = if (swap + 3 <= n - 1) (postMin[swap + 3] >-diff) else true
//            val condition3 = if (swap + 2 <= n - 1) (postMin[swap + 2] > diff) else true
//            val mod = (n - 1 - swap % 2) * 2 - 1
//            val condition4 = (dif[n - 1] - mod * diff) == 0L
//
//            if (condition1 && condition2 && condition3 && condition4) {
//                put("YES")
//                return@case
//            }
//        }
        put("NO")


    }
    done()

    // Write your solution here
}