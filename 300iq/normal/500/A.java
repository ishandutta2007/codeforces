import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {

    PrintWriter out;
    BufferedReader b;
    StringTokenizer s;

    String next() throws IOException {
        while (s == null || !s.hasMoreTokens()) {
            String k = b.readLine();
            if (k == null) {
                return null;
            }
            s = new StringTokenizer(k);
        }
        return s.nextToken();
    }

    char nextChar() throws IOException {
        return (char) (b.read());
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private void solve() throws IOException {
        int n = nextInt(), t = nextInt();
        int a[] = new int[n + 1];
        for (int i = 1; i <= n - 1; i++) {
            a[i] = nextInt();
        }
        for (int i = 1; i <= n; i++) {
            if (i == t) {
                out.println("YES");
                return;
            }
            if (i > t) {
                out.println("NO");
                return;
            }
            i += a[i];
            i--;
        }
    }

    private void run() throws IOException {
        out = new PrintWriter(System.out);
        b = new BufferedReader(new InputStreamReader(System.in));
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}