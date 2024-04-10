import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        CKIntegers solver = new CKIntegers();
        solver.solve(1, in, out);
        out.close();
    }

    static class CKIntegers {
        PriorityQueue<Long> lower = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Long> upper = new PriorityQueue<>();
        long lowerSum = 0;
        long upperSum = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }

            int[] inv = Permutations.inverse(p);

            IntSumBIT indices = new IntSumBIT(n);
            long y = 0;
            long[] answer = new long[n];
            for (int i = 0; i < n; i++) {
                long x = addAndGetDist(inv[i]);
                y += indices.query(inv[i], n);
                indices.update(inv[i], 1);

                answer[i] = x + y;
            }

            out.println(Util.join(answer));
        }

        long addAndGetDist(long a) {
            if (lower.size() == 0 || a <= lower.peek()) {
                addLower(a);
            } else {
                addUpper(a);
            }

            int desiredLowerSize = (lower.size() + upper.size() + 1) / 2;

            while (lower.size() < desiredLowerSize) {
                addLower(pollUpper());
            }
            while (lower.size() > desiredLowerSize) {
                addUpper(pollLower());
            }

            long x = lower.peek();
            long answer = 0;
            answer += upperSum - x * upper.size();
            answer += x * lower.size() - lowerSum;

            answer -= ((long) upper.size()) * (upper.size() + 1) / 2;
            answer -= ((long) lower.size()) * (lower.size() - 1) / 2;

            return answer;
        }

        void addUpper(long x) {
            upper.add(x);
            upperSum += x;
        }

        long pollUpper() {
            long x = upper.poll();
            upperSum -= x;
            return x;
        }

        void addLower(long x) {
            lower.add(x);
            lowerSum += x;
        }

        long pollLower() {
            long x = lower.poll();
            lowerSum -= x;
            return x;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class IntSumBIT {
        public final int size;
        public final int[] value;

        public IntSumBIT(int size) {
            this.size = size;
            value = new int[size + 1];
        }

        public void update(int i, int v) {
            add(i, v - query(i, i + 1));
        }

        public void add(int i, int v) {
            for (i++; i <= size; i += i & -i)
                value[i] += v;
        }

        public int sum(int i) {
            int r = 0;
            for (; i > 0; i -= i & -i)
                r = r + value[i];
            return r;
        }

        public int query(int i, int j) {
            return i >= j ? 0 : sum(j) - sum(i);
        }

    }

    static class Permutations {
        public static int[] inverse(int[] permutation) {
            int n = permutation.length;
            int[] inverse = new int[n];
            for (int i = 0; i < n; i++) {
                inverse[permutation[i]] = i;
            }
            return inverse;
        }

        private Permutations() {
        }

    }

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
        }

    }
}