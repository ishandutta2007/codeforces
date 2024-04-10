import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.random.Random
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println(t)
}
// left most is a peak
// always add global minimum
// always add valley
class rmq(val arr:List<Int>){
    val n = arr.size
    val store = mutableListOf<IntArray>()
    fun preprocess(){
        var s = 1
        var olds = 0
        while(s <= n){
            if(s == 1){
                val new = arr.toIntArray()
                store.add(new)
            }else{
                val size = n-s+1
                val old = store.last()
                val new = IntArray(size)
                for(i in 0 until size){
                    new[i] = minOf(old[i],old[i+olds])
                }
                store.add(new)
            }
            olds = s
            s = s shl 1
        }
    }
    fun minQuery(l:Int,r:Int):Int{
        val d = r - l + 1
        val i = 31 - d.countLeadingZeroBits()
        val s = 1 shl i
        val a1 = l
        val a2 = r - s + 1
        val ret1 = store[i][a1]
        val ret2 = store[i][a2]
        return minOf(ret1,ret2)
    }
    init {
        preprocess()
    }
}


object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    var warningActive = true
    var fakein = StringBuilder()

    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf) // no need for checked exceptions
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
        ret.append(c)
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.append(c)
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
    fun rerouteInput(){
        if(warningActive){
            System.err.println("Not accepting inputs!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
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
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

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
fun assert(a:Boolean){if(!a){throw Exception("Failed Assertion")}}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){1} else if(mode == solveMode.tc){1 } else randCount
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            currentAnswer = null
            currentBruteAnswer = null
            a()
        }
        if(withBruteForce){
            put("Checked ${answersChecked}")
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentBruteAnswer != null){
            checkAnswer()
        }
    }
    fun put2(a:Any){answer(a);put(a) }

    fun bruteAnswer(a:Any){
        currentBruteAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun checkAnswer(){
        if(currentAnswer != currentBruteAnswer){
            throw Exception("Failed Test: BF $currentBruteAnswer Current $currentAnswer")
        }
        answersChecked ++
    }
}

const val HighestBit = 17

inline fun Int.eachBitIndex(act:(Int)->Unit){
    for(i in HighestBit downTo 0){
        if(this and (1 shl i) != 0){
            act(i)
        }
    }
}
const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.tc{
        share(
            """
                3 3
2 1 3
            """.trimIndent()
        )
    }
    solve.tc(1){
        share("""
            6 4
            15 2 18 12 13 4
        """.trimIndent())
    }
    solve.tc(2){
        share(4000)
        share(4000)
        share(List(4000){it * 100000})
    }
    solve.cases{
        val n = getint()
        val m = getint()
        val L = getline(n)
        val q = rmq(L)

        fun ask(a:IntArray):Long{
//            just dei a.map{L[it]}
//            assert(a.size == m)
            var cost = 0L
            for(c in a){
                cost += a.size.toLong() * L[c]
            }

            for(i in a.indices){
                for(j in a.indices){
                    val m = minOf(a[i],a[j])
                    val M = maxOf(a[i],a[j])
                    cost -= q.minQuery(m,M)
                }
            }
            return cost
        }

        fun find(l:Int,r:Int):LongArray{
            if(r < l){
                return longArrayOf(0)
            }else if(l == r){
//                just dei "$l $r ${longArrayOf(0,(m-1).toLong()*L[l]).contentToString()}"
                return longArrayOf(0,(m-1).toLong()*L[l])
            }
            val minPoint = (l..r).minByOrNull { L[it] }!!
            val min = L[minPoint]
            var left = find(l,minPoint-1)
            var right = find(minPoint + 1,r)
            val all = LongArray(minOf(r-l+2,m+1))
            if(right.size < left.size){
                left = right.also{right = left}
            }
            for(take in all.indices){
                for(i in left.indices){
                    val rsize = take - 1 - i
                    if(! right.indices.contains(rsize)) continue

                    val value = left[i] + right[rsize] - min.toLong() * i * (rsize + 1) - min.toLong() * (i+1) * (rsize) + (m - take).toLong() * min
                    all[take] = value
                }
                for(i in left.indices){
                    val rsize = take - i
                    if(! right.indices.contains(rsize)) continue

                    val value = left[i] + right[rsize] - 2 * min.toLong() * i * rsize
                    all[take] = maxOf(all[take],value)
                }
            }
//            just dei "$l $r ${all.contentToString()}"
            return all
        }
        val ans = find(0,n-1)[m]

        put(ans)


//        for(i in 0 until (1 shl n)){
//            val ret = mutableListOf<Int>()
//            i.eachBitIndex { ret.add(it) }
//            if(ret.size != m){
//                continue
//            }
//            val ans = ask(ret.toIntArray())
//            i dei ans
//        }

        // 188 - 15 2 2 2 - 2 2 2 2 - 2 2 18 12 - 2 2 12 12
//        just dei ask(intArrayOf(0,2,5,7,9))
// 2 2 2 1 1 1 3 3 3
        // - 2 1 1 1 1 1 1 1 3
    }

    done()
}