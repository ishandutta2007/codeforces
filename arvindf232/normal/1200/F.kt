
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






// convert all to 0 based

const val needInverse = false

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
        repeat(m){
            val x = getint()
            val y = getint()
            add(x,y)
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
    inline fun DFS_long2_Exhaust( dfsOrder: (Int) -> Unit, long: (Int, Int) -> Unit){
        val done = BooleanArray(n)
        var pointer = 0
        val stack = IntArray(n+1)
        for(i in 0 until n){
            if(done[i]) continue
            stack[0] = i
            pointer = 0
            while(pointer >= 0){
                val now = stack[pointer]
                if(done[now]){
                    dfsOrder(now)
                    pointer--
                }else{
                    done[now] = true
                    NS(now){
                        if(!done[it]){
                            pointer++
                            stack[pointer] = it
                            long(now,it)
                        }
                    }
                }
            }
        }
    }
    inline fun DFS_exhaust_withOrder(dfsOrder: (Int,comp:Int) -> Unit,order:IntArray){

    }

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
    inline fun DFS_Long_Exhaust(dfsOrder:(Int)->Unit,long:(Int,Int)->Unit){
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
                        long(x,a)
                        toDo[pointer] = a
                    }
                }
            }
        }
    }
    fun topologicalSort(): List<Int> {
        val ret = mutableListOf<Int>()
        DFS_Long_Exhaust({ret.add(it)}){a,b ->}
        return ret
    }
    fun DFSrecur(){
        fun go(i:Int,from:Int){
            NS(i){v ->
                if(v != from){
                    go(v,i)
                }
            }
        }
        go(1,0)
    }
    fun strongComponents():List<List<Int>>{
        var ccount = 0
        val exitOrder = IntArray(n)
        var pointer = n-1
        DFS_long2_Exhaust({ exitOrder[pointer] = it; pointer-- }) { a, b -> }

        val reverse = List(n){ mutableListOf<Int>()}

        everyEdge { a, b -> reverse[b].add(a)}


        val ret = mutableListOf<List<Int>>()
        var comp = mutableListOf<Int>()
        val used = BooleanArray(n)
        fun dfs2(v:Int){
            used[v] = true
            comp.add(v)
            for(c in reverse[v]){
                if(!used[c]) dfs2(c)
            }
        }
        TIME {
            for(v in exitOrder) {
                if(!used[v]) {
                    dfs2(v)
                    ret.add(comp)
                    comp = mutableListOf()
                    ccount++
                }
            }
        }
        return ret
    }
}

class functional(val next:IntArray){
    val n = next.size

    val quick = mutableListOf<IntArray>()
    fun calculateQuick(order:Int){
        quick.add(next)
        repeat(order){
            val last = quick.last()
            val new = IntArray(n)
            for(i in 0 until n) {
                new[i] = last[last[i]]
            }
            quick.add(new)
        }
    }
    fun getCycleRoots():List<Int>{
        val found = IntArray(n){-1}
        val roots = mutableListOf<Int>()
        tailrec fun search(a:Int,ID:Int){
            if(found[a] == ID){
                roots.add(a)
            }
            if(found[a] != -1) return
            found[a] = ID
            search(next[a],ID)
        }
        for(i in 0 until n){
            if(found[i] == -1){
                search(i,i)
            }
        }
        return roots
    }
    inline fun actOnCycle(root:Int,act:(Int)->Unit){
        var here = next[root]
        while(true){
            act(here)
            if(here == root){
                break
            }
            here = next[here]
        }
    }

    val roots by lazy{getCycleRoots()}
    val inCycle by lazy{getincycle()}

    fun getincycle():BooleanArray{
        val ret = BooleanArray(n)
        for(r in roots) {
            actOnCycle(r) { ret[it] = true }
        }
        return ret
    }
    fun getfirstCycle():IntArray{
        val firstCycles = IntArray(n){-1}
        val inCycle = inCycle
        for(i in 0 until n){
            if(inCycle[i]){
                firstCycles[i] = i
            }
        }
        tailrec fun findChain(a:Int):Int{
            if(firstCycles[a] != -1) return firstCycles[a]
            return findChain(next[a])
        }
        tailrec fun markChain(a:Int,v:Int){
            if(firstCycles[a] != -1) return
            firstCycles[a] = v
            markChain(next[a],v)
        }
        for(i in 0 until n){
            val v = findChain(i)
            markChain(i,v)
        }
        return firstCycles
    }
    val firstCycles by lazy{getfirstCycle()}
}

class quickSet(max:Int){
    val here = BooleanArray(max)
    val all = IntArray(max)
    var pointer = -1
    var size = 0
    fun add(a:Int){
        if(!here[a]){
            pointer ++
            all[pointer] = a
            here[a] = true
            size ++
        }
    }
    fun remove(a:Int){
        if(here[a]){
            here[a] = false
            size--
        }
    }
    fun clear(){
        for(i in 0..pointer){
            here[all[i]] = false
        }
        pointer = -1
        size = 0
    }
}


