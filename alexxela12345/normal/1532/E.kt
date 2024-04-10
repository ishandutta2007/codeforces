import java.io.PrintWriter
import java.util.StringTokenizer

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
	var arr = readInts(n)
	var arr2 = arr
	arr = arr.sorted()
	var sumAll: Long = 0L
	for (el in arr) {
	    sumAll += el
	}
	var cnt = 0
	var s: MutableSet<Int> = mutableSetOf()
	
	for (i in 0..n - 2) {
	    if (arr[n - 1].toLong() == sumAll - arr[n - 1] - arr[i]) {
		cnt++
		s.add(arr[i])
	    }
	}
	if (arr[n - 2].toLong() == sumAll - arr[n - 2] - arr[n - 1]) {
	    cnt++
	    s.add(arr[n - 1])
	}
	println(cnt)
	for (i in 0..n - 1) {
	    if (arr2[i] in s) {
		print(i + 1)
		print(' ')
	    }
	}
	println()
    }
}