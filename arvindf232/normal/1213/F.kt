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

const val singleCase = true
const val withBruteForce = false
const val randCount = 100
class Graph(val n:Int, val directed:Boolean){
    val E = Array<MutableList<Int>>(n) { mutableListOf() }
    val indices = 0 until n
//    val invE = Array<MutableList<Int>>(n) { mutableListOf() }

    fun add(a:Int,b:Int){
        E[a].add(b)
//        invE[b].add(a)
        if(!directed){
            E[b].add(a)
//            invE[a].add(b)
        }
    }
    inline fun NS(from:Int,act:(Int)->Unit){
        for(v in E[from]){
            act(v)
        }
    }
    inline fun everyEdge(act:(Int,Int)->Unit){
        for((i,v) in E.withIndex()){
            for(to in v){
                act(i,to)
            }
        }
    }


    // maintaining by adjaceny matrix
//    val E = List(n+1){BooleanArray(n+1)}
//    fun add(a:Int,b:Int){
//        E[a][b] = true
//        if(!directed){
//            E[b][a] = true
//        }
//    }
//    fun remove(a:Int,b:Int){
//        E[a][b] = false
//        if(!directed){
//            E[b][a] = false
//        }
//    }
//    inline fun NS(from:Int,act:(Int)->Unit){
//        for(j in 0..n){
//            if(E[from][j]){
//                act(j)
//            }
//        }
//    }


    fun streamEdges(m:Int){
//        repeat(m){
//            val x = getint()
//            val y = getint()
//            add(x,y)
//        }
    }
    inline fun BFS(reached:(Int,Int)->Unit){
        val root = 0
        val toDo = ArrayDeque<Int>()
        val explored = IntArray(n+1){-1} // also store parents
        toDo.add(root)
        explored[root] = -2

        while(toDo.size > 0){
            val x = toDo.removeFirst()
            reached(x,explored[x])
            NS(x){ a->
                if(explored[a] == -1){
                    explored[a] = x
                    toDo.addLast(a)
                }
            }
        }
    }
    val basic_active = false
    val basic_setup = if(basic_active) n else 0

    val parent = IntArray(basic_setup)
    val depth = IntArray(basic_setup)
    val sizes = IntArray(basic_setup)
    val subs = List(basic_setup){mutableListOf<Int>()}
    fun setup(){
        DFS_long(0,{ }){
                from,to ->
            parent[to] = from
            depth[to] = depth[from] + 1
            subs[from].add(to)
        }
        DFS {v ->
            var ret = 1
            for(a in subs[v]){
                ret += sizes[a]
            }
            sizes[v] = ret
        }
    }

    inline fun DFS(dfsOrder:(Int)->Unit){
        DFS_long(0,dfsOrder,{_,_->})
    }

//
//    inline fun DFS_Long_2(root:Int,dfsOrder:(Int)->Unit,long:(Int,Int)->Unit){
//        val done = BooleanArray(n)
//        var pointer = 0
//        val stack = IntArray(n+1)
//        stack[0] = root
//        pointer = 0
//        while(pointer >= 0){
//            val now = stack[pointer]
//            if(done[now]){
//                dfsOrder(now)
//                pointer--
//            }else{
//                done[now] = true
//                NS(now){
//                    if(!done[it]){
//                        pointer++
//                        stack[pointer] = it
//                        long(now,it)
//                    }
//                }
//            }
//        }
//    }

