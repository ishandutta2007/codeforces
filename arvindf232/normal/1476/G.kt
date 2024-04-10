// 2022.07.19 at 18:40:20 HKT
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.random.Random
import kotlin.random.nextInt

// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}
object Reader{
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
    fun rerouteInput(){
        if(warningActive){
            put("Custom test enabled")
            println("Custom test enabled")
            warningActive = false
        }
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ Reader.OUT.println(aa)}
fun done(){ Reader.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){Reader.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){Reader.fakein.append(aa.toString())}
    else{Reader.fakein.append(aa.toString())}
    Reader.fakein.append("\n")
}

val getintfast:Int get() = Reader.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
var dmark = -1
infix fun Any.dei(a:Any){
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }
        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " "
fun crash(){
    throw Exception("Bad programme")}
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Not usual primes!")
        }
        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                Reader.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                Reader.rerouteInput()
            }
            onecase()
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
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
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}


const val box = 2048
const val boxlevel = 11


class query(val l:Int, val r:Int, val ver:Int, val id:Int, val k:Int):Comparable<query>{
    override fun compareTo(other:query):Int {
        var flip = false
        val l1 = l shr boxlevel
        val l2 = other.l shr boxlevel
        if(l1 != l2){
            return l1.compareTo(l2)
        }
        if(l2 and 1 == 1){
            flip = !flip
        }

        val r1 = r shr boxlevel
        val r2 = other.r shr boxlevel
        if(r1 != r2){
            val ret = r1.compareTo(r2)
            if(flip){
                return -ret
            }else{
                return ret
            }
        }
        if(r1 and 1 == 1){
            flip = !flip
        }
        val v1 = ver shr boxlevel
        val v2 = other.ver shr boxlevel
        if(v1 != v2){

            val ans = v1.compareTo(v2)
            return if(flip) - ans else ans
        }
        return id.compareTo(other.id)
    }


}
const val cut = 300
const val cut2 = 310
const val max = 100005
fun debug(){}
const val singleCase = true
fun main(){
    solve.rand {
        val n = 8
        share(n)
        share(n)
        share(List(n){Random.nextInt(1..3)}.conca())
        repeat(n){
            val t = Random.nextInt(1..2)
            if(t == 1){
                var l = Random.nextInt(1..n)
                var r = Random.nextInt(1..n)
                if(l > r){
                    l = r .also { r = l  }
                }
                var k = Random.nextInt(1..3)
                share("$t $l $r $k")
            }else{
                val i = Random.nextInt(1..n)
                val x = Random.nextInt(1..3)
                share("$t $i $x")
            }
        }
    }
//    solve.userand()
    solve.cases{
        val n= getint
        val m = getint
        val L = getline(n)


        val occur = IntArray(max+1)
        val special = BooleanArray(max+1)
        val count = IntArray(max +1)

        val specials = TreeSet<Int>()
        fun addone(x:Int){
            val old = occur[x]
            occur[x] ++
            if(!special[x] && old + 1 >= cut2){
                count[old] --
                special[x] = true
                specials.add(x)
            }else{
                if(!special[x]){
                    count[old] --
                    count[old+1] ++
                }
            }
        }
        fun removeone(x:Int){
            val old = occur[x]
            occur[x] --
            if(special[x] && old - 1 < cut){
                special[x] = false
                specials.remove(x)
                count[old-1] ++
            }else{
                if(!special[x]){
                    count[old]--
                    count[old-1] ++
                }
            }
        }
        fun solve2(k:Int):Int {
            val st = mint
            for(i in 1..cut2){
                repeat(count[i]){
                    st.add(i)
                }
            }
            for(s in specials){
                st.add(occur[s])
            }
            st.sort()
            var best = plarge
            for(i in 0 until st.size){
                val j = i + k - 1
                if(j in 0 until st.size)
                    best = minOf(best, st[j] - st[i])
            }
            return best
        }

        fun solve(k:Int):Int{
            val extra = mint
            for((i,c) in specials.withIndex()){
                extra.add(occur[c])
            }
            for(i in cut+1..cut2){
                repeat(count[i]){
                    extra.add(i)
                }
            }
            extra.sort()
            //0..cut2 , then
            val limit = cut + 1 + extra.size
            var size = 0
            var l = 1
            var ret = plarge
            for(r in 1 until limit){
                if(r in 1..cut){
                    size += count[r]
                }else{
                    size++
                }
                while(l <= r && l < limit && (size - if(l <= cut) count[l] else 1) >= k){
                    size -= if(l <= cut) count[l] else 1
                    l++
                }
                if(size >= k){
                    val right = if(r > cut) extra[r - cut - 1 ] else r
                    val left = if(l > cut) extra[l-cut-1] else l
                    ret = minOf(ret, right - left)
                }
            }
            return ret
        }


        val opi = IntArray(max+1)
        val forwardv = IntArray(max+1)
        val backwardv= IntArray(max+1)


        var vernow = 0
        var qs = 0
        val all = mutableListOf<query>()

        repeat(m){
            val t = getint
            if(t == 1){
                val l = getint - 1
                val r = getint - 1


//                for(i in l..r){
//                    addone(L[i])
//                }
                val k = getint
                val q = query(l,r,vernow,qs,k)
                qs ++
                all.add(q)
//                put(solve(k))

//                for(i in l..r){
//                    removeone(L[i])
//                }
            }else{
                val p = getint -1
                val x = getint
                opi[vernow] = p
                backwardv[vernow] = L[p]
                forwardv[vernow] = x
                L[p] = x
                vernow ++
            }
        }
//        repeat(30){
//            addone(3)
//        }
//        repeat(200){
//            addone(2)
//        }
//        repeat(1000){
//            addone(1)
//        }
//        solve(2)
//        repeat(1000){
//            removeone(1)
//        }
//        all.shuffle()
        all.sort()
        var cur_l = 0
        var cur_r = 0
        addone(L[0])

        fun add(v:Int){
            addone(L[v])
        }
        fun remove(v:Int){
            removeone(L[v])
        }
        fun verplus(){
            if(opi[vernow] !in cur_l..cur_r){
                L[opi[vernow]] = forwardv[vernow]
                vernow ++
                return
            }
            val i = opi[vernow]
            removeone(L[i])
            L[i] = forwardv[vernow]
            addone(L[i])
            vernow ++
        }
        fun verminus(){
            vernow --
            val i = opi[vernow]
            if(i !in cur_l..cur_r){
                L[i] = backwardv[vernow]
                return
            }

            removeone(L[i])
            L[i] = backwardv[vernow]
            addone(L[i])
        }

        val ret = IntArray(all.size)

        for(q in all){
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            while(vernow < q.ver){
                verplus()
            }
            while(vernow > q.ver){
                verminus()
            }
//            val x2 = solve2(q.k)
            val new = solve(q.k)
            ret[q.id] = new
//            assert(x2 == ret[q.id])
        }
        for(r in ret){
            if(r >= plarge){
                put(-1)
            }else{
                put(r)
            }
        }
//        put(ret.conca)







    }
    done()
}

/*
12 10
2 1 1 2 1 1 3 2 1 1 3 3
1 2 11 3
2 7 2
1 3 9 2
1 1 12 1
1 1 12 4
2 12 4
1 1 12 4
2 1 5
1 3 12 2
1 1 4 3



1 1 1 1 1 2 2 2
1


8
8
2 3 2 2 2 1 3 1
2 3 2 3 1 1 3 1
1 3 8 1
1 4 4 3
2 4 3
1 6 6 2
2 1 2
2 5 1
1 4 4 1
1 1 8 2
 */