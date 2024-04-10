/**
  * Created by netman on 3/4/17.
  */
object Main {
  def main(args: Array[String]): Unit = {
    val lines = io.Source.fromInputStream(System.in).getLines().toArray
    val n = lines(0).toInt
    val arr = lines(1).split(" ").map(_.toInt)
    println((arr.max + arr.min) / 2)
  }
}