import scala.collection.mutable.TreeSet
import scala.collection.mutable.ArrayBuffer

/**
  * Created by netman on 3/4/17.
  */
object Main {
  def main(args: Array[String]): Unit = {
    val lines = io.Source.fromInputStream(System.in).getLines().toArray
    val n = lines(0).toInt
    val arr = lines(1).split(" ").map(_.toInt)
    val s = TreeSet()(Ordering.by[Int, (Int, Int)](x => (arr(x), x)).reverse)
    (0 until n).foreach(s.add)
    val res = ArrayBuffer.empty[(Int, Int)]
    def dfs(v: Int): Unit = {
      s.remove(v)
      for (x <- 0 until arr(v)) {
        if (s.nonEmpty) {
          val to = s.firstKey
          res += ((v, to))
          dfs(to)
        }
      }
    }
    dfs(0)
    if (s.nonEmpty) {
      println("-1")
    } else {
      println(res.size)
      for ((x, y) <- res) {
        println((x + 1) + " " + (y + 1))
      }
    }
  }
}