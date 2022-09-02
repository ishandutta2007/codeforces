private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun square(a: Int) : Int
{
    return a*a
}

fun main() {
    var n = readInt()
    var t: Int
    for (i in 0..(n-1))
    {
        t = readInt()
        println(t/2)
    }
}