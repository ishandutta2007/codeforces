import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
        F2LongColorfulStrip solver = new F2LongColorfulStrip();
        solver.solve(1, in, out);
        out.close();
    }

    static class F2LongColorfulStrip {
        static final NumberTheory.ModM m = new NumberTheory.ModM(998244353);
        int length;
        int[] count;
        int[] left;
        int[] right;
        int[] c;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int colors = in.nextInt();
            length = in.nextInt();

            int[] cWithDups = new int[length];
            for (int i = 0; i < length; i++) {
                cWithDups[i] = in.nextInt() - 1;
            }

            c = new int[length];
            c[0] = cWithDups[0];
            int index = 1;
            for (int i = 1; i < length; i++) {
                if (cWithDups[i] == cWithDups[i - 1])
                    continue;
                c[index++] = cWithDups[i];
            }
            int[] compressedC = new int[index];
            System.arraycopy(c, 0, compressedC, 0, index);
            c = compressedC;
            length = c.length;

            //System.out.println(Arrays.toString(c));

            left = new int[colors];
            Arrays.fill(left, Integer.MAX_VALUE);
            right = new int[colors];
            Arrays.fill(right, Integer.MIN_VALUE);
            count = new int[colors];
            for (int i = 0; i < length; i++) {
                count[c[i]]++;
                left[c[i]] = Math.min(left[c[i]], i);
                right[c[i]] = Math.max(right[c[i]], i);
            }

            //System.out.println(Arrays.toString(left));
            //System.out.println(Arrays.toString(right));

            long answer = solve(0, length - 1);

            out.println(answer);
        }

        private long solve(int leftIndex, int rightIndex) {
            //System.out.println("L-R : " + leftIndex + " " + rightIndex);
            long answer = 1;
            List<Integer> currentRun = new ArrayList<>();
            for (int i = leftIndex; i <= rightIndex; i++) {
                int curColor = c[i];
                currentRun.add(curColor);
                if (count[curColor] != 1) {
                    int left = i + 1;
                    i++;
                    for (; i <= right[curColor]; i++) {
                        if (c[i] < curColor) {
                            return 0;
                        }
                        if (c[i] == curColor) {
                            long sub = solve(left, i - 1);
                            answer = m.mult(answer, sub);
                            left = i + 1;
                        }
                    }
                    i--;
                }
            }
            //System.out.println("CR: " + currentRun);
            answer = m.mult(answer, solveF1(array(currentRun)));

            return answer;
        }

        private static int[] array(List<Integer> l) {
            int[] a = new int[l.size()];
            for (int i = 0; i < l.size(); i++) {
                a[i] = l.get(i);
            }
            return a;
        }

        private long solveF1(int[] c) {
            int n = c.length;
            long[][] dp = new long[n][n]; // [i][j] is interval [i, j]
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j] = -1;
            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }

            return compute(0, n - 1, dp, c, n);
        }

        private long compute(int left, int right, long[][] dp, int[] c, int n) {
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
                sub = m.mult(sub, compute(left, l - 1, dp, c, n));
                sub = m.mult(sub, compute(l, min - 1, dp, c, n));
                leftResult = m.add(leftResult, sub);
            }
            for (int r = min; r <= right; r++) {
                long sub = 1;
                sub = m.mult(sub, compute(min + 1, r, dp, c, n));
                sub = m.mult(sub, compute(r + 1, right, dp, c, n));
                rightResult = m.add(rightResult, sub);
            }

            long result = m.mult(leftResult, rightResult);

            dp[left][right] = result;

            //        System.out.format("%5d ", result);
            //        System.out.format("%5d (%4d)    ", min, c[min]);
            //        for (int i = left; i <= right; i++) {
            //            System.out.format("%d, ", c[i]);
            //        }
            //        //System.out.println();

            return result;
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
}