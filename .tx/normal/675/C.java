import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    int get(int[] a) {
        int n = a.length;
        long[] b = new long[n];
        int mn = 0;
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
            if (i > 0) {
                b[i] += b[i - 1];
            }
            if (b[i] < b[mn]) {
                mn = i;
            }
        }

        int c0 = 0;
        long s = 0;

        for (int i = 0; i < n; i++) {
            s += a[(mn + 1 + i) % n];
            if (s == 0) {
                c0++;
            }
        }

        return n - c0;
    }

    int stupid(int[] a) {
        int n = a.length;

        int ans = inf;

        for (int i = 0; i < n; i++) {
            long s = 0;
            int c = 0;
            for (int j = 0; j < n; j++) {
                int x = (i + j) % n;
                s += a[x];
                if (s != 0) {
                    c++;
                }
            }
            ans = min(ans, c);
        }

        return ans;
    }

    int solve(int[] a) throws IOException {
//        int n = a.length;
//        int a1 = get(a);
//        for (int i = 0; i * 2 < n; i++) {
//            int t = a[i];
//            a[i] = a[n - 1 - i];
//            a[n - 1 - i] = t;
//        }
//        int a2 = get(a);
//        int aok = min(a1, a2);
//        return aok;
        int n = a.length;
        Map<Long, Integer> m = new TreeMap<>();
        long s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            m.compute(s, (k, v) -> v == null ? 1 : v + 1);
        }

        int c = 0;
        for (int i : m.values()) {
            c = max(c, i);
        }
        return n - c;
    }

    void run() throws IOException {
        if (true) {
            int n = nextInt();
            int[] a = nextIntArray(n);
            println(solve(a));
            return;
        }

        for (int tt = 0; tt < 1000; tt++) {

            int n = rand.nextInt(100) + 1;
            int[] a = new int[n];
            int s = 0;
            for (int i = 0; i + 1 < n; i++) {
                a[i] = rand.nextInt(200) - 100;
                s += a[i];
            }
            a[n - 1] = -s;
            int astup = stupid(Arrays.copyOf(a, n));
            int aok = solve(Arrays.copyOf(a, n));
            if (aok != astup) {
                println(n);
                for (int i = 0; i < n; i++) {
                    print(a[i]);
                    print(" ");
                }
                flush();
                System.err.println("aok " + aok);
                System.err.println("astup " + astup);
                return;
            }
        }

        println("OK");

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
        main.run();
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