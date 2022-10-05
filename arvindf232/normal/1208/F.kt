import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.random.Random
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
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
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
}object solve{
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

const val singleCase = true
const val withBruteForce = false
const val randCount = 100


class top2 (){
    var one:Int = Int.MIN_VALUE
    var two:Int = Int.MIN_VALUE
    var oneID:Int = -1
    var twoID:Int = -1
    var size = 0
    constructor(one:Int, two:Int):this(){
        this.one = one
        this.two = two
        this.size =2
    }

    fun add(x:Int,id:Int){
        if(x > one){
            two = one
            twoID = oneID
            one = x
            oneID = id
        }else if (x > two) {
            two = x
            twoID = id
        }
        if( size < 2) size ++
    }
    operator fun get(a:Int): Int {
        if(a == 0){
            return one
        }else if( a== 1){
            return two
        }else{
            throw Exception("Bad access")
        }
    }
    fun exclusiveMaxSum(other:top2):Int{
        if(this.oneID != other.oneID){
            return this.one + other.one
        }else{
            return maxOf(this.one + other.two, this.two + other.one)
        }
    }
    fun union(other:top2):top2 {
        val c = top2(this.one, this.two)
        c.add(other.one,0)
        c.add(other.two,0)
        return c
    }
}

inline fun Int.eachBits(act:(Int)->Unit){
    for(i in HighestBit - 1 downTo 0){
        if(this and (1 shl i) != 0){
            act(1 shl i)
        }
    }
}
inline fun Int.eachBitIndex(act:(Int)->Unit){
    for(i in HighestBit -1  downTo 0){
        if(this and (1 shl i) != 0){
            act(i)
        }
    }
}
inline fun Int.submask(act:(Int)->Unit){
    var here = this
    while (here > 0) {
        act(here)
        here = (here - 1) and this
    }
    act(here)
}
inline fun Int.eachDown1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) != 0){
            act(this - (1 shl i))
        }
    }
}
inline fun Int.eachUp1(act:(Int)->Unit){
    for(i in 0 until HighestBit){
        if(this and (1 shl i) == 0){
            act(this + (1 shl i))
        }
    }
}
fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}
fun Int.allexceptlast(a:Int):Int{
    val mask = (1 shl a) - 1
    return (this and (mask).inv())
}
inline fun Int.breakIntoIntervals(act:(Int,Int)->Unit){ // inclusive
    val a = this + 1
    for(k in 30 downTo 0){
        if(!a.hasElement(k)) continue
        act(allexceptlast(k + 1),k)
    }
}
data class br(val start:Int,val i:Int){// binary range
init{
    kotlin.assert(start and ((1 shl i) - 1) == 0)
}
    fun print(){
        println("[$start, ${start + (1 shl i) - 1 }]")
    }
}
fun rangeIntervalBreaks(left:Int,right:Int,act:(Int,Int)->Unit){
    var left = left
    val right = right + 1
    for(k in 0 until HighestBit){
        if(left.hasElement(k) && left + (1 shl k) <= right){
            act(left,k)
            left += 1 shl k
        }
    }
    for(k in HighestBit -1 downTo 0 ){
        if(right.hasElement(k) && !left.hasElement(k)){
            act(left,k)
            left += 1 shl k
        }
    }
}
const val k = 21
const val HighestBit = k

fun main(){
    solve.tc {
        share("""
            5
            2 24 19 2 24
        """.trimIndent())
    }
    solve.rand {
        share("5")
        share(List(5){Random.nextInt(0,32)})
    }
//    solve.userand()
//    solve.usetc()
    solve.cases{
        val n = getint()
        val L = getline(n)

        brute {
            var ret = 0
            for(i in 0 until n){
                for(j in i+1 until n){
                    for(k in j + 1 until n){
                        val next = L[i] or ( L[j] and L[k])
                        ret = maxOf(next, ret)
                    }
                }
            }
            bruteAnswer(ret)
        }

        val first = IntArray(1 shl k){ -1}
        val second = IntArray(1 shl k){-1}
        for(i in n-1 downTo 0){
            val here = L[i]
            if(first[here] == -1){
                first[here] = i
            }else if(second[here] == -1){
                second[here] = i
            }
        }
        for(i in (1 shl k) - 1 downTo 0 ){
            i.eachUp1 { v ->
                if(first[v] != first[i] && first[v] != second[i]){
                    if(first[v] > first[i]){
                        second[i] = first[i]
                        first[i] = first[v]
                    }else if(first[v] > second[i]){
                        second[i] = first[v]
                    }
                }

                if(second[v] != first[i] && second[v] != second[i]){
                    if(second[v] > first[i]){
                        second[i] = first[i]
                        first[i] = second[v]
                    }else if(second[v] > second[i]){
                        second[i] = second[v]
                    }
                }

            }
        }
        val avail = IntArray(1 shl k){
            second[it]
        }
        val leftavailble = IntArray(1 shl k){Int.MAX_VALUE}
        for(i in 0 until n){
            val here = L[i]
            if(leftavailble[here] == Int.MAX_VALUE){
                leftavailble[here] = i
            }
        }
        for(i in (1 shl k) -1 downTo 0 ){
            i.eachDown1 {
                leftavailble[it] = minOf(leftavailble[it],leftavailble[i])
            }
        }
        var ret = 0
        for(left in 0 until (1 shl k)){
            val need = leftavailble[left]
            if(avail[0] <= need) continue
            var res = 0
            for(i in k-1 downTo 0){
                if(left.hasElement(i)) continue
                val testing = res + ( 1 shl i )
                if(avail[testing] > need){
                    res = testing
                }
            }
            ret = maxOf(ret, res or left)
        }
        put(ret)
    }
    done()

}
/*
binary trie transversal may be enough

has to be presistent trie?

a single variable swap...

order conditions
off by 1 , wrong array size

can never use sort
way wayy to slow


I am bad with bits ,
didn't spot what is supposed to be a common trick


another huge variable swap....
 */