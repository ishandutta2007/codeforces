/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
tailrec fun gcd(a: Long, b: Long): Long {
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}
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

fun lcm(a:Long,b:Long):Long{
    return a * b / (gcd(a,b))
}


val ans = listOf<Int>(720719,720704,720639,720704,720095,719424,718319,720704,720639,710720,706079,719424,692159,682304,670095,720704)

fun main() {

    val n = getint()
    val m = getint()

    repeat(n){
        val line = getline(m)

        for(x in 0 until m){
            val a = line[x]
            if((x+it) % 2 == 0){
                put(720720)
            }else{
                put(ans[a-1])
            }
        }
    }
    done()
//
//    var needed = IntArray(16)
//    val x = 720720
//
//    var isForthPower = BooleanArray(1000000)
//    val fp = mutableListOf<Int>()
//
//    for(i in 1..100){
//        val z = i * i * i * i
//        if(z <= 1000000){
//            isForthPower[z] = true
//            fp.add(z)
//        }
//    }
//
//    fun test(x:Int){
//        if(x <= 0 || x > 1000000){
//            return
//        }
//        for(i in 1..16){
//            if(x % i == 0){
//                if(needed[i-1] == 0){
//                    needed[i-1] = x
//                }
//            }
//        }
//    }
//    for(a in fp){
//        test(x - a)
//        test( x+ a)
//    }
//
//    println(needed.joinToString(","))
//
//
//    var start = 1L
//
//    for( i in 1..16){
//        start = lcm(start,i.toLong())
//    }
//    println(start)
    // Write your solution here
}