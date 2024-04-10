import java.io.PrintWriter
import java.util.StringTokenizer
import kotlin.system.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main() {
    var t = 1;
    for (test_num in 1..t) {
	val n = readInt()
	val strs = readStrings(2 * n - 2)
	val check = fun(s: String) {
	    val strs2 = listOf(
		(1..n - 1).map { s.subSequence(it, n).toString() },
		(1..n - 1).map { s.subSequence(0, it).toString() }
	    ).flatten()
	    if (strs.sorted() == strs2.sorted()) {
		var pref: BooleanArray = BooleanArray(n)
		for (el in strs) {
		    if ((el == s.subSequence(0, el.length).toString()) and !pref[el.length]) {
			pref[el.length] = true
			print('P')
		    } else {
			print('S')
		    }
		}
		println()
		exitProcess(0)
	    }
	}
	var lng: List<String> = strs.filter { it.length == n - 1 }
	check(lng[0] + lng[1][n - 2])
	check(lng[1] + lng[0][n - 2])
	assert(false)
	println("bruh")
    }
}