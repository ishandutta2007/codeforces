import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
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
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
	return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
	return LongArray(n){getlong}
}

class Graph(val n:Int){
	val adj = Array(n){ mutableListOf<Int>() }
	fun add(a:Int, b:Int){
		adj[a].add(b)
		adj[b].add(a)
	}
	val parents = IntArray(n){-1}
	val depths = IntArray(n){0}
	fun dfsparents(v:Int, p:Int){
		for(c in adj[v]){
			if(c == p) continue
			parents[c] = v
			depths[c] = depths[v] + 1
			dfsparents(c,v)
			
		}
	}

	val costs = LongArray(n){1000000000L}
	fun dfsCosts(v:Int, p:Int){
		var c1 = 0L
		for(c in adj[v]) {
			if(c == p) continue
			dfsCosts(c,v)
			c1 += costs[c]
		}
		if(c1 == 0L) c1 = 100000000L
		costs[v] = minOf(costs[v], c1)
	}
}
fun main(){
	repeat(getint){
		val n = getint
		val k = getint
		val friends = getline(k)
		val G = Graph(n)
		repeat(n-1){
			val a = getint - 1
			val b = getint - 1
			G.add(a,b)
		}
		G.parents[0]=  0
		G.dfsparents(0,-1)
		val parents = G.parents


		val things = Array(30){IntArray(n)}
		for(i in 0 until 30){
			for(c in 0 until n){
				if(i == 0) {
					things[i][c] = parents[c]
				}else{
					things[i][c] = things[i-1][things[i-1][c]]
				}
			}
		}

		fun calparents(v:Int, e:Int):Int {
			var now = v
			for(v in 20 downTo 0){
				if(e and ( 1 shl v) != 0){
					now = things[v][now]
				}
			}
			return now
		}
		for(f in friends){
			var f = f- 1
			val block = calparents(f,G.depths[f] /2 )
			G.costs[block] = 1L
		}
		G.dfsCosts(0,-1)
		val ans = G.costs[0]
		if(ans > n){
			put(-1)
		}else{
			put(ans)
		}







	}
	done()
}