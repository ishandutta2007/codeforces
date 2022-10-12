import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        CPalindromicPaths solver = new CPalindromicPaths();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPalindromicPaths {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = in.nextInt();
                }
            }

            List<Integer>[] buckets = new List[n + m];
            for (int i = 0; i < buckets.length; i++) {
                buckets[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int d1 = i + j, d2 = n - 1 + m - 1 - d1;
                    if (d1 == d2)
                        continue;
                    buckets[Math.min(d1, d2)].add(a[i][j]);
                }
            }

            long answer = 0;
            for (List<Integer> bucket : buckets) {
                if (bucket.isEmpty())
                    continue;
                HashMap<Integer, Integer> count = new HashMap<>();
                for (int x : bucket) {
                    count.merge(x, 1, Integer::sum);
                }
                int max = Collections.max(count.values());
                answer += bucket.size() - max;
            }

            out.println(answer);
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