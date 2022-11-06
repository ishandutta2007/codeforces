import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    // File names!!!

    void solve() throws IOException {
        int n = io.nextInt();
        int k = io.nextInt();
        int[] a = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = io.nextInt();
            ans += a[i];
        }
        int[] x = new int[k];
        int[] y = new int[k];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                Arrays.fill(x, -1);
                for (int z = 0; z < k; z++) {
                    int min = i;
                    for (int v = i; v <= j; v++) {
                        if (a[v] < a[min]) {
                            min = v;
                        }
                    }
                    int max = -1;
                    for (int v = 0; v < i; v++) {
                        if (max == -1 || a[v] > a[max]) {
                            max = v;
                        }
                    }
                    for (int v = j + 1; v < n; v++) {
                        if (max == -1 || a[v] > a[max]) {
                            max = v;
                        }
                    }
                    if (max == -1 || a[min] >= a[max]) {
                        break;
                    }
                    x[z] = min;
                    y[z] = max;
                    int _ = a[min];
                    a[min] = a[max];
                    a[max] = _;
                }

                int s = 0;
                for (int z = i; z <= j; z++) {
                    s += a[z];
                }
                ans = max(ans, s);
                for (int z = 0; z < k && x[z] != -1; z++) {
                    int _ = a[x[z]];
                    a[x[z]] = a[y[z]];
                    a[y[z]] = _;
                }
            }
        }
        io.println(ans);
    }

    void run() {
        try {
            io = new FastIO();
            solve();
            io.close();
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

    class FastIO extends PrintWriter {
        private BufferedReader in;
        private StringTokenizer stok;

        FastIO() {
            super(System.out);
            in = new BufferedReader(new InputStreamReader(System.in));
        }

        FastIO(String s) throws FileNotFoundException {
            super("".equals(s) ? "output.txt" : s + ".out");
            in = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
        }

        public void close() {
            super.close();
            try {
                in.close();
            } catch (IOException ignored) {
            }
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

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        char[] nextCharArray() {
            return next().toCharArray();
        }

    }
}