import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

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


    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int q = nextInt();
        int[] t = new int[q];
        int[] x = new int[q];
        int[] y = new int[q];
        int[] z = new int[q];
        for (int i = 0; i < q; i++) {
            t[i] = nextInt();
            if (t[i] < 3) {
                x[i] = nextInt() - 1;
            } else {
                x[i] = nextInt() - 1;
                y[i] = nextInt() - 1;
                z[i] = nextInt();
            }
        }
        int[][] ans = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = 0;
            }
        }
        for (int i = q - 1; i >= 0; i--) {
            if (t[i] == 3) {
                ans[x[i]][y[i]] = z[i];
            } else {
                if (t[i] == 1) {
                    int p = ans[x[i]][m - 1];
                    for (int j = m - 1; j > 0; j--) {
                        ans[x[i]][j] = ans[x[i]][j - 1];
                    }
                    ans[x[i]][0] = p;
                } else {
                    int p = ans[n - 1][x[i]];
                    for (int j = n - 1; j > 0; j--) {
                        ans[j][x[i]] = ans[j - 1][x[i]];
                    }
                    ans[0][x[i]] = p;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(ans[i][j] + " " );
            }
            out.println();
        }
    }



    void run() throws IOException {
        // br = new BufferedReader(new FileReader("input.txt"));
        // out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new B().run();
    }
}