import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Item implements Comparable<Item> {
        int x, id;

        public Item(int x, int id) {
            this.x = x;
            this.id = id;
        }

        @Override
        public int compareTo(Item o) {
            return x == o.x ? id - o.id : x - o.x;
        }
    }

    void solve() throws IOException {
        TreeSet<Item>[] a = new TreeSet[3];
        for (int i = 0; i < 3; i++) {
            a[i] = new TreeSet<>();
        }
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            Item x = new Item(nextInt(), i);
            a[x.x % 3].add(x);
        }
        Item cur = a[0].pollFirst();
        if (cur.x != 0) {
            println("Impossible");
            return;
        }
        List<Integer> ans = new ArrayList<>();
        ans.add(cur.id);
        for (int i = 1; i < n; i++) {
            int nm = (cur.x + 1) % 3;
            Item x = a[nm].ceiling(cur);
            if (x == null || x.x != cur.x + 1) {
                x = a[nm].floor(cur);
            }
            if (x == null) {
                println("Impossible");
                return;
            }
            a[nm].remove(x);
            cur = x;
            ans.add(cur.id);
        }
        println("Possible");
        for (Integer i : ans) {
            print(i + 1);
            print(" ");
        }
    }

    public static void main(String[] args) throws IOException {
        try (Main main = new Main()) {
            main.solve();
        }
    }

    Main() throws IOException {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    <T> List<T>[] createAdjacencyList(int verticesNumber) {
        List<T>[] res = new List[verticesNumber];
        for (int i = 0; i < verticesNumber; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }
}