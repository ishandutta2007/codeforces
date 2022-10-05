/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

 simple case : shared : just simple

 Simplec case : x = 0 :
 	just take simple DP

 - but yes it is fixed

 How many "nontrivial moves"

 almost DP able
 - upto some recursion
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
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
		get() {
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
fun put(aa:Any){ reading.pw.println(aa)}
fun done(){ reading.pw.close() }

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}
inline fun cases(ask:()->Unit){ val t = getint();repeat(t){ ask() }}

val List<Char>.ret:String
	get() = this.joinToString("")
infix fun Any.dei(a:Any){
	//does not stand for anything it is just easy to type
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



val powersOfTwo = intArrayOf(1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144)

class edge(val from:Int,val to:Int,val price:Int):Comparable<edge>{
	override fun compareTo(other: edge): Int {
		return this.price - other.price
	}
}


class Graph(val n:Int,val directed:Boolean){
	val E = Array<MutableList<Int>>(n+1) { mutableListOf() }
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
	fun BFS(){

	}
	val parent = IntArray(n+1)
	val depth = IntArray(n+1)
	val subs = List(n+1){mutableListOf<Int>()}
	fun setup(){
		DFS_long({ }){
				from,to ->
			parent[to] = from
			depth[to] = depth[from] + 1
			subs[from].add(to)
		}
	}

	inline fun DFS(dfsOrder:(Int)->Unit){
		DFS_long(dfsOrder,{_,_->})
	}
	inline fun DFS_long(dfsOrder:(Int)->Unit,long:(Int,Int)->Unit){
		//Long: (from,to) i.e. (parent, child)
		val root = 1
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
	fun DFSrecur(){
		val root = 1
		val explored = IntArray(n+1)

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

	val quickParents = mutableListOf<IntArray>()
	fun calQuickPA(){
		var needed = 1
		var total = this.n
		while(total > 1){
			total = total shr 1
			needed += 1
		}
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

	fun connectedComponents(VS:List<Int>):List<List<Int>>{
		val haveNotDone = mutableSetOf<Int>()
		haveNotDone.addAll(VS)
		val ret = mutableListOf<List<Int>>()

		val explored = IntArray(n+1)
//		val from = IntArray(n+1)
		while(haveNotDone.any()){
			var component = mutableListOf<Int>()
			val root = haveNotDone.first()
			val toDo = ArrayDeque<Int>()
			toDo.add(root)
			explored[root] = 1

			while(toDo.size > 0){
				val x = toDo.removeLast()
				NS(x){a ->
					if(explored[a] == 0){
						explored[a] = 1
						component.add(a)
						toDo.addLast(a)
					}
				}
			}
			ret.add(component)

		}
		return ret
	}

	val edgeSets = mutableListOf<edge>()
	fun addEdgeWithPrice(a:Int,b:Int,price:Int){
		val e = edge(a,b,price)
		edgeSets.add(e)
	}

	val sizeLimits = IntArray(n+1)

}

fun sampleTree(n:Int):Graph{
	val G = Graph(n,false)
	for(i in 2..n){
		G.add(i/2,i)
	}
	return G
}
fun main() {
	val n = getint()
	val m = getint()
//	val G = Graph(n*m,false)

	val r = getint() -1
	val c = getint() -1


	val x = getint()
	val y = getint()
	val wall = mutableListOf<BooleanArray>()
	fun encode(a:Int,b:Int):Int{
		return a * m + b
	}
	fun decode(c:Int):Pair<Int,Int> {
		return Pair(c/m,c%m)
	}

	repeat(n){
		val str = getstr()
		wall.add(str.map { it == '*' }.toBooleanArray())
	}
	val walls = BooleanArray(n*m)
	for(i in 0 until n){
		for(j in 0 until m){
			walls[encode(i,j)] = wall[i][j]
		}
	}

//	for(i in 0 until n){
//		for(j in 0 until m){
//			if(i != n-1) {
//				if(!wall[i][j] && !wall[i+1][j]){
//					G.add(encode(i, j), encode(i + 1, j))
//				}
//
//			}
//			if(j != m-1){
//				if(!wall[i][j+1] && !wall[i][j+1]){
//					G.add(encode(i, j), encode(i , j+1))
//				}
//			}
//		}
//	}
	val leftEnd = c - x
	val rightEnd = c + y
	val sizeLimit = IntArray(m){
		if(it < leftEnd || it > rightEnd){
			-1
		}else{
			minOf((it-leftEnd)+x,(rightEnd - it)+y)
		}
	}
//	for(i in 0 until n){
//		for(j in 0 until m){
//			G.sizeLimits[encode(i,j)] = sizeLimit[j]
//		}
//	}
//	just dei sizeLimit
	val N = n*m
	val root = encode(r,c)
	val toDo = ArrayDeque<Int>()
	val explored = IntArray(N+1)
	val distances = IntArray(N+1)
	toDo.add(root)
	explored[root] = 1
	distances[root] = 0
	var ret = 1
	fun test(from:Int,to:Int,d:Int){

		if(explored[to] == 1 || walls[to]){
			return
		}
		val newDis = distances[from] + d
		distances[to] = minOf(distances[to],to)
		if(newDis <= sizeLimit[to % m]){
			ret += 1
			explored[to] = 1
			distances[to] = newDis
			if(d == 0){
				toDo.addFirst(to)
			}else{
				toDo.addLast(to)
			}
//			val (a,b) = decode(to)
//			println("Found $a $b")
		}
	}

	while(toDo.size > 0){
		val x = toDo.remove()
		val up = x/m
		val right = x % m
		if(up != 0){
			test(x, x-m,0)
		}
		if(up != n-1){
			test(x,x+m,0)
		}
		if(right != 0){
			test(x, x-1,1)
		}
		if(right != m-1){
			test(x,x+1,1)
		}
	}
	put(ret)
	done()
    // Write your solution here
}