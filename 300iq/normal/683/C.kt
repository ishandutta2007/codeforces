fun main(args:Array<String>) {
    val cnt = IntArray(3000);
    val res = arrayOfNulls<String>(1)
    val s = readLine()!!.split(' ');
    val len = s[0].toInt();
    for (i in 1 .. len) {    
        cnt[s[i].toInt() + 1001]++;
    }
    val s1 = readLine()!!.split(' ');
    val len1 = s1[0].toInt();
    for (i in 1 .. len1) {    
        cnt[s1[i].toInt() + 1001]++;
    }
    val p = IntArray(1);
    for (i in -1000 .. 1000) {
        if (cnt[i + 1001] == 1) {
            p[0]++;
        }
    }
    print(p[0]);
    for (i in -1000 .. 1000) {
        if (cnt[i + 1001] == 1) {
            print(' ');
            print(i);
        }
    }
}