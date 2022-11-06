import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    void solve() throws IOException {
        int n = nextInt();
        long[] s1 = new long[2 * n - 1];
        long[] s2 = new long[2 * n - 1];
        int[][] a = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = nextIntArray(n);
            for (int j = 0; j < n; j++) {
                s1[i + j] += a[i][j];
                s2[i + n - 1 - j] += a[i][j];
            }
        }
        int ax = -1;
        int ay = -1;
        long am = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i % 2; j < n; j += 2) {
                long t = s1[i + j] + s2[i + n - 1 - j] - a[i][j];
                if (t > am) {
                    am = t;
                    ax = i;
                    ay = j;
                }
            }
        }
        int bx = -1;
        int by = -1;
        long bm = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 1 - i % 2; j < n; j += 2) {
                long t = s1[i + j] + s2[i + n - 1 - j] - a[i][j];
                if (t > bm) {
                    bm = t;
                    bx = i;
                    by = j;
                }
            }
        }
        println(am + bm);
        printf("%d %d %d %d", ax + 1, ay + 1, bx + 1, by + 1);
    }

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
}