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
        var foo = readInt();
        if (foo < 1000) {
            print(foo);
            print('\n');
            continue;
        }
        if (foo < 999500) {
            var u = foo / 1000;
            if (foo % 1000 >= 500) u++;
            print(u);
            print('K');
            print('\n');
            continue;
        }
        var u = foo / 1000000;
        if (foo % 1000000 >= 500000) u++;
        print(u);
        print('M');
        print('\n');
    }
}