private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var n = readInt();
    var a = readInts();
    var check = Array(1001, {i -> 0});
    var ans = ArrayList<Int>();
    for (i in a.size - 1 downTo 0 step 1) {
        if (check[a[i]] > 0) continue;
        else {
            check[a[i]] = 1;
            ans.add(a[i]);
        }
    }
    println(ans.size);
    for (i in ans.size - 1 downTo 0 step 1) {
        print(ans[i]);
        print(' ');
    }
}