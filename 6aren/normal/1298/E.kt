private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

const val N = 200005;

class Programmer {
    var x : Int = 0;
    var y : Int = 0;
}

class CompareByX {
    companion object : Comparator<Programmer> {
        override fun compare(o1: Programmer, o2: Programmer): Int {
            return (o1.x - o2.x);
        }
    }
}

var pro = mutableListOf<Programmer>();
var g = Array(200005, {i -> mutableListOf<Int>()});

fun main(args: Array<String>) {
    var (n, k) = readInts();
    var r = readInts();
    for (i in 1..k) {
        var (x, y) = readInts();
        x--;
        y--;
        g[x].add(y);
        g[y].add(x);
    }
    for (i in 0..n-1) {
        var tmp = Programmer();
        tmp.x = r[i];
        tmp.y = i;
        pro.add(tmp);
    }
    pro.sortWith(CompareByX);
    var ans = Array(n, {i -> 0});
    var cnt = 0;
    var cur = 0;
    while (cur < n) {
        // println(cur);
        var foo = cur;
        var baz = cnt;
        for (e in g[pro[foo].y]) {
            if (r[e] < pro[foo].x) baz--;
        }
        ans[pro[foo].y] = baz;
        while (foo < n - 1 && pro[foo + 1].x == pro[foo].x) {
            foo++;
            baz = cnt;
            for (e in g[pro[foo].y]) {
                if (r[e] < pro[foo].x) baz--;
            }
            ans[pro[foo].y] = baz;
        }
        cnt += foo - cur + 1;
        cur = ++foo;
    }
    for (i in 0..n-1) {
        print(ans[i]);
        print(' ');
    }
}