    inline fun DFS_long(root:Int,dfsOrder:(Int)->Unit,long:(Int,Int)->Unit){
        //Long: (from,to) i.e. (parent, child)
        var pointer = 0
        val toDo = IntArray(n+1)

        val explored = BooleanArray(n+1)
        val secondTime = BooleanArray(n+1)
        toDo[0] = root
        explored[root] = true

        while(pointer >= 0){
            val x = toDo[pointer]
            if(secondTime[x]){
                dfsOrder(x)
                pointer--
                continue
            }
            //move here for top down order
            secondTime[x] = true
            NS(x){ a->
                if(!explored[a]){
                    explored[a] = true
                    pointer++
                    long(x,a)
                    toDo[pointer] = a
                }
            }
        }
    }
        inline fun DFS_long_Exhaust(dfsOrder:(Int)->Unit,long:(p:Int,into:Int,root:Int)->Unit){
        //Long: (from,to) i.e. (parent, child)
        var pointer:Int
        val toDo = IntArray(n)

        val explored = BooleanArray(n)
        val secondTime = BooleanArray(n)

        var exploredCount = 0
        var exploredPointer = 0

        while(exploredCount < n){
            while(explored[exploredPointer]){
                exploredPointer ++
            }
            val root = exploredPointer
            explored[root] = true
            exploredCount ++
            toDo[0] = root
            pointer = 0
            while(pointer >= 0){
                val x = toDo[pointer]
                if(secondTime[x]){
                    dfsOrder(x)
                    pointer--
                    continue
                }
                //move here for top down order
                secondTime[x] = true
                NS(x){ a->
                    if(!explored[a]){
                        explored[a] = true
                        exploredCount ++
                        pointer++
                        long(x,a,root)
                        toDo[pointer] = a
                    }
                }
            }
        }
    }
    fun topologicalSort(): List<Int> {
        val ret = mutableListOf<Int>()
        DFS_long_Exhaust({ret.add(it)}){a,b,_ ->}
        return ret
    }

}

data class permutation(val p:IntArray){
    val n:Int get() = p.size
    companion object{
        fun identity(n:Int): permutation {
            return permutation((0 until n).toList().toIntArray())
        }
        fun all(n:Int): MutableList<permutation> {
            val ret = mutableListOf<permutation>()
            val A = IntArray(n){it}
            val c = IntArray(n)

            ret.add(permutation(A.copyOf()))

            var i = 0
            while(i < n){
                if(c[i] < i){
                    if(i %2 == 0){
                        A[0] = A[i].also { A[i] = A[0] }
                    }else{
                        A[c[i]] = A[i].also { A[i] = A[c[i]] }
                    }
                    ret.add(permutation(A.copyOf()))
                    c[i] += 1
                    i = 0
                }else{
                    c[i] = 0
                    i += 1
                }
            }
            return ret
        }
    }
    // 0 based
    fun inverse():permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[i]] = i
        }
        return permutation(ret)
    }
    infix fun compose(other:permutation):permutation{
        val ret = IntArray(p.size)
        for(i in 0..p.lastIndex){
            ret[p[other.p[i]]] = i
        }
        return permutation(ret)
    }
    fun swapDistances():Int{
        var ret = 0
        cyclesOfPermutations { ret += it.size - 1  }
        return ret
    }
    fun shiftRightBy(a:Int):permutation{
        val ret = IntArray(p.size)
        var here = a - 1
        for(i in 0 until p.size){
            here += 1
            if(here >= p.size){
                here -= p.size
            }
            ret[here] = p[i]
        }
        return permutation(ret)
    }
    fun swapAt(a:Int,b:Int):permutation{
        val new = p.copyOf()
        new[a] = new[b].also{new[b] = new[a]}
        return permutation(new)
    }
    inline fun cyclesOfPermutations(doit:(List<Int>)->Unit){
        val arr = this.p
        val n = arr.size
        val done = BooleanArray(n)
        var haveDone = 0
        var pointer = 0
        while(haveDone < n){
            while(done[pointer]){
                pointer++
            }
            haveDone += 1
            val x = pointer
            val todo = mutableListOf(x)
            var cur = x
            done[x] = true
            while(true){
                val next = arr[cur]
                if(done[next]){
                    break
                }
                done[next] = true
                todo.add(next)
                haveDone += 1
                cur = next
            }
            doit(todo)
        }
    }

    fun subpermutation(mask:Int):permutation{
        val things = mutableListOf<Int>()
        for(i in 0 until p.size){
            if(mask and 1 shl i != 0){
                things.add(i)
            }
        }
        val firstThings = things.withIndex().sortedBy { it.value }
        return (permutation(firstThings.map{it.index}.toIntArray()).inverse())
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) return true
        if (javaClass != other?.javaClass) return false

        other as permutation

        if (!p.contentEquals(other.p)) return false
        return true
    }

    override fun hashCode(): Int {
        return p.contentHashCode()
    }

    override fun toString(): String {
        return p.joinToString(" ")
    }
    operator fun get(i:Int):Int{
        return p[i]
    }
}
fun Graph.condensationGraph():Triple <Graph,IntArray,IntArray>{
    val exitOrder = IntArray(n)
    val assign = IntArray(n)
    var pointer = n-1
    DFS_long_Exhaust({exitOrder[pointer] = it; pointer--}){a,b,_ ->}
    val reverse = List(n){ mutableListOf<Int>()}
    everyEdge { a, b -> reverse[b].add(a) }
    val used = BooleanArray(n)
    var component = mutableListOf<Int>()

    val roots = IntArray(n)
    val rootNodes = mutableListOf<Int>()
    fun dfs2(v:Int){
        used[v] = true
        component.add(v)
        for(c in reverse[v]){
            if(!used[c]) dfs2(c)
        }
    }
    var type = -1
    for(v in exitOrder){
        if(!used[v]){
            dfs2(v)

            type ++
            val root = component[0]
            for(a in component){
                roots[a] = root
                assign[a] = type
            }
            rootNodes.add(root)
            component.clear()
        }
    }
    val retG = Graph(n,true)
    everyEdge { a, b -> if(roots[a] != roots[b]){
        retG.add(roots[a],roots[b])
    }
    }
    return Triple(retG,roots,assign)
}

