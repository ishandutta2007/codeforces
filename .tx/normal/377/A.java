import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = next().toCharArray();
        }
        int[][] b = new int[n][m];
        for (int[] i : b) {
            Arrays.fill(i, inf);
        }
        int sx = -1, sy = -1;
        ff:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '#') {
                    sx = i;
                    sy = j;
                    break ff;
                }
            }
        }
        Queue<Integer> q = new ArrayDeque<>();
        q.add(sx);
        q.add(sy);
        b[sx][sy] = 0;
        int[] dx = new int[] {1, -1, 0, 0};
        int[] dy = new int[] {0, 0, -1, 1};
        int max = 0;
        Map<Integer, List<Integer>> map = new HashMap<>();
        while (!q.isEmpty()) {
            int vx = q.poll();
            int vy = q.poll();
            for (int i = 0; i < 4; i++) {
                int x = vx + dx[i];
                int y = vy + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
                    continue;
                }
                if (b[x][y] > b[vx][vy] + 1) {
                    q.add(x);
                    q.add(y);
                    int t = b[x][y] = b[vx][vy] + 1;
                    max = max(max, t);
                    List<Integer> l = map.get(t);
                    if (l == null) {
                        l = new ArrayList<>();
                        map.put(t, l);
                    }
                    l.add(x);
                    l.add(y);
                }
            }
        }
        for (; k > 0; max--) {
            List<Integer> l = map.get(max);
            for (int i = 0; i < l.size() && k > 0; i += 2, k--) {
                a[l.get(i)][l.get(i + 1)] = 'X';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                print(a[i][j]);
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