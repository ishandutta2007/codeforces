import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    int[][] sum;

    int getSum(int c, int l, int r) {
        int res = sum[c][r];
        if (l != 0) {
            res -= sum[c][l - 1];
        }
        return res;
    }

    // File names!!!

    void solve() throws IOException {
        char[] s = in.next().toCharArray();
        int n = s.length;
        sum = new int[3][n];
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'x';
            sum[c][i] = 1;
            if (i != 0) {
                for (int j = 0; j < 3; j++) {
                    sum[j][i] += sum[j][i - 1];
                }
            }
        }
        int[] s3 = new int[3];

        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            for (int j = 0; j < 3; j++) {
                s3[j] = getSum(j, l, r);
            }
            Arrays.sort(s3);
            int len = r - l + 1;
            boolean ok = len < 3;
            if (len % 3 == 0) {
                if (s3[0] == s3[1] && s3[1] == s3[2]) {
                    ok = true;
                }
            }

            if (len % 3 == 1) {
                if (s3[0] == s3[1] && s3[1] == s3[2] - 1) {
                    ok = true;
                }
            }

            if (len % 3 == 2) {
                if (s3[0] == s3[1] - 1 && s3[1] == s3[2]) {
                    ok = true;
                }
            }
            if (ok) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }
    }

    void run() {
        try {
            in = new FastIO();
            solve();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    class FastIO {
        private BufferedReader in;

        private StringTokenizer stok;

        FastIO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        FastIO(String s) throws FileNotFoundException {
            if ("".equals(s)) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(s + ".in"));
                out = new PrintWriter(s + ".out");
            }
        }

        void close() throws IOException {
            in.close();
            out.close();
        }

        String next() {
            while (stok == null || !stok.hasMoreTokens()) {
                try {
                    stok = new StringTokenizer(in.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return stok.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}