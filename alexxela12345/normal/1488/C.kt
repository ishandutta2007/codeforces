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
			var (n, x, y) = readInts(3)
			if (y < x) {
				x = x xor y
				y = x xor y
				x = x xor y
			}
			var min_ans = 4 * n
			var calc = fun(n2: Int, x: Int): Int {
				return (n2 - 1) + minOf(x - 1, n2 - x)
			}

			
			
			for (i in x..y - 1) {
				// println("" + i + " " + x + " " + calc(i, x))
				// println("" + (n - i) + " " + (n + 1 - y) + " " + calc(n - i, n + 1 - y))
				// println()
				min_ans = minOf(min_ans, maxOf(calc(i, x), calc(n - i, n + 1 - y)))
			}
			println(min_ans)
			
		}
		
    }
}