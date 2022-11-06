import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    List<Integer>[] langsByMan;
    List<Integer>[] menByLang;

    boolean[] used;

    void dfs(int man) {
        used[man] = true;
        for (int lang : langsByMan[man]) {
            for (int toMan : menByLang[lang]) {
                if (!used[toMan]) {
                    dfs(toMan);
                }
            }
        }
    }

    void solve() throws IOException {
        int n = 3;
        int[][] a = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = nextIntArray(n);
        }
        f1:
        for (int t = 1; t <= 100000; t++) {
            int s = t + a[0][1] + a[0][2];
            a[0][0] = t;
            a[1][1] = s - a[1][0] - a[1][2];
            a[2][2] = s - a[2][0] - a[2][1];
            if (a[1][1] <= 0 || a[2][2] <= 0) {
                continue;
            }
            if (a[0][0] + a[1][1] + a[2][2] != s || a[0][2] + a[1][1] + a[2][0] != s) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (a[0][i] + a[1][i] + a[2][i] != s) {
                    continue f1;
                }
            }
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                print(a[i][j] + " ");
            }
            println();
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
}