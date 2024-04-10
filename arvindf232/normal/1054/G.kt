import java.io.BufferedInputStream
import java.io.PrintWriter
import java.util.*
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

    private val IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
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
    inline fun cases(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){getint()} else randCount
        repeat(t){
            currentAnswer = null
            currentBruteAnswer = null
            a()
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    inline fun real(a:()->Unit){
        if(mode == solveMode.real){
            a()
        }
    }
    inline fun rand(a:()->Unit){
        if(mode == solveMode.rand){
            a()
        }
    }
    inline fun tc(a:()->Unit){
        if(mode == solveMode.tc){ a()}
    }
    inline fun brute(a:()->Unit){
        if(withBruteForce){
            a()
        }
    }


    var currentAnswer:String? = null
    var currentBruteAnswer:String? = null
    fun answer(a:Any){
        currentAnswer = a.toString()
        if(currentAnswer != null){
            checkAnswer()
        }
    }
    fun send(a:Any){
        answer(a)
        put(a)
    }

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
    }
}

public class MyBitSet(size: Int = ELEMENT_SIZE) {

    companion object {
        // Default size of one element in the array used to store bits.
        private const val ELEMENT_SIZE = 32
        private const val MAX_BIT_OFFSET = ELEMENT_SIZE - 1
        private const val ALL_TRUE = -1 // 0xFFFF_FFFF_FFFF_FFFF
        private const val ALL_FALSE = 0 // 0x0000_0000_0000_0000
    }

    private var bits: IntArray = IntArray(bitToElementSize(size))

    private val lastIndex: Int
        get() = size - 1

    /** Returns an index of the last bit that has `true` value. Returns -1 if the set is empty. */
    val lastTrueIndex: Int
        get() = previousSetBit(size)

    /** True if this BitSet contains no bits set to true. */
    val isEmpty: Boolean
        get() = bits.all { it == ALL_FALSE }

    /** Actual number of bits available in the set. All bits with indices >= size assumed to be 0 */
    var size: Int = size
        private set

    /**
     * Creates a bit set of given [length] filling elements using [initializer]
     */
    constructor(length: Int, initializer: (Int) -> Boolean): this(length) {
        for (i in 0 until length) {
            set(i, initializer(i))
        }
    }

    // Transforms a bit index into an element index in the `bits` array.
    private val Int.elementIndex: Int
        get() = this / ELEMENT_SIZE

    // Transforms a bit index in the set into a bit in the element of the `bits` array.
    private val Int.bitOffset: Int
        get() = this % ELEMENT_SIZE

    // Transforms a bit index in the set into pair of a `bits` element index and a bit index in the element.
    private val Int.asBitCoordinates: Pair<Int, Int>
        get() = Pair(elementIndex, bitOffset)

    // Transforms a bit offset to the mask with only bit set corresponding to the offset.
    private val Int.asMask: Int
        get() = 1 shl this

    // Transforms a bit offset to the mask with only bits before the index (inclusive) set.
    private val Int.asMaskBefore: Int
        get() = getMaskBetween(0, this)

    // Transforms a bit offset to the mask with only bits after the index (inclusive) set.
    private val Int.asMaskAfter: Int
        get() = getMaskBetween(this, MAX_BIT_OFFSET)

    // Builds a masks with 1 between fromOffset and toOffset (both inclusive).
    private fun getMaskBetween(fromOffset: Int, toOffset: Int): Int {
        var res = 0
        val maskToAdd = fromOffset.asMask
        for (i in fromOffset..toOffset) {
            res = (res shl 1) or maskToAdd
        }
        return res
    }

    // Transforms a size in bits to a size in elements of the `bits` array.
    private fun bitToElementSize(bitSize: Int): Int = (bitSize + ELEMENT_SIZE - 1) / ELEMENT_SIZE

    // Transforms a pair of an element index and a bit offset to a bit index.
    private fun bitIndex(elementIndex: Int, bitOffset: Int) =
        elementIndex * ELEMENT_SIZE + bitOffset

