import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;
    final Random rand = new Random(31);

    void solve() throws IOException {
        List<Integer>[] g = createAdjacencyList(100000);
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            g[nextInt() - 1].add(i);
        }
        List<Integer> aa = new ArrayList<>();
        List<Integer> dd = new ArrayList<>();
        for (int i = 0; i < g.length; i++) {
            List<Integer> is = g[i];
            if (is.isEmpty()) {
                continue;
            }
            if (is.size() == 1) {
                aa.add(i);
                dd.add(0);
            } else if (is.size() == 2) {
                aa.add(i);
                dd.add(is.get(1) - is.get(0));
            } else {
                int d = is.get(1) - is.get(0);
                boolean ok = true;
                for (int j = 2; j < is.size(); j++) {
                    if (is.get(j) - is.get(j - 1) != d) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    aa.add(i);
                    dd.add(d);
                }
            }
        }
        println(aa.size());
        for (int i = 0; i < aa.size(); i++) {
            print(aa.get(i) + 1);
            print(" ");
            println(dd.get(i));
        }
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws FileNotFoundException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    public static void main(String[] args) throws IOException {
        try (Main main = new Main()) {
            main.solve();
        }
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

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[x];
            a[x] = a[i];
            a[i] = _;
        }
    }

    int[] nextIntArray(int len) throws IOException {
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    <T> List<T>[] createAdjacencyList(int n) {
        List<T>[] res = new List[n];
        for (int i = 0; i < n; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }
}