// 2022.10.17 at 16:04:19 BST
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet

// 1. Modded
const val p = 998244353L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.mm(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.mp(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
infix fun Int.ms(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + pI else ans }
fun Int.inverse():Int = intPow(this,pI-2,pI)
infix fun Int.modDivide(b:Int):Int{ return this mm (b.inverse()) }
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
// 3. convenience conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
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
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong())
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
//9.ordered pair
fun order(a:Int, b:Int):Pair<Int,Int>{
    return Pair(minOf(a,b), maxOf(a,b))
}
const val interactive = false
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
            if(interactive){
                return System.`in`.read().toChar()
            }
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
    fun flush(){
        OUT.flush()
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun eat(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>()}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
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
const val just = " "
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
fun debug(){}


class matrixP(val n:Int, val m:Int) {
    companion object{
        //        const val modded = false
        fun identity(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            return ret
        }
        fun standardTriangle(n:Int): matrixP {
            val ret = matrixP(n,n)
            for(i in 0 until n){
                ret.A[i][i] = 1
            }
            for(i in 1 until n){
                ret.A[i-1][i] = 1
            }
            return ret
        }
        fun columnvector(a:IntArray):matrixP{
            val new = matrixP(a.size,1)
            for(i in a.indices){
                new[i][0] = a[i]
            }
            return new
        }
        fun fromcolumns(a:Array<IntArray>):matrixP{
            val new = matrixP(a[0].size, a.size)
            for(i in a.indices){
                for(j in a[0].indices){
                    new[j][i] = a[i][j]
                }
            }
            return new
        }
    }
    val A = Array(n){IntArray(m)}

    infix operator fun times(other: matrixP): matrixP {
        assert(m == other.n)
        val ret = matrixP(n,other.m)
        for(i in 0 until n){
            for(k in 0 until m){
                for(j in 0 until other.m){
                    ret.A[i][j] = ret.A[i][j] mp ( A[i][k] mm other.A[k][j])
                }
            }
        }
        return ret
    }
    fun print(){
        for(i in 0 until n){
            println(A[i].joinToString(" "))
        }
        println()
    }
    operator fun get(i:Int):IntArray{
        return A[i]
    }
    fun copyOf(): matrixP {
        val ret =  matrixP(n,m)
        for(i in 0 until n){
            for(j in 0 until m){
                ret.A[i][j] = A[i][j]
            }
        }
        return ret
    }
    fun elimination():IntArray?{
//        assert(answer.size == this.n)
        //Always vertical

        val where = IntArray(m){-1}
        var row = 0
        val m = this.m - 1
        for(col in 0 until m){
            if(row >= n ) break
            for(i in row until n){
                if(A[i][col] != 0){
                    val temp = A[i]
                    A[i] = A[row]
                    A[row] = temp
                    break
                }
            }
            if(A[row][col] == 0) continue
            where[col] = row
            for(i in 0 until n){
                val inv = A[row][col].inverse()
                if(i != row && A[i][col] != 0){
                    val c = A[i][col] mm inv
                    for(j in col..m){
                        A[i][j] = (A[i][j] ms (A[row][j] mm c))
                    }
                }
            }
            row ++
        }
        val ret = IntArray(m){0}
        for(i in 0 until m){
            if(where[i] != -1){
                ret[i] = A[where[i]][m] modDivide A[where[i]][i]
            }
        }
        for(i in 0 until n){
            var sum = 0
            for(j in 0 until m){
                sum = sum mp (ret[j] mm A[i][j])
            }
            if( sum != A[i][m]){
                return null
            }
        }
//        if(where.any { it == -1 }){
//            //infinity
//        }
        return ret
    }
}





class item(var a00:Int, var a01:Int, var a10:Int, var a11:Int){
    companion object{
        val empty:item get() = item(1,0,0,1)
        val m0:item get() = item(2,0,1,3)
        val m1:item get() = item(2,2,1,1)
        val m2:item get() = item(1,0,0,1)
        init{
//            m0 = item(2,0,1,3)
////            m0[0][0] = 2
////            m0[0][1] = 0
////            m0[1][0] = 1
////            m0[1][1] = 3
//
//            m1 = matrixP(2,2)
//            m1[0][0] = 2
//            m1[0][1] = 2
//            m1[1][0] = 1
//            m1[1][1] = 1

        }
        fun construct(i:Int):item{
            if(i == 0){
                return item(2,0,1,3)
            }else if(i == 1){
                return item(2,2,1,1)
            }else{
                return item(1,0,0,1)
            }
        }
    }
    fun mergewrite(left:item, right:item){
        this.a00 = (right.a00 mm left.a00) mp (right.a01 mm left.a10)
        this.a01 = (right.a00 mm left.a01) mp (right.a01 mm left.a11)
        this.a10 = (right.a10 mm left.a00) mp (right.a11 mm left.a10)
        this.a11 = (right.a10 mm left.a01) mp (right.a11 mm left.a11)
    }
}
class buildableSegTree (withArray:IntArray){
    //Items lenght must be a power of 2

    val nSuggest = withArray.size
    val n = if(nSuggest >= 2) (nSuggest - 1).takeHighestOneBit() shl 1 else nSuggest
    val levels = (31 - n.countLeadingZeroBits()) // (Levels) amount of levels then a layer of leaf
    val arr = Array<item>(n * 2 ){
        if(it  - n in withArray.indices) item.construct(withArray[it - n]) else item.empty}

    init{
        updateAll()
    }


    private fun updateNode(i:Int){
        arr[i].mergewrite(arr[i shl 1 ], arr[(i shl 1) + 1])
    }
    fun queryFunctional(l:Int,r:Int):item{
        var ret = item.empty
        segDivisonOrdered(l,r){i ->
            val new = item.empty
            new.mergewrite(ret,arr[i])
            ret = new
        }
        return ret
    }

    fun queryDebug(l:Int, r:Int):item{
        var ret = item.empty
        segDivisonOrdered(l,r){i ->
            val new = item.empty
            "adding $i" dei arr[i]
            new.mergewrite(ret,arr[i])
            ret = new
            "New: " dei ret
        }
        return ret
    }
    private fun updatePath(i:Int){
        // i is the endpoint, typically (n+i)
        // bottom up, recalculate
        var here = i
        while(here > 1){
            here = here shr 1
            updateNode(here)
        }
    }
    fun updateAll(){
        for(i in n-1 downTo 1){
            updateNode(i)
        }
    }
    fun setValue(i:Int, v:Int){
        arr[n+i] = item.construct(v)
        updatePath(n+i)
    }
    val firstIndex = n
    val lastIndex = (n shl 1 ) - 1
    val indices = firstIndex..lastIndex

    inline fun segDivisonOrdered(l:Int, r:Int, act:(index:Int)->Unit){
        var left = l + n
        var right = r + n + 1
        var level = 0
        while(left < right){
            if(left and 1 != 0){
                act(left)
                left += 1
            }
            left = left shr 1
            right = right shr 1
            level ++
        }
        right = r + n + 1
        for(lev in level - 1 downTo 0){
            if((right shr lev) and 1 == 1){
                act((right shr lev) - 1 )
            }
        }
    }
}

const val singleCase = true
fun main(){
//    solve.tc {
//        share(
//    }
    solve.cases{

        val n = getint
        val intervals = mutableListOf<Pair<Int,Int>>()
        repeat(n){
            intervals.add(Pair(getint  , getint ))
        }
        val max = 300005

        val st = buildableSegTree(IntArray(n){if(it == 0) -1 else 0})
        val add = Array(max+1){mint}
        val remove = Array(max+1){mint}






        for(i in 0 until n){
            val (a,b) = intervals[i]
            add[a].add(i)
            remove[b+1].add(i)
        }
        var start = 0

//        val t1 = matrixP(2,1)
//        t1[0][0] = 1
//        val t0 = matrixP(2,1)
//        t0[1][0] = 1

        var ret = 0
        for(i in 0 until max){
            for(c in add[i]){
                if(c != 0)
                st.setValue(c,1)
                else
                    start = 1
            }
            for(c in remove[i]){
                if(c != 0)
                st.setValue(c,0)
                else
                    start = 0
            }
            val ans = st.arr[1]

            val got = if(start == 0)ans.a01 else ans.a00

//            st.arr[1].m.print()

//            val ans = st.arr[1].m.times(if(start ==0) t0 else t1)[0][0]

//            i dei ans
            ret = ret mp got
        }
        put(ret)





    }
    done()
}



/*

2
1 1
2 2
 */