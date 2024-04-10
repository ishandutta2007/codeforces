fun main(args:Array<String>) {
    val n = readLine()!!.toInt()
    val a = arrayOfNulls<String>(n)
    val b = IntArray(n);
    for (i in 0..n - 1) 
    {
        val(x, y) = readLine()!!.split(' ');
        a[i] = x;
        b[i] = y.toInt();
    }
    for (i in 0..n - 1) 
    {
        for (j in 0 .. n - 2) 
        {
            if (b[j] > b[j + 1]) 
            {
                val t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
                val c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
            }
        }
    }
    for (i in 0..n - 1)
    {
        println(a[i]);
    }
}