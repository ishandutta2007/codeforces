import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    final int mod = inf + 7;

    class Cube {
        int x, y;
        int v;

        public Cube(int x, int y, int v) {
            this.x = x;
            this.y = y;
            this.v = v;
        }

        @Override
        public String toString() {
            return "Cube{" +
                    "v=" + v +
                    '}';
        }
    }

    TreeSet<Cube> byPoint;

    Cube tmp = new Cube(0, 0, 0);
    boolean isOpen(int x, int y) {
        for (int i = -1; i <= 1; i++) {
            tmp.y = y + 1;
            tmp.x = x + i;
            if (byPoint.contains(tmp) && countUnder(tmp.x, tmp.y) == 1) {
                return false;
            }
        }
        return true;
    }

    boolean isOpen(Cube c) {
        return isOpen(c.x, c.y);
    }

    int countUnder(int x, int y) {
        int res = 0;
        tmp.y = y - 1;
        for (int i = -1; i <= 1; i++) {
            tmp.x = x + i;
            if (byPoint.contains(tmp)) {
                res++;
            }
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        byPoint = new TreeSet<>(new Comparator<Cube>() {
            @Override
            public int compare(Cube o1, Cube o2) {
                return o1.x == o2.x ? o1.y - o2.y : o1.x - o2.x;
            }
        });
        TreeSet<Cube> byV = new TreeSet<>(new Comparator<Cube>() {
            @Override
            public int compare(Cube o1, Cube o2) {
                return o1.v - o2.v;
            }
        });
        List<Cube> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Cube c = new Cube(nextInt(), nextInt(), i);
            byPoint.add(c);
            a.add(c);
        }
        for (Cube cube : a) {
            if (isOpen(cube)) {
                byV.add(cube);
            }
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            Cube c = null;
            do {
                if (c != null) {
                    byV.remove(c);
                }
                if (i % 2 == 0) {
                    c = byV.last();
                } else {
                    c = byV.first();
                }
            } while (!isOpen(c));
            ans[i] = c.v;
            byV.remove(c);
            byPoint.remove(c);
            for (int j = -1; j <= 1; j++) {
                tmp.y = c.y - 1;
                tmp.x = c.x + j;
                if (byPoint.contains(tmp)) {
                    Cube down = byPoint.ceiling(tmp);
                    if (isOpen(down)) {
                        byV.add(down);
                    }
                }
            }
        }
        long mul = 1;
        long res = 0;
        int mod = inf + 9;
        for (int i = 0; i < n; i++) {
            res = (res + ans[n - 1 - i] * mul) % mod;
            mul = mul * n % mod;
        }
        println(res);
    }

    public static void main(String[] args) throws IOException {
        try (Main main = new Main()) {
            main.solve();
        }
    }

    Main() throws IOException {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
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
}