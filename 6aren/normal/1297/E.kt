private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var g = Array(300005, {i -> ArrayList<Int>()});
var p = Array(300005, {i -> 0});

fun dfs(u : Int, v : Int) {
    p[u] = v;
    for (e in g[u]) {
        if (e == v) continue;
        dfs(e, u);
    }
}

fun dfs2(u : Int, v : Int) : Int {
    if (g[u].size == 1) return u;
    for (e in g[u]) {
        if (e == v) continue;
        return dfs2(e, u);
    }
    return 0;
}

fun main(args: Array<String>) {
    var ntest = readInt();
    while (ntest > 0) {
        ntest--;
        var (n, k) = readInts();
        for (i in 1..n) {
            g[i].clear();
        }
        for (i in 1..n - 1) {
            var (u, v) = readInts();
            g[u].add(v);
            g[v].add(u);
        }
        if (n == 2) {
            if (k == 1) {
                println("Yes");
                println(1);
                println(1);
            }
            else {
                print("Yes\n");
                print("2\n");
                print("1 2\n");
            }
            continue;
        }
        var root = 0;
        var leaf = mutableListOf<Int>();
        var check = Array(n + 5, {i -> 0});
        for (i in 1..n) {
            if (g[i].size > 1) root = i;
        }
        var a = dfs2(g[root][0], root);
        var b = dfs2(g[root][1], root);
        leaf.add(a);
        leaf.add(b);
        if (k == 1) {
            println("Yes");
            println(1);
            println(1);
            continue;
        }
        for (i in 1..n) {
            if (g[i].size == 1 && i != a && i != b) {
                if (leaf.size < k) leaf.add(i);
            }
        }
        if (leaf.size < k) {
            println("No");
            continue;
        }
        dfs(root, 0);
        for (e in leaf) {
            var foo = e;
            while (foo != 0) {
                check[foo] = 1;
                foo = p[foo];
                if (check[foo] == 1) break;
            }
        }

        var count = 0;
        for (i in 1..n) {
            if (check[i] == 1) count++;
        }
        println("Yes");
        println(count);
        for (i in 1..n) {
            if (check[i] == 1) {
                print(i);
                print(' ');
            }
        }
        println();
    }
}