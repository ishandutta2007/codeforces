fun main(args:Array<String>) {
    val s = readLine()!!;
    val p = IntArray(7);
    val len = s.length;
    p[5] = 0;
    p[6] = 1;
    for (i in 0 .. len - 1) {
        if (s[i] >= '0' && s[i] <= '9') {
            p[0] = p[0] * 10 + (s[i] - '0');
            if (p[3] == 0) {
                p[2] = p[2] * 10 + (s[i] - '0');
            }
            if (p[3] != 0) {
                p[5] = p[5] * 10 + 9;
            }
            if (p[3] == 0 && p[4] != 0) {
                p[6] = p[6] * 10;
            }
        }
        if (s[i] == '.') {
            p[4]++;
        }
        if (s[i] == '(') {
            p[3]++;
        }
    }
    val a = p[0] - p[2];
    val b = p[5] * p[6];
    val pq = IntArray(3);
    pq[0] = a;
    pq[1] = b;
    while (pq[0] != 0) {
        pq[2] = pq[0];
        pq[0] = pq[1] % pq[0];
        pq[1] = pq[2];
    }
    print(a / pq[1]);
    print('/');
    print(b / pq[1]);
}