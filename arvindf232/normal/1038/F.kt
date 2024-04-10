import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
const val huge = 2_727_000_000_000_000_000L // used for seg tree things
val Char.code :Int get() = this.toInt() -  'a'.toInt()

class BinaryTrieImplicit {
    val next = Array(2){ mutableListOf(-1) }
    val root = 0
    var count =1

    fun addString(a:BooleanArray):Int{
        var v = root
        for(c in a){
            val b = if(c) 1 else 0
            val newv = next[b][v]
            if(newv == -1){
                next[0].add(-1)
                next[1].add(-1)
                next[b][v] = count
                v = count
                count++
            }else{
                v = newv
            }
        }
        return v
    }
    fun nextPosition(from:Int,c:Boolean):Int{
        // return -1 if end of tree
        return next[if(c)1 else 0][from]
    }
}
fun prefix_function(s:String):IntArray{
    val n = s.length
    val ret = IntArray(n)
    for(i in 1 until n){
        var j = ret[i-1]
        while(j > 0 && s[i] != s[j]){
            j = ret[j-1]
        }
        if(s[i] == s[j]){
            j++
        }
        ret[i] = j
    }
    return ret
}


const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val d = getint()
        val rawstr = getstr()
        val str = rawstr.map{it == '1'}.toBooleanArray()
        val n = str.size

        val startTree = BinaryTrieImplicit()
        val prefix = prefix_function(rawstr)

        val leafindex = IntArray(n+1)
        for(i in 0 until n){
            leafindex[n-i] = startTree.addString(str.slice(i until n).toBooleanArray())
        }
        val deadstate = startTree.count
        val allstartStates = deadstate * 2


        var DP = Array(allstartStates){LongArray(n+1)}
        DP[0][0] = 1
        for(i in 0 until d){
            val new = Array(allstartStates){LongArray(n+1)}
            for(l in 0 until allstartStates){
                for(r in 0 until n+1){
                    for(c in 0 until 2){
                        var newL = l
                        if(l < deadstate){
                            val next = startTree.nextPosition(l,c == 1)
                            if(next != -1){
                                newL = next
                            }else{
                                newL = l +deadstate
                            }
                        }
                        var newR = r
                        while(true){
                            if(newR == n){
                                break
                            }
                            if(str[newR] == (c == 1)){
                                newR ++
                                break
                            }else{
                                if(newR == 0){
                                    break
                                }
                                newR = prefix[newR - 1]
                            }
                        }
                        new[newL][newR] += DP[l][r]
                    }
                }
            }
            DP = new
        }
        val peak = IntArray(deadstate)
        for((i,v) in leafindex.withIndex()){
            peak[v] = i
        }
        for(c in 0 until deadstate){
            for(k in 0 until 2){
                val next = startTree.nextPosition(c,k==1)
                if(next != -1){
                    peak[next] = maxOf(peak[next],peak[c])
                }
            }
        }

        val lookup = Array(n+1){BooleanArray(n+1)}

        for(l in 0..n){
            for(r in 0..n){
                val lstr = str.slice( (n-l) until n)
                val rstr = str.slice(0 until r)
                val s = rstr + lstr
                val s2 = s.map{if(it) '1' else '0'}.joinToString("")
                lookup[l][r] = s2.contains(rawstr)
            }
        }


        fun ok(l:Int, r:Int):Boolean{
            val ll = if(l >= deadstate) l- deadstate else l
            val trueleft = peak[ll]
            return lookup[trueleft][r]
        }
        var ret = 0L
        for(l in 0 until allstartStates){
            for(r in 0 until n+1){
                if(ok(l,r)){
                    ret += DP[l][r]
                }
            }
        }
        put(ret)
    }
    done()
}
const val singleCase = true
/*
never use tostring on array
 */