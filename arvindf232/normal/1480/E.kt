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

class Graph(val n:Int){
    val E = Array<MutableList<Int>>(n+1) { mutableListOf() }
    val inverseE = Array<MutableList<Int>>(n+1) { mutableListOf() }

    val sizes = Array(33,{IntArray(33)})

    var maxR = 0
    var maxNused = 0
    var edgeCount =0


    fun add(a:Int,b:Int,size:Int){
        E[a].add(b)
        inverseE[b].add(a)
        assert(sizes[a][b] == 0)
        sizes[a][b] = size
        edgeCount += 1

    }
    fun duplicate(){
        val k = maxNused

        for(p in inverseE[k]){
            val s = sizes[p][k]
            add(p,k+1,s)
        }
        maxNused += 1
    }
    fun double(){
        val k = maxNused
        val R = maxR
        duplicate()
        add(k,k+1,R)
        maxR *= 2
    }
    fun doublePlus1(){
        val k = maxNused
        val R = maxR
//        duplicate()
//        add(k,k+1,R)
//        add(1,k+1,2 * R + 1)
//        maxR *= 2


        add(k,k+1,1)
        add(k,k+2,1)
        add(k+1,k+2,R)
        add(1,k+2,1)

        maxNused = k + 2
        maxR *= 2
        maxR += 1
    }
    fun times4plus(a:Int){
        assert( a <= 3 && a >= 0)
        if(a == 0){
            double()
            double()
        }else if( a== 3){
            fourThree()
        }else{
            val k = maxNused
            val R = maxR
            add(k,k+1,R)
            add(k,k+2,R)
            add(k,k+3,1)
            add(k+1,k+2,R)
            add(k+1,k+3,1)
            add(k+2,k+3,R+1)
            maxNused = k + 3
            maxR *= 4
            maxR += a
            if( a >= 1){
                add(1,k+3,1)
            }
            if(a >= 2){
                add(1,k+2,3* R + 1)
            }
        }

    }
    fun fourThree(){
        val k = maxNused
        val R = maxR
        add(k,k+1,R)
        add(k,k+2,R)
        add(k,k+3,1)
        add(k+1,k+2,R)
        add(k+1,k+3,1)
        add(k+2,k+3,R+2)
        maxNused = k + 3
        maxR *= 4
        maxR += 3
        add(1,k+3,1)
        add(1,k+1,2 * R  +1)
    }
    fun postAppend(size:Int){
        if(size > 0){
            val k = maxNused
            add(k,k+1,size)
            maxNused += 1
        }
    }
    fun start(){
        maxNused = 2
        add(1,2,1)
        maxR = 1
    }
    fun verify(from:Int,to:Int){
        val things = MutableList<MutableList<Int>>(33){ mutableListOf()}
        things[1].add(0)
        for(i in 2..maxNused){
            for(p in inverseE[i]){
                val s = sizes[p][i]
                for(a in things[p]){
                    things[i].add(a + s)
                }
            }
        }
        val final = things[maxNused]
        val count = final.toSet().size == final.size
        val s = final.sorted()
        if( count && s[0] == from && s.last() == to){
            put("Pass")
        }else{
            put(to)
            put(s.joinToString(" "))
        }
    }
    fun printGraph(){
        put("YES")
        put(maxNused)
        put(edgeCount)
        for(i in 1..maxNused){
            for(n in E[i]){
                val s = sizes[i][n]
                kotlin.assert(s != 0)
                put("${i} ${n} ${s}")
            }
        }
        put("Want ${maxR}")
        verify(1,maxR)
    }
}

fun main() {
//    val L = 1
    val L = getInt()
    val R = getInt()

//    for (R in 17..32){
        val toAppend = L-1
        val toBuild = R-(L-1)
        val G = Graph(33)
        G.start()

        var maxIndex = 22
        while((1 shl maxIndex) > toBuild){
            maxIndex -= 1
        }
        var k = (maxIndex-1)
        while(k >= 0){
            if(k == 0){
                val hasByte = ((1 shl k) and toBuild) > 0
                if(hasByte){
                    G.doublePlus1()
                }else{
                    G.double()
                }
                k -= 1
            }else{
                val hasByte1 = ((1 shl k) and toBuild) > 0
                val hasByte2 = ((1 shl (k-1)) and toBuild) > 0
                val a = (if(hasByte1) 2 else 0) + (if(hasByte2) 1 else 0)
                G.times4plus(a)
                k -=2
            }
//            G.printGraph()
        }
        G.postAppend(toAppend)

        put("YES")
        put(G.maxNused)
        put(G.edgeCount)
        for(i in 1..G.maxNused){
            for(n in G.E[i]){
                val s = G.sizes[i][n]
                kotlin.assert(s != 0)
                put("${i} ${n} ${s}")
            }
        }
        assert(G.maxNused <= 32)
        assert(G.maxR == toBuild)
//        put("Max ${G.maxR}")
//        G.verify(L,R)


//    }
    done()


    // Write your solution here
}