import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun square(a: Int) : Int
{
    return a*a
}

fun main() {

    var t = readInt()

    for (j in 0..(t-1)) {
        var s: String = readLn()
        val n = s.length
        var lol: CharArray = s.toCharArray()
        lol.sort()
        if (lol[0] == lol[n - 1]) println("-1")
        else {
            for (i in lol) print(i)
            print("\n")
        }
    }
}