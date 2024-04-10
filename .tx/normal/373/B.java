import java.math.BigInteger;
import java.util.*;
import java.io.*;

import static java.lang.Math.*;

public class Main {
    FastIO in;
    PrintWriter out;

    int kc(long x) {
        return Long.toString(x).length();
    }

    long pow(long a, int q) {
        if (q == 0) {
            return 1;
        }
        return a * pow(a, q - 1);
    }

    // File names!!!

    void solve() throws IOException {
        long w = in.nextLong();
        long m = in.nextLong();
        long k = in.nextLong();

        int km = kc(m);
        long m10 = pow(10, km);
        BigInteger cm = BigInteger.TEN.pow(km).subtract(BigInteger.valueOf(m)).multiply(BigInteger.valueOf(k)).multiply(BigInteger.valueOf(km));
        if (cm.compareTo(BigInteger.valueOf(w)) > 0) {
            out.println(w / (km * k));
            return;
        }
        w -= cm.longValue();
        long ans = m10 - m;
        BigInteger bm = BigInteger.valueOf(m);
        BigInteger bm10 = BigInteger.valueOf(m10);
        for (int i = km + 1; ; i++) {
            m = m10;
            m10 = m10 * 10;
            cm = BigInteger.valueOf(m10 - m).multiply(BigInteger.valueOf(k)).multiply(BigInteger.valueOf(i));
//            bm = bm10.add(BigInteger.ZERO);
//            bm10 = bm10.multiply(BigInteger.TEN);
//            cm = bm10.subtract(bm).multiply(BigInteger.valueOf(k)).multiply(BigInteger.valueOf(i));
            if (cm.compareTo(BigInteger.valueOf(w)) > 0) {
                ans += w / (i * k);
                break;
            }
//            ans += bm10.subtract(bm).longValue();
            ans += m10 - m;
            w -= cm.longValue();
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