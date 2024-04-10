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
        int m = nextInt();
        int k = nextInt();
        int R = 0;
        int L = 1;
        int D = 2;
        int U = 3;
        int[] dx = new int[] {0, 0, 1, -1};
        int[] dy = new int[] {1, -1, 0, 0};
        int[][] c = new int[m][n];
        int[] ans = new int[m];
        for (int i = 0; i < n; i++) {
            char[] s = next().toCharArray();
            for (int j = 0; j < m; j++) {
                int dir;
                switch (s[j]) {
                    case 'U': dir = U; break;
                    case 'D': dir = D; break;
                    case 'R': dir = R; break;
                    case 'L': dir = L; break;
                    default: continue;
                }
//                int cx = i;
//                int cy = j;
//                for (int t = 0; t < n; t++) {
//                    if (cx == t) {
//                        c[cy][t]++;
//                    }
//                    cx += dx[dir];
//                    cy += dy[dir];
//                    if (cx >= n || cx < 0 || cy < 0 || cy >= m) {
//                        break;
//                    }
//                }
                if (dir == R) {
                    if (j + i < m) {
                        ans[i + j]++;
                    }
                } else if (dir == L) {
                    if (j - i >= 0) {
                        ans[j - i]++;
                    }
                } else if (dir == U) {
                    if (i % 2 == 0) {
                        ans[j]++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                ans[i] += c[i][j];
//            }
            print(ans[i]);
            print(" ");
        }

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