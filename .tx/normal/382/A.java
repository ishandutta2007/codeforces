import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    public void solve() throws IOException {
        String[] s = next().split("\\|");
        if (s.length == 0) {
            s = new String[] {"", ""};
        }
        if (s.length == 1) {
            s = new String[] {s[0], ""};
        }
        String t = next();
        int x = s[0].length() + s[1].length() + t.length();
        if (x % 2 != 0 || s[0].length() > x / 2 || s[1].length() > x / 2) {
            println("Impossible");
        } else {
            int y = x / 2 - s[0].length();
            print(s[0] + t.substring(0, y));
            print("|");
            print(s[1] + t.substring(y));
        }
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