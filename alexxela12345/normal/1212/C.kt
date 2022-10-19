import kotlin.math.max
import kotlin.math.min
import kotlin.random.Random

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun rand(a: Int, b: Int): Int {
    return Random.nextInt(a, b);
}

fun quickSort(arr: IntArray, l: Int, r: Int, k: Int): Int {
    if (l == r) {
        return arr[l];
    }
    val piv = rand(l, r);
    val arr2 = IntArray(r - l + 1);
    var ll = 0;
    var rr = r - l;
    for (i in l..r) {
        if (i == piv) {
            continue;
        }
        if (arr[i] <= arr[piv]) {
            arr2[ll] = arr[i];
            ll++;
        } else {
            arr2[rr] = arr[i];
            rr--;
        }
    }
    arr2[ll] = arr[piv];
    for (i in l..r) {
        arr[i] = arr2[i - l];
    }
    ll += l;
    rr += r;
    if (k == ll) {
        return arr2[ll - l];
    }
    if (k < ll) {
        return quickSort(arr2.slice(0..ll - 1 - l).toIntArray(), 0, ll - 1 - l, k - l);
    }
    return quickSort(arr2.slice(ll + 1 - l..r - l).toIntArray(), 0, r - ll - 1, k - (ll + 1));
}

fun solve0(n: Int, k: Int, arr: IntArray): Int {
    if (k == n) {
        var max_v = arr[0];
        for (i in 1..n - 1) {
            max_v = max(max_v, arr[i]);
        }
        return max_v;
    }
    if (k == 0) {
        var min_v = arr[0];
        for (i in 1..n - 1) {
            min_v = min(min_v, arr[i]);
        }
        if (min_v != 1) {
            return min_v - 1;
        }
        return -1;
    }
    val ans1 = quickSort(arr, 0, n - 1, k - 1);
    val ans2 = quickSort(arr, 0, n - 1, k);
    return if (ans1 != ans2) {
        ans1;
    } else {
        -1;
    }
}

fun solve2(n: Int, k: Int, arr: IntArray): Int {
    arr.sort();
    if (k == n) {
        return arr[n - 1];
    }
    var k1 = k;
    k1--;
    if (k1 == -1) {
        if (arr[0] != 1) {
            return arr[0] - 1;
        }
        return -1;
    }
    if (arr[k1] != arr[k1 + 1]) {
        return arr[k1];
    }
    return -1;
}

fun stress() {
    Random(179);
    var seed = rand(0, 100000000);
    while (true) {
        Random(seed);
        val n = rand(1, 10);
        val k = rand(0, n);
        val arr = (List(n) { rand(1, 50); }).toIntArray();
        Random(179);
        if (solve0(n, k, arr.clone()) != solve2(n, k, arr.clone())) {
            println(n.toString() + " " + k.toString());
            for (i in arr) {
                print(i);
                print(' ');
            }
            println();
            println(arr);
            break;
        }
        Random(seed);
        seed = rand(0, 100000000);
    }
}

fun runFast() {
    Random(179);
    val (n, k) = readInts();
    val arr = readInts().toIntArray();
    println(solve0(n, k, arr));
}

fun runSlow() {
    val (n, k) = readInts();
    val arr = readInts().toIntArray();
    println(solve2(n, k, arr));
}

fun main() {
//    stress();
    runFast();
//    runSlow();
}