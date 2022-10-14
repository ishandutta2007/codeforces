import java.util.*
import kotlin.math.min
import kotlin.math.max
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readString() = readLn().toString()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }

fun main () {
    var t = readInt()
    while (t --> 0) {
        var s = readString()
        var cnt1 = 0
        var cnt2 = 0
        for (i in 0..s.length-1) {
            if (s[i] == '>')
                cnt1++;
            if (s[i] == '<')
                cnt2++;
        }
        if (cnt1 == 0 && cnt2 == 0)
            println("=")
        else if (cnt1 == 0)
            println("<")
        else if (cnt2 == 0)
            println(">")
        else
            println("?")
            
    }
}