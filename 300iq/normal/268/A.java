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
        int n = nextInt();
        int a[] = new int[n];
        int h[] = new int[n];
        for (int i = 0; i < n; i++) {
            h[i] = nextInt();
            a[i] = nextInt();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && a[i] == h[j]) {
                    ans++;
                }
            }
        }
        out.println(ans);
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