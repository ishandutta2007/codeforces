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
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DTheUnionOfKSegments solver = new DTheUnionOfKSegments();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTheUnionOfKSegments {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();

            DTheUnionOfKSegments.Pii[] p = new DTheUnionOfKSegments.Pii[2 * n];
            for (int i = 0; i < n; i++) {
                int l = in.nextInt(), r = in.nextInt();
                p[i] = DTheUnionOfKSegments.Pii.of(l, +1);
                p[i + n] = DTheUnionOfKSegments.Pii.of(r, -1);
            }
            Arrays.sort(p, Comparator.comparingInt((DTheUnionOfKSegments.Pii i) -> i.a).thenComparingInt(i -> -i.b));

            List<DTheUnionOfKSegments.Pii> answer = new ArrayList<>();
            int count = 0;
            int last = Integer.MAX_VALUE;

            for (DTheUnionOfKSegments.Pii i : p) {
                int x = i.a;
                count += i.b;
                if (count == k && i.b == +1) {
                    last = x;
                } else if (count == k - 1 && i.b == -1) {
                    answer.add(DTheUnionOfKSegments.Pii.of(last, x));
                }
            }

            out.println(answer.size());
            for (DTheUnionOfKSegments.Pii i : answer) {
                out.println(i);
            }
        }

        private static class Pii {
            final int a;
            final int b;

            public Pii(int a, int b) {
                this.a = a;
                this.b = b;
            }

            public static DTheUnionOfKSegments.Pii of(int a, int b) {
                return new DTheUnionOfKSegments.Pii(a, b);
            }

            public String toString() {
                return a + " " + b;
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