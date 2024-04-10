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
        int ans = 0, a, b, cura, curb;
        a = in.nextInt();
        b = in.nextInt();
        cura = a;
        curb = 0;
        do {
            ans += cura;
            curb += cura;
            cura = curb / b;
            curb %= b;
        } while (cura > 0);
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