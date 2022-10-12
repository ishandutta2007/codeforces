import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.BitSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        C1BalancedRemovalsEasier solver = new C1BalancedRemovalsEasier();
        solver.solve(1, in, out);
        out.close();
    }

    static class C1BalancedRemovalsEasier {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            C1BalancedRemovalsEasier.P[] p = new C1BalancedRemovalsEasier.P[n];
            for (int i = 0; i < n; i++) {
                p[i] = new C1BalancedRemovalsEasier.P(i, in.nextInt(), in.nextInt(), in.nextInt());
            }

            BitSet removed = new BitSet(n);

            for (int i = 0; i < n; i++) {
                if (removed.get(i))
                    continue;
                int minJ = -1, d = Integer.MAX_VALUE;
                for (int j = i + 1; j < n; j++) {
                    if (removed.get(j))
                        continue;

                    if (d(p[i], p[j]) < d) {
                        d = d(p[i], p[j]);
                        minJ = j;
                    }
                }
                print(i, minJ, removed, out);
            }
        }

        private void print(int i, int j, BitSet removed, PrintWriter out) {
            removed.set(i);
            removed.set(j);
            out.format("%d %d%n", i + 1, j + 1);
        }

        private static int d(C1BalancedRemovalsEasier.P a, C1BalancedRemovalsEasier.P b) {
            return Math.abs(a.x - b.x) + Math.abs(a.y - b.y) + Math.abs(a.z - b.z);
        }

        static class P {
            final int i;
            final int x;
            final int y;
            final int z;

            P(int i, int x, int y, int z) {
                this.i = i;
                this.x = x;
                this.y = y;
                this.z = z;
            }

            public String toString() {
                return "P{" + "i=" + i + ", x=" + x + ", y=" + y + ", z=" + z + '}';
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