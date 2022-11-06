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
        int n = nextInt();
        int k = nextInt();
        if (n == 1) {
            if (k == 0) {
                println(rand.nextInt(inf));
            } else {
                println(-1);
            }
            return;
        }
        if (k < n / 2) {
            println(-1);
            return;
        }
        int kp = 0;
        for (int i = 0; i + 2 <= n - 2; i += 2) {
            printf("%d %d ", inf - i, inf - i - 1);
            k--;
            kp += 2;
        }
        printf("%d %d ", k, k * 2);
        kp += 2;
        if (n % 2 == 1) {
            print(k * 2 + 1);
            kp++;
        }
        System.err.println(kp);
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