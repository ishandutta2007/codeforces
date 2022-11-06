import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    boolean hasRight(char c) {
        return "+->LUD".indexOf(c) != -1;
    }

    boolean hasLeft(char c) {
        return "+-<RUD".indexOf(c) != -1;
    }

    boolean hasUp(char c) {
        return "+|^LRD".indexOf(c) != -1;
    }

    boolean hasDown(char c) {
        return "+|vLRU".indexOf(c) != -1;
    }

    char[][] a;
    int n;
    int m;
    char[][] rot;

    char get(int x, int y, int d) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return '*';
        }
        return rot[a[x][y]][d];
    }

    void solve() throws IOException {
        rot = new char[256][];
        rot['+'] = "++++".toCharArray();
        rot['-'] = "-|-|".toCharArray();
        rot['|'] = "|-|-".toCharArray();
        rot['^'] = "^>v<".toCharArray();
        rot['>'] = ">v<^".toCharArray();
        rot['v'] = "v<^>".toCharArray();
        rot['<'] = "<^>v".toCharArray();
        rot['L'] = "LURD".toCharArray();
        rot['R'] = "RDLU".toCharArray();
        rot['U'] = "URDL".toCharArray();
        rot['D'] = "DLUR".toCharArray();
        rot['*'] = "****".toCharArray();


        n = nextInt();
        m = nextInt();
        a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }

        int sx = nextInt() - 1;
        int sy = nextInt() - 1;
        int ex = nextInt() - 1;
        int ey = nextInt() - 1;

        int[][][] b = new int[n][m][4];
        for (int[][] i : b) {
            for (int[] j : i) {
                Arrays.fill(j, inf);
            }
        }
        b[sx][sy][0] = 0;
        Queue<Integer> q = new ArrayDeque<>();
        q.add(sx);
        q.add(sy);
        q.add(0);

        while (!q.isEmpty()) {
            int vx = q.poll();
            int vy = q.poll();
            int d = q.poll();

            int x, y;

            x = vx + 1;
            y = vy;
            if (hasDown(get(vx, vy, d)) && hasUp(get(x, y, d)) && b[x][y][d] > b[vx][vy][d] + 1) {
                b[x][y][d] = b[vx][vy][d] + 1;
                q.add(x);
                q.add(y);
                q.add(d);
            }

            x = vx - 1;
            y = vy;
            if (hasUp(get(vx, vy, d)) && hasDown(get(x, y, d)) && b[x][y][d] > b[vx][vy][d] + 1) {
                b[x][y][d] = b[vx][vy][d] + 1;
                q.add(x);
                q.add(y);
                q.add(d);
            }

            x = vx;
            y = vy + 1;
            if (hasRight(get(vx, vy, d)) && hasLeft(get(x, y, d)) && b[x][y][d] > b[vx][vy][d] + 1) {
                b[x][y][d] = b[vx][vy][d] + 1;
                q.add(x);
                q.add(y);
                q.add(d);
            }

            x = vx;
            y = vy - 1;
            if (hasLeft(get(vx, vy, d)) && hasRight(get(x, y, d)) && b[x][y][d] > b[vx][vy][d] + 1) {
                b[x][y][d] = b[vx][vy][d] + 1;
                q.add(x);
                q.add(y);
                q.add(d);
            }

            int nd = (d + 1) % 4;

            if (b[vx][vy][nd] > b[vx][vy][d] + 1) {
                b[vx][vy][nd] = b[vx][vy][d] + 1;
                q.add(vx);
                q.add(vy);
                q.add(nd);
            }
        }

        int ans = b[ex][ey][0];
        for (int i = 1; i < 4; i++) {
            ans = min(ans,  b[ex][ey][i]);
        }

        println(ans == inf ? -1 : ans);
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