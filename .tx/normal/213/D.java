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

    int pid = 0;

    class Point {
        double x, y;
        int id;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
            id = ++pid;
            points.add(this);
        }
    }

    Point[] def = new Point[5];

    List<Point> points = new ArrayList<>();
    int[][] pids;

    List<Integer> moves = new ArrayList<>();

    void gen(int n, Point f) {
        pids[n][0] = f.id;
        Point s = new Point(f.x + def[3].x - def[0].x, f.y + def[3].y - def[0].y);
        pids[n][1] = s.id;
        moves.add(s.id);
        if (n > 1) {
            gen(n - 1, s);
        }
        s = new Point(s.x + def[1].x - def[3].x, s.y + def[1].y - def[3].y);
        pids[n][2] = s.id;
        moves.add(s.id);
        s = new Point(s.x + def[4].x - def[1].x, s.y + def[4].y - def[1].y);
        pids[n][3] = s.id;
        moves.add(s.id);
        s = new Point(s.x + def[2].x - def[4].x, s.y + def[2].y - def[4].y);
        pids[n][4] = s.id;
        moves.add(s.id);
        moves.add(f.id);
    }

    Point rot(Point a, Point b, double ang) {
        double x = a.x - b.x;
        double y = a.y - b.y;
        double nx = x * cos(ang) - y * sin(ang);
        double ny = x * sin(ang) + y * cos(ang);
        return new Point(nx + b.x, ny + b.y);
    }

    void solve() throws IOException {
        def[0] = new Point(0, 0);
        def[1] = new Point(10, 0);
        double ang = -PI * 108 / 180;
        def[2] = rot(def[0], def[1], ang);
        def[3] = rot(def[1], def[2], ang);
        def[4] = rot(def[2], def[3], ang);

        points.clear();
        pid = 0;

        int n = nextInt();

        pids = new int[n + 1][5];
        moves.add(1);
        gen(n, new Point(0, 0));
        println(points.size());
        for (Point point : points) {
            printf("%.21f %.21f%n", point.x, point.y);
        }
        for (int i = 1; i <= n; i++) {
            printf("%d %d %d %d %d%n", pids[i][0], pids[i][2], pids[i][4], pids[i][1], pids[i][3]);
        }
        for (Integer move : moves) {
            print(move);
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