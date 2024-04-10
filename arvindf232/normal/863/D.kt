import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import java.lang.IndexOutOfBoundsException
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
class tnode(var value:Int, val priority:Int = Random.nextInt()){
    var left:tnode? = null
    var right:tnode? = null
    var size:Int = 1

    var rev:Boolean = false
//    var add:Int? = null
//    var paint:Int? = null
//
//    var sum:Int = value
//    var min:Int = value

    fun updateSize(){
        this.size = 1 + (left?.size ?: 0) + (right?.size ?: 0)
//
//        this.sum = (left?.calsum() ?: 0) + (right?.calsum() ?: 0) + value
        //require free of updates whenever calling this
    }

    //    fun calsum(): Int {
//        if(paint != null){
//            return paint!! * size
//        }else{
//            return sum + (add ?: 0) * size
//        }
//    }
    fun pushUpdates(){
        if(rev){
            this.left = this.right.also { this.right = this.left }
            if(left != null) left!!.rev = !left!!.rev
            if(right != null) right!!.rev = !right!!.rev
            rev = false
        }
//        if(add != null){
//
//        }
    }
    fun asList():List<Int>{
        val ret = mutableListOf<Int>()
        fun print(c:tnode?){
            if(c == null) return
            c.pushUpdates()
            print(c.left)
            ret.add(c.value)
            print(c.right)
        }
        print(this)
        return ret
    }
    fun print(){
        println(asList().joinToString(" "))
    }
}

fun split(root:tnode?,key:Int,res:Int):Pair<tnode?,tnode?>{
    // split into [0,key] and [key+1, lastIndex]
    if(root == null){
        return Pair(null,null)
    }else{
        root.pushUpdates()
        val currentkey = res + (root.left?.size ?: 0)
        if(currentkey <= key){
            val (l,r) = split(root.right,key,res + 1 + (root.left?.size ?: 0))
            root.right = l
            root.updateSize()
            return Pair(root,r)
        }else{
            val (l,r) = split(root.left,key,res)
            root.left = r
            root.updateSize()
            return Pair(l,root)
        }
    }
}
fun merge(l:tnode?,r:tnode?):tnode?{
    l?.pushUpdates()
    r?.pushUpdates()
    if(l == null || r == null){
        if(l == null) return r else return l
    }else if(l.priority > r.priority){
        l.right = merge(l.right,r)
        l.updateSize()
        return l
    }else{
        r.left = merge(l,r.left)
        r.updateSize()
        return r
    }
}

//Non implicit version
//fun insert(root:tnode?,new:tnode):tnode{
//    if(root == null){
//        return new
//    }else if(new.priority > root.priority){
//        val (l,r) = split(root,new.key)
//        new.left = l
//        new.right = r
//        new.updateSize()
//        return new
//    }else{
//        if(root.key <= new.key){
//            root.right = insert(root.right,new)
//        }else{
//            root.left = insert(root.left,new)
//        }
//        root.updateSize()
//        return root
//    }
//}
fun insertNode(root:tnode?,new:tnode,i:Int):tnode?{
    // i will become the new index
    val (L,R) = split(root,i-1,0)
    val T1 = merge(L,new)
    return merge(T1,R)
}
fun erase(root:tnode?, key:Int,res:Int):tnode?{
    val root = root ?: throw IndexOutOfBoundsException()
    root.pushUpdates()
    val here = res + (root.left?.size ?: 0)
    if(here == key){
        return merge(root.left,root.right)
    }else{
        return if(key < here){
            root.left = erase(root.left,key,res)
            root.updateSize()
            root
        }else{
            root.right = erase(root.right,key, here + 1)
            root.updateSize()
            root
        }
    }
}
tailrec fun find(root:tnode?,key:Int,res:Int):tnode{
    val root = root ?: throw IndexOutOfBoundsException()
    root.pushUpdates()
    val here = res + (root.left?.size ?: 0)
    if(here == key){
        return root
    }else{
        if(key < here){
            return find(root.left,key,res)
        }else{
            return find(root.right,key, here + 1)
        }
    }
}
inline fun rangeAct(root:tnode?, left:Int, right:Int, act:(tnode)->Unit):tnode?{
    val (L1,R1) = split(root,left-1,0)
    val (want,R2) = split(R1,right-left,0)
    if(want != null){
        act(want)
    }
    val t1 = merge(L1,want)
    val t2 = merge(t1,R2)
    return t2
}
//tailrec fun contains(root:tnode?, key:Int):Boolean{
//    if(root == null) return false
//    if(root.key == key){
//        return true
//    }else if(root.key < key){
//        return contains(root.right,key)
//    }else{
//        return contains(root.left,key)
//    }
//}

object treapStandard{


//    fun printAll(a:tnode?):IntArray{
//        val s = a?.size ?: 0
//        val ret = IntArray(s)
//        for(i in 0 until s){
//            ret[i] = find(a,i,0).value
//        }
//        return ret
//    }
}

class treapHandler(){
    constructor(arr:IntArray):this(){
        val nodes = Array(arr.size){tnode(arr[it])}
        for(c in arr.lastIndex downTo 0){
            insertWhole(0,nodes[c])
        }
    }
    var root:tnode? = null
    operator fun get(i:Int): Int {
        return find(root,i,0).value
    }
    fun insert(i:Int,v:Int){
        insertWhole(i,tnode(v))
    }
    private fun insertWhole(i:Int,n:tnode){
        root = insertNode(root,n,i)
    }
    fun print(){
        root?.print()
    }
    fun reverse(l:Int,r:Int){
        //200k reversals in 727ms , WYSI
        root = rangeAct(root,l,r){
            it.rev = !it.rev
        }
    }
    fun cyclicRightShift(l:Int,r:Int){
        val (L1,R1) = split(root,l-1,0)
        val (want,R2) = split(R1,r-l,0)
        val (most,last) = split(want,want!!.size -2,0)
        val newwant = merge(last,most)
        root = merge(L1,merge(newwant,R2))
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

const val singleCase = true
const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val n = getint()
         val q = getint()
        val m = getint()
        val L = getline(n)

        val arr = treapHandler(L)


        repeat(q){
            val t = getint()
            val l = getint() -1
            val r = getint() -1
            if(t == 1){
                arr.cyclicRightShift(l,r)
            }else{
                arr.reverse(l,r)
            }
        }
        val out = arr.root!!.asList()
        val qs = getline(m)
        for(i in 0 until m){
            put(out[qs[i] - 1 ])
        }

    }
    done()
}