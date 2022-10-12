import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DBicolorings solver = new DBicolorings();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBicolorings {
        static final long MOD = 998244353L;
        static final DBicolorings.Mod m = new DBicolorings.Mod();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            long[][][] dp = new long[n + 1][2 * n + 5][2]; // dp[length][components][top^bottom]

            dp[1][1][0] = 2;
            dp[1][2][1] = 2;

            for (int len = 1; len < n; len++) {
                for (int components = 0; components <= 2 * n; components++) {
                    for (int xor = 0; xor <= 1; xor++) {
                        long cur = dp[len][components][xor];
                        if (xor == 0) {
                            // add same thing
                            dp[len + 1][components][xor] = m.add(dp[len + 1][components][xor], cur);
                            // add opposite thing
                            dp[len + 1][components + 1][xor] = m.add(dp[len + 1][components + 1][xor], cur);
                            // add 10 or 01
                            dp[len + 1][components + 1][1 - xor] = m.add(dp[len + 1][components + 1][1 - xor], cur * 2);
                        } else {
                            // add same thing
                            dp[len + 1][components][xor] = m.add(dp[len + 1][components][xor], cur);
                            // add opposite thing
                            dp[len + 1][components + 2][xor] = m.add(dp[len + 1][components + 2][xor], cur);
                            // add 00 or 11
                            dp[len + 1][components][1 - xor] = m.add(dp[len + 1][components][1 - xor], cur * 2);
                        }
                    }
                }
            }

            long answer = 0;
            for (int xor = 0; xor <= 1; xor++) {
                answer = m.add(answer, dp[n][k][xor]);
            }
            out.println(answer);
        }

        static class Mod extends NumberTheory.Modulus<DBicolorings.Mod> {
            public long modulus() {
                return MOD;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class NumberTheory {
        public abstract static class Modulus<M extends NumberTheory.Modulus<M>> {
            ArrayList<NumberTheory.ModularNumber<M>> factorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(create(1));
            }

            public long normalize(long x) {
                x %= modulus();
                if (x < 0)
                    x += modulus();
                return x;
            }

            public long add(long a, long b) {
                return normalize(a + b);
            }

            public NumberTheory.ModularNumber<M> create(long value) {
                return new NumberTheory.ModularNumber(value, this);
            }

        }

        public static class ModularNumber<M extends NumberTheory.Modulus<M>> {
            public final long value;
            public final M m;

            public ModularNumber(long value, M m) {
                this.m = m;
                value = value % m.modulus();
                if (value < 0)
                    value += m.modulus();
                this.value = value;
            }

            public String toString() {
                return String.valueOf(value);
            }

        }

    }
}