import java.io.*
import java.util.*
import java.lang.Math.*

const val STRESS = false
const val STRESS_ITER = 100

data class Solver(val io: FastIO) {
    fun FastIO.solve() {
        val n = nextInt()
        val a = IntList(n / 2, { nextInt() - 1 })
        var a1 = 0
        var a2 = 0
        a.sort()
        for (i in 0 until a.size) {
            a1 += abs(a[i] - i * 2)
            a2 += abs(a[i] - i * 2 - 1)
        }
        println(min(a1, a2))
    }

    fun run() {
        io.use { it.solve() }
    }
}

fun main(args: Array<String>) {
    if (args.isNotEmpty() && args[0] == "KLOCAL") {
        if (STRESS) {
            Stresser.doStress()
        } else {
            Solver(FastIO(FileInputStream("input.txt"), System.out)).run()
        }
    } else {
        Solver(FastIO(System.`in`, System.out)).run()
    }
}

data class SlowSolver(val io: FastIO) {
    fun FastIO.slowSolve() {

    }

    fun run() {
        io.use { it.slowSolve() }
    }
}

class Stresser {
    companion object {
        const val INPUT = "input.txt"
        const val OUTPUT = "output.txt"
        const val SLOW = "slow.txt"

        fun PrintWriter.generateTest() {
            val rand = Random(31)

        }

        fun doStress() {
            for (it in 1..STRESS_ITER) {
                System.err.println(it)
                PrintWriter(INPUT).use { it.generateTest() }
                SlowSolver(FastIO(FileInputStream(INPUT), FileOutputStream(SLOW))).run()
                Solver(FastIO(FileInputStream(INPUT), FileOutputStream(OUTPUT))).run()
                compareFiles()
            }
        }

        fun compareFiles() {
            val out = File(OUTPUT).readLines().toMutableList()
            val slw = File(SLOW).readLines().toMutableList()
            while (out.size < slw.size) {
                out.add("\n")
            }
            while (out.size > slw.size) {
                slw.add("\n")
            }
            for (i in 0 until out.size) {
                if (out[i].trimEnd() != slw[i].trimEnd()) {
                    throw AssertionError("\nline ${i + 1}\nout: ${out[i]}\nslw: ${slw[i]}")
                }
            }
        }
    }
}

class FastIO(input: InputStream, output: OutputStream) : PrintWriter(output, false) {
    val br = BufferedReader(InputStreamReader(input))
    var stok = StringTokenizer("")

    fun nextToken(): String? {
        while (!stok.hasMoreTokens()) {
            val s = br.readLine() ?: return null
            stok = StringTokenizer(s)
        }
        return stok.nextToken()
    }

    fun nextInt(): Int {
        return nextToken()!!.toInt()
    }

    fun nextLong(): Long {
        return nextToken()!!.toLong()
    }

    fun nextDouble(): Double {
        return nextToken()!!.toDouble()
    }

    fun print(vararg args: Any?) {
        args.forEachIndexed { i, arg ->
            if (i != 0) {
                print(" ")
            }
            print(arg)
        }
    }

    fun println(vararg args: Any?) {
        print(*args)
        println()
    }
}

class IntList {
    private var a: IntArray
    var size = 0

    constructor() {
        a = IntArray(4)
    }

    constructor(n: Int, x: Int = 0) {
        a = if (x == 0) {
            IntArray(n)
        } else {
            IntArray(n, { x })
        }
        size = n
    }

    constructor(n: Int, init: (Int) -> Int) {
        a = IntArray(n, init)
        size = n
    }

    fun add(x: Int) {
        ensureCapacity()
        a[size++] = x
    }

    fun front(): Int {
        return a[0]
    }

    fun back(): Int {
        return a[size - 1]
    }

    fun pop(): Int {
        return a[--size]
    }

    operator fun get(i: Int): Int {
        return a[i]
    }

    operator fun set(i: Int, x: Int) {
        a[i] = x
    }

    fun removeAt(i: Int) {
        var i = i
        while (i + 1 < size) {
            a[i] = a[i + 1]
            i++
        }
        --size
    }

