import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader br;
    StringTokenizer stok;

    int s(long x) {
        int res = 0;
        while (x > 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

    void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int c = nextInt();
        List<Long> ans = new ArrayList<>();
        for (int i = 1; i <= 81; i++) {
            long x = 1;
            for (int j = 0; j < a; j++) {
                x *= i;
            }
            x = x * b + c;
            if (s(x) == i && x > 0 && x < 1e9) {
                ans.add(x);
            }
        }
        println(ans.size());
        for (long i : ans) {
            print(i);
            print(" ");
        }
    }

    void run() throws IOException {
        try {
            solve();
            close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        }
    }

    public static void main(String[] args) throws IOException {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception ignore) {
        }
        new Main().run();
    }

    Main() {
        super(System.out);
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String s) throws FileNotFoundException {
        super("".equals(s) ? "output.txt" : s + ".out");
        br = new BufferedReader(new FileReader("".equals(s) ? "input.txt" : s + ".in"));
    }

    String next() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(br.readLine());
            }
        } catch (Exception e) {
            return null;
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