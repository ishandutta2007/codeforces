

import java.util.*
import java.io.BufferedInputStream
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.Math.abs

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
fun MutableList<Int>.streamint(n:Int){ repeat(n){this.add(getint())}}
fun MutableList<Long>.streamlong(n:Int){ repeat(n){this.add(getlong())}}


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

class Edge(var v1: Int, var v2: Int, var cap: Int, var flow: Int) {
	var rev: Edge? = null
}

class Dinic(var n: Int) {
	// Queue for the top level BFS.
	var q: ArrayDeque<Int>

	// Stores the graph.
	var adj: Array<MutableList<Edge>>

	// s = source, t = sink
	var s: Int
	var t: Int

	// For BFS.
	var blocked: BooleanArray
	var dist: IntArray

	// Just adds an edge and ALSO adds it going backwards.
	fun add(v1: Int, v2: Int, cap: Int, flow: Int) {
		val e = Edge(v1, v2, cap, flow)
		val rev = Edge(v2, v1, 0, 0)
		adj[v1].add(e.also { rev.rev = it })
		adj[v2].add(rev.also { e.rev = it })
	}

	// Runs other level BFS.
	fun bfs(): Boolean {

		// Set up BFS
		q.clear()
		Arrays.fill(dist, -1)
		dist[t] = 0
		q.add(t)

		// Go backwards from sink looking for source.
		// We just care to mark distances left to the sink.
		while (!q.isEmpty()) {
			val node = q.poll()
			if (node == s) return true
			for (e in adj[node]) {
				if (e.rev!!.cap > e.rev!!.flow && dist[e.v2] == -1) {
					dist[e.v2] = dist[node] + 1
					q.add(e.v2)
				}
			}
		}

		// Augmenting paths exist iff we made it back to the source.
		return dist[s] != -1
	}

	// Runs inner DFS in Dinic's, from node pos with a flow of min.
	fun dfs(pos: Int, min: Int): Int {

		// Made it to the sink, we're good, return this as our max flow for the augmenting path.
		if (pos == t) return min
		var flow = 0

		// Try each edge from here.
		for (e in adj[pos]) {
			var cur = 0

			// If our destination isn't blocked and it's 1 closer to the sink and there's flow, we
			// can go this way.
			if (!blocked[e.v2] && dist[e.v2] == dist[pos] - 1 && e.cap - e.flow > 0) {

				// Recursively run dfs from here - limiting flow based on current and what's left on this edge.
				cur = dfs(e.v2, Math.min(min - flow, e.cap - e.flow))

				// Add the flow through this edge and subtract it from the reverse flow.
				e.flow += cur
				e.rev!!.flow = -e.flow

				// Add to the total flow.
				flow += cur
			}

			// No more can go through, we're good.
			if (flow == min) return flow
		}

		// mark if this node is now blocked.
		blocked[pos] = flow != min

		// This is the flow
		return flow
	}

	fun flow(): Int {
		clear()
		var ret = 0

		// Run a top level BFS.
		while (bfs()) {

			// Reset this.
			Arrays.fill(blocked, false)

			// Run multiple DFS's until there is no flow left to push through.
			ret += dfs(s, oo)
		}
		return ret
	}

	// Just resets flow through all edges to be 0.
	fun clear() {
		for (edges in adj) for (e in edges) e.flow = 0
	}

	companion object {
		const val oo = 1E9.toInt()
	}

	// Constructor.
	init {

		// s is the source, t is the sink, add these as last two nodes.
		s = n++
		t = n++

		// Everything else is empty.
		blocked = BooleanArray(n)
		dist = IntArray(n)
		q = ArrayDeque()
		adj= Array(n) { mutableListOf<Edge>() }
	}
}


fun quickask(n:Int,m:Int):Long{
	val x = minOf(n,m)
	val y = maxOf(n,m)
	var sub = 0
	if( x == 1){
		sub = listOf(0,1,2,3,2,1)[y % 6]
	}else if(x == 2){
		if(y == 2){
			sub = 4
		}else if(y==3 || y == 7){
			sub = 2
		}
	}else{
		if(y % 2 == 1 && x % 2 == 1){
			sub = 1
		}else{
			sub = 0
		}
	}
	return n.toLong() * m.toLong() - sub
}



fun main() {
	val n = getint()
	val m = getint()
	put(quickask(n,m))
	done()
//	for(i in 1..30){
//		for(j in 1..30){
//			val ans = ask(i,j)
//			val ans2 = quickask(i,j)
//			assert(ans == ans2){
//				"$i $j : $ans $ans2"
//			}
//			print(i * j  - ask(i,j))
//			print(" ")
//		}
//		println()
//	}


	// Write your solution here
}

private fun ask(n:Int, m:Int):Int{
	val counts = n * m
	val s = n * m
	val t = n * m + 1

	fun encode(a:Int, b:Int):Int? {
		if((0 until n).contains(a) && (0 until m).contains(b)) {
			return a * m + b
		} else {
			return null
		}
	}

	val G = Dinic(counts)
	val adjacent = mutableListOf<Pair<Int, Int>>()
	for(x in -3..3) {
		for(y in -3..3) {
			if(abs(x) + abs(y) == 3) {
				adjacent.add(Pair(x, y))
			}
		}
	}
	for(a in 0 until n) {
		for(b in 0 until m) {
			val parity = (a + b) % 2 == 0
			val en = encode(a, b)!!

			if(parity) {
				G.add(s, en, 1, 0)
			} else {
				G.add(en, t, 1, 0)
			}
			if(parity) {
				for((dx, dy) in adjacent) {
					val new = encode(a + dx, b + dy)
					if(new != null) {
						G.add(en, new, 1, 0)
					}
				}
			}
		}
	}
	val ans = G.flow() * 2
	return ans
}