    // Sets all bits after the last available bit (size - 1) to 0.
    private fun clearUnusedTail() {
        val (lastElementIndex, lastBitOffset) = lastIndex.asBitCoordinates
        bits[bits.lastIndex] = bits[bits.lastIndex] and lastBitOffset.asMaskBefore
        for (i in lastElementIndex + 1 until bits.size) {
            bits[i] = ALL_FALSE
        }
    }

    // Internal function. Sets bits specified by the element index and the given mask to value.
    private fun setBitsWithMask(elementIndex: Int, mask: Int, value: Boolean) {
        val element = bits[elementIndex]
        if (value) {
            bits[elementIndex] = element or mask
        } else {
            bits[elementIndex] = element and mask.inv()
        }
    }

    // Internal function. Flips bits specified by the element index and the given mask.
    private fun flipBitsWithMask(elementIndex: Int, mask: Int) {
        val element = bits[elementIndex]
        bits[elementIndex] = element xor mask
    }

    /**
     * Checks if index is valid and extends the `bits` array if the index exceeds its size.
     * @throws [IndexOutOfBoundsException] if [index] < 0.
     */
    private fun ensureCapacity(index: Int) {
        if (index < 0) {
            throw IndexOutOfBoundsException()
        }
        if (index >= size) {
            size = index + 1
            if (index.elementIndex >= bits.size) {
                // Create a new array containing the index-th bit.
                bits = bits.copyOf(bitToElementSize(index + 1))
            }
            // Set all bits after the index to 0. TODO: We can remove it.
            clearUnusedTail()
        }
    }

    /** Set the bit specified to the specified value. */
    operator fun set(index: Int, value: Boolean) {
        ensureCapacity(index)
        val (elementIndex, offset) = index.asBitCoordinates
        setBitsWithMask(elementIndex, offset.asMask, value)
    }

    /** Sets the bits with indices between [from] (inclusive) and [to] (exclusive) to the specified value. */
    fun set(from : Int, to: Int, value: Boolean = true) = set(from until to, value)

    /** Sets the bits from the range specified to the specified value. */
    fun set(range: IntRange, value: Boolean = true) {
        if (range.start < 0 || range.endInclusive < 0) {
            throw IndexOutOfBoundsException()
        }
        if (range.start > range.endInclusive) { // Empty range.
            return
        }
        ensureCapacity(range.endInclusive)
        val (fromIndex, fromOffset) = range.start.asBitCoordinates
        val (toIndex, toOffset) = range.endInclusive.asBitCoordinates
        if (toIndex == fromIndex) {
            val mask = getMaskBetween(fromOffset, toOffset)
            setBitsWithMask(fromIndex, mask, value)
        } else {
            // Set bits in the first element.
            setBitsWithMask(fromIndex, fromOffset.asMaskAfter, value)
            // Set all bits of all elements (excluding border ones) to 0 or 1 depending.
            for (index in fromIndex + 1 until toIndex) {
                bits[index] = if (value) ALL_TRUE else ALL_FALSE
            }
            // Set bits in the last element
            setBitsWithMask(toIndex, toOffset.asMaskBefore, value)
        }
    }


    /** Clears the bit specified */
    fun clear(index: Int) = set(index, false)
    /** Clears the bits with indices between [from] (inclusive) and [to] (exclusive) to the specified value. */
    fun clear(from : Int, to: Int) = set(from, to, false)
    /** Clears the bit specified */
    fun clear(range: IntRange) = set(range, false)

    /** Sets all bits in the BitSet to `false`. */
    fun clear() {
        for (i in bits.indices) {
            bits[i] = ALL_FALSE
        }
    }

    /** Reverses the bit specified. */
    fun flip(index: Int) {
        ensureCapacity(index)
        val (elementIndex, offset) = index.asBitCoordinates
        flipBitsWithMask(elementIndex, offset.asMask)
    }

    /** Reverses the bits with indices between [from] (inclusive) and [to] (exclusive). */
    fun flip(from: Int, to: Int) = flip(from until to)

