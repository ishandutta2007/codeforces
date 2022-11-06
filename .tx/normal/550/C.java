import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    void solve() throws IOException {
        char[] s = next().toCharArray();
        int n = s.length;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 8 == 0) {
                println("YES");
                println(a[i]);
                return;
            }
            for (int j = i + 1; j < n; j++) {
                if ((a[i] * 10 + a[j]) % 8 == 0) {
                    println("YES");
                    printf("%d%d", a[i], a[j]);
                    return;
                }
                for (int k = j + 1; k < n; k++) {
                    if ((a[i] * 100 + a[j] * 10 + a[k]) % 8 == 0) {
                        println("YES");
                        printf("%d%d%d", a[i], a[j], a[k]);
                        return;
                    }
                }
            }
        }
        println("NO");
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

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    <T> List<T>[] createAdjacencyList(int verticesNumber) {
        List<T>[] res = new List[verticesNumber];
        for (int i = 0; i < verticesNumber; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }
}