    fun rotate(distance: Int) {
        if (size == 0)
            return
        var distance = distance % size
        if (distance < 0)
            distance += size
        if (distance == 0)
            return

        var cycleStart = 0
        var nMoved = 0
        while (nMoved != size) {
            var displaced = a[cycleStart]
            var i = cycleStart
            do {
                i += distance
                if (i >= size)
                    i -= size
                val tmp = a[i]
                a[i] = displaced
                displaced = tmp
                nMoved++
            } while (i != cycleStart)
            cycleStart++
        }
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    operator fun contains(x: Int): Boolean {
        for (i in 0 until size) {
            if (a[i] == x) {
                return true
            }
        }
        return false
    }

    override fun equals(other: Any?): Boolean {
        if (other == null || other !is IntList || size != other.size) {
            return false
        }

        for (i in 0 until size) {
            if (a[i] != other.a[i]) {
                return false
            }
        }

        return true
    }

    operator fun compareTo(other: IntList): Int {
        var i = 0
        while (i < min(size, other.size)) {
            if (a[i] < other.a[i]) {
                return -1
            }
            if (a[i] > other.a[i]) {
                return 1
            }
        }
        if (size < other.size) {
            return -1
        }
        if (size > other.size) {
            return 1
        }
        return 0
    }

    fun sort(from: Int = 0, to: Int = size) {
        a.sort(from, to)
    }

    fun reverse() {
        var i = 0
        while (i * 2 < size) {
            val x = a[i]
            a[i] = a[size - 1 - i]
            a[size - 1 - i] = x
            i++
        }
    }

    fun shuffle(rand: Random = Random()) {
        for (i in 1 until size) {
            val j = rand.nextInt(i + 1)
            if (i != j) {
                val x = a[i]
                a[i] = a[j]
                a[j] = x
            }
        }
    }

    fun nextPermutation(): Boolean {
        var i = size - 2
        while (i >= 0) {
            if (a[i] < a[i + 1]) {
                var b = size - 1
                while (true) {
                    if (a[b] > a[i]) {
                        var t = a[i]
                        a[i] = a[b]
                        a[b] = t
                        ++i
                        b = size - 1
                        while (i < b) {
                            t = a[i]
                            a[i] = a[b]
                            a[b] = t
                            ++i
                            --b
                        }
                        return true
                    }
                    --b
                }
            }
            --i
        }
        return false
    }

    fun forEach(block: (x: Int) -> Unit) {
        for (i in 0 until size) {
            block(a[i])
        }
    }

    fun forEachIndexed(block: (i: Int, x: Int) -> Unit) {
        for (i in 0 until size) {
            block(i, a[i])
        }
    }

    fun getArray(): IntArray {
        return a.copyOf(size)
    }

    private fun ensureCapacity() {
        if (size == a.size) {
            a = a.copyOf(size * 2)
        }
    }
}

class LongList {
    private var a: LongArray
    var size = 0

    constructor() {
        a = LongArray(4)
    }

    constructor(n: Int, x: Long = 0) {
        a = if (x == 0L) {
            LongArray(n)
        } else {
            LongArray(n, { x })
        }
        size = n
    }

    constructor(n: Int, init: (Int) -> Long) {
        a = LongArray(n, init)
        size = n
    }

    fun add(x: Long) {
        ensureCapacity()
        a[size++] = x
    }

    fun front(): Long {
        return a[0]
    }

    fun back(): Long {
        return a[size - 1]
    }

    fun pop(): Long {
        return a[--size]
    }

    operator fun get(i: Int): Long {
        return a[i]
    }

    operator fun set(i: Int, x: Long) {
        a[i] = x
    }

    fun removeAt(i: Int) {
        var i = i
        while (i + 1 < size) {
            a[i] = a[i + 1]
            i++
        }
        --size
    }