inline fun Graph.strongSearch(newitem:(root:Int)->Unit,newcomp:(v:Int)->Unit){
    val exitOrder = IntArray(n)
    var pointer2 = n-1
    DFS_long_Exhaust({exitOrder[pointer2] = it; pointer2--}){a,b,_ ->}
    val reverse = List(n){ mutableListOf<Int>()}
    everyEdge { a, b -> reverse[b].add(a) }

    var pointer:Int
    val toDo = IntArray(n)
    val explored = BooleanArray(n)
    val secondTime = BooleanArray(n)

    for(v in exitOrder){
        if(!explored[v]){
            newcomp(v)
            val root = v
            toDo[0] = root
            pointer = 0
            explored[root] = true
            while(pointer >= 0){
                val x = toDo[pointer]
                if(secondTime[x]){
                    newitem(x)
                    pointer--
                    continue
                }
                //move here for top down order
                secondTime[x] = true
                for(a in reverse[x]){
                    if(!explored[a]){
                        explored[a] = true
                        pointer++
                        toDo[pointer] = a
                    }
                }
            }
        }
    }
}
fun Graph.strongComponentsArray():IntArray{
    val ret = IntArray(n)
    var now = -1
    strongSearch({v ->ret[v] = now},{now++})
    return ret
}

fun main(){
//    val G = Graph(4,true)
//    G.add(0,1)
//    G.add(0,2)
//    G.add(1,2)
//    G.add(2,1)
//    G.DFS_long_Exhaust({println(it)}){_,_,_ ->}

    solve.cases{
        val n = getint()
         val k = getint()
        val G = Graph(n,true)

        val A = permutation(getline(n).map{it -1}.toIntArray())
        val B = permutation(getline(n).map{it -1}.toIntArray())

        for(i in 0 until n-1){
            G.add(A[i],A[i+1])
            G.add(B[i],B[i+1])
        }



        val assign = G.strongComponentsArray()
//        val (retG,roots,assign) = G.condensationGraph()

        val max = assign.maxOrNull()!!
        if(max < k-1){
            put("NO")
        }else{
            put("YES")
            val ret = CharArray(n)
            for(i in 0 until n){
                val c = minOf(25,assign[i])
                val cc = (c + 'a'.toInt()).toChar()
                ret[i] = cc
            }
            for(i in 0 until n-1){
                assert(ret[A[i]] <=  ret[A[i+1]])
                assert(ret[B[i]] <= ret[B[i+1]])
//                G.add(B[i],B[i+1])
            }
            put(ret.joinToString(""))
        }
    }
    done()
}

/*

strong connected components are hard
 */