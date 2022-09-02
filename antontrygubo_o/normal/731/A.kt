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
    var s : String = readLn()
    s = 'a'+s
    var n = s.length
    var total = 0
    for (i in 0..(n-2))
    {
        var a = s[i]
        var b = s[i+1]
        if (a<b) a = b.also { b = a }
        total+=min(a.toInt()-b.toInt(), 26-(a.toInt()-b.toInt()))
    }
    print(total)

}