    /** Reverses the bits from the range specified. */
    fun flip(range: IntRange) {
        if (range.start < 0 || range.endInclusive < 0) {
            throw IndexOutOfBoundsException()
        }
        if (range.start > range.endInclusive) { // Empty range.
            return
        }
        ensureCapacity(range.endInclusive)
        val (fromIndex, fromOffset) = range.start.asBitCoordinates
        val (toIndex, toOffset) = range.endInclusive.asBitCoordinates
        if (toIndex == fromIndex) {
            val mask = getMaskBetween(fromOffset, toOffset)
            flipBitsWithMask(fromIndex, mask)
        } else {
            // Flip bits in the first element.
            flipBitsWithMask(toIndex, toOffset.asMaskAfter)
            // Flip bits between the first and the last elements.
            for (index in fromIndex + 1 until toIndex) {
                bits[index] = bits[index].inv()
            }
            // Flip bits in the last element.
            flipBitsWithMask(toIndex, toOffset.asMaskBefore)
        }
    }

    /**
     * Returns an index of a next set (if [lookFor] == true) or clear
     * (if [lookFor] == false) bit after [startIndex] (inclusive).
     * Returns -1 (for [lookFor] == true) or [size] (for lookFor == false)
     * if there is no such bits between [startIndex] and [size] - 1.
     * @throws IndexOutOfBoundException if [startIndex] < 0.
     */
    private fun nextBit(startIndex: Int, lookFor: Boolean): Int {
        if (startIndex < 0) {
            throw IndexOutOfBoundsException()
        }
        if (startIndex >= size) {
            return if (lookFor) -1 else startIndex
        }
        val (startElementIndex, startOffset) = startIndex.asBitCoordinates
        // Look for the next set bit in the first element.
        var element = bits[startElementIndex]
        for (offset in startOffset..MAX_BIT_OFFSET) {
            val bit = element and (1 shl offset) != 0
            if (bit == lookFor) {  // Look for not 0 if we need a set bit and look for 0 otherwise.
                return bitIndex(startElementIndex, offset)
            }
        }
        // Look for in the remaining elements.
        for (index in startElementIndex + 1..bits.lastIndex) {
            element = bits[index]
            for (offset in 0..MAX_BIT_OFFSET) {
                val bit = element and (1 shl offset) != 0
                if (bit == lookFor) { // Look for not 0 if we need a set bit and look for 0 otherwise.
                    return bitIndex(index, offset)
                }
            }
        }
        return if (lookFor) -1 else size
    }

    /**
     * Returns an index of a next bit which value is `true` after [startIndex] (inclusive).
     * Returns -1 if there is no such bits after [startIndex].
     * @throws IndexOutOfBoundException if [startIndex] < 0.
     */
    fun nextSetBit(startIndex: Int = 0): Int = nextBit(startIndex, true)

    /**
     * Returns an index of a next bit which value is `false` after [startIndex] (inclusive).
     * Returns [size] if there is no such bits between [startIndex] and [size] - 1 assuming that the set has an infinite
     * sequence of `false` bits after (size - 1)-th.
     * @throws IndexOutOfBoundException if [startIndex] < 0.
     */
    fun nextClearBit(startIndex: Int = 0): Int = nextBit(startIndex, false)

    /**
     * Returns the biggest index of a bit which value is [lookFor] before [startIndex] (inclusive).
     * Returns -1 if there is no such bits before [startIndex].
     * If [startIndex] >= [size] returns -1
     */
    fun previousBit(startIndex: Int, lookFor: Boolean): Int {
        var correctStartIndex = startIndex
        if (startIndex >= size) {
            // We assume that all bits after `size - 1` are 0. So we can return the start index if we are looking for 0.
            if (!lookFor) {
                return startIndex
            } else {
                // If we are looking for 1 we can skip all these 0 after `size - 1`.
                correctStartIndex = size - 1
            }
        }
        if (correctStartIndex < -1) {
            throw IndexOutOfBoundsException()
        }
        if (correctStartIndex == -1) {
            return -1
        }

        val (startElementIndex, startOffset) = correctStartIndex.asBitCoordinates
        // Look for the next set bit in the first element.
        var element = bits[startElementIndex]
        for (offset in startOffset downTo 0) {
            val bit = element and (1 shl offset) != 0
            if (bit == lookFor) {  // Look for not 0 if we need a set bit and look for 0 otherwise.
                return bitIndex(startElementIndex, offset)
            }
        }
        // Look for in the remaining elements.
        for (index in startElementIndex - 1 downTo 0) {
            element = bits[index]
            for (offset in MAX_BIT_OFFSET downTo 0) {
                val bit = element and (1 shl offset) != 0
                if (bit == lookFor) {  // Look for not 0 if we need a set bit and look for 0 otherwise.
                    return bitIndex(index, offset)
                }
            }
        }
        return -1
    }

