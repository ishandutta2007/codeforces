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
        char[] s = next().toCharArray();
        char[] t = next().toCharArray();
        long[][] l = new long[26][n];
        long[][] r = new long[26][n];
        for (int i = 0; i < n; i++) {
            l[s[i] - 'A'][i] += i + 1;
            r[s[i] - 'A'][i] += n - i;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < n; j++) {
                l[i][j] += l[i][j - 1];
            }
            for (int j = n - 2; j >= 0; j--) {
                r[i][j] += r[i][j + 1];
            }
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            int c = t[i] - 'A';
            res += 1.0 * l[c][i] * (n - i);
            if (i + 1 < n) {
                res += 1.0 * (i + 1) * r[c][i + 1];
            }
//            if (s[i] == t[i]) {
//                res -= 1;
//            }
        }
        res /= 1L * n * (n + 1) * (2 * n + 1) / 6;
        printf("%.11f", res);
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
        } else if ("_iodef".equals(IO)) {
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