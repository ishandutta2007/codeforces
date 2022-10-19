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
    output {
		var t = readInt();
		for (test_num in 1..t) {
			val (n, s) = readLongs(2)
			var l = (s + n - 1) / n
			var r = s + 1
			while (r - l > 1) {
				val m = (l + r) / 2
				var cur = m
				var sum = 0L
				for (i in 0..n - 1) {
					sum += cur
					cur = (cur + 1) / 2
					if (cur == 1L) {
						sum += n - 1 - i
						break
					}
					if (sum > s) {
						break
					}
				}
				if (sum <= s) {
					l = m
				} else {
					r = m
				}
			}
			println(l)
		}
    }
}