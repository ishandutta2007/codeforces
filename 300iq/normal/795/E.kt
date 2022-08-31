fun main(args:Array<String>) {
    val s = readLine()!!;
    val m = readLine()!!.toInt();
    val n = s.length;
    val p = IntArray(n + n);
    val pw = IntArray(n + n);
    for (i in 0 .. n + n - 1)
    {
        val t = i % n;
        if (i != 0)
        {
            pw[i] = (pw[i - 1] * 10) % m;
            p[i] = (p[i - 1] * 10);
            p[i] = (p[i] + (s[t] - '0')) % m;
        }
        else
        {
            pw[i] = 1;
            p[i] = (s[t] - '0') % m;
        }
    }
    val ans = IntArray(1);
    val res = IntArray(1);
    val kok = LongArray(1);
    ans[0] = m;
    for (i in 0 .. n - 1)
    {
        if (s[i] != '0')
        {
            val l = i;
            val r = i + n - 1;
            if (l == 0)
            {
                res[0] = p[r];
            }
            else
            {
                kok[0] = p[l - 1].toLong();
                kok[0] = kok[0] * pw[r - l + 1];
                kok[0] = kok[0] % m;
                res[0] = p[r] - kok[0].toInt();
                if (res[0] < 0)
                {
                    res[0] += m;
                }
            }
            if (res[0] < ans[0])
            {
                ans[0] = res[0];
            }
        }
    }
    print(ans[0])
}