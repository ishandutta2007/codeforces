import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Item implements Comparable<Item> {
        int b, c, id;

        public Item(int b, int c, int id) {
            this.b = b;
            this.c = c;
            this.id = id;
        }

        @Override
        public int compareTo(Item o) {
            return Integer.compare(b, o.b);
        }
    }

    class Bug implements Comparable<Bug> {
        int a, id;

        public Bug(int a, int id) {
            this.a = a;
            this.id = id;
        }

        @Override
        public int compareTo(Bug o) {
            return Integer.compare(a, o.a);
        }
    }

    int n, m, s;
    Bug[] a;
    Item[] st;
    int[] ans;

    boolean can(int d) {
        int cs = (n + d - 1) / d;
        if (cs > m) {
            return false;
        }
        int step = d;
        Queue<Item> q = new PriorityQueue<>((a, b) -> Integer.compare(a.c, b.c));
        int curb = n - 1;
        int curs = m - 1;
        int sumC = 0;
        for (int i = 0; i < cs; i++) {
            while (curs >= 0 && st[curs].b >= a[curb].a) {
                q.add(st[curs]);
                curs--;
            }
            if (q.isEmpty()) {
                return false;
            }
            Item it = q.poll();
            sumC += it.c;
            if (sumC > s) {
                return false;
            }
            for (int j = 0; j < step && curb >= 0; j++, curb--) {
                ans[a[curb].id] = it.id;
            }
        }

        return true;
    }

    void solve() throws IOException {
        m = nextInt();
        n = nextInt();
        s = nextInt();
        a = new Bug[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Bug(nextInt(), i);
        }
        Arrays.sort(a);
        int[] b = nextIntArray(m);
        int[] c = nextIntArray(m);
        st = new Item[m];
        for (int i = 0; i < m; i++) {
            st[i] = new Item(b[i], c[i], i);
        }
        Arrays.sort(a);
        Arrays.sort(st);

        ans = new int[n];

        int l = 0, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (r == n + 1) {
            println("NO");
        } else {
            println("YES");
            can(r);
            for (int i : ans) {
                print(i + 1);
                print(" ");
            }
        }
    }

    BufferedReader in;
    StringTokenizer stok;

    Main() {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String fileIn, String fileOut) throws IOException {
        super(fileOut);
        in = new BufferedReader(new FileReader(fileIn));
    }

    public static void main(String[] args) throws IOException {
        Main main;
        if ("_std".equals(IO)) {
            main = new Main();
        } else if ("_iotxt".equals(IO)) {
            main = new Main("input.txt", "output.txt");
        } else {
            main = new Main(IO + ".in", IO + ".out");
        }
        main.solve();
        main.close();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
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
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArraySorted(int len) throws IOException {
        int[] a = nextIntArray(len);
        shuffle(a);
        Arrays.sort(a);
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    void shuffleAndSort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int n) {
        List<T>[] res = new List[n];
        for (int i = 0; i < n; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }

    void println(Object... a) {
        for (int i = 0; i < a.length; i++) {
            if (i != 0) {
                print(" ");
            }
            print(a[i]);
        }
        println();
    }
}