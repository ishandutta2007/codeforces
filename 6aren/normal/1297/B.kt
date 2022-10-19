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
        var list = mutableListOf<Int>();
        var n = readInt();
        for (i in 1..n) {
            var (u, v) = readInts();
            list.add(u * 2);
            list.add((v + 1) * 2 + 1);
        }
        list.sort();
        var cur = 0;
        var cnt = 0;
        var flag = false;
        while (cur < 2 * n) {
            while (cur < 2 * n - 1 && list[cur + 1] / 2 == list[cur] / 2) {
                if (list[cur] % 2 == 0) cnt++;
                else cnt--;
                cur++;
            }
            if (list[cur] % 2 == 0) cnt++;
            else cnt--;
            if (cnt == 1) {
                flag = true;
                println(list[cur] / 2);
                break;
            }
            cur++;
        }
        if (flag == false) println("-1");
    }
}