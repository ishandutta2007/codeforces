import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
import kotlin.math.abs
import java.util.*

class DisjointUnionSets(n:Int) {
	var rank:IntArray
	var parent:IntArray
	var n:Int

	fun makeSet() {
		for(i in 0 until n) {
			parent[i] = i
		}
	}

	fun find(x:Int):Int {
		if(parent[x] != x) {
			parent[x] = find(parent[x])
		}
		return parent[x]
	}

	fun union(x:Int, y:Int) {
		val xRoot = find(x)
		val yRoot = find(y)
		if(xRoot == yRoot) return
		if(rank[xRoot] < rank[yRoot])
			parent[xRoot] = yRoot else if(rank[yRoot] < rank[xRoot])
			parent[yRoot] = xRoot else {
			parent[yRoot] = xRoot
			rank[xRoot] = rank[xRoot] + 1
		}
	}

	init {
		rank = IntArray(n)
		parent = IntArray(n)
		this.n = n
		makeSet()
	}
}

class FastScanner {
	private val BS = 1 shl 16
	private val NC = 0.toChar()
	private val buf = ByteArray(BS)
	private var bId = 0
	private var size = 0
	private var c = NC
	private var `in`:BufferedInputStream? = null

	constructor() {
		`in` = BufferedInputStream(System.`in`, BS)
	}

	private val char:Char
		private get() {
			while(bId == size) {
				size = try {
					`in`!!.read(buf)
				} catch(e:Exception) {
					return NC
				}
				if(size == -1) return NC
				bId = 0
			}
			return buf[bId++].toChar()
		}

	fun nextInt():Int {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextLong():Long {
		var neg = false
		if(c == NC) c = char
		while(c < '0' || c > '9') {
			if(c == '-') neg = true
			c = char
		}
		var res = 0L
		while(c >= '0' && c <= '9') {
			res = (res shl 3) + (res shl 1) + (c - '0')
			c = char
		}
		return if(neg) -res else res
	}

	fun nextString():String {
		if(c == NC) c = char
		val ret = StringBuilder()
		while(true) {
			c = char
			if(!isWhitespace(c)) {
				break
			}
		}
		ret.appendCodePoint(c.toInt())
		while(true) {
			c = char
			if(isWhitespace(c)) {
				break
			}
			ret.appendCodePoint(c.toInt());
		}
		return ret.toString()
	}

	fun isWhitespace(c:Char):Boolean {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t'
	}
}

class reading {
	companion object {
		var jin = FastScanner()
		var pw = PrintWriter(System.out)
	}
}

fun put(aa:Any) {
	reading.pw.println(aa)
}

fun done() {
	reading.pw.close()
}

fun getint():Int {
	return reading.jin.nextInt()
}

fun getlong():Long {
	return reading.jin.nextLong()
}

fun getline(n:Int):List<Int> {
	return (1..n).map { reading.jin.nextInt() }
}

fun getlineL(n:Int):List<Long> {
	return (1..n).map { reading.jin.nextLong() }
}

fun getstr():String {
	return reading.jin.nextString()
}

inline fun cases(ask:() -> Unit) {
	val t = getint()
	repeat(t) {
		ask()
	}
}

fun just(a:Boolean) {
	put(if(a) "YES" else "NO")
}

fun List<Int>.out() {
	put(this.joinToString(" "))
}

val List<Char>.ret:String
	get() = this.joinToString("")

infix fun Long.divCeil(b:Long):Long{
	//Positives numbers only!
	if(this == 0L) {
		return 0
	}
	return (this-1)/b + 1
}
fun prefixSumL(arr:List<Long>):MutableList<Long>{
	val ret = mutableListOf<Long>()

	var previous = 0L
	for(a in arr){
		previous += a
		ret.add(previous)
	}
	return ret
}


val powersOfTwo = intArrayOf(1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144)

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
		val root = 1
		val toDo: Queue<Int> = LinkedList<Int>()
		val explored = IntArray(n+1)
		toDo.add(root)
		explored[root] = 1

		while(toDo.size > 0){
			val x = toDo.remove()
			NS(x){ a->
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
			NS(x){ a->
				if(explored[a] == 0){
					explored[a] = 1
					toDo.addLast(a)
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
	fun DFSrecurTrvael(){
		val root = 0
		val explored = IntArray(n+1)
		fun travel(a:Int,b:Int){

		}
		fun go(i:Int,from:Int){
			NS(i){v ->
				if(v != from){
					travel(i,v)
					go(v,i)
					travel(v,i)
				}
			}
		}
		go(root,0)
	}
	//With depth: add a depth parameter in recursion, or = from + 1
	//With Sizes: Return sizes and accumulate them
	//With order: Update pointer, U
	// With Euler order: Add a update function
	//With reached: Add one in

	val parents = IntArray(n+1)
	val depth = IntArray(n+1)
	val DFSorder = IntArray(n)
	var DFSPointer = 0
	val leafOrder = IntArray(n)
	var leafPointer = 0
	val treeSize = IntArray(n+1)


	fun DFSTransversalDiTree(){
		fun go(i:Int,from:Int,d:Int):Int{
			depth[i] = d

			DFSorder[DFSPointer] = i
			DFSPointer += 1
			var size:Int = 1
			NS(i){v ->
				if(v != from){
					size += go(v,i,d+1)
					parents[v] = i
				}
			}
			leafOrder[leafPointer] = i
			leafPointer += 1

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

}
fun IntArray.maxInsert(v:Int){
	val a = this.indexOfFirst { v > it }
	if(a == -1){
		return
	}else{
		for(i in a until this.size - 1){
			this[i+1] = this[i]
		}
		this[a] = v
	}
}


fun main() {
	val n = getint()
	val t = getint()
	val k = getint()

	val arrs = getline(t)

	val G = Graph(n,true)

	arrs.dropLastWhile { it == 0 }
	if(arrs.contains(0)){
		put("-1")
		done()
		return
	}
	val maxLeaf = arrs.sum() - arrs.size + 1
//	println(maxLeaf)
	if(k > maxLeaf){
		put("-1")
		done()
		return
	}

	var usedUpto = 1
	var previousAnchor = 1
	var defLeft = maxLeaf - k
	for(i in arrs.indices){
		val d = i + 1
		val have = arrs[i]
		val currentAnchor = usedUpto + 1

//		val vertex = (usedUpto+1..usedUpto+have)

		val previous = if(i > 0){
			arrs[i-1]
		}else{
			1
		}
		val canMatch = minOf(arrs[i],previous) - 1
		val willMatch = minOf(defLeft,canMatch)
//		println("matching ${willMatch}")

		defLeft -= willMatch

		for(i in 1..have){
			if(i <= willMatch + 1){
				G.add(previousAnchor + i -1, currentAnchor + i -1 )
			}else{
				G.add(previousAnchor,currentAnchor + i -1 )
			}
		}
		previousAnchor = currentAnchor
		usedUpto += have
	}
	if(defLeft > 0){
		put("-1")
		done()
		return
	}
	put(n)
	for(i in 1..n){
		for(a in G.E[i]){
			put("$i $a")
		}
	}
	done()

}