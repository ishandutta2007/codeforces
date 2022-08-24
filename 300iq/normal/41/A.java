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
        String a, b;
        a = in.nextLine();
        b = in.nextLine();
        String reverse = new StringBuffer(a).reverse().toString();
        if (Objects.equals(b, reverse)) {
            out.println("YES");
        }
        else {
            out.println("NO");
        }
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}