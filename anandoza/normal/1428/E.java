import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.function.LongBinaryOperator;
import java.util.PriorityQueue;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractCollection;
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
        ECarrotsForRabbits solver = new ECarrotsForRabbits();
        solver.solve(1, in, out);
        out.close();
    }

    static class ECarrotsForRabbits {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] a = in.readIntArray(n);

            LongBinaryOperator score = (long len, long count) -> {
                long low = len / count;
                long hi = low + 1;
                long numHi = len - low * count;
                return (count - numHi) * low * low + numHi * hi * hi;
            };
            PriorityQueue<Pii> q = new PriorityQueue<>(Comparator.comparingLong(p -> {
                long cur = score.applyAsLong(p.first, p.second);
                long next = score.applyAsLong(p.first, p.second + 1);
                return next - cur;
            }));

            long ans = 0;
            for (int x : a) {
                if (x > 1)
                    q.add(Pii.of(x, 1));
                else
                    ans++;
            }

            for (int i = 0; i < k - n; i++) {
                Pii p = q.poll();
                if (p.first == p.second + 1) {
                    ans += p.first;
                } else {
                    q.add(Pii.of(p.first, p.second + 1));
                }
            }

            while (!q.isEmpty()) {
                Pii p = q.poll();
                ans += score.applyAsLong(p.first, p.second);
            }

            out.println(ans);
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}