import java.util.PriorityQueue
import java.util.Queue

fun main(args: Array<String>) {
  val N = readLine() ?. toInt() ?: return
  val V = readLine() ?. split(" ") ?. map { it.toLong() } ?: return
  val T = readLine() ?. split(" ") ?. map { it.toLong() } ?: return
  
  val pq: Queue<Long> = PriorityQueue<Long>()
  val ans = LongArray (N) { 0 }
  var sumt = 0L
  for(i in 0 until N) {
    var ret = 0L

    pq.add(V[i] + sumt)
    while(!pq.isEmpty() && pq.peek() - sumt <= T[i]) {
      ret = ret + (pq.poll() - sumt)
    }

    sumt = sumt + T[i]
    ans[i] = ret + pq.size.toLong() * T[i]
  }

  println(ans.joinToString(" "))
}