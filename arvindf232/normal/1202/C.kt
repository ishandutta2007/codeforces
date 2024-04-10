import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

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
        val t = if(mode == solveMode.real){getint()} else if(mode == solveMode.tc){1 } else randCount
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



class moves(val s:String){
    val n = s.length + 1
    val curX:IntArray = IntArray(n)
    val curY = IntArray(n)
    val maxX:IntArray = IntArray(n)
    val minX = IntArray(n)
    val minY = IntArray(n)
    val maxY = IntArray(n)

    init{
        var pt = 0
        for(c in s){
            pt ++
            val dx = if(c == 'D') 1 else if ( c== 'A') -1 else 0
            val dy = if(c == 'W') 1 else if (c == 'S') -1 else 0
            val newx = dx + curX[pt - 1 ]
            val newy = dy + curY[pt - 1]
            curX[pt] = newx
            curY[pt] = newy

            minX[pt] = minOf(minX[pt - 1],newx)
            maxX[pt] = maxOf(maxX[pt -1],newx)
            minY[pt] = minOf(minY[pt-1],newy)
            maxY[pt] = maxOf(maxY[pt-1],newy)
        }

    }

    fun signature():Pair<Int, Int> {
        return Pair(maxX.last() - minX.last() + 1, maxY.last() - minY.last() + 1 )
    }

}


fun Char.negate():Char {
    if(this == 'A') return 'D'
    if(this == 'D') return 'A'
    if(this == 'W') return 'S'
    return 'W'
}


const val withBruteForce = false
const val randCount = 100
fun main(){
    val dir = listOf(Pair(-1,0),Pair(1,0),Pair(0,1),Pair(0,-1))
    solve.tc {
        share("WWWWWW")
    }
    solve.tc(2){
        share("""
            3
            DSAWWAW
            D
            WA

        """.trimIndent())
    }
//    solve.usetc(2)
    solve.cases{
        val str = getstr()
        val n = str.length

        val A = moves(str)
        val B = moves(str.reversed().map{it.negate()}.joinToString(""))
        var min = Long.MAX_VALUE
        for(i in 0..n){
              brute {
                  val s = str.slice(0 until i)
                  val s2 = str.slice(i until n)
                  for(c in listOf('W','A','S','D')){
                      val sx = s + c.toString() + s2

                      sx dei moves(sx).signature()
                  }
              }

            val mx = A.minX[i]
            val Mx = A.maxX[i]
            val my = A.minY[i]
            val My = A.maxY[i]

            val mx2 = B.minX[n-i] - B.curX[n-i] + A.curX[i]
            val Mx2 = B.maxX[n-i] - B.curX[n-i] + A.curX[i]
            val my2 = B.minY[n-i] - B.curY[n-i] + A.curY[i]
            val My2 = B.maxY[n-i] - B.curY[n-i] + A.curY[i]

            for((dx,dy) in dir){
                val xx = maxOf(Mx,Mx2 + dx) - minOf(mx,mx2 + dx) + 1
                val yy = maxOf(My,My2 + dy) - minOf(my, my2+ dy) + 1

//                "$dx $dy" dei Pair(xx,yy)

                min = minOf(min,xx * yy.toLong())
            }

        }
        val extraX = A.maxX.last() - A.minX.last() + 1
        val extraY = A.maxY.last() - A.minY.last() + 1
        min = minOf(min, extraX.toLong() * extraY)
        put(min)
    }
    done()
}

/*

shorter pointer name , pt

reversed....

off by 1 by occupied area
 */