    fun rotate(distance: Int) {
        if (size == 0)
            return
        var distance = distance % size
        if (distance < 0)
            distance += size
        if (distance == 0)
            return

        var cycleStart = 0
        var nMoved = 0
        while (nMoved != size) {
            var displaced = a[cycleStart]
            var i = cycleStart
            do {
                i += distance
                if (i >= size)
                    i -= size
                val tmp = a[i]
                a[i] = displaced
                displaced = tmp
                nMoved++
            } while (i != cycleStart)
            cycleStart++
        }
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    operator fun contains(x: Long): Boolean {
        for (i in 0 until size) {
            if (a[i] == x) {
                return true
            }
        }
        return false
    }

    override fun equals(other: Any?): Boolean {
        if (other == null || other !is LongList || size != other.size) {
            return false
        }

        for (i in 0 until size) {
            if (a[i] != other.a[i]) {
                return false
            }
        }

        return true
    }

    operator fun compareTo(other: LongList): Int {
        var i = 0
        while (i < min(size, other.size)) {
            if (a[i] < other.a[i]) {
                return -1
            }
            if (a[i] > other.a[i]) {
                return 1
            }
        }
        if (size < other.size) {
            return -1
        }
        if (size > other.size) {
            return 1
        }
        return 0
    }

    fun sort(from: Int = 0, to: Int = size) {
        a.sort(from, to)
    }

    fun reverse() {
        var i = 0
        while (i * 2 < size) {
            val x = a[i]
            a[i] = a[size - 1 - i]
            a[size - 1 - i] = x
            i++
        }
    }

    fun shuffle(rand: Random = Random()) {
        for (i in 1 until size) {
            val j = rand.nextInt(i + 1)
            if (i != j) {
                val x = a[i]
                a[i] = a[j]
                a[j] = x
            }
        }
    }

    fun nextPermutation(): Boolean {
        var i = size - 2
        while (i >= 0) {
            if (a[i] < a[i + 1]) {
                var b = size - 1
                while (true) {
                    if (a[b] > a[i]) {
                        var t = a[i]
                        a[i] = a[b]
                        a[b] = t
                        ++i
                        b = size - 1
                        while (i < b) {
                            t = a[i]
                            a[i] = a[b]
                            a[b] = t
                            ++i
                            --b
                        }
                        return true
                    }
                    --b
                }
            }
            --i
        }
        return false
    }

    fun forEach(block: (x: Long) -> Unit) {
        for (i in 0 until size) {
            block(a[i])
        }
    }

    fun forEachIndexed(block: (i: Int, x: Long) -> Unit) {
        for (i in 0 until size) {
            block(i, a[i])
        }
    }

    fun getArray(): LongArray {
        return a.copyOf(size)
    }

    private fun ensureCapacity() {
        if (size == a.size) {
            a = a.copyOf(size * 2)
        }
    }
}

class DoubleList {
    private var a: DoubleArray
    var size = 0

    constructor() {
        a = DoubleArray(4)
    }

    constructor(n: Int, x: Double = .0) {
        a = if (x == .0) {
            DoubleArray(n)
        } else {
            DoubleArray(n, { x })
        }
        size = n
    }

    constructor(n: Int, init: (Int) -> Double) {
        a = DoubleArray(n, init)
        size = n
    }

    fun add(x: Double) {
        ensureCapacity()
        a[size++] = x
    }

    fun front(): Double {
        return a[0]
    }

    fun back(): Double {
        return a[size - 1]
    }

    fun pop(): Double {
        return a[--size]
    }

    operator fun get(i: Int): Double {
        return a[i]
    }

    operator fun set(i: Int, x: Double) {
        a[i] = x
    }

    fun removeAt(i: Int) {
        var i = i
        while (i + 1 < size) {
            a[i] = a[i + 1]
            i++
        }
        --size
    }

    fun rotate(distance: Int) {
        if (size == 0)
            return
        var distance = distance % size
        if (distance < 0)
            distance += size
        if (distance == 0)
            return

        var cycleStart = 0
        var nMoved = 0
        while (nMoved != size) {
            var displaced = a[cycleStart]
            var i = cycleStart
            do {
                i += distance
                if (i >= size)
                    i -= size
                val tmp = a[i]
                a[i] = displaced
                displaced = tmp
                nMoved++
            } while (i != cycleStart)
            cycleStart++
        }
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    operator fun contains(x: Double): Boolean {
        for (i in 0 until size) {
            if (a[i] == x) {
                return true
            }
        }
        return false
    }

    override fun equals(other: Any?): Boolean {
        if (other == null || other !is DoubleList || size != other.size) {
            return false
        }

        for (i in 0 until size) {
            if (a[i] != other.a[i]) {
                return false
            }
        }

        return true
    }

    operator fun compareTo(other: DoubleList): Int {
        var i = 0
        while (i < min(size, other.size)) {
            if (a[i] < other.a[i]) {
                return -1
            }
            if (a[i] > other.a[i]) {
                return 1
            }
        }
        if (size < other.size) {
            return -1
        }
        if (size > other.size) {
            return 1
        }
        return 0
    }

    fun sort(from: Int = 0, to: Int = size) {
        a.sort(from, to)
    }

    fun reverse() {
        var i = 0
        while (i * 2 < size) {
            val x = a[i]
            a[i] = a[size - 1 - i]
            a[size - 1 - i] = x
            i++
        }
    }

    fun shuffle(rand: Random = Random()) {
        for (i in 1 until size) {
            val j = rand.nextInt(i + 1)
            if (i != j) {
                val x = a[i]
                a[i] = a[j]
                a[j] = x
            }
        }
    }

    fun nextPermutation(): Boolean {
        var i = size - 2
        while (i >= 0) {
            if (a[i] < a[i + 1]) {
                var b = size - 1
                while (true) {
                    if (a[b] > a[i]) {
                        var t = a[i]
                        a[i] = a[b]
                        a[b] = t
                        ++i
                        b = size - 1
                        while (i < b) {
                            t = a[i]
                            a[i] = a[b]
                            a[b] = t
                            ++i
                            --b
                        }
                        return true
                    }
                    --b
                }
            }
            --i
        }
        return false
    }

    fun forEach(block: (x: Double) -> Unit) {
        for (i in 0 until size) {
            block(a[i])
        }
    }

    fun forEachIndexed(block: (i: Int, x: Double) -> Unit) {
        for (i in 0 until size) {
            block(i, a[i])
        }
    }

    fun getArray(): DoubleArray {
        return a.copyOf(size)
    }

    private fun ensureCapacity() {
        if (size == a.size) {
            a = a.copyOf(size * 2)
        }
    }
}

class BooleanList {
    private var a: BooleanArray
    var size = 0

