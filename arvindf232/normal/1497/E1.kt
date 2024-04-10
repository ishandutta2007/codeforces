import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.ln
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

object sieve{

    const val sieveMx = 10000000
    val primeOf = IntArray(sieveMx + 1)
    var primeCounter = 0
    val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
    val primes = IntArray(primeUpperBound)
    var sieveCalculated = false
    val nextPrime = IntArray(sieveMx+1)
    val nextPrimePower = IntArray(sieveMx+1)
    val afterPrimePowerDivison = IntArray(sieveMx+1)
    var mobius = IntArray(0)

    var factors:List<MutableList<Int>> = mutableListOf()

    fun calculateSieveFast(){
        if(sieveCalculated){
            return
        }
        sieveCalculated = true
        for(i in 2..sieveMx){
            if(primeOf[i] == 0 ){
                primeOf[i] = i
                primes[primeCounter] = i
                primeCounter += 1
            }
            for(j in 0 until primeCounter){
                val p = primes[j]
                val pd = p * i
                if(p <= i && pd <= sieveMx){
                    primeOf[pd] = p
                }else{
                    break
                }
            }
        }
    }
    fun preparePrimePower(){
        nextPrime[1] = -1
        nextPrimePower[1] = -1
        afterPrimePowerDivison[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            val new = i / p
            nextPrime[i] = p
            if(nextPrime[new] == p){
                nextPrimePower[i] = nextPrimePower[new]
                afterPrimePowerDivison[i] = afterPrimePowerDivison[new]
            }else{
                afterPrimePowerDivison[i] = new
            }
            nextPrimePower[i] += 1
        }
    }
    fun prepareFactors(){
        // 700ms in 1M
        // shoudl not be used for 1M
        // 200ms codeforces for 200k
        factors = List(sieveMx + 1){ mutableListOf()}
        factors[1].add(1)

        for(i in 2..sieveMx){
            val p = nextPrime[i]
            val a = nextPrimePower[i]
            val old = afterPrimePowerDivison[i]

            var here = 1
            repeat(a+1){
                for(c in factors[old]){
                    factors[i].add(c * here )
                }
                here *= p
            }
//            factors[1].ad
//            factors[i].addAll(i.factors())
        }
    }
    fun calculateMobius(){
        assert(sieveCalculated)
        mobius = IntArray(sieveMx + 1)
        mobius[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            if(p == primeOf[i/p]){
                mobius[i] = 0
            }else{
                mobius[i] = -1 * mobius[i/p]
            }
        }
    }
}
inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
    assert(sieve.sieveCalculated)
    var here = this
    while(here > 1){
        act(sieve.nextPrime[here], sieve.nextPrimePower[here])
        here = sieve.afterPrimePowerDivison[here]
    }
}
fun Int.factors():List<Int>{
    val ret = mutableListOf(1)
    this.eachPrimePower { p, e ->
        val s = ret.toList()
        var now = 1
        repeat(e){
            now *= p
            ret.addAll(s.map{it * now})
        }
    }
    return ret
}
fun totient(a:Int):Int{
    var ret = a
    a.eachPrimePower{
            p, _ ->
        ret /= p
        ret *= (p-1)
    }
    return ret
}
fun Int.numOfDivisors():Int{
    var ret = 1
    this.eachPrimePower { _, e -> ret *= (e+1) }
    return ret
}
fun Int.factorLook():List<Int>{
    return sieve.factors[this]
}

fun factorSingleNumber(a:Long): MutableList<Pair<Long, Int>> {
    val ret = mutableListOf<Pair<Long,Int>>()
    var now = a
    for(pi in 0 until sieve.primeCounter){
        val p = sieve.primes[pi]
        var level = 0
        while(now % p == 0L){
            now /= p
            level ++
        }
        if(level > 0){
            ret.add(Pair(p.toLong(),level ))
        }
    }
    if(now > 1){
        ret.add(Pair(now, 1))
    }
    return ret
}
fun main(){
	sieve.calculateSieveFast()
	sieve.preparePrimePower()
	fun value(a:Int):Int {
		 var ret = 1
		a.eachPrimePower{
			p, e ->
			if(e and 1 == 1){
				ret *=  p
			}
		}
		return ret
	}

	repeat(getint){
		val n = getint
		val k = getint
		val L = getline(n)
		val V = IntArray(n){value(L[it])}

		var now = mutableSetOf<Int>()
		var ret = 1
		for(i in 0 until n){
			if(now.contains(V[i])){
				now.clear()
				ret++
				now.add(V[i])
			}else{
				now.add(V[i])
			}
		}
		put(ret)




	}
	done()
}
/*
1
2 0
1 16

 */