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
        long a = nextLong();
        int[] d = nextIntArray(n);
        long s = 0;
        for (int i : d) {
            s += i;
        }
        if (n == 1) {
            println(d[0] - 1);
            return;
        }
        for (int i = 0; i < n; i++) {
            int x = 0;
            if (s - d[i] + 1 < a) {
                x += a - (s - d[i] + 1);
            }
            if (d[i] + n - 1 > a) {
                x += d[i] + n - 1 - a;
            }
            print(x);
            print(" ");
        }
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