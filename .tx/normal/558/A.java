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

    class Pair {
        int x, a;

        public Pair(int x, int a) {
            this.x = x;
            this.a = a;
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        List<Pair> l = new ArrayList<>(), r = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Pair p = new Pair(nextInt(), nextInt());
            (p.x < 0 ? l : r).add(p);
        }
        Collections.sort(l, (p1, p2) -> Integer.compare(p2.x, p1.x));
        Collections.sort(r, (p1, p2) -> Integer.compare(p1.x, p2.x));
        int ln = l.size();
        int rn = r.size();
        if (ln == 0) {
            println(r.get(0).a);
            return;
        }
        if (rn == 0) {
            println(l.get(0).a);
            return;
        }
        int[] sl = new int[ln];
        sl[0] = l.get(0).a;
        for (int i = 1; i < ln; i++) {
            sl[i] = sl[i - 1] + l.get(i).a;
        }
        int[] sr = new int[rn];
        sr[0] = r.get(0).a;
        for (int i = 1; i < rn; i++) {
            sr[i] = sr[i - 1] + r.get(i).a;
        }
        if (ln < rn) {
            println(sl[ln - 1] + sr[ln]);
        } else if (ln > rn) {
            println(sl[rn] + sr[rn - 1]);
        } else {
            println(sl[ln - 1] + sr[rn - 1]);
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