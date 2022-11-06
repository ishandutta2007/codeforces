import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    // File names!!!

    void solve() throws IOException {
        char[] s = in.in.readLine().toCharArray();
        int n = s.length;
        List<Integer> a = new ArrayList<>();
        a.add(-1);
        for (int i = 0; i < n - 3; i++) {
            if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r') {
                a.add(i);
            }
        }
        if (a.size() == 1) {
            out.println(0);
            return;
        }
        int ans = 0;
        for (int i = 1; i < a.size(); i++) {
            ans += (a.get(i) - a.get(i - 1)) * (n - a.get(i) - 3);
        }
        out.println(ans);
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