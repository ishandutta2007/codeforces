/**
 * Created by andrew on 15.5.14.
 */
import io.Source
import java.io.PrintWriter

object cf432a {

  def solve(in: In, out: PrintWriter) {
    val n = in().toInt
    val k = in().toInt
    val ans = in(n).map(x => x.toInt).filter(x => 5 - x >= k).size / 3
    out.print(ans)
  }


  def main(args: Array[String]) {
    new Thread(null, new Runnable {
      override def run(): Unit = {
        val in = new In(Source.fromInputStream(System.in))
        val out = new PrintWriter(System.out)
        solve(in, out)
        out.close()
      }
    }, "cf432a", 64000000).run()
  }

  class TokenIterator(iter: BufferedIterator[Char], delim: String) extends Iterator[String] {
    private val sb = new StringBuilder

    def hasNext: Boolean = {
      skipDelims()
      iter.hasNext
    }

    def skipDelims() = {
      while (iter.hasNext && delim.indexOf(iter.head) != -1) {
        iter.next()
      }
    }

    def next() = {
      skipDelims()

      while (iter.hasNext && delim.indexOf(iter.head) == -1) {
        sb.append(iter.next)
      }

      val ret = sb.toString()
      sb.clear()

      ret
    }
  }

  class In(source: Source) {
    val iter = source.buffered

    val tokenIter = new TokenIterator(iter, " \n\r");

    def apply() = tokenIter.next()

    def apply(n: Int) = tokenIter.take(n)
  }
}