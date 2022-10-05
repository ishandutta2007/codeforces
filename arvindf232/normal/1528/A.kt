/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 *
 *
 * can assume lower or upper limit
 * lower when what
 */
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import kotlin.math.absoluteValue
import kotlin.math.min
import kotlin.math.max
import kotlin.reflect.KProperty0
import kotlin.system.measureTimeMillis
import java.util.*
import kotlin.collections.ArrayDeque

inline fun TIME(f:()->Unit){
	val t = measureTimeMillis(){
		f()
	}
	println(t)
}

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


class Graph(val n:Int, val directed:Boolean){
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
		val root = 1
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
	val basic_setup = if(basic_active) n+1 else 0

	val parent = IntArray(basic_setup)
	val depth = IntArray(basic_setup)
	val subs = List(basic_setup){mutableListOf<Int>()}
	fun setup(){
		DFS_long(1,{ }){
				from,to ->
			parent[to] = from
			depth[to] = depth[from] + 1
			subs[from].add(to)
		}
	}

	inline fun DFS(dfsOrder:(Int)->Unit){
		DFS_long(1,dfsOrder,{_,_->})
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
		sizesCentroid = IntArray(n+1)
		centroidLevel = IntArray(n+1)
		centroidParent = IntArray(n+1)
		centroidStep(1,0)
	}
}




fun main() {
	cases{
		val n = getint()
		val G = Graph(n,false)
		val things = mutableListOf<Pair<Int,Int>>()
		repeat(n){
			things.add(Pair(getint(),getint()))
		}
		repeat(n-1){
			G.add(getint(),getint())
		}
		G.setup()
		val parity = BooleanArray(n+1)
		for(i in 1..n){
			parity[i] = G.depth[i] % 2 == 0
		}
		val lowerRet = LongArray(n+1)
		val upperRet = LongArray(n+1)


		fun test(v:Int, here:Int):Long{
			var ret = 0L
			for(s in G.subs[v]){
				val o1 = (here - things[s-1].first).absoluteValue + lowerRet[s]
				val o2 = (here - things[s-1].second).absoluteValue + upperRet[s]
				ret += maxOf(o1,o2)
			}
			return ret
		}


		G.DFS { v ->
			val lower = things[v-1].first
			val upper = things[v-1].second

			lowerRet[v] = test(v,lower)
			upperRet[v] = test(v,upper)
		}
		put(maxOf(lowerRet[1],upperRet[1]))


	}
	done()
    // Write your solution here
}

/*
 		val ret1 = IntArray(n+1)
		val ret2 = IntArray(n+1)

		for(i in 1..n){
			val a1 = things[i-1].first
			val a2 = things[i-1].second
			if(parity[i]){
				ret1[i] = a1
				ret2[i] = a2
			}else{
				ret1[i] = a2
				ret2[i] = a1
			}
		}

		1 dei ret1
		2 dei ret2
		fun beautyOf(a:IntArray):Long {
			var ret = 0L
			G.everyEdge { x, y -> ret += (a[x] - a[y]).absoluteValue  }
			return ret
		}
		val ans = maxOf(beautyOf(ret1),beautyOf(ret2))
		put(ans)
 */