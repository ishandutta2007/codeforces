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
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
const val funny = -777222777 // start array with this to be safe, WYSI
const val huge = 2_727_000_000_000_000_000L // used for seg tree things
val Char.code :Int get() = this.toInt() -  'a'.toInt()
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge



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
        if(!basic_active){
            println("Did not set basic setup ")
        }
        DFS_long(0,{ v ->
            sizes[v]++
            if(v != 0) sizes[parent[v]] += sizes[v]
        }){
                from,to ->
            parent[to] = from
            depth[to] = depth[from] + 1
            subs[from].add(to)
        }
    }
    inline fun DFS(dfsOrder:(Int)->Unit){
        DFS_long(0,dfsOrder,{_,_->})
    }
    inline fun DFS_long(root:Int,dfsOrder:(Int)->Unit,long:(parent:Int,here:Int)->Unit){
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
    inline fun DFS_Long_Exhaust(dfsOrder:(Int)->Unit,newroot:(Int)->Unit = {},long:(p:Int,into:Int,root:Int)->Unit = {_,_,_ ->}){
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
            newroot(root)
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
    fun bridges(): List<Pair<Int, Int>> {
        var cur = 0
        val visited = BooleanArray(n)
        val tin = IntArray(n){-1}
        val low = IntArray(n){-1}
        val ret = mutableListOf<Pair<Int,Int>>()
        fun dfs(v:Int, p:Int){
            visited[v] = true
            low[v] = cur++
            tin[v] = low[v]
            NS(v){to ->
                if(to == p) return@NS
                if(visited[to]){
                    low[v] = minOf(low[v],tin[to])
                }else{
                    dfs(to,v)
                    low[v] = minOf(low[v],low[to])
                    if(low[to] > tin[v]){
                        ret.add(Pair(v,to))
                    }
                }
            }
        }
        for(i in 0 until n){
            if(!visited[i]){
                dfs(i,-1)
            }
        }
        return ret
    }

}

fun Int.hasElement(a:Int):Boolean{
    return (this and ( 1 shl a)) != 0
}

inline fun Int.submask(act:(Int)->Unit){
    var here = this
    while (here > 0) {
        act(here)
        here = (here - 1) and this
    }
    act(here)
}


const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.cases{
        val n = getint()
         val m = getint()

        val adjbad = Array(n){BooleanArray(n)}
        repeat(m){
            val a = getint() - 1
            val b = getint() - 1
            adjbad[a][b] = true
            adjbad[b][a] = true
        }
        // start, finish,
        val hascycle = BooleanArray(1 shl n)
        val DP = Array(n){Array(n){IntArray(1 shl n){-1}}}
        for(start in 0 until n){
            DP[start][start][0] = n
            for(mask in  0 until ( 1 shl n)){
                for(right in 0 until n){
                    if(-1 == DP[start][right][mask]) continue
                    if(right == start && mask != 0){
                        hascycle[mask] = true
                        continue
                    }
                    for(next in 0 until n){
                        if(!adjbad[right][next]) continue
                        if(mask.hasElement(next)) continue
                        val newmask = mask xor (1 shl next)
                        if(newmask.countOneBits() == 2 && start == next) continue
                        DP[start][next][newmask] = right
                    }
                }
            }
        }
        val costs = IntArray(1 shl n){plarge}
        val best = Array(1 shl n){IntArray(3)}
        for(i in hascycle.indices){
            if(hascycle[i] && i.countOneBits() > 2){
                costs[i] = i.countOneBits()
                best[i][0] = -2 
            }
        }
        val values = IntArray(1 shl n){it.countOneBits()}
        // mask1 , leftendpoint, rightendpoint

        for(newmask in 0 until (1 shl n)){
            newmask.submask { sub ->
                if(costs[sub] >= plarge) return@submask
                val all = IntArray(values[sub])
                var pointer = -1
                for(l in 0 until n){
                    if((sub and ( 1 shl l)) != 0){
                        pointer ++
                        all[pointer] = l
                    }
                }
                for(l in all){
                    for(r in all){
                        if(l < r) continue
                        val other = (newmask xor sub) or ( 1 shl r)
                        if(l == r && values[other] <= 2) continue
                        if(DP[l][r][other] != -1){
                            val newcost = costs[sub] + values[other]
                            if(newcost < costs[newmask]){
                                costs[newmask] = newcost
                                best[newmask][0] = sub
                                best[newmask][1] = l
                                best[newmask][2] = r
//                                best[newmask] = intArrayOf(sub,l,r)
                            }
                        }
                    }
                }
            }
        }
        val x = 0
        val ret = mutableListOf<Pair<Int,Int>>()

        fun addPath(start:Int,end:Int,mask:Int){
//            just dei "$start $end $mask"
            val root = start
            var end = end
            var masknow = mask
            while(masknow != 0){
                if(root == end && (mask == (1 shl end))) break
                val last = DP[root][end][masknow]
                ret.add(Pair(last,end))
                masknow = masknow xor ( 1 shl end)
                end = last
            }
        }
        fun addCycle(mask:Int){
            val pos = (0 until n).first{mask.hasElement(it)}
            addPath(pos,pos,mask)
        }
        fun resolve(mask:Int){
            if(best[mask][0] == -2){
                addCycle(mask)
            }else{
                val BS = best[mask]
                val (L,l,r) = BS
                val other = (mask xor L) or ( 1 shl r)
                addPath(l,r,other)
                resolve(L)
            }
        }
        resolve((1 shl n)- 1)
        put(ret.size)
        for(a in ret){
            put("${a.first + 1} ${a.second + 1}")
        }

    }
    done()
}
const val singleCase = true
/*
 bad mistake: strategy cannot get all cycles correctly
 but only needs is there a cycle
 which is 2CC

 Logic mistakes:
    2CC cannot get all cycles
    Constructive and inductive arguments is better than reading papers

 2CC is not enought, need a full DP for cycles
 range iteration actually satisfy submask condition

 simple induction and constructive arguments, it is not hard
 no need for papers

 because needs to consider paths, so transition to paths
 Mistakes
 1. special start and end, have to differentite them
 2. flipped binary condition ( costs <= 2 rejects rather than rejects cost > 2)
 3. nonsense skip conditino( because new is defined to be the current area, not the old area, so shoul skip old area instead)
4. is not comfortable with iterating over top down DP
5. recovering a cycle needs more info
6. mistakes old and new versios (mask, static input and newmask, modifiers)
7. legacy spehatti ( path handling != cycle hangling)
8. very high inconsistency ( cycle handling != path handling!)

TLE, but close
1. Just take a simple symmetric constant time optimisations

5 6
1 3
2 3
1 2
3 5
3 4
4 5

8 9
1 2
2 3
3 4
4 5
5 6
6 7
7 1
4 8
8 7

128 64 8
 */