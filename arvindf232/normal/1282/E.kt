import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
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
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        IN = BufferedInputStream(fakein.toString().byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
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
fun getline(n:Int):IntArray{
    val ret = IntArray(n);repeat(n){ret[it] = getint()};return ret
}
fun getlineL(n:Int):LongArray{
    val ret = LongArray(n);repeat(n){ret[it] = getlong()};return ret
}
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
fun assert(a:Boolean){
    if(!a){throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    inline fun cases(a:solve.()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
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
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()


const val withBruteForce = false
const val randCount = 100


class triangle(val a:Int,val  b:Int, val c:Int,val id:Int){
    var removed = false
    var aval = -1

    val edgesslow:List<edge> get() = listOf(edge.new(a,b),edge.new(b,c), edge.new(a,c))
}
data class edge(val a:Int, val b:Int){
    companion object{
        fun new( a:Int,  b:Int):edge {
            return edge(minOf(a,b), maxOf(a,b))
        }
    }

//    override fun hashCode():Int {
//        return (a shl 15) xor b
//    }

//    override fun equals(other:Any?):Boolean {
//        if(this === other) return true
//        if(javaClass != other?.javaClass) return false
//
//        other as edge
//
//        if(a != other.a) return false
//        if(b != other.b) return false
//
//        return true
//    }
}
fun main(){
    solve.cases{
        val n = getint()
        val triangles = Array(n-2) {
            triangle(getint() - 1, getint() - 1, getint() - 1, it)
        }
        val edgeToTriangle =  mutableMapOf<edge,MutableList<triangle>>()
        val edgeStore = Array(n-2){triangles[it].edgesslow}
        fun triangle.edges():List<edge>{
            return edgeStore[this.id]
        }
        for(t in triangles) {
            for(e in t.edges()) {
                if(edgeToTriangle[e] == null) {
                    edgeToTriangle[e] = ArrayList(2)
                }
                edgeToTriangle[e]!!.add(t)
            }
        }

        val cycle = edgeToTriangle.filterValues { it.size == 1 }.keys
        val to = Array(n){ ArrayList<Int>(2)}

        for(e in cycle){
            to[e.a].add(e.b)
            to[e.b].add(e.a)
        }
        var pointer = -1
        val retPermu = IntArray(n)
        pointer ++
        retPermu[0] = 0
        val any = to[0][0]
        pointer ++
        retPermu[1] = any
        tailrec fun dfs(a:Int, from:Int){
            var next =-1
            for(c in to[a]){
                if(c == from || c == 0) continue
                pointer++
                retPermu[pointer] = c
                next = c
            }
            if(next != -1)
                dfs(next,a)
        }
        dfs(any,0)
//        pointer = 1
//        dfs(any,0)
        val mainEdges = HashSet<edge>((n+2)/3 * 4)
        for(e in cycle){
            mainEdges.add(e)
        }

        val ret = mutableListOf<Int>()

        val consider = ArrayDeque<triangle>()
        for(t in triangles){
            var count = 0
            for(e in t.edges()){
                if(mainEdges.contains(e)){
                    count++
                }
            }
            t.aval = count
            if(count>= 2){
                consider.add(t)
            }
        }
        while(consider.isNotEmpty()){
            val v = consider.removeFirst()
            if(v.removed == true) continue
            if(v.aval < 2) continue

            v.removed = true
            ret.add(v.id)

            for(e in v.edges()){
                if(mainEdges.contains(e)){
                    mainEdges.remove(e)
                }else{
                    mainEdges.add(e)
                    for(tt in edgeToTriangle[e]!!){
                        if(tt == v) continue
                        consider.addLast(tt)
                        tt.aval ++
                    }
                }
            }
        }
        assert(ret.size == (n-2))

        for(i in 0 until n){
            put(retPermu[i] + 1)
        }
        for(a in ret){
            put(a + 1)
        }
//        put("")
    }
    done()
}
const val singleCase = false

/*

DFS chain be very careful
Logicerror: careless about recursion optimsiations
 */