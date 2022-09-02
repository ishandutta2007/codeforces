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

    var (a, b, c) = readInts()
    var (x, y, z) = readInts()

    if (a>x)
    {
        print("NO")
        return
    }
    y+=(x-a)
    if (b>y)
    {
        print("NO")
        return
    }
    z+=(y-b)
    if (c>z)
    {
        print("NO")
        return
    }
    print("YES")
}