/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
no palindrome


if two sides are equal, just loop it
if 3 cycle, just loop it

 */
import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
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
        while (c >= '0' && c <= '9') {
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
        while (c >= '0' && c <= '9') {
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
}
class reading{
    companion object{
        var jin = FastScanner()
        var pw = PrintWriter(System.out)
    }
}
fun put(aa:Any){
    reading.pw.println(aa)
}
fun done(){
    reading.pw.close()
}

fun getInt():Int{ return reading.jin.nextInt() }
fun getLong():Long{ return reading.jin.nextLong() }
fun getLine(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getLineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getString():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
    val t = getInt()
    repeat(t){
        ask()
    }
}


val powersOfTwo = intArrayOf(1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144)

class Graph(val n:Int,val directed:Boolean){
    val E = Array<MutableList<Int>>(n+1) { mutableListOf() }

    fun streamEdges(m:Int){
        repeat(m){
            val x = getInt()
            val y = getInt()
            E[x].add(y)
            if(!directed){
                E[y].add(x)
            }
        }
    }
    fun BFS(){
        val root = 1
        val toDo: Queue<Int> = LinkedList<Int>()
        val explored = IntArray(n+1)
        toDo.add(root)
        explored[root] = 1

        while(toDo.size > 0){
            val x = toDo.remove()
            val things = E[x]
            for( a in things){
                if(explored[a] == 0){
                    explored[a] = 1
                    toDo.add(a)
                }
            }
        }
    }
    fun DFS(){
        val root = 1
        val toDo = ArrayDeque<Int>()
        val explored = IntArray(n+1)
        toDo.add(root)
        explored[root] = 1

        while(toDo.size > 0){
            val x = toDo.removeLast()
            val things = E[x]
            for( a in things){
                if(explored[a] == 0){
                    explored[a] = 1
                    toDo.addLast(a)
                }
            }
        }
    }

    val parents = IntArray(n+1)
    val depth = IntArray(n+1)
    val DFSorder = IntArray(n+1)
    var DFSPointer = 1
    val treeSize = IntArray(n+1)
    fun DFSTransversalDiTree(){
        fun go(i:Int,from:Int,d:Int):Int{
            depth[i] = d
            DFSorder[DFSPointer] = i
            DFSPointer += 1

            var size:Int = 1
            for(v in E[i]){
                if(v != from){
                    size += go(v,i,d+1)
                    parents[v] = i
                }
            }
//            f(i)
            treeSize[i] = size
            return size
        }
        DFSPointer = 1
        go(1,0,0)
        parents[1] = 1
    }

    val quickParents = mutableListOf<IntArray>()
    fun calQuickPA(){
        var needed = 1
        var total = this.n
        while(total > 1){
            total = total shr 1
            needed += 1
        }
        quickParents.add(parents)
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

        for( (i,p) in powersOfTwo.withIndex()){
            if(p > layer){
                break
            }
            if(p and layer > 0){
                now = quickParents[i][now]
                layer -= p
            }
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

}

fun main() {
    cases case@{
        val n = getInt()
        val m = getInt()
        val vG = List(n){IntArray(n)}
        val G = Graph(n,true)

        fun loopAnswer(a:Int,b:Int){
            repeat(m){
                put("YES")
                put(if(it % 2 == 0) a else b)
            }

        }
        val inDegs = IntArray(n)

        repeat(n){
            val y = it
            for((x,c) in getString().withIndex()){
                val value = if(c == 'a') 1 else -1
                if(y < x){
                    vG[y][x] = value
                    if(value == 1){
                        G.E[x].add(y)
                        inDegs[y] += 1
                    }else{
                        G.E[y].add(x)
                        inDegs[x] += 1
                    }
                }else if(y > x){
                    if(vG[x][y] == value){
                        val a = x+1
                        val b = y+1
                        put("YES")
                        repeat(m+1){

                            put(if(it % 2 == 0) a else b)
                        }
                        return@case
                    }
                }
            }
        }
        if(m % 2 == 1){
            val a = 1
            val b = 2
            put("YES")
            repeat(m+1){

                put(if(it % 2 == 0) a else b)
            }
            return@case
        }
        if(n==2){
            if(m > 1){
                put("NO")
                return@case
            }else{
                put("YES")
                put(1)
                put(2)
                return@case
            }
        }
        fun allOut(a:Int,b:Int,c:Int){
            val k = m/ 2
            val x = a + 1
            val y = b + 1
            val z = c + 1

            repeat(k+1){
                put(if( (k-it) % 2 == 1) x else y )
            }
            repeat(k){
                put(if(it% 2 == 0) z else x)
            }
        }
        for(a in 0 until n){
            if(G.E[a].size == 0){
                var b = 0
                var c = 0
                if(a == 0){
                    b = 1
                    c = 2
                }else if(a ==1){
                    b = 0
                    c = 2
                }else{
                    b = 0
                    c = 1
                }
                put("YES")
                if(G.E[b].contains(c)){
                    allOut(b,c,a)
                }else{
                    allOut(c,b,a)
                }
                return@case
            }
        }
        var current = 0
        put("YES")
        repeat(m+1){
            put(current+1)
            current = G.E[current].first()
        }
        return@case
//
//        val stack = LinkedList<Int>()
//
//        for(i in 0 until n){
//            if(inDegs[i] == 0){
//                stack.add(i)
//            }
//        }
//        var current = 0
//        val ret = mutableListOf<Int>()
//
//
//        while(stack.isNotEmpty()){
//            val a = stack.remove()
//            val Ns = G.E[a]
//            ret.add(a)
//            current += 1
////            result[a] = current
//            for(n in Ns){
//                inDegs[n] -= 1
//                if(inDegs[n] == 0){
//                    stack.add(n)
//                }
//            }
//        }
//        if(current < n){
//            val have = IntArray(n+1)
//            have[n] = 1
//            val subset = mutableListOf<Int>()
//            var some = 0
//            for(a in ret){
//                have[a] = 1
//            }
//            for(i in 0 until n){
//                if(have[i] == 0){
//                    subset.add(i)
//                    some = i
//                }
//            }
//
//            val G2 = Graph(n,true)
//            for((n,out) in G.E.withIndex()){
//                if(have[n] == 1){
//                    continue
//                }
//                for(o in out){
//                    if(have[o] == 1){
//                        continue
//                    }
//                    G2.E[o].add(n)
//                }
//            }
//            var current = some
//            put("YES")
//            repeat(m+1){
//                put(current+1)
//                current = G2.E[current].first()
//            }
//            return@case
//        }
////        if(m + 1 <= n){
////            put("YES")
////            repeat(m+1){
////                put(ret[it]+1)
////            }
////        }else{
////            val k = m/ 2
////            if( n == 2){
////                put("NO")
////                return@case
////            }else{
////                val x = ret[0] + 1
////                val y = ret[1] + 1
////                val z = ret[2] + 1
////
////                repeat(k+1){
////                    put(if( (k-it) % 2 == 1) x else y )
////                }
////                repeat(k){
////                    put(if(it% 2 == 0) z else x)
////                }
////            }
////        }
////        for((i,a) in sorting.withIndex()){
////            for(j in (i+1 )..sorting.lastIndex){
////                val b = sorting[b]
////                if
////            }
////        }

        /*
        1
        3 6
        *aa
        b*a
        bb*

         */
        val g = 0

    }
    done()
    // Write your solution here
}