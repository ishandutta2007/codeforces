import java.io.*;
import java.util.*;


public class Main {

    class FastScanner {
        BufferedReader br;
        StringTokenizer stok;

        FastScanner(InputStream is) throws FileNotFoundException {
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

    FastScanner in;
    PrintWriter out;

    private void solve() throws IOException {
        int k = in.nextInt();
        in.nextToken();
        String s = in.nextToken();
        if (s.equals("week")) {
            if (k >= 5 && k < 7)  {
                out.println(53);
            }
            else {
                out.println(52);
            }
        }
        if (s.equals("month")) {
            if (k == 31) {
                out.println(7);
            }
            else if (k == 30) {
                out.println(11);
            }
            else if (k == 29) {
                out.println(12);
            }
            else {
                out.println(12);
            }
        }
    }

    private void run() throws IOException {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}