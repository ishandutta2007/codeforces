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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DBerserkAndFireball solver = new DBerserkAndFireball();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBerserkAndFireball {
        long x;
        long y;
        int k;
        int[] a;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            x = in.nextLong();
            k = in.nextInt();
            y = in.nextLong();
            a = in.readIntArray(n);
            int[] b = in.readIntArray(m);

            BitSet delete = new BitSet();
            delete.set(0, n);
            for (int j = 0, i = 0; j < m; j++, i++) {
                while (i < n && a[i] != b[j]) {
                    i++;
                }
                if (i == n) {
                    out.println(-1);
                    return;
                }
                delete.clear(i);
            }

            if (delete.isEmpty()) {
                out.println(0);
                return;
            }

            long answer = 0;
            for (int i = 0, j = 0; i < n; i = j) {
                while (j < n && delete.get(i) == delete.get(j))
                    j++;

                if (delete.get(i)) {
                    long cost = cost(i, j);
                    if (cost == -1) {
                        out.println(-1);
                        return;
                    }
                    answer += cost;
                }
            }

            out.println(answer);
        }

        private long cost(int l, int r) {
            int max = 0;
            for (int i = l; i < r; i++) {
                max = Math.max(max, a[i]);
            }
            if (l - 1 >= 0)
                max = Math.max(max, a[l - 1]);
            if (r < a.length)
                max = Math.max(max, a[r]);

            int count = r - l;

            int small = 0;
            for (int i = l; i < r; i++) {
                if (a[i] < max)
                    small++;
            }

            long answer = 0;
            if (x < y * k) {
                answer += x * (count / k);
                count %= k;

                if (small >= count) {
                    answer += count * y;
                } else {
                    return -1;
                }
            } else {
                if (small >= count) {
                    answer += count * y;
                } else {
                    long blocks = ((count - small) + (k - 1)) / k;
                    if (blocks * k > count) {
                        return -1;
                    }
                    answer += blocks * x;
                    answer += (count - blocks * k) * y;
                }
            }
            return answer;
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

        public long nextLong() {
            return Long.parseLong(next());
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