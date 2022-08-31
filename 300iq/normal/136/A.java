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

    int n, t;
    int a[] = new int[101];

    private void run() throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            t = in.nextInt();
            a[t] = i + 1;
        }
        for (int i = 1; i <= n; i++) {
            out.print(a[i] + " ");
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}