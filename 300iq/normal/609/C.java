import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {

    class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String nextToken() throws IOException {
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
            return Integer.parseInt(nextToken());
        }

        long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(nextToken());
        }

        char nextChar() throws IOException {
            return (char) (br.read());
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }

    FastScanner in = new FastScanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    private void solve() throws IOException {
        int n;
        n = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        int s = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            s += a[i];
        }
        Arrays.sort(a);
        int full = s / n;
        int mod = s % n;
        for (int i = 0; i < n; i++) {
            b[i] = full;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (mod == 0) {
                continue;
            }
            else {
                b[i]++;
                mod--;
            }
        }
        s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                s += a[i] - b[i];
            }
        }
        out.println(s);
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}