    /**
     * Returns the biggest index of a bit which value is `true` before [startIndex] (inclusive).
     * Returns -1 if there is no such bits before [startIndex] or if [startIndex] == -1.
     * If [startIndex] >= size will search from (size - 1)-th bit.
     * @throws IndexOutOfBoundException if [startIndex] < -1.
     */
    fun previousSetBit(startIndex: Int): Int = previousBit(startIndex, true)

    /**
     * Returns the biggest index of a bit which value is `false` before [startIndex] (inclusive).
     * Returns -1 if there is no such bits before [startIndex] or if [startIndex] == -1.
     * If [startIndex] >= size will return [startIndex] assuming that the set has an infinite
     * sequence of `false` bits after (size - 1)-th.
     * @throws IndexOutOfBoundException if [startIndex] < -1.
     */
    fun previousClearBit(startIndex: Int): Int = previousBit(startIndex, false)

    /** Returns a value of a bit with the [index] specified. */
    operator fun get(index: Int): Boolean {
        if (index < 0) {
            throw IndexOutOfBoundsException()
        }
        if (index >= size) {
            return false
        }
        val (elementIndex, offset) = index.asBitCoordinates
        return bits[elementIndex] and offset.asMask != 0
    }

    private inline fun doOperation(another: MyBitSet, operation: Int.(Int) -> Int) {
        ensureCapacity(another.lastIndex)
        var index = 0
        while (index < another.bits.size) {
            bits[index] = operation(bits[index], another.bits[index])
            index++
        }
        while (index < bits.size) {
            bits[index] = operation(bits[index], ALL_FALSE)
            index++
        }
    }
    fun contains(other:MyBitSet):Boolean{
        for(it in 0 until other.bits.size){
            if(bits[it].or(other.bits[it]) != bits[it]) return false
        }
        return true
//        return (0 until other.bits.size).all{ bits[it].or(other.bits[it]) == bits[it]}
    }

    /** Performs a logical and operation over corresponding bits of this and [another] BitSets. The result is saved in this BitSet. */
    fun and(another: MyBitSet) = doOperation(another, Int::and)

    /** Performs a logical or operation over corresponding bits of this and [another] BitSets. The result is saved in this BitSet. */
    fun or(another: MyBitSet) = doOperation(another, Int::or)

    /** Performs a logical xor operation over corresponding bits of this and [another] BitSets. The result is saved in this BitSet. */
    fun xor(another: MyBitSet) = doOperation(another, Int::xor)

    /** Performs a logical and + not operations over corresponding bits of this and [another] BitSets. The result is saved in this BitSet. */
    fun andNot(another: MyBitSet) {
        ensureCapacity(another.lastIndex)
        var index = 0
        while (index < another.bits.size) {
            bits[index] = bits[index] and another.bits[index].inv()
            index++
        }
        while (index < bits.size) {
            bits[index] = bits[index] and ALL_TRUE
            index++
        }
    }

    /** Returns true if the specified BitSet has any bits set to true that are also set to true in this BitSet. */
    fun intersects(another: MyBitSet): Boolean =
        (0 until minOf(bits.size, another.bits.size)).any { bits[it] and another.bits[it] != 0 }

    override fun toString(): String {
        val sb = StringBuilder()
        var first = true
        sb.append('[')
        var index = nextSetBit(0)
        while (index != -1) {
            if (!first) {
                sb.append('|')
            } else {
                first = false
            }
            sb.append(index)
            index = nextSetBit(index + 1)
        }
        sb.append(']')
        return sb.toString()
    }

    override fun hashCode(): Int {
        var x: Int = 1234
        for (i in 0..bits.lastIndex) {
            x = x xor bits[i] * (i + 1)
        }
        return (x).toInt()
    }

