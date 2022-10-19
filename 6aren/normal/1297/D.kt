private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var ntest = readInt();
    while (ntest > 0) {
        ntest--;
        var (n, k) = readInts();
        var tmp = readLongs();
        var a = mutableListOf<Long>();
        var cur = 0;
        var id = Array<Long>(n, {i -> 0});
        var res = Array<Long>(n, {i -> 0});
        for (e in tmp) {
            a.add(e * 2000000000 + cur);
            cur++;
        }
        a.sort();
        for (i in 0..n-1) {
            id[i] = (a[i] % 2000000000);
            a[i] = a[i] / 2000000000;
        }
        var l = a[n - 1];
        var r = a[n - 1] + k;
        var ans : Long = 2000000000;
        while (r >= l) {
            var mid = (l + r) / 2;
            var tmp : Long = k.toLong();
            var check = 1;
            var sum : Long = mid;
            tmp -= (mid - a[n - 1]);
            for (i in n - 2 downTo 0) {
                sum--;
                tmp -= (sum - a[i]);
            }
            if (tmp > 0) check = 0;
            if (check == 1) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        for (i in n - 1 downTo 0) {
            var foo = ans - a[i];
            if (foo > k) {
                res[id[i].toInt()] = k.toLong();
                break;
            } else {
                res[id[i].toInt()] = foo;
            }
            ans--;
            k -= foo.toInt();
        }
        for (i in 0..n-1) {
            print(res[i]);
            print(' ');
        }
        println("");
    }
}