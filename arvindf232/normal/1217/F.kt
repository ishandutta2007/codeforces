
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
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
val Char.code :Int get() = this.toInt() -  'a'.toInt()
class DSU_unroll(val n: Int) {
    var size: IntArray = IntArray(n){1}
    var parent: IntArray = IntArray(n){it}

    var ver = -1
    val p_i = IntArray(n)
    val p_v = IntArray(n)
    val s_i = IntArray(n)
    val s_v = IntArray(n)

    fun find(x: Int): Int {
        // no path compression
        if (parent[x] != x) {
            return find(parent[x])
        }
        return parent[x]
    }

    fun set(i:Int, p:Int, j:Int, s:Int){
        ver ++
        p_i[ver] = i
        p_v[ver] = parent[i]
        s_i[ver] = j
        s_v[ver] = size[j]

        parent[i] = p
        size[j] = s
    }
    fun unrollTo(v:Int){
        while(ver > v){
            parent[p_i[ver]] = p_v[ver]
            size[s_i[ver]] = s_v[ver]
            ver --
        }
    }

    fun union(x: Int, y: Int) {
        val xRoot = find(x)
        val yRoot = find(y)
        if (xRoot == yRoot) return
        if(size[xRoot] < size[yRoot]){
            set(xRoot,yRoot,yRoot,size[xRoot] + size[yRoot])
        }else{
            set(yRoot,xRoot,xRoot,size[xRoot] + size[yRoot])
        }
    }
    fun getsize(a:Int):Int{
        return size[find(a)]
    }

    fun getVersionNumber(): Int {
        return ver
    }


    inline fun eachComponent(act:(Int)->Unit){
        for(i in 0 until n){
            if(parent[i] == i){
                act(i)
            }
        }
    }

    fun printAll(){
        val comps = Array(n){ mutableListOf<Int>()}
        for(i in 0 until n){
            comps[find(i)].add(i)
        }
        println(comps.filter { it.isNotEmpty() }.joinToString("     "))
    }

}
const val singleCase = true
const val withBruteForce = false
const val randCount = 100

data class edge(val a:Int, val b:Int){
    constructor(p:Pair<Int,Int>):this(p.first,p.second){}
}

class buildableSegTree (nSuggest  :Int, graphSize:Int){
    //Items lenght must be a power of 2

    val n = (maxOf((nSuggest - 1).takeHighestOneBit(),2)) shl 1
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = Array(n * 2 + 1 ){ mutableListOf<edge>()}
    var layer = levels
    val G = DSU_unroll(graphSize)
    val versionNumber = IntArray(n * 2 + 1)
    var cur = 1