    constructor() {
        a = BooleanArray(4)
    }

    constructor(n: Int, x: Boolean = false) {
        a = if (x == false) {
            BooleanArray(n)
        } else {
            BooleanArray(n, { x })
        }
        size = n
    }

    constructor(n: Int, init: (Int) -> Boolean) {
        a = BooleanArray(n, init)
        size = n
    }

    fun add(x: Boolean) {
        ensureCapacity()
        a[size++] = x
    }

    fun front(): Boolean {
        return a[0]
    }

    fun back(): Boolean {
        return a[size - 1]
    }

    fun pop(): Boolean {
        return a[--size]
    }

    operator fun get(i: Int): Boolean {
        return a[i]
    }

    operator fun set(i: Int, x: Boolean) {
        a[i] = x
    }

    fun removeAt(i: Int) {
        var i = i
        while (i + 1 < size) {
            a[i] = a[i + 1]
            i++
        }
        --size
    }

    fun rotate(distance: Int) {
        if (size == 0)
            return
        var distance = distance % size
        if (distance < 0)
            distance += size
        if (distance == 0)
            return

        var cycleStart = 0
        var nMoved = 0
        while (nMoved != size) {
            var displaced = a[cycleStart]
            var i = cycleStart
            do {
                i += distance
                if (i >= size)
                    i -= size
                val tmp = a[i]
                a[i] = displaced
                displaced = tmp
                nMoved++
            } while (i != cycleStart)
            cycleStart++
        }
    }

    fun isEmpty(): Boolean {
        return size == 0
    }

    operator fun contains(x: Boolean): Boolean {
        for (i in 0 until size) {
            if (a[i] == x) {
                return true
            }
        }
        return false
    }

    override fun equals(other: Any?): Boolean {
        if (other == null || other !is BooleanList || size != other.size) {
            return false
        }

        for (i in 0 until size) {
            if (a[i] != other.a[i]) {
                return false
            }
        }

        return true
    }

    operator fun compareTo(other: BooleanList): Int {
        var i = 0
        while (i < min(size, other.size)) {
            if (a[i] < other.a[i]) {
                return -1
            }
            if (a[i] > other.a[i]) {
                return 1
            }
        }
        if (size < other.size) {
            return -1
        }
        if (size > other.size) {
            return 1
        }
        return 0
    }

    fun reverse() {
        var i = 0
        while (i * 2 < size) {
            val x = a[i]
            a[i] = a[size - 1 - i]
            a[size - 1 - i] = x
            i++
        }
    }

    fun shuffle(rand: Random = Random()) {
        for (i in 1 until size) {
            val j = rand.nextInt(i + 1)
            if (i != j) {
                val x = a[i]
                a[i] = a[j]
                a[j] = x
            }
        }
    }

    fun nextPermutation(): Boolean {
        var i = size - 2
        while (i >= 0) {
            if (a[i] < a[i + 1]) {
                var b = size - 1
                while (true) {
                    if (a[b] > a[i]) {
                        var t = a[i]
                        a[i] = a[b]
                        a[b] = t
                        ++i
                        b = size - 1
                        while (i < b) {
                            t = a[i]
                            a[i] = a[b]
                            a[b] = t
                            ++i
                            --b
                        }
                        return true
                    }
                    --b
                }
            }
            --i
        }
        return false
    }

    fun forEach(block: (x: Boolean) -> Unit) {
        for (i in 0 until size) {
            block(a[i])
        }
    }

    fun forEachIndexed(block: (i: Int, x: Boolean) -> Unit) {
        for (i in 0 until size) {
            block(i, a[i])
        }
    }

    fun getArray(): BooleanArray {
        return a.copyOf(size)
    }

    private fun ensureCapacity() {
        if (size == a.size) {
            a = a.copyOf(size * 2)
        }
    }
}