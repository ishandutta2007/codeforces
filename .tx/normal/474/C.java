import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    Random rand = new Random(31);

    class Poc {
        int x, y, a, b;

        Poc(int x, int y, int a, int b) {
            this.x = x;
            this.y = y;
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Poc poc = (Poc) o;

            if (a != poc.a) return false;
            if (b != poc.b) return false;
            if (x != poc.x) return false;
            if (y != poc.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            result = 31 * result + a;
            result = 31 * result + b;
            return result;
        }

        @Override
        public String toString() {
            return String.format("(%d %d)", x, y);
        }
    }

    class Pocs {
        Poc[] pocs;

        Pocs(Poc... pocs) {
            this.pocs = pocs;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pocs pocs1 = (Pocs) o;

            if (!Arrays.equals(pocs, pocs1.pocs)) return false;

            return true;
        }

        @Override
        public int hashCode() {
            return pocs != null ? Arrays.hashCode(pocs) : 0;
        }

        public Pocs copy() {
            return new Pocs(Arrays.copyOf(pocs, pocs.length));
        }

        @Override
        public String toString() {
            return Arrays.toString(pocs);
        }
    }

    long dist(Poc p1, Poc p2) {
        long res = (0L + p1.x - p2.x) * (p1.x - p2.x) + (0L + p1.y - p2.y) * (p1.y - p2.y);
        if (res < 0) {
            throw new AssertionError();
        }
        return res;
    }

    boolean isSq(Poc... p) {
        Poc p0 = p[0];
        int n1 = dist(p0, p[1]) < dist(p0, p[2]) ? 1 : 2;
        Poc p1 = p[n1];
        int n2 = dist(p1, p[3]) < dist(p1, p[3 - n1]) ? 3 : 3 - n1;
        Poc p2 = p[n2];
        Poc p3;
        if (n1 == 1) {
            if (n2 == 2) {
                p3 = p[3];
            } else {
                p3 = p[2];
            }
        } else {
            if (n2 == 1) {
                p3 = p[3];
            } else {
                p3 = p[1];
            }
        }
        long d = dist(p0, p1);
        if (d == 0) {
            return false;
        }
        if (dist(p1, p2) != d || dist(p2, p3) != d || dist(p3, p0) != d) {
            return false;
        }
        if (dist(p0, p2) != 2 * d || dist(p1, p3) != 2 * d) {
            return false;
        }
        return true;
    }

    void solve() throws IOException {
        int n = nextInt();
        for (; n-- > 0; ) {
            Queue<Pocs> q = new ArrayDeque<>();
            Poc[] pocs = new Poc[4];
            for (int i = 0; i < 4; i++) {
                pocs[i] = new Poc(nextInt(), nextInt(), nextInt(), nextInt());
            }
            Pocs v;
            q.add(v = new Pocs(pocs));
            Map<Pocs, Integer> was = new HashMap<>();
            was.put(v, 0);
            int ans = -1;
            while (!q.isEmpty()) {
                v = q.poll();
                int c = was.get(v);
                if (isSq(v.pocs)) {
                    ans = c;
                    break;
                }
                Pocs t = v.copy();
                for (int i = 0; i < 4; i++) {
                    int x = v.pocs[i].x;
                    int y = v.pocs[i].y;
                    int a = v.pocs[i].a;
                    int b = v.pocs[i].b;
//                    t.pocs[i] = new Poc((y - b) + a, -(x - a) + b, a, b);
//                    if (!was.containsKey(t)) {
//                        Pocs pp = t.copy();
//                        was.put(pp, c + 1);
//                        q.add(pp);
//                    }
                    t.pocs[i] = new Poc(-(y - b) + a, (x - a) + b, a, b);
                    if (!was.containsKey(t)) {
                        Pocs pp = t.copy();
                        was.put(pp, c + 1);
                        q.add(pp);
                    }
                    t.pocs[i] = v.pocs[i];
                }
            }
            println(ans);
        }
    }

    void run() throws IOException {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws FileNotFoundException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(br.readLine());
            }
        } catch (IOException e) {
            return null;
        }
        return stok.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[x];
            a[x] = t;
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

    <T> List<T>[] genAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}