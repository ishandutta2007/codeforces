import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int[][] s2;

    int getS2(int x1, int y1, int x2, int y2) {
        return s2[x2][y2] - s2[x1 - 1][y2] - s2[x2][y1 - 1] + s2[x1 - 1][y1 - 1];
    }

    boolean isOk(int x1, int y1, int x2, int y2) {
        return x1 <= x2 && y1 <= y2 && getS2(x1, y1, x2, y2) == 0;
    }

    int[][][][] s4;

    int getS4(int x1, int y1, int z1, int t1, int x2, int y2, int z2, int t2) {
        --x1;
        --y1;
        --z1;
        --t1;
        return s4[x2][y2][z2][t2] - s4[x1][y2][z2][t2] - s4[x2][y1][z2][t2] - s4[x2][y2][z1][t2] - s4[x2][y2][z2][t1]
                + s4[x1][y1][z2][t2] + s4[x1][y2][z1][t2] + s4[x1][y2][z2][t1] + s4[x2][y1][z1][t2] + s4[x2][y1][z2][t1] + s4[x2][y2][z1][t1]
                - s4[x1][y1][z1][t2] - s4[x1][y1][z2][t1] - s4[x1][y2][z1][t1] - s4[x2][y1][z1][t1] + s4[x1][y1][z1][t1];
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        s2 = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                s2[i][j] = s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1] + a[i - 1][j - 1] - '0';
            }
        }

        s4 = new int[n + 1][m + 1][n + 1][m + 1];
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                for (int z = 1; z <= n; z++) {
                    for (int t = 1; t <= m; t++) {
                        s4[x][y][z][t] = s4[x - 1][y][z][t] + s4[x][y - 1][z][t] + s4[x][y][z - 1][t] + s4[x][y][z][t - 1]
                                - s4[x - 1][y - 1][z][t] - s4[x - 1][y][z - 1][t] - s4[x - 1][y][z][t - 1]
                                - s4[x][y - 1][z - 1][t] - s4[x][y - 1][z][t - 1] - s4[x][y][z - 1][t - 1]
                                + s4[x - 1][y - 1][z - 1][t] + s4[x - 1][y - 1][z][t - 1] + s4[x - 1][y][z - 1][t - 1] + s4[x][y - 1][z - 1][t - 1]
                                - s4[x - 1][y - 1][z - 1][t - 1] + (isOk(x, y, z, t) ? 1 : 0);
                    }
                }
            }
        }

        while (q-- > 0) {
            int x1 = nextInt();
            int y1 = nextInt();
            int x2 = nextInt();
            int y2 = nextInt();
            println(getS4(x1, y1, x1, y1, x2, y2, x2, y2));
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