import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
val powersOfTwo = intArrayOf(1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144)

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

fun getint():Int{ return reading.jin.nextInt() }
fun getlong():Long{ return reading.jin.nextLong() }
fun getline(n:Int):List<Int>{ return (1..n).map{reading.jin.nextInt()} }
fun getlineL(n:Int):List<Long>{return (1..n).map{reading.jin.nextLong()} }
fun getstr():String{ return reading.jin.nextString() }


inline fun cases(ask:()->Unit){
	val t = getint()
	repeat(t){
		ask()
	}
}
fun just(a:Boolean){
	put(if(a)"YES" else "NO")
}
fun List<Int>.out(){ put(this.joinToString(" ")) }
val List<Char>.ret:String
	get() = this.joinToString("")

val Long.highestBitPlace:Int
	get(){
		return (0..62).last last@{
			return@last (1L shl it) <= this
		}
	}


fun cross(a:Pair<Long,Long>,b:Pair<Long,Long>):Long{
	val (x,y) = a
	val (z,w) = b
	return (x * w - z * y )
}

fun Pair<Long,Long>.clockwise():Pair<Long,Long>{
	return Pair(this.second, -this.first)
}
fun Pair<Long,Long>.antiClockwise():Pair<Long,Long>{
	return Pair(- this.second, this.first)
}

//fun Pair<Long,Long>.reduced():Pair<Long,Long>{
//	val (x,y) = this
//	val d = gcd(x,y)
//	return Pair(x/d,y/d)
//}
fun dot(a:Pair<Long,Long>,b:Pair<Long,Long>):Long{
	val (x,y) = a
	val (z,w) = b
	return (x * z + y * w)
}
class Graph(val n:Int,val directed:Boolean){
	val E = Array<MutableList<Int>>(n+1) { mutableListOf() }

//    val invE = Array<MutableList<Int>>(n+1) { mutableListOf() }

	fun add(a:Int,b:Int){
		E[a].add(b)
//        invE[b].add(a)
		if(!directed){
			E[b].add(a)
//            invE[a].add(b)
		}
	}

	fun streamEdges(m:Int){
		repeat(m){
			val x = getint()
			val y = getint()
			add(x,y)
		}
	}
	fun BFS(){
		val root = 1
		val toDo:Queue<Int> = LinkedList<Int>()
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
//	fun travel(from:Int,to:Int){
//
//	}

	//With depth: add a depth parameter in recursion, or = from + 1
	//With Sizes: Return sizes and accumulate them
	//With order: Update pointer, U
	// With Euler order: Add a update function
	//With reached: Add one in

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
fun <T> List<List<T>>.printMatrix(){
	for(a in this){
		println(a.joinToString(" "))
	}
}

fun main(){
	val n = getint()
	val m = getint()
	val q = getint()

	val book = List(n){BooleanArray(m)}
	val booksFliped = BooleanArray(n)
	val counts = MutableList(n){0}
	var total = 0


	val history = BooleanArray(q)

	val Qs = IntArray(q)
	val qp1 = IntArray(q)
	val qp2 = IntArray(q)

	val G = Graph(q+1,true)

	repeat(q) {
		val int = getint()
		Qs[it] = int
		if(int == 1 || int == 2) {
			val s = getint() - 1
			val m = getint() - 1
			qp1[it] = s
			qp2[it] = m
		}else{
			if(int == 3){
				qp1[it] = getint() - 1
			}else{
				qp1[it] = getint()
			}

		}

		if(int != 4){
			G.add(it,it+1)
		}else{
			G.add(qp1[it],it+1)
		}
	}
	fun undoAction(q:Int){
//		println("undoing $q")
		val int = Qs[q]
		if(int == 1 || int == 2){
			val s = qp1[q]
			val m = qp2[q]
			val insert = int == 1
			val now = book[s][m] != booksFliped[s]
			val his = history[q]
			if(now != his){
				if(int == 1){
					counts[s] -= 1
					total -= 1
				}else{
					counts[s] += 1
					total += 1
				}

			}
			book[s][m] = his != booksFliped[s]
		}else if(int == 3){
			val s = qp1[q]
			booksFliped[s] = !booksFliped[s]

			val previousCount = counts[s]
			val newCounts = m - counts[s]
			counts[s] = newCounts
			total += newCounts - previousCount
		}else if(int == 4){

		}
	}

	fun executeAction(q:Int){
//		println("executing $q")
		val int = Qs[q]
		if(int == 1 || int == 2){
			val s = qp1[q]
			val m = qp2[q]
			val insert = int == 1
			val has = book[s][m] != booksFliped[s]
//			println("$q ${has}")
			history[q] = has
			if(has != insert){
				if(int == 1){
					counts[s] += 1
					total += 1
				}else{
					counts[s] -= 1
					total -= 1
				}
			}
			book[s][m] = insert != booksFliped[s]
		}else if(int == 3){
			val s = qp1[q]
			booksFliped[s] = !booksFliped[s]

			val previousCount = counts[s]
			val newCounts = m - counts[s]
			counts[s] = newCounts
			total += newCounts - previousCount
		}
	}

//	for(i in 0 until q){
//		executeAction(i)
//	}
//	for(i in q-1 downTo 0){
//		undoAction(i)
//	}
	val ret = IntArray(q+1)
	fun travel(i:Int,i2:Int){
//		println("traveled $i ${i2}")
		if(i2 > i){
			if(i2 - i == 1){
				executeAction(i)
			}
		}else{
			if(i - i2 == 1){
				undoAction(i2)
			}
		}
//		println("${i2} ${total}")
		ret[i2] = total
	}
	fun DFSrecur(){
		val root = 0
		val explored = IntArray(n+1)

		fun go(i:Int,from:Int){

			for(v in G.E[i]){
				if(v != from){
					travel(i,v)
					go(v,i)
					travel(v,i)
				}
			}
		}
		go(root,0)
	}
	DFSrecur()

	for(i in 1..q){
		put(ret[i])
	}


	done()


}