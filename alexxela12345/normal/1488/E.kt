import java.io.PrintWriter
import java.util.StringTokenizer
import java.util.Arrays

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

lateinit var tree: IntArray;

fun getMax(v: Int, l: Int, r: Int, ql: Int, qr: Int): Int {
	if ((l >= qr) or (ql >= r)) {
		return 0
	}
	if ((ql <= l) and (r <= qr)) {
		return tree[v]
	}
	val m = (l + r) / 2
	return maxOf(getMax(2 * v + 1, l, m, ql, qr), getMax(2 * v + 2, m, r, ql, qr))
}

fun update(v: Int, l: Int, r: Int, i: Int, x: Int) {
	if ((i < l) or (i >= r)) {
		return
	}
	if (l + 1 == r) {
		tree[v] = x
		return
	}
	val m = (l + r) / 2
	update(2 * v + 1, l, m, i, x)
	update(2 * v + 2, m, r, i, x)
	tree[v] = maxOf(tree[2 * v + 1], tree[2 * v + 2])
}

fun main() {
    output {
		var t = readInt();
		for (test_num in 1..t) {
			val n = readInt()
			var arr = readInts(n).map { x: Int -> x - 1 }
			var right = IntArray(n) { -1 }
			var was: MutableMap<Int, Int> = mutableMapOf()
			for (i in n - 1 downTo 0) {
				if (arr[i] in was) {
					right[i] = was[arr[i]]!!
				}
				was[arr[i]] = i
			}
			tree = IntArray(4 * n)
			var ans = IntArray(n)
			var maxAns = 1
			for (i in 0..n - 1) {
				if (right[i] != -1) {
					// println("get: " + 0 + " " + 0 + " " + n + " " + right[i] + " " + n)
					ans[i] = getMax(0, 0, n, right[i], n) + 2
					maxAns = maxOf(maxAns, ans[i])
					if (arr[i + 1] != arr[i])  {
						maxAns = maxOf(maxAns, ans[i] + 1)
					}
					// println("upd: " + 0 + " " + 0 + " " + n + " " + right[i] + " " + ans[i])
					update(0, 0, n, right[i], ans[i])
				}
			}
			// println(Arrays.toString(ans))
			println(maxAns)
		}
    }
}