import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*
import kotlin.math.absoluteValue
import kotlin.random.Random
import kotlin.random.nextInt
import kotlin.system.measureTimeMillis
fun minEndTransform(a:List<Int>):List<Int>{
    val ret = a.toMutableList()
    for(i in a.lastIndex downTo 0){
        if(i == a.lastIndex){
            continue
        }
        ret[i] = minOf(ret[i],ret[i+1])
    }
    return ret
}

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    private val IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = try {
                    IN.read(buf)
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
        while (c in '0'..'9') {
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
        while (c in '0'..'9') {
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

//    init {
//        IN = BufferedInputStream(System.`in`, BS)
//    }
}
//class reading{
//    companion object{
//        var jin = FastScanner()
//        var pw = PrintWriter(System.out)
//    }
//}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }

fun getint():Int{ return IO.nextInt() }
fun getlong():Long{ return IO.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{IO.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{IO.nextLong()} }
fun getstr():String{ return IO.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
    get() = this.joinToString("")
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    var str = ""
    if(this is String){ str = this
    }else if(this is Int){ str = this.toString()
    }else if(this is Long){ str = this.toString()
    }
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){throw Exception("Bad programme")} // because assertion does not work



data class problem(val n:Int, val m:Int, val points:List<Int>, val Is: List<interval>){
    fun killall(a:Int,b:Int,c:Int,d:Int):Boolean {
        val I1 = interval(points[0] +a, points[0] + b)
        val I2 =interval(points[1] + c, points[1] + d )
        return Is.all { I1.intersect(it) || I2.intersect(it) }

    }
    fun price(a:Int,b:Int):Int{
        val aa = a.absoluteValue
        val bb = b.absoluteValue
        return minOf(aa,bb) * 2 + maxOf(aa,bb)
    }
    fun BF():Int{
        assert(n == 2)
        var ret = Int.MAX_VALUE
        for(i in -10..0){
            for(j in 0..10){
                for(i2 in -10..0){
                    for(j2 in 0..10){
                        if(killall(i,j,i2,j2)){
                            val final = price(i.absoluteValue, j) + price(i2.absoluteValue, j2)
//                            val final = i.absoluteValue + j + i2.absoluteValue + j2
                            ret = minOf(ret, final)
                        }
                    }
                }
            }
        }
        return ret
    }
}
data class interval(val l:Int,val r:Int,var cluster:Int = 0 ){
    fun intersect(other:interval):Boolean{
        return !(r < other.l || other.r < l)
    }

}
fun main(){
    cases{
//        val n = 2
//        val m = 6
//        val points = listOf(0,10)
//        var intervals = mutableListOf<interval>()
//
//        repeat(2){
//            intervals.add(interval(Random.nextInt(-6,-4),Random.nextInt(-3..-1)))
//        }
//        repeat(2){
//            intervals.add(interval(kotlin.random.Random.nextInt(1..4), kotlin.random.Random.nextInt(5..8)))
//        }
//        repeat(2){
//            intervals.add(interval(Random.nextInt(11..13),Random.nextInt(14..16)))
//        }
//        intervals = intervals.sortedBy{it.l}.toMutableList()

//            List(m){interval(kotlin.random.Random.nextInt(1,4), kotlin.random.Random.nextInt(5,9))}.sortedBy { it.l }
        val n = getint()
        val m = getint()

        val points = getline(n).sorted()
        val intervals = List(m){interval(getint(),getint())}.sortedBy { it.l }

//        val P = problem(n,m,points,intervals)
//        val BF = P.BF()

        val TS = TreeMap<Int,Int>()
        for(p in points){
            TS[p]  = TS.getOrDefault(p,0) + 1
        }
        val indices = TreeMap<Int,Int>()

        var count = -1
        val trueN = TS.size
        val values = IntArray(trueN)
        for(p in TS.keys){
            count += 1
            indices[p] = count
            values[count] = p
        }




        val clusters = List(trueN+1){ mutableListOf<interval>()}




        for(I in intervals){
            val down = TS.floorKey(I.r)
            if(down == null){
                clusters[0].add(I)
                I.cluster = 0
                continue
            }
            if(down >= I.l){
                continue
            }else{
                val ni = indices[down]!! + 1
                clusters[ni].add(I)
                I.cluster = ni
            }
        }
        val clusterMinGet = List(trueN+1){
            minEndTransform(clusters[it].map{it.r})
        }

        val large = 100000000000000000L

        val swing = LongArray(trueN+1){large}
        val neutral = LongArray(trueN +1){large}
        for(i in 0..(trueN)){
            if(i == 0){
                val cost = values[0].toLong() - clusterMinGet[0].getOrElse(0){values[0]}
                swing[i] = cost
                neutral[i] = (2 * cost)
                if(TS[values[i]]!! > 1){
                    neutral[i] = minOf(neutral[i], swing[i])
                }
            }else if(i < trueN){
                val cost = values[i].toLong() - clusterMinGet[i].getOrElse(0){values[i]}
                swing[i] = minOf(swing[i], swing[i-1] + cost )
                neutral[i] = minOf(neutral[i],swing[i-1] + 2 * cost )
                for(j in clusters[i].indices){
                    val returnCost = values[i].toLong() - clusterMinGet[i].getOrElse(j+1){values[i]}
                    val forwardCost = clusters[i][j].l.toLong() - values[i-1]
                    swing[i] = minOf(swing[i], neutral[i-1] + returnCost + forwardCost, swing[i-1] + forwardCost * 2 + returnCost )
                    neutral[i] = minOf(neutral[i], neutral[i-1] + returnCost * 2 + forwardCost, swing[i-1] + forwardCost * 2 + returnCost * 2 )
                }
                if(TS[values[i]]!! > 1){
                    neutral[i] = minOf(neutral[i], swing[i])
                }


            }else{
                if(clusters[trueN].isEmpty()){
                    swing[i] = minOf(neutral[i-1],swing[i-1])
                }else{
                    val finalPrice = clusters[trueN].last().l.toLong() - values[i -1 ]
                    swing[i] = minOf(swing[i-1] + finalPrice * 2 , neutral[i-1] + finalPrice)
                }
            }
        }
//        println("B $BF")
        put(swing[trueN])
//        if(swing[trueN] != BF.toLong()){
//            val x = 0
//        }
val x = 0 
    }
    done()
}

/*
1
2 13
3 7
1 2
2 3
3 4
1 4
4 5
4 7
7 9
3 10
5 6
4 6
6 7
7 8
8 9

1
2 2
0 10
2 6
3 9


1
2 6
0 10
-6 -3
-5 -2
1 7
2 6
12 16
13 16


1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19


1
2 3
0 10
1 4
2 6
4 7

 */