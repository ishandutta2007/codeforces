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


fun ask(a:List<Long>):Boolean{
    val n = (a.size / 2).toInt()
    val arr2 = a.sorted()

    val ars = mutableListOf<Long>()
    for(i in 0 until n){
        val v = arr2[2*i]
        if(arr2[2*i] != arr2[2*i+1]){
            return false
        }
        if(v % 2 != 0L){
            return false
        }
        ars.add(v)
    }
    val dif1 = LongArray(n-1)
    for(i in dif1.indices){
        dif1[i] =  ars[i+1] - ars[i]
    }
    val dif2 = LongArray(n-1)
    for(i in dif2.indices){
        val v = dif1[i]
        val t = 2 * (i + 1)
        if(v % t != 0L || v <= 0L){
            return false
        }
        dif2[i] = v/t
    }
    val smallestCount = 2 * n
    var currentSum = 0L
    for(i in dif2.indices){
        currentSum += ((2*n)).toLong() * dif2[i]
    }
    val remaining = ars.last()
    if(remaining <= currentSum){
        return false
    }
    if((remaining - currentSum) % smallestCount != 0L){
        return false
    }
//    val solution = (remaining - currentSum) / smallestCount
//    val totalSol = LongArray(n)
//    totalSol[0] = solution
//    for(i in dif2.indices){
//        totalSol[i+1] = totalSol[i] + dif2[i]
//    }
//    println(totalSol.joinToString(" "))
//    if((0 until n).all{totalSol[it] == ars[it]}){
//        return true
//    }else{
//        return false
//    }

    return (remaining - currentSum) % smallestCount == 0L

}


fun main() {

//    for(a in 1..5){
//        for(b in 1..5){
//            for(c in 1..5){
//                val bb = a+ b
//                val cc = a+b+c
//                val x = (2 * a + 2* bb + 2*cc).toLong()
//                val y = ( 4 * bb + 2 *cc).toLong()
//                val z = (6 * cc).toLong()
//                val ans = ask(mutableListOf(x,y,z,x,y,z))
//                if(ans == false){
//                    print("' ")
//                }
//            }
//        }
//    }

    cases{
        val n = getInt()
        val arr = getLineL( 2 * n)
        put(if(ask(arr)) "YES" else "NO")

    }
    done()
    // Write your solution here
}