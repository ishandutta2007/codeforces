import java.io.BufferedInputStream
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.*
import kotlin.collections.ArrayDeque
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

    private val IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf)
//                size = try {
//                    IN.read(buf)
//                } catch (e: Exception) {
//                    return NC
//                }
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
        ret.appendCodePoint(c.toInt())
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.appendCodePoint(c.toInt());

        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
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


// convert all to 0 based


class Graph(val n:Int, val directed:Boolean){
    val E = Array<MutableList<Int>>(n) { mutableListOf() }
    val indices = 0 until n
    //    val invE = Array<MutableList<Int>>(n+1) { mutableListOf() }
    // Maintaining all the in/out edges
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
    val basic_active = true
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
    //With depth: add a depth parameter in recursion, or = from + 1
    //With Sizes: Return sizes and accumulate them
    //With order: Update pointer, U
    // With Euler order: Add a update function
    //With reached: Add one in

    private val quickParents = mutableListOf<IntArray>()
    fun calQuickPA(){
        val needed = 32 - n.countLeadingZeroBits()
        quickParents.add(parent)
        for( i in 1..needed){
            val previous = quickParents.last()
            val new = IntArray(n+1)
            for(a in new.indices){
                new[a] = previous[previous[a]]
            }
            quickParents.add(new)
        }
    }
    fun calParent(i:Int,l:Int):Int{
        var now = i
        var layer = l

        repeat(layer.countOneBits()){
            val p = layer.takeHighestOneBit()
            val lookup = 31 - layer.countLeadingZeroBits()
            now = quickParents[lookup][now]
            layer -= p
        }
        return now
    }
    fun isParent(i:Int,of:Int):Boolean{
        val a = depth[i]
        val b = depth[of]
        if(a > b){
            return false
        }else{
            return calParent(of,b-a) == a
        }
    }
    fun LCA(a:Int,b:Int):Int{
        var x = a
        var y = b
        val ad = depth[a]
        val bd = depth[b]
        if(ad < bd){
            val d = bd - ad
            y = calParent(y,d)
        }else if(bd < ad){
            val d = ad - bd
            x = calParent(x,d)
        }

        for(i in quickParents.lastIndex downTo 0){
            val ta = quickParents[i][x]
            val tb = quickParents[i][y]
            if(ta != tb){
                x = ta
                y = tb
            }
        }
        return parent[x]
    }

    fun connectedComponents():List<List<Int>>{
        // always take 1..n
        val done = BooleanArray(n+1)
        var pointer = 0
        var completeCount = 0
        done[0] = true
        val ret = mutableListOf<List<Int>>()

//		val from = IntArray(n+1)
        while(true){
            if(completeCount >= n){
                break
            }
            while(done[pointer]){
                pointer += 1
            }
            val root = pointer
            val component = mutableListOf<Int>(root)
            val toDo = ArrayDeque<Int>()
            toDo.add(root)
            done[root] = true


            while(toDo.size > 0){
                val x = toDo.removeLast()
                NS(x){a ->
                    if(!done[a]){
                        done[a] = true

                        component.add(a)
                        toDo.addLast(a)
                    }
                }
            }
            completeCount += component.size
            ret.add(component)

        }
        return ret
    }

    var sizesCentroid = IntArray(0)
    var centroidLevel = IntArray(0)
    var centroidParent = IntArray(0)
    private fun sizeRecur(root:Int){
        fun go(i:Int,from:Int):Int{
            var ret:Int = 1
            NS(i){v ->
                if(v != from && centroidLevel[v] == 0){
                    ret += go(v,i)
                }
            }
            sizesCentroid[i] = ret
            return ret
        }
        go(root,-1)
    }
    private tailrec fun findCentroid(newRoot:Int,totalSize:Int,banned:Int):Int{
        var heaviestChild = -1
        var heaviestSize = -1
        var ok:Boolean = true
        NS(newRoot){
            if(sizesCentroid[it] > totalSize / 2 && it != banned && centroidLevel[it] == 0){
                ok = false
                if(sizesCentroid[it] > heaviestSize){
                    heaviestChild = it
                    heaviestSize = sizesCentroid[it]
                }
            }
        }
        if(ok){
            return newRoot
        }
        return findCentroid(heaviestChild,totalSize,newRoot)
    }
    private fun centroidStep(current:Int,parent:Int){
        sizeRecur(current)
        val newCentroid = findCentroid(current,sizesCentroid[current],-1)
        centroidLevel[newCentroid] = centroidLevel[parent] + 1
        centroidParent[newCentroid] = parent
        NS(newCentroid){
            if(centroidLevel[it] == 0){
                centroidStep(it,newCentroid)
            }
        }
    }
    fun centroidDecomposition(){
        sizesCentroid = IntArray(n)
        centroidLevel = IntArray(n)
        centroidParent = IntArray(n)
        centroidStep(0,0)
    }
}




fun main(){
    val x = 0 
    cases{
        val n = getint()
        val G = Graph(n,false)
        repeat(n-1){
            G.add(getint()-1,getint()-1)
        }
        G.setup()
//        val hasOddPath = BooleanArray(n)
//        val hasEvenpath = BooleanArray(n)
        val marked = BooleanArray(n)
        var ret = 1
        G.DFS {
            v ->
//            println(v)
            val fork = G.subs[v].count{!marked[it]}

            if(fork > 0){
                ret += fork - 1
                marked[v] = true
            }
//            if(G.subs[v].isEmpty()){
//                hasOddPath[v] = true
//            }else{
//                hasOddPath[v] = G.subs[v].any { hasEvenpath[it] }
//                hasEvenpath[v] = G.subs[v].any {hasOddPath[it]}
//            }
//            val nonbreaks = G.subs[v].count{hasOddPath[it]}
//            if(nonbreaks >= 1){
//                ret += nonbreaks - 1
////                println(nonbreaks - 1 )
//            }
//            println("$v ${nonbreaks}")
        }
        put(ret)
    }
    done()
}