    override fun equals(other: Any?): Boolean {
        if (this === other) {
            return true
        }
        if (other !is MyBitSet) {
            return false
        }
        var index = 0
        while (index < minOf(bits.size, other.bits.size)) {
            if (bits[index] != other.bits[index]) {
                return false
            }
            index++
        }
        val longestBits = if (bits.size > other.bits.size) bits else other.bits
        while (index < longestBits.size) {
            if (longestBits[index] != ALL_FALSE) {
                return false
            }
            index++
        }
        return true
    }
}

const val withBruteForce = false
const val randCount = 100
fun main(){
    solve.mode = solveMode.real

//    var x = 0
//    TIME{
//        repeat(4000000*63){
//            x = x.or(it)
//            val y = x == 0
//        }
//    }
//    return


//    TIME{
   solve.cases{
//       val n = 2000
//       val m = 2000
//        System.err.println("Bad")


        val n = getint()
        val m = getint()
        val item = List(n){MyBitSet(m)}
        val rowCount = IntArray(m)


       real{
           repeat(m){
               val line = getstr()
//            if(tc == 43){
//                put(line)
//            }
               for(i in 0 until n){
                   item[i].set(it,line[i] == '1')
                   if(line[i] == '1'){
                       rowCount[it]++
                   }
               }
           }
       }
        var containCount = 0
        fun contains(i:Int,k:Int):Boolean{
//            containCount ++
//            if(containCount == 1000000){
//                println(containCount)
//                containCount = 0
//            }
//            val test = item[i]
////            val test = item[i].clone() as BitSet
//            test.and(item[k])
            return item[k].contains(item[i])
        }
//       TIME{
//           repeat(4000000){
//               contains(1,2)
//           }
//       }
//       return
        val ok = List(n){BooleanArray(n)}
        val okCount = IntArray(n)
        for(i in 0 until n){
            var any = false
            for(j in 0 until n){
                if(j == i){continue}
                if(contains(i,j)){
                    ok[i][j] = true
                    any = true
                    okCount[i] ++
                }
            }
        }

        val taken = BooleanArray(n)

        fun cleanOKCount(i:Int){
            for(j in 0 until n){
                if(ok[j][i]){
                    ok[j][i] = false
                    okCount[j] --
                }
            }
        }


        fun recalculate(i:Int){
            for(j in 0 until n){
                if(j == i){continue}
                if(contains(i,j)){
                    if(!ok[i][j]){
                        ok[i][j] = true
                        okCount[i] ++
                    }

                }
            }
        }
        fun clean(){
            for(j in 0 until m){
                if(rowCount[j] == 1){
                    rowCount[j] = -1
                    var that = -1
                    for(i in 0 until n){
                        if(item[i][j]){
                            if(that != -1){
                                crash()
                            }
                            that = i
                            item[i][j] = false
                        }
                    }
                    if(that != -1){
                        recalculate(that)
                    }
                }
            }
        }
        fun verify(){
            for(i in 0 until n){
                for(j in 0 until n){
                    if(taken[i] || taken[j]) continue
                    if(i == j)continue
                    val z = contains(i,j)
                    assert(contains(i,j) == ok[i][j])
                }
            }
            for(i in 0 until n){
                assert(okCount[i] == (0 until n).count{ok[i][it] && !taken[it]})
            }

        }

        fun eraseAndUpdate(i:Int){
            taken[i] = true
            for(j in 0 until m){
                val past = item[i][j]
                if(past){
                    rowCount[j] --
                }
                item[i][j] = false
            }
            clean()
            cleanOKCount(i)
        }
        clean()
        val ret = mutableListOf<Pair<Int,Int>>()


        while(true){
            if(ret.size == n-1){
                break
            }
//            verify()
            val next = (0 until n).firstOrNull{okCount[it] > 0 && !taken[it]}
            if(next == null){
                break
            }
            val to = (0 until n).firstOrNull { ok[next][it] && !taken[it] && it != next }

            ret.add(Pair(next,to!!))
            eraseAndUpdate(next)
        }
        if(ret.size == n-1){
            put("YES")
            for((a,b) in ret){
                put(a + 1 )
                put(b + 1)
            }
        }else{
            put("NO")
        }
        

//    }
    }
    done()
}