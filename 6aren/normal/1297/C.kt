private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt();
    while (t > 0) {
        t--;
        var n = readInt();
        var a = readInts();
        var check = Array(n, {i -> 0});
        var negId = -1;
        var posId = -1;
        var negMx = -1000000000;
        var posMn = 1000000000;
        var ans = 0;
        for (i in 0..n-1) {
            if (a[i] < 0 && a[i] > negMx) {
                negMx = a[i];
                negId = i;
            }
            if (a[i] > 0) {
                ans += a[i];
                check[i] = 1;
            }
            if (a[i] > 0 && a[i] < posMn) {
                posMn = a[i];
                posId = i;
            }
        }
        if (negMx + posMn > 0) {
            ans += negMx;
            check[negId] = 1;
        } else {
            ans -= posMn;
            check[posId] = 0;
        }
        println(ans);
        for (i in 0..n-1){
            print(check[i]);
        }
        print('\n');
    }
}