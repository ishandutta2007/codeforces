/*
naive problem
I don't want to write it !!!

*/
import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Long.min
import java.time.Clock
import java.util.*
import kotlin.math.max

class SegTreeMin(val gl: Int, val gr: Int, initF: ((Node, Int) -> Unit)? = null) {
  class Node {
    var tmin: Long = 0

    fun setX(x: Long) {
      tmin = x
    }

    fun update(cl: Int, cr: Int, l: Node, r: Node) {
      tmin = min(l.tmin, r.tmin)
    }
  }

  private val t = Array((gr - gl) * 4) { Node() }

  private fun update(c: Int, cl: Int, cr: Int) = t[c].update(cl, cr, t[c * 2 + 1], t[c * 2 + 2])

  private fun build(c: Int, cl: Int, cr: Int, initF: ((Node, Int) -> Unit)?) {
    if (cl + 1 == cr) {
      initF?.invoke(t[c], cl)
    } else {
      val mid = (cl + cr) / 2
      build(c * 2 + 1, cl, mid, initF)
      build(c * 2 + 2, mid, cr, initF)
      update(c, cl, cr)
    }
  }

  init {
    build(0, gl, gr, initF)
  }

  constructor(n: Int) : this(0, n)
  constructor(n: Int, initF: ((Node, Int) -> Unit)?) : this(0, n, initF)

  private fun getMin(l: Int, r: Int, c: Int, cl: Int, cr: Int): Long {
    if (cr <= l || r <= cl) return LINF
    if (l <= cl && cr <= r) {
      return t[c].tmin
    }
    val mid = (cl + cr) / 2
    return min(
      getMin(l, r, c * 2 + 1, cl, mid),
      getMin(l, r, c * 2 + 2, mid, cr)
    )
  }

  fun getMin(l: Int, r: Int): Long = getMin(l, r, 0, gl, gr)
}

const val LINF = 0x3f3f3f3f3f3f3f3fL

class SegTree2Min(val gl: Int, val gr: Int, initF: ((Node, Int) -> Unit)? = null) {
  class Node {
    var minA: Long = LINF
    var minB: Long = LINF
    var minAB: Long = LINF

    fun setAB(a: Long, b: Long) {
      minA = a
      minB = b
      minAB = a + b
    }

    fun update(l: Node, r: Node) {
      minA = min(l.minA, r.minA)
      minB = min(l.minB, r.minB)
      minAB = min(min(l.minAB, r.minAB), l.minA + r.minB)
    }
  }

  private val t = Array((gr - gl) * 4) { Node() }

  private fun update(c: Int, cl: Int, cr: Int) = t[c].update(t[c * 2 + 1], t[c * 2 + 2])

  private fun build(c: Int, cl: Int, cr: Int, initF: ((Node, Int) -> Unit)?) {
    if (cl + 1 == cr) {
      initF?.invoke(t[c], cl)
    } else {
      val mid = (cl + cr) / 2
      build(c * 2 + 1, cl, mid, initF)
      build(c * 2 + 2, mid, cr, initF)
      update(c, cl, cr)
    }
  }

  init {
    build(0, gl, gr, initF)
  }

  constructor(n: Int) : this(0, n)
  constructor(n: Int, initF: ((Node, Int) -> Unit)?) : this(0, n, initF)

  fun getLeaf(i: Int): Node {
    var c = 0
    var cl = gl
    var cr = gr
    while (cl + 1 != cr) {
      val mid = (cl + cr) / 2
      if (i < mid) {
        c = c * 2 + 1
        cr = mid
      } else {
        c = c * 2 + 2
        cl = mid
      }
    }
    return t[c]
  }

  private fun <R> withLeaf(i: Int, foo: (Node) -> R, c: Int, cl: Int, cr: Int): R {
    if (cl + 1 == cr) return foo(t[c])
    val mid = (cl + cr) / 2
    return if (i < mid) {
      withLeaf(i, foo, c * 2 + 1, cl, mid)
    } else {
      withLeaf(i, foo, c * 2 + 2, mid, cr)
    }.also {
      update(c, cl, cr)
    }
  }

  fun <R> withLeaf(i: Int, foo: (Node) -> R): R {
    return withLeaf(i, foo, 0, gl, gr)
  }

  private fun getMinAB(l: Int, r: Int, c: Int, cl: Int, cr: Int): Node? {
    if (cr <= l || r <= cl) return null
    if (l <= cl && cr <= r) {
      return t[c]
    }
    val mid = (cl + cr) / 2
    val n1 = getMinAB(l, r, c * 2 + 1, cl, mid)
    val n2 = getMinAB(l, r, c * 2 + 2, mid, cr)
    if (n1 == null) return n2
    if (n2 == null) return n1
    val tt = Node()
    tt.update(n1, n2)
    return tt
  }

  fun getMinAB(l: Int, r: Int) = getMinAB(l, r, 0, gl, gr)?.minAB ?: LINF
}

class MyReader(inputStream: InputStream) {
  private val reader = BufferedReader(InputStreamReader(inputStream))
  private var tokenizer: StringTokenizer? = null

  fun next(): String {
    while (true) {
      tokenizer.let {
        if (it == null || !it.hasMoreTokens()) {
          tokenizer = StringTokenizer(reader.readLine())
        } else {
          return it.nextToken()
        }
      }
    }
  }
}
val reader = MyReader(System.`in`)
fun next() = reader.next()
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextStrings(n: Int) = Array(n) { next() }
fun nextInts(n: Int) = IntArray(n) { nextInt() }
fun nextLongs(n: Int) = LongArray(n) { nextLong() }
fun nextDoubles(n: Int) = DoubleArray(n) { nextDouble() }

fun main() {
  val n = nextInt()
  val a = nextLongs(n - 1)
  val b = nextLongs(n - 1)
  val c = nextLongs(n)
  val cs = LongArray(n + 1) { 0 }
  for (i in 0 until n) cs[i + 1] = cs[i] + c[i]

  val st2 = SegTree2Min(n - 1) { it, i -> it.setAB(a[i] - cs[i + 1], b[i] + cs[i + 1]) }
  val st3 = SegTree2Min(n - 1) { it, i -> it.setAB(b[i] - cs[i + 1], a[i] + cs[i + 1]) }
  val st4 = SegTreeMin(n - 1) { it, i -> it.setX(a[i] - cs[i + 1]) }
  val st5 = SegTreeMin(n - 1) { it, i -> it.setX(a[i] + cs[i + 1]) }

  (0 until nextInt()).map {
    var l = nextInt() - 1
    var r = nextInt() - 1
    if (l > r) l = r.also { r = l }
    if (l == r) r = n - 1
    var ans = LINF
    ans = min(ans, st2.getMinAB(l, r))
    ans = min(ans, st3.getMinAB(l, r))
    ans = min(ans, st4.getMin(l, r) + cs[r + 1])
    ans = min(ans, st5.getMin(l, r) - cs[l])
    ans
  }.joinToString(" ").let { println(it) }
}