fun main(args:Array<String>) {
    val n = readLine()!!.toInt();
    for (i in 0 .. n - 1) {
        val (n, m, p) = readLine()!!.split(' ').map(String::toInt);
        val good = IntArray(1);
        for (j in 1 .. p) {
            if (p % j == 0 && ((j <= n && p / j <= m) || (j <= m && p / j <= n))) {
                good[0]++;
            }
        }
        if (good[0] >= 1) {
            println("Yes");
        } else {
            println("No");
        }
    }
}