import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

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
        F1ShortColorfulStrip solver = new F1ShortColorfulStrip();
        solver.solve(1, in, out);
        out.close();
    }

    static class F1ShortColorfulStrip {
        static final NumberTheory.ModM m = new NumberTheory.ModM(998244353);
        int n;
        long[][] dp;
        int[] c;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            int unused = in.nextInt();

            c = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
            }

            dp = new long[n][n]; // [i][j] is interval [i, j]

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j] = -1;

            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }

            long answer = compute(0, n - 1);

            out.println(answer);
        }

        private long compute(int left, int right) {
            if (left < 0 || right >= n || left > right)
                return 1;

            if (dp[left][right] >= 0)
                return dp[left][right];

            int min = left;
            for (int i = left; i <= right; i++) {
                if (c[i] < c[min]) {
                    min = i;
                }
            }

            long leftResult = 0;
            long rightResult = 0;
            for (int l = left; l <= min; l++) {
                long sub = 1;
                sub = m.mult(sub, compute(left, l - 1));
                sub = m.mult(sub, compute(l, min - 1));
                leftResult = m.add(leftResult, sub);
            }
            for (int r = min; r <= right; r++) {
                long sub = 1;
                sub = m.mult(sub, compute(min + 1, r));
                sub = m.mult(sub, compute(r + 1, right));
                rightResult = m.add(rightResult, sub);
            }

            long result = m.mult(leftResult, rightResult);

            dp[left][right] = result;

            //        System.out.format("%5d ", result);
            //        System.out.format("%5d (%4d)    ", min, c[min]);
            //        for (int i = left; i <= right; i++) {
            //            System.out.format("%d, ", c[i]);
            //        }
            //        System.out.println();

            return result;
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
            ArrayList<Long> factorial = new ArrayList<>();
            ArrayList<Long> invFactorial = new ArrayList<>();

            public abstract long modulus();

            public Modulus() {
                super();
                factorial.add(1L);
                invFactorial.add(1L);
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

            public long mult(long a, long b) {
                return normalize(a * b);
            }

        }

        public static class ModM extends NumberTheory.Modulus<NumberTheory.ModM> {
            private final long modulus;

            public ModM(long modulus) {
                this.modulus = modulus;
            }

            public long modulus() {
                return modulus;
            }

        }

    }
}