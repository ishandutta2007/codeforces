import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.IntPredicate;
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
        CChoosingFlowers solver = new CChoosingFlowers();
        solver.solve(1, in, out);
        out.close();
    }

    static class CChoosingFlowers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            Pii[] pairs = new Pii[m];
            for (int i = 0; i < m; i++) {
                pairs[i] = Pii.of(in.nextInt(), in.nextInt());
            }
            Arrays.sort(pairs, Comparator.reverseOrder());

            long[] prefix = new long[m + 1];
            prefix[0] = 0;
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + pairs[i].first;
            }

            long answer = prefix[Math.min(m, n)];

            for (int i = 0; i < m; i++) {
                long b = pairs[i].second;
                int better = BinarySearch.binarySearch(j -> j >= m || pairs[j].first < b);

                int count = Math.min(better, n);

                long candidate = 0;
                if (i < count) {
                    candidate = prefix[count] + (n - count) * b;
                } else {
                    count = Math.min(better, n - 1);
                    candidate = prefix[count] + pairs[i].first + (n - 1 - count) * b;
                }
                // System.out.println("i = " + i + "  " + pairs[i]);
                // System.out.println("better = " + better);
                // System.out.println("candidate = " + candidate);
                answer = Math.max(answer, candidate);
            }

            out.println(answer);
        }

    }

    static class BinarySearch {
        public static int binarySearch(IntPredicate bigEnough) {
            int tooSmall = 0, tooBig;
            if (bigEnough.test(tooSmall)) {
                return tooSmall;
            }

            for (tooBig = 1; !bigEnough.test(tooBig); tooBig *= 2)
                ;

            if (!bigEnough.test(tooBig - 1)) {
                return tooBig;
            }

            while (tooBig - tooSmall > 1) {
                int center = tooSmall + (tooBig - tooSmall) / 2;
                if (!bigEnough.test(center)) {
                    tooSmall = center;
                } else {
                    tooBig = center;
                }
            }

            return tooBig;
        }

    }

    static class Pii implements Comparable<Pii> {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pii o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
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