    private fun updateNode(i:Int){
//        arr[i] = arr[i shl 1 ] + arr[(i shl 1) + 1]
    }
    fun rangeAddFunctional(l:Int,r:Int,e:edge){
        segDivision(l,r){v,_ ->
            arr[v].add(e)
        }
    }
    fun moveLeft(){
        layer --
        versionNumber[cur] = G.getVersionNumber()
        cur = (cur shl 1)
        for(e in arr[cur]){
            G.union(e.a,e.b)
        }

//        println(" $cur ")
//        G.printAll()
    }
    fun moveRight(){
        layer --
        versionNumber[cur] = G.getVersionNumber()
        cur = (cur shl 1) + 1
        for(e in arr[cur]){
            G.union(e.a,e.b)
        }
//        println(" $cur ")
//        G.printAll()
    }
    fun moveUp(){

        layer ++
        cur = (cur shr 1)
        G.unrollTo(versionNumber[cur])

//        println(" $cur ")
//        G.printAll()
    }
    fun goToState(i:Int){
        val want = i + n
        while((want shr layer) != cur){
            moveUp()
        }
        while(layer != 0){
            if(want and (1 shl (layer -1)) != 0){
                moveRight()
            }else{
                moveLeft()
            }
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex

    inline fun segDivision(l:Int, r:Int, act:(index:Int,level:Int)->Unit){
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){

                act(left,level)
                left += 1
            }
            if(right and 1 != 0){
                right -= 1
                act(right,level)
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
    }


    val Int.leftNode:Int get(){
        // assert(this <= n )
        return this shl 1
    }
    val Int.rightNode:Int get(){
        // assert(this <= n)
        return (this shl 1) + 1
    }
    val Int.endpoints:Pair<Int,Int> get(){
        val offSet = this - this.takeHighestOneBit()
        val widthLevel = levels - (31 - this.countLeadingZeroBits())
        return Pair(offSet shl widthLevel, (offSet shl widthLevel) + (1 shl widthLevel) - 1)
    }
}
var n = 0
fun Int.next():Int{
    return if(this == n-1) 0 else this + 1
}
class query(val type:Int, val a:Int, val b:Int){
    val p1:Pair<Int,Int> get() = Pair(a,b).sort()
    val p2:Pair<Int,Int> get() = Pair(a.next(),b.next()).sort()
}
fun Pair<Int,Int>.sort():Pair<Int, Int> {
    if(this.first >= this.second){
        return Pair(this.second, this.first)
    }else{
        return this
    }
}


fun main(){
    solve.cases{
         n = getint()
        val m = getint()
        val nextUseful = Array(2){IntArray(m){m}}
        val status = HashMap<Pair<Int,Int>,Boolean>(2 * m /3 * 4 )

        val lastOccurence = HashMap<Pair<Int,Int>,Pair<Int,Int>>( 2 * m /3 * 4 )

        val qs = Array(m){query(getint(), getint()-1, getint()-1 )}

        val st = buildableSegTree(m+1,n)

        for((i,q) in qs.withIndex()){
            if(q.type == 2) continue
            lastOccurence[q.p1]?.let{nextUseful[it.second][it.first] = i }
            lastOccurence[q.p2]?.let{nextUseful[it.second][it.first] = i}
            lastOccurence[q.p1] = Pair(i,0)
            lastOccurence[q.p2] = Pair(i,1)

        }

        val ret = mutableListOf<Char>()
        var last = 0

        for((i,q) in qs.withIndex()){
            st.goToState(i)
//            st.G.printAll()

//            i dei doit
            if(q.type == 2){
                val doit = if(last == 1)q.p2 else q.p1

                val ans = st.G.find(doit.first) == st.G.find(doit.second)
                ret.add(if(ans) '1' else '0')
                last = if(ans) 1 else 0

            }else{
                if(n == 2){
                    val s1 = status.getOrDefault(q.p1, false)
                    val next1 = !s1
                    status[q.p1] = next1
                    if(next1){
//                        i dei Triple(i + 1, nextUseful[i], edge(q.p1))
                        st.rangeAddFunctional(i + 1, minOf(nextUseful[1][i],nextUseful[0][i]), edge(q.p1))
                    }
                }else {
                    val s1 = status.getOrDefault(q.p1, false)
                    val s2 = status.getOrDefault(q.p2, false)
                    val active1 = (last == 0)
                    val next1 = s1 xor active1
                    val next2 = s2 xor (!active1)
                    status[q.p1] = next1
                    status[q.p2] = next2
                    if(next1) {
//                        i dei Triple(i + 1, nextUseful[0][i], edge(q.p1))
                        st.rangeAddFunctional(i + 1, nextUseful[0][i], edge(q.p1))
                    }
                    if(next2) {
//                        i dei Triple(i + 1, nextUseful[1][i], edge(q.p2))
                        st.rangeAddFunctional(i + 1, nextUseful[1][i], edge(q.p2))
                    }
                }
            }
        }
        put(ret.joinToString(""))
    }
    done()
}

/*

reversed the layers ( legacy speghatti)
did not read input ( different coding scheme)
unique hash of edges (not sorted)
n = 2 edge case
next useful, wrong ordering

3 7
1 1 3
2 2 3
1 2 3
2 1 2
1 3 2
2 2 3
1 1 3


 */