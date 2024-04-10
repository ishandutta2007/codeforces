import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    List<Integer>[] g;
    List<Integer> ts = new ArrayList<>();
    boolean[] used;

    void dfs(int v) {
        used[v] = true;
        for (Integer i : g[v]) {
            if (!used[i]) {
                dfs(i);
            }
        }
        ts.add(v);
    }

    void solve() throws IOException {
        int n = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }

        char[] p = new char[26];
        for (int i = 0; i < 26; i++) {
            p[i] = (char) ('a' + i);
        }

        g = createAdjacencyList(26);

        for (int i = 0; i < n; i++) {
            char[] s = a[i];
            for (int j = i + 1; j < n; j++) {
                char[] t = a[j];
                int len = min(s.length, t.length);
                for (int k = 0; k < len; k++) {
                    if (s[k] != t[k]) {
                        g[s[k] - 'a'].add(t[k] - 'a');
//                        moveBefore(p, s[k], t[k]);
                        break;
                    }
                }
            }
        }
        used = new boolean[26];
        for (int i = 25; i >= 0; i--) {
            if (!used[i]) {
                dfs(i);
            }
        }
        for (int i = 0; i < 26; i++) {
            p[ts.get(25 - i)] = (char) (i + 'a');
        }


        String[] b = new String[n];
        for (int i = 0; i < n; i++) {
            char[] s = a[i];
            for (int j = 0; j < s.length; j++) {
                s[j] = p[s[j] - 'a'];
            }
            b[i] = String.valueOf(s);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (b[i].compareTo(b[i + 1]) > 0) {
                    println("Impossible");
                    return;
                }
            }
        }
        for (int i = 25; i >= 0; i--) {
            print((char) (ts.get(i) + 'a'));
        }
    }

    void moveBefore(char[] p, char x, char y) {
        int px = -1, py = -1;
        for (int i = 0; i < p.length; i++) {
            if (p[i] == x) {
                if (py == -1) {
                    return;
                }
                px = i;
            }
            if (p[i] == y) {
                py = i;
            }
        }
        for (int i = px; i > py; i--) {
            char _ = p[i];
            p[i] = p[i - 1];
            p[i - 1] = _;
        }
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

    class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
        A a;
        B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int aa = a.compareTo(o.a);
            return aa == 0 ? b.compareTo(o.b) : aa;
        }
    }
}