import kotlin.math.max
import kotlin.math.min
import kotlin.random.Random

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong();
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() }

fun count(n: Long): Pair<Int, Int> {
    var nn = n;
    var a = 0;
    var b = 0;
    while (nn % 3 == 0L) {
        a -= 1;
        nn /= 3;
    }
    while (nn % 2 == 0L) {
        b += 1;
        nn /= 2;
    }
    return Pair<Int, Int>(a, b);
}

fun main() {
    val n = readInt();
    val arr = readLongs();
    var max_ind = 0;
    for (i in 1 until n) {
        val xx = count(arr[max_ind]);
        val xxx = count(arr[i]);
        if (xx.first > xxx.first) {
            max_ind = i;
        } else if (xx.first == xxx.first && xxx.second < xx.second) {
            max_ind = i;
        }
    }
    while (true) {
        print(arr[max_ind]);
        print(' ');
        var found = false;
        for (i in 0 until n) {
            if (arr[max_ind] % 3 == 0L && arr[max_ind] / 3 == arr[i]) {
                max_ind = i;
                found = true;
                break;
            } else if (2 * arr[max_ind] == arr[i]) {
                max_ind = i;
                found = true;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
}