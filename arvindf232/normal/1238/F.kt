import java.io.BufferedInputStream
import java.io.File
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
	fun takeFile(name:String){
		IN = BufferedInputStream(File(name).inputStream(),BS)
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
		val t = if(mode == solveMode.real){if(singleCase) 1 else getint()} else if(mode == solveMode.tc){1 } else randCount
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
fun Int2(a:Int,b:Int) = List(a){IntArray(b)}
fun Int3(a:Int,b:Int,c:Int) = List(a){List(b){IntArray(c)}}
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }


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
//        repeat(m){
//            val x = getint()
//            val y = getint()
//            add(x,y)
//        }
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
	inline fun DFS_exhaust_withOrder(dfsOrder: (Int, comp:Int) -> Unit, order:IntArray){

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
}



class top2 {
	var one:Int = -1000
	var two:Int = -1000
	var oneID:Int = -1
	var twoID:Int = -1

	fun add(x:Int,id:Int){
		if(x > one){
			two = one
			twoID = oneID
			one = x
			oneID = id
		}else if (x > two) {
			two = x
			twoID = id
		}
	}
	operator fun get(a:Int): Int {
		if(a == 0){
			return one
		}else if( a== 1){
			return two
		}else{
			throw Exception("Bad access")
		}
	}
	fun exclusiveMaxSum(other:top2):Int{
		if(this.oneID != other.oneID){
			return this.one + other.one
		}else{
			return maxOf(this.one + other.two, this.two + other.one)
		}
	}
}
const val singleCase = false
const val withBruteForce = false
const val randCount = 100
fun main(){
	solve.cases{
		val n = getint()
		val G = Graph(n,false)
		repeat(n-1){
			G.add(getint() - 1 ,getint() - 1)
		}
		G.setup()
		var ret = 0
		val DP = IntArray(n)
		G.DFS { v ->

			val dbonus = G.subs[v].size  - 1 + 1
			val bags = top2()
			for(w in G.subs[v]){
				bags.add(DP[w],w)
			}
			val newDP = maxOf(1,bags.one + dbonus)
			DP[v] = newDP

//			v dei newDP

			val retOption = maxOf(newDP,bags.one + bags.two + dbonus - 1 + if(v == 0) 0 else 1  )
			ret = maxOf( ret, retOption)
		}
		put(ret)
	}
	done()
}
/*
1
10
4 1
2 8
4 9
2 6
3 8
10 9
2 5
2 4
8 7
 */


/*

mistake:
	the top 2 things with exact sizes are to be handled
 */