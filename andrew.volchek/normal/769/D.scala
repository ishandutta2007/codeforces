import scala.collection.mutable.ListBuffer
import scala.util.Random

/**
  * Created by netman on 3/4/17.
  */
object Main {
  def main(args: Array[String]): Unit = {
    val lines = io.Source.fromInputStream(System.in).getLines().toArray
    val Array(n, k) = lines(0).split(" ").map(_.toInt)
    val MaxValue = 1 << 14
    val cntBits = Array.ofDim[Int](MaxValue)
    for (i <- 1 until MaxValue) {
      cntBits(i) = cntBits(i >> 1) + (i & 1)
    }
    val rnd = new Random
    val arr = lines(1).split(" ").map(_.toInt)
    val cnt = Array.ofDim[Int](MaxValue)
    arr.foreach(cnt(_) += 1)
    if (k == 0) {
      var res = 0L
      for (i <- cnt.indices) {
        res += (cnt(i).toLong * (cnt(i) - 1).toLong) / 2
      }
      println(res)
    } else {
      val tmp = ListBuffer.empty[Int]
      for (mask <- cntBits.indices) {
        if (cntBits(mask) == k) tmp += mask
      }
      val lst = tmp.toArray
      var res = 0L
      for (mask <- cnt.indices) {
        if (cnt(mask) != 0) {
          for (other <- lst) {
            res += cnt(mask ^ other).toLong * cnt(mask).toLong
          }
        }
      }
      println(res / 2)
    }
  }
}