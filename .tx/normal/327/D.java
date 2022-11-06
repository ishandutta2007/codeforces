import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int n, m;
    char[][] a;

//    List<String> ops = new ArrayList<>();
    StringBuilder ans = new StringBuilder();
    int ansK = 0;

    int[] dx = new int[] {1, -1, 0, 0};
    int[] dy = new int[] {0, 0, 1, -1};

    void op(String s, int x, int y) {
        ansK++;
        ans.append(s);
        ans.append(" ");
        ans.append(x + 1);
        ans.append(" ");
        ans.append(y + 1);
        ans.append("\n");
    }

    void opb(int x, int y) {
        op("B", x, y);
    }

    void opd(int x, int y) {
        op("D", x, y);
    }

    void opr(int x, int y) {
        op("R", x, y);
    }

    void dfs(int x, int y, int sx, int sy) {
        opb(x, y);
        a[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') {
                continue;
            }
            dfs(nx, ny, sx, sy);
        }
        if (x != sx || y != sy) {
            opd(x, y);
            opr(x, y);
        }
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }//
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '#') {
                    dfs(i, j, i, j);
                }
            }
        }
        println(ansK);
        println(ans);
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
}//