import java.util.TreeSet

fun main(args: Array<String>) {
  val N = readLine() ?. toInt() ?: return
  val A = readLine() ?. split(" ") ?. map { it.toInt() } ?: return
  val P = readLine() ?. split(" ") ?. map { it.toInt() } ?. sorted() ?: return

  val par = IntArray(N+10) { it }
  fun get(x: Int): Int {
    if(x == par[x]) return x
    
    val v = generateSequence(x, { par[it].takeIf { it != par[it] }})
    val p = par[v.last()]
    for(u in v) par[u] = p
    return p
  }

  fun lb(x: Int): Int {
    var ret = N
    var low = 0
    var high = N-1
    while(low <= high) {
      val mid = (low + high) shr 1
      if(P[mid] >= x) {
        ret = mid
        high = mid - 1
      }else {
        low = mid + 1
      }
    }
    return ret
  }

  val ans = IntArray(N)
  for(i in 0 until N) {
    var ret = 0
    for(b in 29 downTo 0) {
      ret = ret xor (A[i] and (1 shl b))
      val x = get(lb(ret))
      if(x >= N || P[x] >= ret + (1 shl b)) {
        ret = ret xor (1 shl b)
      } 
    }
    ans[i] = ret xor A[i]

    val p = get(lb(ret))
    val q = get(p+1)
    if(p <= N+2)
      par[p] = q
  }
  
  println(ans.joinToString(" "))
  
}