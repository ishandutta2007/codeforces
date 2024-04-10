fun main(args: Array<String>) {
  val X2 = readLine() ?. toInt() ?: return

  val C = 1000000
  val mxp = IntArray(C+5) { -1 }
  for(i in 2 .. C) {
    if(mxp[i] == -1) {
      for(j in i .. C step i) {
        mxp[j] = i
      }
    }
  }

  val a = X2 - mxp[X2]
  val b = (X2 - mxp[X2] + 1 .. X2).filter({ mxp[it] != it }).map { it - mxp[it] }.min() ?: return
  println(Math.min(a, b) + 1)
}