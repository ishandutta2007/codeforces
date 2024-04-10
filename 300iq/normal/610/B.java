import java.io.*;
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
        long n = in.nextLong();
        int a[] = new int[(int)n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        long lmin = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < a[(int)lmin]) {
                lmin = i;
            }
        }
        ArrayList <Long> k = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (a[i] == a[(int)lmin]) {
                k.add((long)i);
            }
        }
        long ans = 0;
        for (int i = 0; i < k.size(); i++) {
            if (i == k.size() - 1) {
                ans = Math.max(ans, (n - k.get(i) - 1 + k.get(0)));
            }
            else {
                ans = Math.max(ans, k.get(i + 1) - k.get(i) - 1);
            }
        }
        ans += n * a[(int)lmin];
        out.println(ans);
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}