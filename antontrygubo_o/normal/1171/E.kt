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

    var n = readInt()
    if (n==1)
    {
        print("Yes")
        return
    }
    var s : String = readLn()
    var kek : CharArray = s.toCharArray()
    kek.sort()
    for (i in 0..(n-2))
    {
        if (kek[i]==kek[i+1])
        {
            print("Yes")
            return
        }
    }
    print("No")
}