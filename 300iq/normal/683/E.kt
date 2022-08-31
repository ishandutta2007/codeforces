fun main(args:Array<String>) {
    val n = readLine()!!.toInt();
    val a = IntArray(n);
    val ans = IntArray(n);
    val b = IntArray(n);
    val d = readLine()!!.split(' ');
    for (i in 0 .. n - 1) {
        a[i] = d[i].toInt();
        b[i] = 0;
    }
    for (i in 0 .. n - 1) {
        val k = n - 1 - i;
        val pos = a[k];
        for (j in k + 1 .. n - 1) {
            if (b[j] >= pos) {
                b[j]++;
            }
        }
        b[k] = pos;
    }
    for (i in 0 .. n - 1) {
        ans[b[i]] = i + 1;
    }
    print(ans[0]);
    for (i in 1 .. n - 1) {
        print(' ');
        print(ans[i]);
    }
}