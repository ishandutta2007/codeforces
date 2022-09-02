import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() }// list of ints

fun square(a: Int) : Int
{
    return a*a
}

fun main() {
    var n : Int = readInt()
    var a : IntArray = readInts().toIntArray()
    for (i in 0..(n-1)){
        a[i]%=2
        if (a[i]!=0)
        {
            if (i!=n-1&&a[i+1]>0) a[i+1]-=1
            else
            {
                print("NO")
                return
            }
        }
    }
    print("YES")

}