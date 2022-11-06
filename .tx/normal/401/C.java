import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO io;

    // File names!!!

    void solve() throws IOException {
        int n = io.nextInt();
        int m = io.nextInt();
        if (n - 1 > m) {
            io.println(-1);
            return;
        }
        if (m - 2 > 2 * n) {
            io.println(-1);
            return;
        }
        int nm = m;
        for (int i = 0; nm > 0 && i < m - 2 * n; i++) {
            io.print(1);
            nm--;
        }
        for (int i = 0; i < n; i++) {
            io.print(0);
            if (nm > 0) {
                io.print(1);
                nm--;
            }
            if (nm > n - i - 1) {
                io.print(1);
                nm--;
            }
        }

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