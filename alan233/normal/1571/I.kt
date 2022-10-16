import java.util.*

fun readInt() = readLine()!!.toInt()
fun readInts() = readLine()!!.split(' ').map { it.toInt() }.toIntArray()

fun main() {
  var T = readInt()
  repeat(T) {
    val n = readInt()
    val l = readInts()
    val r = readInts()
    var sL = l.sortedBy { it }
    var sR = r.sortedBy { it }
    var L = 1
    var R = 1000000000
    for (i in 0 until n) {
      L = maxOf(L, sL[i] - i)
      R = minOf(R, sR[i] - i)
    }
    val ans = mutableListOf<Int>()
    val g = Array(n) { mutableListOf<Int>() }
    for (i in 0 until n) {
      g[maxOf(l[i] - L, 0)].add(i)
    }
    var ok = 1
    val pq = PriorityQueue<Long>()
    var sz = 0
    for (i in 0 until n) {
      for (j in g[i]) {
        pq.add(n.toLong() * r[j] + j)
        sz += 1
      }
      if (sz < i + 1) {
        break
      }
      val it = (pq.poll() % n.toLong() + 1).toInt()
      ans.add(it.toInt())
      if ((l[it - 1] > L + i) or (r[it - 1] < L + i)) {
        ok = 0
        break
      }
    }
    if ((sz != n) or (ok == 0)) {
      println(-1)
    } else {
      println("${L}") 
      for (i in ans) {
        print("${i} ")
      } 
      println()
    }
  }
}