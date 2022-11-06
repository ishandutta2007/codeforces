import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    public void solve() throws IOException {
        char[] s = next().toCharArray();
        int n = s.length;
        int m1 = nextInt();
        int m2 = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        int[] ma = new int[n];
        ma[0] = a[0] % m1;
        for (int i = 1; i < n; i++) {
            ma[i] = (ma[i - 1] * 10 + a[i]) % m1;
        }
        int p10 = 1;
        int[] mb = new int[n];
        mb[n - 1] = a[n - 1] % m2;
        for (int i = n - 2; i >= 0; i--) {
            p10 = (p10 * 10) % m2;
            mb[i] = (mb[i + 1] + p10 * a[i]) % m2;
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] != 0 && ma[i] == 0 && mb[i + 1] == 0) {
                println("YES");
                for (int j = 0; j < n; j++) {
                    print(s[j]);
                    if (j == i) {
                        println();
                    }
                }
                return;
            }
        }
        println("NO");
    }

    public void run() {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws IOException {
        super("".equals(s) ? "output.txt" : (s + ".out"));
        in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : (s + ".in")));
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignored) {
        }
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

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }
}