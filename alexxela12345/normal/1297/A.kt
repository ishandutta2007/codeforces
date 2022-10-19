import kotlin.math.max
import kotlin.math.min
import kotlin.random.Random
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong();
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() }
 
fun main() {
    val n = readInt();
    for (i in 0 until n) {
        val x = readInt();
        if (x < 1000) {
            print(x);
            print('\n')
        } else if (x < 999500) {
            print((x + 500) / 1000);
            print("K\n");
        } else {
            print((x + 500000) / 1000000);
            print("M\n");
        }
    }
}