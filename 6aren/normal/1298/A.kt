import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Arrays
import java.util.Scanner

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
fun main() {
    val inputStream = System.`in`
    val outputStream = System.out
    val `in` = Scanner(inputStream)
    val out = PrintWriter(outputStream)
    val solver = TaskA()
    solver.solve(1, `in`, out)
    out.close()
}

internal class TaskA {
    fun solve(testNumber: Int, `in`: Scanner, out: PrintWriter) {
        val a = IntArray(4)
        for (i in 0..3) {
            a[i] = `in`.nextInt()
        }
        Arrays.sort(a)
        for (i in 0..2) {
            out.print(a[3] - a[i])
            out.print(' ')
        }
    }

}