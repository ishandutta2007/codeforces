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


fun search(text: String, pattern: String):IntArray{

    // Create concatenated string "P$T"
    val concat = "$pattern$$text"
    val l = concat.length
    val Z = IntArray(l)

    // Construct Z array
    getZarr(concat, Z)

    // now looping through Z array for matching condition
    return Z
//    for (i in 0 until l) {
//
//        // if Z[i] (matched region) is equal to pattern
//        // length we got the pattern
//        if (Z[i] == pattern.length) {
//            println(
//                "Pattern found at index "
//                        + (i - pattern.length - 1)
//            )
//        }
//    }
}

// Fills Z array for given string str[]
private fun getZarr(str: String, Z: IntArray) {
    val n = str.length

    // [L,R] make a window which matches with
    // prefix of s
    var L = 0
    var R = 0
    for (i in 1 until n) {

        if (i > R) {
            R = i
            L = R

            while (R < n && str[R - L] == str[R]) R++
            Z[i] = R - L
            R--
        } else {

            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            val k = i - L

            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R - i + 1) Z[i] = Z[k] else {


                // else start from R and check manually
                L = i
                while (R < n && str[R - L] == str[R]) R++
                Z[i] = R - L
                R--
            }
        }
    }
}
fun main() {
    cases{
        val n = getInt()
        val str = getString()

        val Lstring = String(CharArray(n){ if(it % 2 == 0) 'R' else 'L'})
        val Rstring = String(CharArray(n){ if(it % 2 == 0) 'L' else 'R'})
        val offSet = Lstring.length + 1
        val Z = search(str,Lstring)
        val Z2 = search(str.reversed(),Rstring)
        val ret = IntArray(n+1)
        for(i in ret.indices){
            val right = when{
                i < n -> Z[offSet + i]
                else -> 0
            }
            val left = when{
                i > 0 -> Z2[offSet + (n-i)]
                else -> 0
            }
            ret[i] = left + right + 1
        }
        put(ret.joinToString(" "))

    }
    done()
    // Write your solution here
}