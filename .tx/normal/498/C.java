import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    class Item {
        int p, id;
        List<Item> to = new ArrayList<>();

        public Item(int p, int id) {
            this.p = p;
            this.id = id;
        }
    }

    boolean[] used;
    Item[] back;

    boolean kuhn(Item v) {
        if (used[v.id]) {
            return false;
        }
        used[v.id] = true;
        for (Item to : v.to) {
            if (back[to.id] == null || kuhn(back[to.id])) {
                back[to.id] = v;
                return true;
            }
        }
        return false;
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        List<Item>[] byNum = createAdjacencyList(n);
        int ids = 0;
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0) {
                    x /= j;
                    byNum[i].add(new Item(j, ids++));
                }
            }
            if (x > 1) {
                byNum[i].add(new Item(x, ids++));
            }
        }
        while (m-- > 0) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            if (x % 2 == 1) {
                int _ = x;
                x = y;
                y = _;
            }
            for (Item itX : byNum[x]) {
                for (Item itY : byNum[y]) {
                    if (itX.p == itY.p) {
                        itX.to.add(itY);
                    }
                }
            }
        }
        used = new boolean[ids];
        back = new Item[ids];
        for (int i = 0; i < n; i += 2) {
            for (Item item : byNum[i]) {
                Arrays.fill(used, false);
                kuhn(item);
            }
        }
        int ans = 0;
        for (Item item : back) {
            if (item != null) {
                ans++;
            }
        }
        println(ans);
    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    boolean nextPerm(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
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
        return false;
    }

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}