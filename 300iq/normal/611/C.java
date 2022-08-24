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
    char a[][] = new char[507][507];
    int dph[][] = new int[507][507];
    int dpw[][] = new int[507][507];

    private void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < n; i++) {
            String s = in.nextLine();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        int q = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') {
                    if (j > 0) {
                        dpw[i][j] = dpw[i][j - 1];
                    }
                    if (i > 0) {
                        dph[i][j] = dph[i - 1][j];
                    }
                } else {
                    if (j > 0) {
                        if (a[i][j - 1] == '.') {
                            dpw[i][j] = dpw[i][j - 1] + 1;
                        } else {
                            dpw[i][j] = dpw[i][j - 1];
                        }
                    }
                    if (i > 0) {
                        if (a[i - 1][j] == '.') {
                            dph[i][j] = dph[i - 1][j] + 1;
                        } else {
                            dph[i][j] = dph[i - 1][j];
                        }
                    }
                }
            }
        }
        for (int k = 1; k <= q; k++) {
            long ans = 0;
            int ax = in.nextInt();
            int ay = in.nextInt();
            int bx = in.nextInt();
            int by = in.nextInt();
            ax--;
            ay--;
            bx--;
            by--;
            for (int i = ax; i <= bx; i++) {
                ans += (dpw[i][by] - dpw[i][ay]);
            }
            for (int i = ay; i <= by; i++) {
                ans += (dph[bx][i] - dph[ax][i]);
            }
            out.println(ans);
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