import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO_NAME = "_std";

    boolean have2(String s, String fst, String snd) {
        int x = s.indexOf(fst);
        if (x == -1) {
            return false;
        }
        int y = s.indexOf(snd, x + 2);
        return y != -1;
    }

    void solve() throws IOException {
        String s = next();
        println(have2(s, "AB", "BA") || have2(s, "BA", "AB") ? "YES" : "NO");
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

    BufferedReader in;
    StringTokenizer stok;

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

    Main(String filename) throws IOException {
        super(getOutputStream(filename));
        in = new BufferedReader(new InputStreamReader(getInputStream(filename)));
    }

    public static void main(String[] args) throws IOException {
        new Main(IO_NAME).run();
    }

    static InputStream getInputStream(String filename) throws IOException {
        if ("_std".equals(filename)) {
            return System.in;
        }
        if ("_iotxt".equals(filename)) {
            return new FileInputStream("input.txt");
        }
        return new FileInputStream(filename + ".in");
    }

    static OutputStream getOutputStream(String filename) throws IOException {
        if ("_std".equals(filename)) {
            return System.out;
        }
        if ("_iotxt".equals(filename)) {
            return new FileOutputStream("output.txt");
        }
        return new FileOutputStream(filename + ".out");
    }
}