const val withBruteForce = false
const val randCount = 100
const val X = 2520
fun Int.adjust():Int {
    if(this < 0) return this + X
    return this
}
fun Int.normalize():Int{
    return (this % X).adjust()
}
fun main(){
//    val T = functional(intArrayOf(2,2,3,4,2))
//    T.actOnCycle(2){
//        println(it)
//    }

    solve.rand{
        share(5)
        share(List(5){ Random.nextInt(0,10)})
        repeat(5){
            share(3)
            share(List(3){Random.nextInt(1,6)})
        }
        share(1)
        repeat(1){
            share(Random.nextInt(1,6))
            share(Random.nextInt(0,10))
        }
    }
    solve.tc(1){
        share(1000)
        share(List(1000){-99999999})
        repeat(1000){
            share(10)
            repeat(10){
                share(Random.nextInt(1,1001))
            }
        }
        share(1)
        share(1)
        share(0)
    }
    solve.tc {
        share(
        """ 3
            0 0 0
            1
            2
            1
            3
            1
            1
            3
            1 0
            2 0
            3 0
        """.trimIndent())
    }
    solve.tc(2){
        share("""
            4
            0 0 0 0
            2
            2 3
            1
            2
            3
            2 4 1
            4
            3 1 2 1
            6
            1 0
            2 0
            3 -1
            4 -2
            1 1
            1 5
        """.trimIndent())
    }
//    solve.usetc(2)
    solve.cases{
        val n = getint()
        val L = getline(n).map{it.normalize()}
        val go = List(n){getline(getint()).map{it - 1 }}
        val M = go.map{it.size}
//        val G = Graph(n * X,true)
        val jump = IntArray(n * X)
        for(i in 0 until n) {
            for(j in 0 until X) {
                val next = ((j + L[i]) % X)
                val land = go[i][next % M[i]]
                val first = i * X + j
                val second = land * X + next
//                G.add(first, second)
                jump[first] = second
            }
        }
//        val finalAns = IntArray(n){-1}

        val N = n * X
        val ans = IntArray(N)

        val F = functional(jump)
        val roots = F.getCycleRoots()
        val qs = quickSet(n)
        for(r in roots){
            F.actOnCycle(r){
                qs.add(it/X)
            }
            val final = qs.size
            F.actOnCycle(r){
                ans[it] = final
            }
            qs.clear()
        }
//        F.calculateQuick(25)


//        val cycling = BooleanArray(N)
//        val found = IntArray(N){-1}
//        val ans = IntArray(N){-1}
//        tailrec fun markCycle(a:Int,start:Int){
//            cycling[a] = true
//            if(a == start) return
//            markCycle(jump[a],start)
//        }
//        tailrec fun search(a:Int,searchID:Int){
//            if(found[a] == searchID) {
//                markCycle(jump[a], a)
//                return
//            }
//            if(found[a] != -1) return
//            found[a] = searchID
//            search(jump[a],searchID)
//        }
//        tailrec fun searchendPoint(a:Int,start:Int,stack:BooleanArray){
//            if(a == start) return
//            stack[a / X] = true
//            searchendPoint(jump[a],start,stack)
//        }
//        tailrec fun cycleSet(a:Int,start:Int,va:Int){
//            if(a == start) return
//            ans[a] = va
//            cycleSet(jump[a],start,va)
//        }
//        for(i in 0 until N){
//            if(found[i] == -1 ){
//                search(i,i)
//                println("searching $i")
//            }
//        }
//        for(i in 0 until N){
//            if(!cycling[i]){
//                continue
//            }
//            if(ans[i] == -1){
//                val ab = BooleanArray(n)
//                searchendPoint(jump[i],i, ab)
//                cycleSet(jump[i],i,ab.count{it})
//            }
//
//        }

//        var start = 3 * X + (X -2)
//        repeat(100){
//            it dei start
//            start = jump[start]
//
//        }
//        var st:List<List<Int>> = listOf()
//        st = G.strongComponents()
//
////        val ans = IntArray(n * X )
//        for(c in st) {
//            if(c.size == 1) {
//                continue
//            }
//            val found = BooleanArray(n)
//            for(a in c) {
//                found[a / X] = true
//            }
//            val total = found.count { it }
//            for(a in c) {
//                ans[a] = total
//            }
//        }


//        val quickJumps = mutableListOf<IntArray>(jump)
//        repeat(25) {
//            val new = IntArray(n * X)
//            val last = quickJumps.last()
//            for(i in 0 until (n * X)) {
//                new[i] = last[last[i]]
//            }
//            quickJumps.add(new)
//        }

        val q = getint()
        val allans = mutableListOf<Int>()
        val allbrute = mutableListOf<Int>()
        repeat(q){
            val x = getint() - 1
            var v  = getint()
            v %= X
            if(v < 0) v += X

            val node = x * X + v
            val result = F.firstCycles[node]
            val final = ans[result]
            brute {
                var here = node
                val store = mutableListOf<Int>()
                val done = BooleanArray(n)
                repeat(1000){
                    here = jump[here ]
                }
                repeat(1000){
                    here = jump[here]
                    store.add(here)
                    done[here / X] = true
                }
                val a2 = done.count { it }
                allbrute.add(a2)
                put("brute $a2")
                if(a2 != final){
                    crash()
                }
            }
            put(final)
//            allans.add(final)
        }
//        answer(allans.joinToString(" "))
//        bruteAnswer(allbrute.joinToString(" "))

    }

    done()
}

/*
mistake 1 : forgetting shift by 1
     1 +: get the - 1 on the right place
     Minor 2 : forget the formul: confused / and %
     Minor 3: array bounds incorrect
     Minor 4 : forget to adjust the input ( forgetting input can be negative)
    Major:  did not notice the importance of order ( add first, then jump, or jump then add etc)

    Minor, forgetting to share the TC

    EXTREMELY MAJOR:
        failing the quick jump

      CRTICAIL :
        graph isn't fast enough

    Bad; Recursion forgetting both cases

    VERY BAD:
        handling cycles jumping

     STRATEGIC:
        any new data strcture should be DISTILLed and TESTED
 */