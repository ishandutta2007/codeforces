import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EInverseGenealogy solver = new EInverseGenealogy();
        solver.solve(1, in, out);
        out.close();
    }

    static class EInverseGenealogy {
        private static final String NO = "NO";
        private static final String YES = "YES";
        private static final int[][] small = {
                // x = 0
                null,
                // x = 1
                {-1},
                // x = 2
                {-1, 0, 1, 2, 0},
                // x = 3
                {-1, 0, 0},
                // x = 4
                {-1, 0, 0, 1, 1},
                // x = 5
                {-1, 0, 0, 1, 1, 2},
                // x = 6
                {-1, 0, 0, 1, 1, 3, 3, 4},
                // x = 7
                {-1, 0, 0, 1, 1, 2, 2}};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            if (n % 2 == 0) {
                out.println(NO);
                return;
            }
            if (n == 1) {
                if (k == 0) {
                    out.println(YES);
                    out.println(0);
                } else {
                    out.println(NO);
                }
                return;
            }

            int balanced = n - k;
            int leaves = n / 2 + 1;
            int x = balanced - leaves; // number of balanced internal nodes
            n -= leaves; // number of internal nodes
            if (x <= 0 || x > n) {
                out.println(NO);
                return;
            }
            Util.ASSERT(x > 0 && n > 0);

            int[] answer = solve(x, n);
            if (answer == null) {
                out.println(NO);
                return;
            }
            int[] degree = new int[answer.length];
            for (int i = 0; i < answer.length; i++) {
                if (answer[i] >= 0)
                    degree[answer[i]]++;
            }
            out.println(YES);
            for (int i = 0; i < answer.length; i++) {
                answer[i]++;
            }
            out.print(Util.join(answer) + " ");
            for (int i = 0; i < answer.length; i++) {
                for (int j = degree[i]; j < 2; j++) {
                    out.print((i + 1) + " ");
                }
            }
        }

        private int[] solve(int x, int n) {
            int[] ans = f(x);
            if (ans == null || ans.length > n)
                return null;

            return pad(ans, n);
        }

        private int[] f(int x) {
            if (x < small.length) {
                return small[x];
            }
            if (Integer.bitCount(x + 1) == 1) {
                return powerOfTwoMinus1(x);
            }

            int powerOfTwoMinus1 = getPowerOfTwoMinus1(x);
            int remaining = x - powerOfTwoMinus1;
            if (Integer.bitCount(remaining + 1) == 1 && remaining != powerOfTwoMinus1) {
                // remaining is also 2^k-1, so we do a merge with an imbalanced root
                return merge(f(powerOfTwoMinus1), f(remaining));
            }

            // merge with balanced root
            return merge(f(powerOfTwoMinus1), pad(f(remaining - 1), remaining));
        }

        private int[] pad(int[] ans, int n) {
            if (ans.length >= n)
                return ans;

            int[] big = new int[n];
            System.arraycopy(ans, 0, big, big.length - ans.length, ans.length);
            for (int i = 0; i < big.length - ans.length + 1; i++) {
                big[i] = i - 1;
            }
            for (int i = big.length - ans.length + 1; i < big.length; i++) {
                big[i] += big.length - ans.length;
            }
            return big;
        }

        private int[] merge(int[] left, int[] right) {
            if (left == null || right == null)
                return null;

            int[] answer = new int[1 + left.length + right.length];
            answer[0] = -1;
            System.arraycopy(left, 0, answer, 1, left.length);
            answer[1] = 0;
            System.arraycopy(right, 0, answer, 1 + left.length, right.length);
            answer[1 + left.length] = 0;
            for (int i = 1 + 1; i < 1 + left.length; i++) {
                answer[i] += 1;
            }
            for (int i = 1 + left.length + 1; i < answer.length; i++) {
                answer[i] += 1 + left.length;
            }

            return answer;
        }

        private int getPowerOfTwoMinus1(int x) {
            int powerOfTwoMinus1 = 3;
            while (true) {
                if (x <= powerOfTwoMinus1 * 3) {
                    return powerOfTwoMinus1;
                }
                powerOfTwoMinus1 = 2 * (powerOfTwoMinus1 + 1) - 1;
            }
        }

        private int[] powerOfTwoMinus1(int x) {
            int[] ans = new int[x];
            ans[0] = -1;
            for (int i = 1; i < x; i++) {
                ans[i] = (i - 1) / 2;
            }
            return ans;
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

        private Util() {
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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